# include <bits/stdc++.h>
using namespace std;

const int m = 1e7;
bool notprime[m + 1];

int main() {
    int t, mod = 920011128;
    cin >> t;
    memset(notprime, 0, sizeof(notprime));
    notprime[0] = true;
    vector<int> ps;
    for (int i = 2; i <= m; ++i) {
        if (!notprime[i]) {
            ps.emplace_back(i);
        }
        for (int j = 0; j < ps.size() && ps[j] <= m / i; ++j) {
            notprime[i * ps[j]] = true;
            if (i % ps[j] == 0) break;
        }
    }

    for (int i = 0; i < t; ++i) {
        int n, x;
        cin >> n >> x;
        int len = n / x;
        long long ret = x;

        for (int i = 0; i < ps.size(); ++i) {
            if (ps[i] <= len) ret = (ret * ps[i]) % mod;
            else break;
        }
        
        cout << ret << endl;
    }


    system("pause");
    return 0;
}