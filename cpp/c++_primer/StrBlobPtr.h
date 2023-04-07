# ifndef STRBLOBPTR_H
# define STRBLOBPTR_H

# include "StrBlob.h"
using namespace std;

class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob& a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    string& deref() const; // 解引用
    StrBlobPtr& incr(); // 递增StrBlobPtr

private:
    // 检查 成功则返回 一个指向vector<string>的shared_prt
    shared_ptr<vector<string>> check(size_t, const string&) const;
    // 保存一个weak_ptr, 意味着底层vector可能被销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const {
    auto ret = wptr.lock(); // 判断vector是否还存在
    if (!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret; 
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  // 解引用p 获取下标为curr的元素
}

// 返回递增之后的对象的引用
StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr"); // 检查curr是不是尾巴
    ++curr;
    return *this;
}

# endif