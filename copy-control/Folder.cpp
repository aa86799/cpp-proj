//
// Created by stone on 2022/9/5.
//
#include <set>

class Message; // 若用 include 就相互文件包含了；这里只要 声明 就行了

class Folder {

public:
    void addMsg(Message *msg);
    void removeMsg(Message *msg);

private:
    std::set<Message*> Msgs;
};

void Folder::addMsg(Message *msg) {
    this->Msgs.insert(msg);
}

void Folder::removeMsg(Message *msg) {
    this->Msgs.erase(msg);
}