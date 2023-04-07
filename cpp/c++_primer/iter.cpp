# include <bits/stdc++.h>
using namespace std;

int main() {
    /* 插入迭代器 
    front_inserter(_Container &__x)  使用push_front()
    back_inserter(_Container &__x) 使用push_back()
    inserter(_Container &__x, _Iterator __i ) 相当于 insert(c, __i); 
    */

    /* 流迭代器
    istream_iterator<T> in(cin);
    ostream_iterator<T> out(cout, c_str);
    */
    istream_iterator<int> in(cin);
    istream_iterator<int> eof;
    vector<int> vec(in, eof);

    ostream_iterator<int> out(cout, " ");
    for (const auto& i: vec) {
        *out++ = i;
    }
    cout << endl;

    /* 反向迭代器
    rbegin() rend()
    具有方法 base() 得到正常的正向迭代器
    */
    auto it = vec.rend().base();
    cout << it[2] << endl;
    for_each(it, vec.end(), [] (int x) {cout << x << " ";});

    system("pause");
    return 0;
}