//
// Created by stone on 2022/7/30.
//

#ifndef CPPPROJ_FriendSymbol_H
#define CPPPROJ_FriendSymbol_H

class FriendUser {
    // 友元函数，声明在类的内部，但并不是类的 成员函数; 在实现中，就可以访问私有的属性
    // 外部可以直接调用 本函数
    friend int getAge(const FriendUser &friends);

    // 友元类; 该类中，可以访问本类的 私有属性
    friend class OtherUser;

public:
    explicit FriendUser(int age);
private:
    int age;
};

#endif //CPPPROJ_友元特性_H