# include <iostream>
using namespace std;

class reload{
    // 非成员函数 左右侧运算对象可互换的 应定义成非成员函数
    friend ostream& operator<<(ostream&, const reload&);
    friend istream& operator>>(istream&, reload&);
    friend reload& operator+(const reload& lhs, const reload& rhs); 
    friend reload& operator-(const reload& lhs, const reload& rhs);
    friend bool operator==(const reload& lhs, const reload& rhs);
    friend bool operator!=(const reload& lhs, const reload& rhs);

public:
    reload() = default;
    // 成员函数 左侧运算对象默认为*this
    reload& operator+=(const reload&);
    reload& operator-=(const reload&);
    // 下标运算符 一般提供两种版本 一种返回普通引用 另一种返回常量引用
    int& operator[](size_t n);
    const int& operator[](size_t n) const;
    // 递增递减运算符 带int参数的是后置版本 不带的是前置版本
    reload& operator++();
    reload& operator++(int); 
    reload& operator--();
    reload& operator--(int);
    // 函数调用运算符 使类对象能像一个函数一样被调用
    void operator() () {
        cout << this->val << " " << this->num;
    }

private:
    double val;
    int num;
};

ostream& operator<<(ostream& os, const reload& d) {
    os << d.val << " " << d.num;
    return os;
}
istream& operator>>(istream& is, reload& d) {
    is >> d.val >> d.num;
    if (!is) d = reload(); // 判断输入是否成功 不成功则将d置为初始状态
    return is;
}

reload& reload::operator+=(const reload& rhs) {
    this->val += rhs.val;
    this->num += rhs.num;
    return *this;
}
reload& operator+(const reload& lhs, const reload& rhs) {
    reload sum = lhs;
    sum += rhs;
    return sum;
}

reload& reload::operator-=(const reload& rhs) {
    this->val -= rhs.val;
    this->num -= rhs.num;
    return *this;
}
reload& operator-(const reload& lhs, const reload& rhs) {
    reload ret = lhs;
    ret -= rhs;
    return ret;
}

bool operator==(const reload& lhs, const reload& rhs) {
    return lhs.val == rhs.val && lhs.num == rhs.num;
}
bool operator!=(const reload& lhs, const reload& rhs) {
    return !(lhs == rhs);
}

int main() {



    system("pause");
    return 0;
}