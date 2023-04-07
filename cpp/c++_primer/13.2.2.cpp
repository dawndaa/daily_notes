// 定义一个像 指针 的类
# include <string> 

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr& p):
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    std::string* ps;
    int i;
    std::size_t* use; // 引用计数
};

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    
    return *this;
}

/* 定义了swap的类的 赋值操作
HasPtr& HasPtr::operator=(HasPtr rhs) { //参数是按值传递的
    swap(*this, rhs); // 交换二者
    return *this; 
}
*/

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}