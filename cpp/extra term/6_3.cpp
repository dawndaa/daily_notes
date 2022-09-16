# include <bits/stdc++.h>
using namespace std;

/*
5 5
.....
.....
.....
.....
.....
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        map.emplace_back(tmp);
    }

    vector<vector<int>> dp(n, vector<int> (m, INT_MIN));
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '*') {
                dp[i][j] = cnt;
                ++cnt;
            }
            else cnt = 0;
        }
    } // 从左往右数
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = m - 1; j >= 0; --j) {
            if (map[i][j] == '*') {
                dp[i][j] = min(dp[i][j], cnt);
                ++cnt;
            }
            else cnt = 0;
        }
    } // 从右往左数
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (map[j][i] == '*') {
                dp[j][i] = min(dp[j][i], cnt);
                ++cnt;
            }
            else cnt = 0;
        }
    } // 从上往下数
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (map[j][i] == '*') {
                dp[j][i] = min(dp[j][i], cnt);
                ++cnt;
            }
            else cnt = 0;
        }
    } // 从下往上数

    int ret = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            ret = max(ret, dp[i][j]);
    }

    if (ret == INT_MIN) ret = -1;
    cout << ret + 1;

    system("pause");
    return 0;
}