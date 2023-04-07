# include "ex13_5.h"

void StrVec::push_back(const std::string& s) {
    chk_n_alloc(); // 确保空间足够
    alloc.construct(first_free++, s); // 构造
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
    auto data = alloc.allocate(e - b);  //利用e - b 分配需要空间的大小
    return {data, uninitialized_copy(b, e, data)}; // 利用uninitialized_copy进行拷贝
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p); // 先逆序销毁元素
        alloc.deallocate(elements, cap - elements);  // 再释放空间
    }
}

StrVec::StrVec(const StrVec& s) { // 拷贝初始化
    auto newdata = alloc_n_copy(s.begin(), s.end()); // 先进行拷贝
    // 再设置指针
    elements = newdata.first; 
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); } // 析构函数 

StrVec& StrVec::operator=(const StrVec& rhs) { // 拷贝赋值
    //先拷贝 后释放 可以解决自赋值问题  先释放后拷贝 可能导致值为空
    auto data = alloc_n_copy(rhs.begin(), rhs.end()); // 先拷贝新值
    free(); // 再销毁旧值

    // 更新指针
    elements = data.first; 
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1; // 原容量为0 则新容量为1 否则 * 2
    auto newdata = alloc.allocate(newcapacity); // 分配空间
    auto dest = newdata; 
    auto elem = elements;
    
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++)); // 移动构造函数move
    }
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}