//
// Created by austin stone on 2021/4/25.
//
#include <string>

using namespace std;

struct StructSales {
// struct的成员默认访问修饰符是public，而类(class)默认是private
public: // 这里加不加  public，都一样，因struct 只能是 public 的
    // 构造函数
    StructSales() = default; // 当没有声明任何构造函数时，默认就是这个
//    StructSales(const string &s): bookNo(s) {};
    StructSales(const string &s) : bookNo(s), sold(0), revenue(0) {};

    StructSales(const string &s, unsigned count, double price) : bookNo(s), sold(count), revenue(count * price) {};

    StructSales(istream &is); // 仅声明

    StructSales *combine(const StructSales &);

    StructSales &combine2(const StructSales &);

    string isbn() const {
        return bookNo;
    }

//private:
    string bookNo;
    unsigned sold = 0;  //售出数量
    double revenue = 0; //收益

    double avg_price() const;
};
/*
 * 紧跟在参数列表后的 const，表示 将 this 声明成 指向常量的指针。 则，不能通过this修改成员属性。
 * 此时，通过this调用的成员函数，就是常量成员函数。
 * 常量对象，及常量对象的指针或引用只能调用常量成员函数。
 */
//在struct 类外部定义成员函数
double StructSales::avg_price() const {
//    this->sold = 8; // error
    if (this->sold) return revenue / sold;
    else return 0;
}

//this 属性加上 rhs 属性，返回 this 指针
StructSales *StructSales::combine(const StructSales &rhs) {
    this->sold += rhs.sold;
    this->revenue += rhs.revenue;
    return this;
}

//this 属性加上 rhs 属性，返回 this 指向实例的引用
StructSales &StructSales::combine2(const StructSales &rhs) {
    this->sold += rhs.sold;
    this->revenue += rhs.revenue;
    return *this;
}

#include <iostream>

// io 类属性不可拷贝类型，所以用引用接受; 因会改变流的内容，所以用的普通引用，而非常量引用
istream &read(istream &is, StructSales &data) {
    double price = 0;
    is >> data.bookNo >> data.sold >> price; // 输入 书号，数量，单价
    data.revenue = price * data.sold;
    return is;
}

ostream &print(ostream &os, StructSales &data) {
    os << data.isbn() << " " << data.sold << " " << data.revenue << " " << data.avg_price();
    return os;
}

// 外部实现构造函数； 依赖于输入流构造对象
StructSales::StructSales(istream &is) {
    read(is, *this);
}

int main() {
    // 测试输入输出
//    StructSales ss;
//    auto &is = read(cin, ss);
//    print(cout, ss);
//    cout << endl;

    StructSales ss1("asdf");
    print(cout, ss1);
    cout << endl;

    StructSales ss2(string("abc"), 10, 9.9);
    print(cout, ss2);
    cout << endl;

    StructSales ss3(cin); //依赖输入流构造对象
    print(cout, ss3);
    cout << endl;
    return 1;
}