# include <iostream>
# include <vector>

template <typename T>
int compare(const T& v1, const T& v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main() {
    int a = 2, b = 1;
    std::vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {2, 3, 4, 5, 6};

    int ret1 = compare(a, b);
    int ret2 = compare(v1, v2);

    std::cout << ret1 << std::endl;
    std::cout << ret2 << std::endl;

    system("pause");
    return 0;
}