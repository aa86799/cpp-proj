//
// Created by austin stone on 2021/5/23.
//
#include <iostream>
class ConstTest {
public:
    //constexpr 构造函数，必须初始化所有成员属性。函数体通常为空
    constexpr ConstTest(int a): pa(a), pb(a) {};
    constexpr int abc() const {
        return pa + pb; // pb 是 bool 的； 为真时值为1，false 时为0
    }
private:
    int pa;
    bool pb;

};

int main() {
    ConstTest ct = { 10 };
    std::cout << ct.abc() << std::endl; // 输出11.
    return 1;
}
