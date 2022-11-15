# include <string>
# include <sstream>
# include <iostream>

template <typename T> std::string debug_rep(const T& t) { // 1 适用于任何类型
    std::ostringstream ret;
    ret << t;
    std::cout << "1" << std::endl;
    return ret.str();
}

template <typename T> std::string debug_rep(T* p) { // 2 适用于指针类型
    std::ostringstream ret;
    ret << "pointer: " << p;
    // if (p)
    //     ret << " " << debug_rep(*p);
    // else 
    //     ret << " null pointer";
    std::cout << "2" << std::endl;
    return ret.str();
}

std::string debug_rep(const std::string& s) { // 3 非模板函数
    std::cout << "3" << std::endl;
    return '"' + s + '"';
}

int main() {
    std::string s("hi");
    // 调用3 传递的是string 在1和3之间选择更特例化的版本
    std::cout << "fir: " << debug_rep(s) << std::endl; 
    // 调用2 传递的是string* 与2直接匹配 匹配1需要类型转换
    std::cout << "sec: " << debug_rep(&s) << std::endl; 

    const std::string* sp = &s;
    // 调用2 传递的是const string* 匹配1,2都要发生类型转换
    // 但最后调用的是 更特例化的 指针版本
    std::cout << "thi: " << debug_rep(sp) << std::endl;

    /* 调用2 传递的是const char* 
    1: const T&  -->  T为char[10]
    2: T*  -->  T为const char
    3: const string&  -->  要从const char* 转换为 string
    可见1 2都提供精确匹配 但我们选择更特例化的2
    */
    std::cout << "fou: " << debug_rep("hi world!") << std::endl;

    system("pause");
    return 0;
}