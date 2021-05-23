//
// Created by austin stone on 2021/5/23.
//
class StaticTest {
public:
    static int a;
    static sfunc() { //若在头文件中定义static 函数，相应源文件中的实现定义，不需要 static key。
        func()
        a = 11;
    }
    static StaticTest st; //正确，是类 类型
    StaticTest *st; // 正确。
    //StaticTest st; // 错误。
private:
    static int b;
    void func() {
        a = 10;
        b = 9;
    }

};

void f() {
    StaticTest s;
    s.sfunc();

    StaticTest::a = 13;
    StaticTest::sfunc();
}