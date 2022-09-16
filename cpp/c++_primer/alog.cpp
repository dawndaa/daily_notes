# include <bits/stdc++.h>  
using namespace std;
using namespace std::placeholders;

ostream& print(ostream& os, const vector<int>& vec) {
    for (const auto& item: vec) {
        os << item << " ";
    }

    return os;
}

void elimDups(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    auto end_iter = unique(vec.begin(), vec.end());
    print(cout, vec) << endl;

    vec.erase(end_iter, vec.end());

    print(cout, vec) << endl;
}

bool isshorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

int main() {
    vector<int> fir(10), sec;
    iota(fir.begin(), fir.end(), 0);
    replace_copy(fir.begin(), fir.end(), back_inserter(sec), 3, 33);
    // back_inserter(sec) 返回一个插入迭代器 记作it 对插入迭代器进行赋值 相当于向容器中插入元素

    print(cout, fir) << endl;
    print(cout, sec) << endl;

    for (int i = 0; i < 10; ++i) {
        fir.emplace_back(i);
    }
    elimDups(fir);
    stable_partition(fir.begin(), fir.end(), [](int x) {return x > 5 && x < 8;});
    print(cout, fir) << endl;

    auto p = bind(print, ref(cout), _1); 
    // bind采用拷贝传递参数 iostream无法拷贝 使用ref() cref()进行转化
    p(fir);
    
    vector<string> strs = {"woshinibaba", "nibabashiwo", "nishishei", "ninini", "lalala"};
    stable_sort(strs.begin(), strs.end(), isshorter);
    for_each(strs.begin(), strs.end(), [] (const string& tmp) {cout << tmp << " ";});
    cout << endl;

    stable_sort(strs.begin(), strs.end(), bind(isshorter, _2, _1));
    for_each(strs.begin(), strs.end(), [] (const string& tmp) {cout << tmp << " ";});

    system("pause");
    return 0;
}