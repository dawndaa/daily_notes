/*
随机产生n个整数并对其排序
产生随机数使用的是 rand() 容器使用的是vector
排序分别用了 冒泡排序 和 归并排序
问题规模取了 10 100 1000 
*/
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void get_random_vector(vector<int>& arr, int n) { // 生成一个大小为n的随机数组
    arr.clear(); // 先将arr清空
    for (int i = 0; i < n; ++i) {
        int tmp = rand();
        arr.emplace_back(tmp);
    }
}

ostream& print(ostream& os, const vector<int>& arr) { // 打印数组
    for_each(arr.begin(), arr.end(), [&](const int& x) { os << x << " "; });
}

void bubble_sort(vector<int>& arr) { // 冒泡排序
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[i]) 
                swap(arr[i], arr[j]);
        }
    }
}

vector<int> merge_sort(const vector<int>& left, const vector<int>& right) { // 排序
    int l_id = 0, r_id = 0;
    vector<int> ret;
    while (l_id  != left.size() && r_id != right.size()) {
        if (left[l_id] < right[r_id]) {
            ret.emplace_back(left[l_id]);
            ++l_id;
        }
        else {
            ret.emplace_back(right[r_id]);
            ++r_id;
        }
    }
    
    while (l_id != left.size()) {
        ret.emplace_back(left[l_id]);
        ++l_id;
    }
    while (r_id != right.size()) {
        ret.emplace_back(right[r_id]);
        ++r_id;
    }

    return ret;
}

vector<int> merge(const vector<int>::iterator& begin, const vector<int>::iterator& end) { // 归并
    if (begin + 1 == end) return {*begin};

    vector<int> left = merge(begin, begin + (end - begin + 1) / 2);
    vector<int> right = merge(begin + (end - begin + 1) / 2, end);
    vector<int> ret = merge_sort(left, right);

    return ret;
}

int main() {
    vector<int> scope{10, 100, 1000};

    for (const auto& n: scope) {
        vector<int> arr;

        get_random_vector(arr, n);
        print(cout, arr) << endl;
        bubble_sort(arr); // 冒泡排序
        print(cout, arr) << endl;

        get_random_vector(arr, n);
        print(cout, arr) << endl;
        arr = merge(arr.begin(), arr.end()); // 归并排序
        print(cout, arr) << endl << endl;
    }

    system("pause");
    return 0;
}