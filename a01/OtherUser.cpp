//
// Created by stone on 2022/7/31.
//

#include "FriendSymbol.h"

class OtherUser {
public:
    explicit OtherUser(int age) {
        this->age = age;
    }

    // 访问了 FriendUser 的私有属性
    void changeFriendUser(FriendUser &friendUser) const {
        friendUser.age = this->age;
    }

private:
    int age;
};
