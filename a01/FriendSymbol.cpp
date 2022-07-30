//
// Created by stone on 2022/7/30.
//

#include "FriendSymbol.h"

//class FriendUser {
//    friend int getAge(const FriendUser &friends) {
//        return friends.age;
//    }
//
//public:
//    FriendUser() = default;
//
//private:
//    int age;
//};

FriendUser::FriendUser(int age) {
    this->age = age;
}

// 没有前缀FriendUser:: ，所以不是 成员函数
int getAge(const FriendUser &friends) {
    return friends.age;
}

