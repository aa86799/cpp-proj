//
// Created by austin stone on 2021/6/26.
//

#include <iostream>
#include <pthread.h> // c 语言 头文件，在 cpp 源文件中 有 .h 字符

using namespace std;

void *pthreadTask(void *args) {
    int *i = static_cast<int *>(args);
    cout << "posix线程:" << *i << endl;
    return nullptr;
}

/*
typedef struct
{
       int                       detachstate;   // 线程的分离状态
       int                       schedpolicy;   // 线程调度策略
       structsched_param         schedparam;    // 线程的调度参数
       int                       inheritsched;  // 线程的继承性
       int                       scope;         // 线程的作用域
       size_t                    guardsize;     // 线程栈末尾的警戒缓冲区大小
       int                       stackaddr_set; // 线程的栈设置
       void*                     stackaddr;     // 线程栈的位置
       size_t                    stacksize;     // 线程栈的大小
} pthread_attr_t;
 */

void testPthread() {
    pthread_t pid; //声明线程ID
    int pi = 100;
    pthread_create(&pid, nullptr, pthreadTask, &pi); //创建线程
    pthread_join(pid, nullptr); //等待线程的结束

    pthread_attr_t attr; // 线程属性
    pthread_attr_init(&attr); // 初始化为 默认值
    pthread_attr_setstacksize(&attr, 1024); // pthread_attr_set[xxx] 属性set方法
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置成分离的线程属性。默认非分离。
    /*
     * SCHED_FIFO 实时调度策略，先到先服务 一旦占用cpu则一直运行。一直运行直到有更高优先级任务到达或自己放弃。
     * SCHED_RR   实时调度策略，时间轮转 系统分配一个时间段，在时间段内执行本线程
     */
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    //设置优先级
    //获得对应策略的最小、最大优先级
    int max = sched_get_priority_max(SCHED_FIFO);
    int min = sched_get_priority_min(SCHED_FIFO);
    sched_param param{}; //调试参数
    param.sched_priority = max;
    pthread_attr_setschedparam(&attr, &param);

    pthread_t pid2;
    int pii = 101;
    pthread_create(&pid2, &attr, pthreadTask, &pii); //创建线程
    pthread_join(pid2, nullptr); //等待线程的结束
    cout << "who you are" << endl;
    pthread_attr_destroy(&attr); // 销毁 线程属性

    // pid2 是线程分离的 可能在主线程语句前执行，也可能在后
    pthread_exit(nullptr); // 等待所有线程结束后，再结束主进程
}

#include <queue>

queue<int> que;

void *pop(void *args) {
    if (!que.empty()) {
        printf("取出数据: %d\n", que.front());
        que.pop();
    } else {
        printf("无数据\n");
    }
    return nullptr;
}

// 线程未同步导致的多线程安全问题
// 会有重复的数据取出并出现异常
void testPop() {
    for (int i = 0; i < 5; i++) {
        que.push(i);
    }
    pthread_t pid[10];
//    for (size_t i = 0; i < 10; i++) {
//        pthread_create(&pid[i], nullptr, pop, &que);
//    }
    // 并发 10个线程
    for (auto &i : pid) {
        pthread_create(&i, nullptr, pop, nullptr);
    }

    pthread_exit(nullptr); // 等待所有线程结束后，再结束主进程
}

pthread_mutex_t mut;

//互斥锁
void *sync_pop(void *args) {
    pthread_mutex_lock(&mut);
    if (!que.empty()) {
        printf("取出数据: %d\n", que.front());
        que.pop();
    } else {
        printf("无数据\n");
    }
    pthread_mutex_unlock(&mut);
    return nullptr;
}

//应用互斥锁。一个线程进入函数执行，其它线程等待。
void testSyncPop() {
    pthread_mutex_init(&mut, nullptr);
    for (int i = 0; i < 5; i++) {
        que.push(i);
    }
    pthread_t pid[10];
    for (auto &i : pid) {
        pthread_create(&i, nullptr, sync_pop, nullptr);
    }

    pthread_mutex_destroy(&mut);

    pthread_exit(nullptr); // 等待所有线程结束后，再结束主进程
}

#include "SafeQueue.cpp"

SafeQueue<int> sq;

void *testSafeQueueGet(void *args) {
    int i;
    sq.dequeue(i);
    return nullptr;
}

void *testSafeQueuePut(void *args) {
    int *i = static_cast<int *>(args);
    sq.enqueue(*i);
    return nullptr;
}

void testSafeQueue() {
    pthread_t pid1, pid2;
    for (int i = 0; i < 100; ++i) {
        pthread_create(&pid1, nullptr, testSafeQueueGet, nullptr);
        pthread_create(&pid2, nullptr, testSafeQueuePut, &i);
        /*
         * 等待线程 pid2 执行完。
         * mutex的使用，保证了最多一个线程被真正唤醒, 即便是 broadcast.
         *
         * 当没有 join(pid2)，并发 n 个 生产/消费 线程同时运行，最终 &i 会=100，不符合循环条件，但 &i 在结果输出中出现 多个 100；
         * pthread_cond_broadcast 会唤醒所有线程中的一个(因mutex)，当前是生产，若已有元素，会继续唤醒，唤醒的可能是另一个生产或多个，
         * 直至唤醒消费，消费一个后，消费线程结束，剩余线程争夺，若还是消费线程，消费线程wait，直至生产线程，生产线程结束后，剩余线程争夺，若是之前
         * pthread_cond_wait 的生产线程，这时会继续执行，继续生产； 正因出现连续生产，后面就会出现连续消费。
         */
        pthread_join(pid1, nullptr); //传参pid1或pid2 效果一样的。
        cout << "队列为空吗：" << sq.empty() << endl;
    }
    pthread_exit(nullptr);
}

int main() {
//    testPthread();

//    testPop();

//    testSyncPop();

    testSafeQueue();
    return 1;
}