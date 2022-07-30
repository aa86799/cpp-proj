//
// Created by austin stone on 2021/6/20.
//

#include <iostream>
#include <vector> // 可变大小数组的序列容器；采用的连续存储空间来存储元素；动态分配数组
#include <array>
#include <list>
#include <forward_list>
#include <string>
#include <functional>
//#define NDEBUG // 如在程序顶部加上后，则不再执行内部的assert()

using namespace std;

//测试两个迭代器间的距离差异
void testDifferenceType() {
    vector<int> src;
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);

    auto i1 = src.begin();
    vector<int>::iterator i2 = src.end();

    vector<int>::difference_type diff = i2 - i1;
    cout << "diff = " << diff << endl;
}
#include <queue>;
void testSwap() {
    vector<string> v1 = { "a", "b", "c" };
    vector<string> v2 = { "e", "f" };
    swap(v1, v2);
    cout << v1[0];
    cout << v1[1];

    cout << endl;
    string s1 = "abcde";
    string s2 = "fghi";
    swap(s1, s2);
    cout << s1;
    cout << s2;

    cout << endl;
    array<int, 5> a1 = {1,2,3,4,5};
    array<int, 5> a2 = {6, 7, 8}; // 后面位置初始为0
    swap(a1, a2); // 交换数组元素
    cout << a1[4]; // 0
    cout << a2[4]; // 5
    cout << " maxsize: " << a1.max_size();

//    forward_list<int> fl;
//    fl.insert_after()

    cout << endl;
    cout << *(--s1.end()); //end()在最后之后， --即last位置。
    cout << s1.back();

    string s3 = "ppppp";
    copy(s1.begin(), s1.end(), s3.begin());
    cout << endl << s3 << endl;

}

void testLambda() {
    vector<int> vec = {1,20,3,4,5};
    int temp = 3;
    auto res = find_if(vec.begin(), vec.end(), [temp](int &it) -> bool {
        return it == temp;
    });
    cout << *res << endl;

    auto mut = [temp] () mutable {
        return ++temp;
    };
    cout << mut() << temp << endl;
}

/*
 * 参数 绑定。 bind()， 是一个函数适配器。能改变原函数的参数顺序，能改变调用时参数个数。
 * auto newer = bind(origin_fun, args...); 可使用 参数占位符，相应的占位符编号就是原函数中的参数位置。
 */
bool check_size(const string &str, const string::size_type &sz) {
    return str.size() > sz;
}
using namespace std::placeholders; //bind()和占位符 、ref()和cref() 都定义在 #include <functional>
void testBind() {
    auto check = bind(check_size, _1, 4); //_1是占位符，对应 check_size的第一个参数
    vector<string> vec = { "abcd", "efg", "zz", "j", "hello", "stone"};
//    auto res = find_if(vec.begin(), vec.end(), check);
    auto res = find_if(vec.begin(), vec.end(), bind(check_size, _1, 3));
    cout << *res << endl;

    auto newCheck = bind(check_size, _2, _1); // 定义新的bind函数的入参顺序
    cout << "符合条件吗：" << (newCheck(3, "stone")) << endl;
}

void testConst() {
    const int a = 1024;
//    a= 8; // error

//    const int *b = &a; // 常量指针，本质是指针，不论指向的是否是常量, *p 改变指向值不行.  底层
    int const *b = &a; // 与上一句作用相同
    int c = 1025;
    b = &c;
    cout << *b << endl; // 1025
//    *b = 1026; // error 无法修改指向的值

    int d = 1027;
    const int *e = &d; // 常量指针，本质是指针，不论指向的是否是常量, *p 改变指向值不行.   底层
    int f = 1025;
    e = &f;
    cout << *e << endl; // 1025
//    *e = 1026; // error 无法修改指向的值
    /* 以上这两种形式，就是 const 要在 指针符号 * 之前 */

    int g = 1028;
    int *const h = &g; // 指针常量。指针是常量；本质是一个常量，该常量是一个指针类型. 顶层 const
    *h = 1029;
//    h = &e; // error  无法修改指针地址

    const int * const i = &g;
    int const * const j = &g;

//    int & const aa = 10; // error. 顶层 const 的引用常量， 不存在
    const int &aa = 10; // 底层 const，常量引用
}

int staticArg() {
    static int c = 10;
    return ++c;
}

template<typename T>
void testVarg(initializer_list<T> list) {
    for (auto element: list) {
        cout << element << endl;
    }
}

int s1(int a[]) {return 0;}
int s2(int* a) { return 1; }

extern const int bufSize = 2046;
#include "../ame/externTest.cpp" // 不需要 cmake 中添加
int main() {
    testDifferenceType();

    testSwap();

    testLambda();

    testBind();

    testConst();

    testBuf(); // in atest.cpp

    list<int> li = {1,2,3};
    for (auto i : li) {
        cout << i << endl;
    }

    for (int i = 0; i < 10; ++i)
        cout << staticArg() << endl;

    testVarg(initializer_list<string>{"1,2,3", "cde"});

    assert(true); // 断言，是一个宏；当为 false，则中断程序.
    cout << "stone" << endl; // #define NDEBUG // 如在程序顶部加上后，则不再执行内部的assert()及之后的代码

    cout << __TIME__ << endl;

    return 1;
}


