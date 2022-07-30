//
// Created by austin stone on 2021/6/26.
//

#include <iostream>
#include <thread>

using namespace std;
void test(int i) {
    cout << "task:" << i << endl;
}

int main() {
    thread t1(test, 100); // 创建线程，参数为 函数指针及其参数列表
    t1.detach(); //从主流程中分离，不阻塞主线程

    cout << "then" << endl;

    thread t2(test, 101);
    t2.join(); //阻塞主线程. t2执行完成后，继续主线程

    cout << "end" << endl;

    return 1;
}