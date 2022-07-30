//
// Created by austin stone on 2021/6/27.
//

#include <iostream>
#include <memory>

/*
 * shared_ptr 智能指针.
 * 它负责自动释放所指向的对象； 允许多个指针指向同一个对象。
 * 使用引用计数，每一个shared_ptr的拷贝都指向相同的内存。每使用它一次，内部的引用计数加1，
 * 每析构一次，内部的引用计数减1，减为0时，释放所指向的堆内存。
 * shared_ptr内部的引用计数是安全的，但是对象的读取需要加锁
 */

using namespace std;

class User {
    string name;
    int age = 18;
public:
    explicit User(string &name) {
        this->name = name;
    }

    string display() {
        return string("name:").append(name).append(", age:").append(to_string(age));
    }
};

shared_ptr<User> factory(string &name) {
    return make_shared<User>(name); // 在动态内存中分配一个对象并初始化它,返回指向此对象的shared_ptr
}

shared_ptr<User> use_factory(string name) {
    auto p = factory(name);
    auto q(p); // 拷贝p给q。
    cout << p.use_count() << endl; // p的引用计数为2， 离开作用域后，q 被释放，p的计数减1。
    return p;
}

int main() {
    auto p = use_factory("stone");
//    User *user = p.get();
    auto user = p.get();
    cout << user->display() << endl;
    cout << p.use_count() << endl;


    return 1;
}