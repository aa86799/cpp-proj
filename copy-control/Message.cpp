//
// Created by stone on 2022/9/5.
//

#include <string>
#include <set>
#include "Folder.cpp"

/*
 * 一个 Message 可以在 多个 Folder 中；
 * 一个 Message 更新后，
 */

class Folder;

class Message {
    friend class Folder;

public:
    explicit Message(const std::string &str = ""): contents(str) { }
    Message(const Message&); // 拷贝构造函数
    Message(Message&&); // 移动构造函数
    Message& operator=(const Message&); // 赋值运算符
    Message& operator=(Message&&) noexcept; // 移动赋值运算符
    ~Message(); // 析构函数
    // 从给定 Folder 中 添加、删除本 message
    void save(Folder&);
    void remove(Folder&);
    void swap(Message &lhs, Message &rhs) {
        for (auto f: lhs.folders) f->removeMsg(&lhs);
        for (auto f: rhs.folders) f->removeMsg(&rhs);
        using std::swap;
        swap(lhs.folders, rhs.folders); // set.swap
        swap(lhs.contents, rhs.contents); // string.swap
        for (auto f: lhs.folders) f->addMsg(&lhs);
        for (auto f: rhs.folders) f->addMsg(&rhs);
    }
    // 从给定 message 移动 Folder 指针
    void moveFolders(Message*);
private:
    std::string contents; // 消息文本
    std::set<Folder*> folders;
    // 将 本 message 添加到 参数 Message 对应的 Folders 中
    void add_to_folders(const Message&);
    // 从每个 folder 中删除 本message482935

    void remove_from_Folders();
};

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.removeMsg(this);
}

void Message::add_to_folders(const Message &msg) {
    for (auto &item: msg.folders) {
        item->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for (auto &item: folders) {
        item->removeMsg(this);
    }
}
// 拷贝构造函数
Message::Message(const Message &msg): contents(msg.contents), folders(msg.folders) {
    add_to_folders(msg);
}

// 使用 string 的 move 来移动 contents；set 的 move 来移动 folder
Message::Message(Message &&msg): contents(std::move(msg.contents)) {
    moveFolders(&msg); // 移动 folder ，并更新 folder 指针
}

Message::~Message() {
    remove_from_Folders();
}

Message & Message::operator=(const Message &rhs) {
    remove_from_Folders(); // 删除自身的 folders 中的 msg
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message& Message::operator=(Message &&rhs) noexcept {
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        moveFolders(&rhs);
    }
}

// 可能抛出异常，未标记成 noexcept
void Message::moveFolders(Message *m) {
    /*
     * 使用 set 的移动赋值运算符
     * 如果不使用 move()，代码也能正常工作，只是带来了不必要的拷贝开销
     *
     */
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->removeMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

int main() {
    return 1;
}