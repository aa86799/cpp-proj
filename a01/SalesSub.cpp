//
// Created by austin stone on 2021/5/16.
//

#include "SalesSub.h"
#include <iostream>

SalesSub::~SalesSub() {
    std::cout << "执行析构" << std::endl;
}

std::string SalesSub::isbn() {
    weight = 99.5f;
    std::cout << "sub" << weight << std::endl;
    return "";
}

void SalesSub::destroy() {
    delete this;
}

int main() {
//    SalesSub sub1 = SalesSub(); //栈初始化. 栈，自动回收。执行 public 级的 析构。
    SalesSub sub1; // 等价于 上一句； 栈初始化. 栈，自动回收。执行 public 级的 析构。
    sub1.isbn();
//    sub1.combine(Sales(10)); //  error. Non-const lvalue reference to type 'Sales' cannot bind to a temporary of type 'Sales'
    auto ss = Sales(10);
    sub1.combine(ss);
    //从 形参类型 到 该类类型 的一个隐式转换; 使用 Sales(int a) 构造函数。
    /*
     * 类 隐式转换，只能有一步转换， 比如有构造函数 Sales(string s);
     * 而 combine(Sales sales);
     * 调用：combine("aaa"); // error.  因先要把 "" 转成 string; 再转成 Sales，两步转换 错误
     * /
    //对应的构造函数上，添加 explicit， 会抑制 隐式的，形参 类 类型转换。
    sub1.combine(11);

//    SalesSub *sub2 = new SalesSub(); //堆初始化
//    sub2 -> isbn();
//    sub2->destroy();
    return 1;
}