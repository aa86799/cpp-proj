//
// Created by austin stone on 2021/5/23.
//

class ConstTest {
public:
    //constexpr 构造函数，必须初始化所有成员属性。函数体通常为空
    constexpr ConstTest(int a): pa(a), pb(a) {};

private:
    int pa;
    bool pb;
};
