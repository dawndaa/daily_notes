# include <bits/stdc++.h>
using namespace std;

bool judge(const string& t, const string& r) {
    int i = 1, mod = 26;
    while (i < t.size() && i < r.size() && 
    (t[i] - t[0] + mod) % mod == (r[i] - r[0] + mod) % mod) 
        ++i;
    if (i == t.size()) return true;
    else if (i == r.size()) return false;
    else return (t[i] - t[0] + mod) % mod < (r[i] - r[0] + mod) % mod;
}

int main() {
    int n;
    cin >> n;

    string ret;
    cin >> ret;
    for (int i = 1; i < n; ++i) {
        string tmp;
        cin >> tmp;
        
        if (judge(tmp, ret)) {
            ret = tmp;
        }
    }

    for (int i = 1; i < ret.size(); ++i) {
        ret[i] = 'a' + (ret[i] - ret[0] + 26) % 26;
    }
    ret[0] = 'a';
    cout << ret;

    system("pause");
    return 0;
}