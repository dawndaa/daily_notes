# ifndef STRBLOB_H
# define STRBLOB_H

# include <string>
# include <vector>
# include <memory>
# include "StrBlobPtr.h"
using namespace std;

class StrBlobPtr;
class StrBlob{
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;

    // 构造函数
    StrBlob();
    StrBlob(initializer_list<string> il);
    // 容量操作
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // 添加 删除元素
    void push_back(const string& t) {data->push_back(t); }
    void pop_back();

    // 元素访问
    string& front();
    const string& front() const; // 重载const类型
    string& back();
    const string& back() const; // 重载const类型

    // 获取迭代器
    StrBlobPtr begin() { return StrBlobPtr(*this); };
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

private:
    // 使用智能指针动态分配空间 保证只要data被引用 就不会被销毁
    shared_ptr<vector<string>> data;
    // 检查data[i]是否合法 不合法抛出异常
    void check(size_type i, const string& msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { };
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { };

void StrBlob::check(size_type i, const string& msg) const {
    if (i >= data->size()) 
        throw out_of_range(msg);
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

# endif