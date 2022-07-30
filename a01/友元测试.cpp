//
// Created by stone on 2022/7/30.
//
#include "FriendSymbol.h"
#include <iostream>
#include "OtherUser.cpp"
using namespace std;

int main() {
    FriendUser user = FriendUser(29);
    cout << getAge(user) << endl; // 29

    OtherUser otherUser = OtherUser(18);
    otherUser.changeFriendUser(user); // 修改 user.age
    cout << getAge(user) << endl; // 18

    cout << string(10, 'c'); // 10个 c
    return 1;
}