//
// Created by austin stone on 2021/6/14.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Info {
    string name;
    vector<string> phones;
};

void readFile() {
    string line, word;
    vector<Info> infos;
    ifstream ifs("/Users/stone/CLionProjects/cpp-proj/a02-io/test"); // 文件输入流
    while (getline(ifs, line)) { //读取行
        Info info;
        istringstream record(line); // 绑定line数据到 string 输入流
        record >> info.name; // 输入一个string 到info.name
        while (record >> word) { //循环每次输入string 到 word
            info.phones.push_back(word); //写入word到集合
        }
        infos.push_back(info);
    }

    //遍历 infos 输出
//    for (auto v = infos.begin(); v != infos.end(); ++v) {
//        cout << v->name << " ";
//        for (auto p = v->phones.begin(); p != v->phones.end(); ++p) {
//            cout << *p << " ";
//        }
//        cout << endl;
//    }

    //ostringstream 输出
    for (const auto &entry : infos) { //for each
        ostringstream out;
        out << entry.name;
        for (const auto &num: entry.phones) {
            out << " " << num;
        }
        out << endl;
        cout << out.str(); // 输出 out流中的 所有 string
    }
}

int main() {
    cout << "hello" << flush;
    cout << "stone" << ends;
    cout << "stone" << endl;

//    int a;
//    cin >> a;
//    cout << cin.rdstate() << endl;
//    cout << "read int value = " << a;

    readFile();

    return 1;
}