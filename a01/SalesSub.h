//
// Created by austin stone on 2021/5/16.
//

#ifndef CPPPROJ_SALESSUB_H
#define CPPPROJ_SALESSUB_H
#include "Sales.h"
/*
 * : 继承，  父类有三种继而方式。  public protected private； 如果不写，默认为 private。
 *  下表汇总了不同继承方式，对基类中不同属性的成员的影响结果
    继承方式/基类成员	public成员	protected成员	private成员
    public继承	    public	    protected	    不可见
    protected继承	protected	protected	    不可见
    private继承	    private 	private	        不可见
    ---
    基类中的private成员，子类不论哪种方式继承，都不可见
 */
class SalesSub : public Sales {
private:
//    ~SalesSub(); //不能 外部delete this， 不能 栈初始化
public:
    ~SalesSub();
    virtual std::string isbn(); // 父类中被重写的方法必须是 virtual 的, 仅是继承使用 不需要;  同时子类需要相同的定义
//    virtual std::string Sales::isbn2(); //父类函数是final的， 不可被重写。

    using Sales::weight;
    void destroy();
};
#endif //CPPPROJ_SALESSUB_H
