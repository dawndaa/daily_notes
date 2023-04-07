# include <iostream>
# include <memory>
# include <vector>
# include <numeric>
using namespace std;

int main() {
    allocator<string> a; // 定义一个string的分配器 
    size_t n = 10;
    string* p = a.allocate(n); // 分配一段10string的内存
    string* q = p;

    for (int i = 0; i < 10; ++i) {
        a.construct(q++, "hi " + to_string(i)); // 分别为10个string构造对象
    }

    while (q != p) {
        --q;
        cout << *q << endl;
        a.destroy(q); // 销毁元素 销毁之后可以重新使用
    }

    a.deallocate(p, n); // 释放内存

    vector<int> vec(n, 0);
    iota(vec.begin(), vec.end(), 0);
    allocator<int> v;

    auto ptr = v.allocate(vec.size() * 2); // 分配是vec两倍大小的内存
    auto qtr =  uninitialized_copy(vec.begin(), vec.end(), ptr); // 将vec中的内容填充进动态内存中
    // 等价于 auto qtr = uninitialized_copy_n(vec.begin(), vec.size(), ptr);
    uninitialized_fill_n(qtr, vec.size(), 99);
    // 等价于 uninitialized_fill(qtr, end, 42); end是动态内存的尾后指针
     


    system("pause");
    return 0;
}