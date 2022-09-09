//
// Created by austin stone on 2021/4/25.
//

#ifndef CPPPROJ_SALES_H
#define CPPPROJ_SALES_H

#include <string>

class Sales {
private:
    int count = 0;
    //析构函数 私有时，只能在类域中被调用，无法被外界（包括自己的对象）调用
    // 禁止在栈内存空间内创建此类型的对象。要创建对象，只能用 new 在堆上进行.
    // 禁止 使用 delete 删除此类型对象. 对象的删除只能在类内实现
//    ~Sales(); //析构函数， destroy 执行。
    const int pa; //需要初始化。若定义不初始化，则要在构造函数上初始化。
    int &pb;  // 需要初始化。若定义不初始化，则要在构造函数上初始化。
public:
    Sales(); //默认(无参)构造函数
    /*explicit*/ Sales(int a); //explicit 会抑制 隐式的，形参 类 类型转换。
    Sales(std::string a, int b = 10); //参数有默认值。
    Sales(std::string s, unsigned count, double price);
    Sales(std::string s, unsigned count); // 委托构造函数，要在源文件中定义
    ~Sales(); // 基类中，析构必须是 public
    void combine(Sales &sales);
    void combine2(Sales sales);
    void add(Sales sales);
    void read();
    int size();

protected:
    float weight;
    //父类中被重写的方法必须是 virtual 的, 仅是继承使用 不需要；  同时子类需要相同的定义
    virtual std::string isbn();
    virtual std::string isbn2() final;  //final added in cpp11
};

#endif //CPPPROJ_SALES_H
