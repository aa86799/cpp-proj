//
// Created by austin stone on 2021/6/20.
//

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <string>
#include <functional>

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
    array<int, 5> a2 = {6, 7, 8};
    swap(a1, a2);
    cout << a1[0];
    cout << a2[0];
    cout << " " << a1.max_size();

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

int main() {
    testDifferenceType();

    testSwap();

    testLambda();

    testBind();

    return 1;
}