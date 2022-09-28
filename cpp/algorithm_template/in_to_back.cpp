// 用于将中缀表达式 转化为 后缀表达式
# include <iostream>
# include <string>
using namespace std;

int main() {


    system("pause");
    return 0;
}
/*
分析:
1+2+3+4  -->  12+3+4+
1+2*3  -->  123*+
2*(4-8/4)  --> 2484/-*
*/