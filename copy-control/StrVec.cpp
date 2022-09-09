//
// Created by stone on 2022/9/8.
//

#include <string>
#include <vector>
#include <memory>


using namespace std;

/*
 * 动态内存分配 string 的内存空间
 */
class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}; // 默认构造函数
    StrVec(const StrVec &); // 拷贝构造函数
    /*
     * && 用右值引用，表示存活周期短暂；
     * noexcept 显式声明成 不抛出异常；若不声明，编译器会做些额外的工作
     */
    StrVec(StrVec &&) noexcept; // 移动构造函数
    StrVec &operator=(const StrVec &); // 赋值运算符
    StrVec &operator=(StrVec &&) noexcept; // 移动赋值运算符
    ~StrVec();

    void push_back(const string &);
    void push_back(string &&); // 移动元素的实现

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    string *begin() const { return elements; };

    string *end() const { return first_free; };

    StrVec& qa() & { // 一个&，表示 返回的是 左值引用
        return *this;
    }
    StrVec& qb() && { // 两个&，表示返回的是 右值引用
        return *this;
    }
    std::vector<int> ve;
    StrVec qc() const & { // const 左值， this 是 const 左值
//        sort(this->ve.begin(), this->ve.end()); // 对 const 左值，无法直接排序
//        return *this;

        StrVec sv(*this); // 拷贝构造
        sort(sv.ve.begin(), sv.ve.end());
        return sv;
    }
private:
    std::allocator<string> alloc; // 分配元素
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }

    std::pair<string *, string *> alloc_n_copy(const string *, const string *);

    void free(); // 销毁元素并释放内存
    void reallocate(); // 获得更多内存，并拷贝已有元素
    string *elements; // 指向数组首元素的指针
    string *first_free; // 指向第一个空闲元素的指针
    string *cap; // 指向数组尾后位置的指针

};

StrVec::StrVec(const StrVec &sv) {
    auto newData = alloc_n_copy(sv.begin(), sv.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

// 实现资源的移动，而非拷贝； 接管给定对象中的 成员指针；再将给定对象中的指针置空
StrVec::StrVec(StrVec &&sv) noexcept : elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
    sv.elements = sv.first_free = sv.cap = nullptr; // 置空后，再对 sv 运行析构函数是安全的
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) { // 需要先检测，非自身；因为后面会先 free() this
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::push_back(const string &s) {
    chk_n_alloc(); // 确保有空闲内存
    alloc.construct(first_free++, s); // 在 first_free 指向元素中构造 s 的副本
}

void StrVec::push_back(string &&s) {
    chk_n_alloc(); // 确保有空闲内存
    /*
     * construct 根据第二个参数是右值引用， 会使用 string 的 移动构造函数 来构造新元素
     */
    alloc.construct(first_free++, std::move(s));
}

std::pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b); // 分配
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements); // 释放内存
    }
}

//void StrVec::reallocate() {
//    auto newCapacity = size() ? 2 * size() : 1; // 两倍的空间
//    auto newData = alloc.allocate(newCapacity);
//
//    auto dest = newData; // 新数组中下一个空闲位置
//    auto elem = elements; //
//    // for 循环，中应用 construct() 从旧元素中拷贝到新内存中
//    for (size_t i = 0; i != size(); ++i) {
//        /*
//         * move 是一个 标准库函数，在 utility 头文件中；
//         * 而我们使用是 std::move();
//         * 由 move() 返回的 string，会令 construct 调用 string 的移动构造函数；
//         * 这个构造函数，实现了 指针的拷贝，而避免了 string 对象的拷贝
//         */
//        alloc.construct(dest++, std::move(*elem++));
//    }
//
//    free(); // 销毁旧元素
//    elements = newData;
//    first_free = dest;
//    cap = elements + newCapacity;
//}

void StrVec::reallocate() {
    auto newCapacity = size() ? 2 * size() : 1; // 两倍的空间
    auto first = alloc.allocate(newCapacity);
    /*
     * make_move_iterator() 创建移动迭代器
     * uninitialized_copy() 将源迭代器区间[first, last)的每个对象拷贝到目的区间[result,...)
     *    内部 construct 时，会使用 string 的移动构造函数来构造元素
     * 由于移动一个对象后，可能销毁原对象；
     * 因此只有确定，算法在为一个元素赋值或将其传递给一个用户定义的函数后不再使用它，才能将移动迭代器传递给算法
     */
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newCapacity;
}