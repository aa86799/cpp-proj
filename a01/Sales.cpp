//
// Created by austin stone on 2021/4/25.
//

#include "Sales.h"
#include <iostream>
using namespace std;

//初始化 pa、pb属性
//Sales::Sales():pa(0), pb(const_cast<int &>(pa)) {
Sales::Sales(): Sales(0) { //委托构造函数

}

//初始化 pa、pb属性
Sales::Sales(int a):pa(a), pb(a) {

}

Sales::Sales(std::string a, int b):pa(a.size()), pb(b) {

}

// 将 unsigned int, 赋值给 int&, 需要类型转换 reinterpret_cast
Sales::Sales(std::string s, unsigned int count, double price): pa(count), pb(reinterpret_cast<int &>(count)) {

}

Sales::Sales(std::string s, unsigned count): Sales(s, count, 0) { //委托构造函数

}

Sales::~Sales() {

}

void Sales::combine(Sales &sales) {
    cout << "Sales::combine" << sales.pa << endl;
}

void Sales::combine2(Sales sales) {
    cout << "Sales::combine" << sales.pa << endl;
}

void Sales::add(Sales sales) {

}

void Sales::read() {
    count += 1;
}

int Sales::size() {
    return this->count;
}

std::string Sales::isbn() {
    cout << "isbn super" << endl;
    return "";
}

std::string Sales::isbn2() {
    return "";
}



//int main() {
//    Sales s = Sales();
//    s.read();
//    cout << s.size() << std::endl;
//    return 1;
//}