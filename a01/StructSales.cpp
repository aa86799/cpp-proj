//
// Created by austin stone on 2021/4/25.
//
using namespace std;
struct StructSales {
    string bookNo;
    unsigned sold = 0;  //销售
    double revenue = 0; //收益
    string isbn() const {
        return bookNo;
    }
    StructSales& combine(const StructSales&);
    double avg_price() const;
};
/*
 * 紧跟在参数列表后的 const，表示 将 this 声明成 指向常量的指针。 则，不能通过this修改成员属性。
 * 此时，通过this调用的成员函数，就是常量成员函数。
 * 常量对象，及常量对象的指针或引用只能调用常量成员函数。
 */

//在struct 外部定义成员函数
double StructSales::avg_price() const {
    if (this->sold) return revenue / sold;
    else return 0;
}

//this 属性加上 rhs 属性，返回this
StructSales & StructSales::combine(const StructSales &rhs) {
    this->sold += rhs.sold;
    this->revenue += rhs.revenue;
    return this;
}