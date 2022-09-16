# include <bits/stdc++.h>
using namespace std;

/* 
dp数组的含义: dp[i][j][s] 代表从[0][0]到达[i][j]处能够达到状态s的数量
dp数组的状态转移:
    对于格子[i][j] 它由上侧和左侧转移而来 
    s是上侧或左侧格子拥有的状态 c是格子[i][j]的生物种类
    dp[i][j][s | (1 << (c - 1))] += dp[i - 1][j][s];
    dp[i][j][s | (1 << (c - 1))] += dp[i][j - 1][s];
dp数组的初始化:
    注意初始化 首行没有上侧 首列没有左侧
dp数组的遍历顺序:
    由题意 是从左上走到右下  
    再根据状态转移方程 每个格子由左侧和上侧转移得到
    因此 在得到[i][j]处的情况时 需要先知道[i - 1][j] 和 [i][j - 1]处
    所以可以有两种遍历方式
        1. 
            -> -> -> ->
            -> -> 
        2.  | | 
            v v 
            |
            v
输出与检验:
    最后 输出dp[n - 1][m - 1][check]即可 
    check = 11···111 (q个1)
ps:
对于每一个格子 维护2^q种状态(利用状态压缩 q最大是10) 分别记录其次数
(为了减少空间消耗 可以改用哈希表来存 [状态, 对应次数])
*/

int main() {
    int n, m, q, check = 0, mod = 998244353;
    cin >> n >> m >> q;

    int col[n][m];
    for (int i = 0; i < q; ++i) check += 1 << i;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp;
            cin >> tmp;
            col[i][j] = tmp;
        }
    }

    vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>> (m));
    dp[0][0][1 << (col[0][0] - 1)] = 1;
    for (int i = 1; i < m; ++i) {
        int mask = 1 << (col[0][i] - 1);
        for (const auto& p: dp[0][i - 1]) {
            dp[0][i][p.first | mask] = (dp[0][i][p.first | mask] + p.second) % mod;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int mask = 1 << (col[i][j] - 1);
            for (const auto& p: dp[i - 1][j]) {
                dp[i][j][p.first | mask] = (dp[i][j][p.first | mask] + p.second) % mod;
            }
            if (j != 0) {
                for (const auto& p: dp[i][j - 1]) {
                    dp[i][j][p.first | mask] = (dp[i][j][p.first | mask] + p.second) % mod;
                }
            }
        }
    }

    cout << dp[n - 1][m - 1][check];

    system("pause");
    return 0;
}