//
// Created by austin stone on 2021/6/26.
//

#include <pthread.h>
#include <queue>
#include <iostream>
#include <thread>
#include <cstdlib>

using namespace std;

template<class T>
class SafeQueue {
public:
    SafeQueue() {
        pthread_mutex_init(&mut, 0);
        pthread_cond_init(&cond, 0);
    }

    ~SafeQueue() {
        pthread_mutex_destroy(&mut);
        pthread_cond_destroy(&cond);
    }

    void enqueue(const T &t) {
        pthread_mutex_lock(&mut);
        if (!q.empty()) {
            pthread_cond_wait(&cond, &mut);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 50)); //当前线程睡眠
//        std::this_thread::sleep_for(std::chrono::seconds(1));
        q.push(t);
        cout << "生产:" << t << endl;
        //发出信号 通知挂起线程
        // pthread_cond_signal(&cond); //由系统唤醒一个线程
        pthread_cond_broadcast(&cond); //广播 对应多个消费者的时候 多个线程等待唤醒其它所有
        pthread_mutex_unlock(&mut);
    }

    int dequeue(T &t) {
        pthread_mutex_lock(&mut);
        while (q.empty()) {
            pthread_cond_wait(&cond, &mut); // 等待 挂起
        }
        t = q.front();
        q.pop();
        cout << "消费:" << t << endl;
        pthread_mutex_unlock(&mut);

        return 1;
    }

    const char *empty() {
        return q.empty() ? "true" : "false";
    }

private:
    std::queue<T> q;
    pthread_mutex_t mut; // 互斥锁
    pthread_cond_t cond; // 线程条件
};
