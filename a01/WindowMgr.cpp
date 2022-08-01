//
// Created by stone on 2022/7/31.
//

#include <string>
#include <vector>
#include "Screen.cpp"

using namespace std;

class WindowMgr {
public:
    void addFirst(Screen &screen) {
        screens.insert(screens.begin(), screen);
    }
    void removeFirst() {
        screens.erase(screens.begin());
    }
    Screen * getFirst() {
        if (!screens.empty()) {
            return &screens[0];
        }
        return nullptr;
    }
    int screenSize() {
        return screens.size();
    }
private:
//    vector<Screen> screens{Screen(10, 20, ' ')};
    vector<Screen> screens;
};

int main() {
    WindowMgr mgr = WindowMgr();
    auto screen = Screen(10, 20, ' ');
    mgr.addFirst(screen);
    auto p = mgr.getFirst();
    p->some_member();

    const Screen cs;
    cs.some_member(); // 内部 ctr++
    mgr.addFirst(const_cast<Screen &>(cs));

    auto ss = mgr.getFirst();
    cout << *ss->getCtr() << endl; // 输出 1

    auto ctr = p->getCtr(); // 返回底层 const, 常量指针
    Screen::pos xx = 88;
//    *ctr = xx; // error， 指针指向值不可变
    ctr = &xx;
    cout << *ctr << endl; // 输出 0
    cout << mgr.screenSize() << endl; // 输出 2
    return 1;
}