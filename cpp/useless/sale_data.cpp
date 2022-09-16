# include <bits/stdc++.h>
using namespace std;


// class 和 struct 的区别在于默认访问权限 class默认为private struct默认为public
class Sales_data{
// 友元 允许非成员函数访问private的内容
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const string& s): bookNo(s) { }
    Sales_data(const string& s, unsigned n, double p): 
        bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(istream &);

    // 成员函数
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

    // 属性
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

Sales_data::Sales_data(istream& is) {
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    
    sum.combine(rhs);
    
    return sum;
}

ostream &print(ostream& os, const Sales_data& hs) {
    os << hs.bookNo << " " << hs.revenue << " " << hs.units_sold << " " << hs.avg_price();

    return os;
}

istream &read(istream& is, Sales_data& hs) {
    double price = 0;
    is >> hs.bookNo >> hs.units_sold >> price;
    hs.revenue = price * hs.units_sold;

    return is;
}

int main() {
    Sales_data acc = Sales_data("10086", 8, 521.123);
    print(cout, acc);

    system("pause");
    return 0;
}