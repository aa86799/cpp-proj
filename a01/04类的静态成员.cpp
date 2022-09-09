//
// Created by austin stone on 2021/5/23.
//
class StaticTest {
public:
//    static int a = 0; // 错误。非静态常量的，需要在外部初始化
    static int a;
    static void sfunc() { //若在头文件中定义static 函数，相应源文件中的实现定义，不需要 static key。
        // func()// 静态函数中，不能直接调用 成员函数
        a = 11;
    }
    static StaticTest st; //正确，是类 类型
    StaticTest *stt; // 正确。
    // StaticTest sts; // 错误。 必须有指针符
    const static int con = 1024; // 静态常量
    static constexpr int con2 = 1025; // con2 是常量表达式
private:
    static int b;
    void func() {
        a = 10;
        b = 9;
    }

};

// 直接使用 class 的静态属性成员，报了链接错误。ld: symbol(s) not found for ...
// 需要在函数外部声明一下
int StaticTest::a;
void f() {
    StaticTest s{};
//    s.sfunc();

    StaticTest::a = 13;
    StaticTest::sfunc(); // 使用域运算符 :: 调用静态成员
//    StaticTest::con = 8; // 常量不可改变
}


#include <algorithm>
#include <numeric>
#include <array>
#include <iostream>
#include <vector>

int main() {
    std::array<int, 3> ary = {1,2,3};
    auto c = std::find(ary.begin(), ary.end(), 4);
    std::cout << *c; // 未找到输出 0

    StaticTest::a = 13;

    int a1[] = {0,1,2,202020202};
    std::cout << (sizeof(a1)/sizeof(int));

    std::vector<int> v = {1,2,3};
    std::for_each(v.begin(), v.end(), [](const int& s) { std::cout << s << " "; });

    int aa = 8;
    int &bb = aa;
    aa = 9;
    std::cout << bb; // 输出9
    return 1;
}