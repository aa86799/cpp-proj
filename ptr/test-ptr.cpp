//
// Created by austin stone on 2021/6/27.
//

#include <iostream>
#include <memory>

using namespace std;

class User {
    string name;
    int age = 18;
public:
    User(string name) {
        this->name = name;
    }
};

shared_ptr<User> factory(string arg) {
    return make_shared<User>(arg);
}

shared_ptr<User> use_factory(string arg) {
    auto p = factory(arg);
    auto q(p); // 拷贝p给q。
    cout << p.use_count() << endl; // p的引用计数为2， 离开作用域后，q 被释放，p的计数减1。
    return p;
}

int main() {
    auto p = use_factory("stone");
    cout << p.use_count() << endl;

    return 1;
}