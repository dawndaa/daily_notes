# include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> ump;
    for (int i = 0; i < 100; ++i) {
        ump[i] = i;
    }

    // 元素通过哈希函数映射到桶 然后再在桶中顺序寻找到对应元素
    // 一个桶中可能含有多个元素 如果含有元素过多 会影响查找效率
    cout << ump.bucket_count() << endl; // 已用桶数目
    cout << ump.max_bucket_count() << endl; // 最大桶数目
    cout << ump.bucket_size(0) << endl; // 指定桶大小
    cout << ump.bucket(1) << endl; // 指定元素在哪个桶

    system("pause");
    return 0;
}