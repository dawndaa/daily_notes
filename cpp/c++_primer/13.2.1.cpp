// 定义了一个行为像 值 的类
# include <string>

class HasPtr {
public:
    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0) { }
    // 每个HasPtr对象中ps指向的string 都有自己的拷贝
    HasPtr(const HasPtr& p):
        ps(new std::string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr& ); // 重载运算符=
    ~HasPtr() { delete ps; } // 析构函数 需要释放new出来的动态空间
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    // 先拷贝 再删除
    auto newp = new std::string(*rhs.ps); // *rhs.ps = *(rhs.ps)
    delete ps;

    ps = newp;
    i = rhs.i;
    return *this;
}