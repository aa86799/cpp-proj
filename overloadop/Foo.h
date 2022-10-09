//
// Created by stone on 2022/9/9.
//

#ifndef CPPPROJ_FOO_H
#define CPPPROJ_FOO_H

#include <iostream>

using namespace std;
class Foo {
public:
    double price;
    double weight;
    // 输出运算符，重载，需要是 friend 友元函数
//    friend ostream& operator<<(ostream& os,const Foo& foo);
};

// 非成员函数
ostream& operator<<(ostream& os,const Foo& foo);

#endif //CPPPROJ_FOO_H
