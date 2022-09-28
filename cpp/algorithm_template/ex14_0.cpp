class smallInt{
public:
    smallInt(int v): val(v) { } // 构造函数
    // 类型转换运算符 必须是类的成员函数1 没有返回类型和参数列表 通常定义为const函数
    operator int() const { return val; } // 允许隐式转换
    // 加上了ecplicit 不允许隐式转换
    explicit operator int() const { return val; }
private:
    int val;
};