//
// Created by stone on 2022/7/31.
//
#include <string>
#include <iostream>

using namespace std;

class Screen {
public:
//    typedef string::size_type pos; // 类型别名
    using pos = string::size_type; // 类型别名
    Screen() = default;

    Screen(pos w, pos h, char c) : width(w), height(h), contents(string(w * h, c)) {}

    char get() const {
        return this->contents[cursor];
    }

    inline char get(pos r, pos c) const;

    Screen &move(pos r, pos c);

    /* const 函数重载 */
    void some_member() const;
    void some_member();

    // 底层 const， 顶层 const(内部 this 指针不可变)
    const pos* getCtr() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable pos access_ctr = 0;
};

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this; // 以引用类型返回 this 指针，返回就是常量引用
}

void Screen::some_member() const { // 看作 some_member(const *this)
    this->access_ctr++;
    cout << "const this 指针的 some_member() const" << endl;
}

void Screen::some_member() {
    cout << "普通some_member()" << endl;
}

const Screen::pos * Screen::getCtr() const {
    return &access_ctr;
}