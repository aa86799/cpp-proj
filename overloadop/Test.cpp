//
// Created by stone on 2022/9/9.
//

#include <iostream>

#include "Foo.h"

using namespace std;

int main() {
    Foo f1 = {};
    f1.weight = 10;
    f1.price = 20;
    cout << f1 << endl; // Foo 中应用了 << 运算符重载
    f1.weight = 30;
    cout << f1 << endl;

    double s = 500;
    int i = 1;
    while (i < 24) {
        i++;
        s *= 1.5;
    }
    cout << "---" << s << endl;


    return 1;
}