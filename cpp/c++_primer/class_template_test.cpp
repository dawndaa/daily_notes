# include "class_template.h"
# include <iostream>

int main() {
    Blob<int> b;

    for (int i = 0; i < 100; ++i) {
        b.push_back(i);
    }
    auto end = b.back();
    std::cout << "b.back(): " << end << std::endl;
    std::cout << "b.size(): " << b.size() << std::endl;
    std::cout << "b[99]: " << b[99] << std::endl;

    for (int i = 0; i < 100; ++i) {
        b.pop_back();
        std::cout << b.size() << std::endl;
    }
    if (b.empty()) {
        std::cout << "b is empty!";
    }

    system("pause");
    return 0;
}