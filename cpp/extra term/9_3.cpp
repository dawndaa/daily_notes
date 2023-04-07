# include <bits/stdc++.h>
using namespace std;
/*
5 7
1 2
1 3
2 3
3 5
2 5
4 5
3 4
*/

int mod = 998244353;
int n, m;
unordered_map<int, vector<int>> mp;
unordered_set<int> start;
unordered_set<int> ending;

int travel(int node, vector<int>& cnt) {
    int ans = 0;
    if (ending.count(node)) return 1;

    for (int i = 0; i < mp[node].size(); ++i) {
        if (cnt[mp[node][i]] == 0) cnt[mp[node][i]] = travel(mp[node][i], cnt);
        ans = (ans + cnt[mp[node][i]]) % mod;
    }

    return ans;
}

int main() {
    cin >> n >> m;
    vector<int> in(n + 1, 0), out(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ++out[a], ++in[b];
        mp[a].emplace_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) start.insert(i);
        if (out[i] == 0) {
            ending.insert(i);
        }
    }

    vector<int> cnt(n + 1, 0);
    int ret = 0;
    for (const auto& p: start) {
        int tmp = travel(p, cnt);
        ret = (ret + tmp) % mod;
    }

    cout << (ret + mod) % mod;

    system("pause");
    return 0;
}