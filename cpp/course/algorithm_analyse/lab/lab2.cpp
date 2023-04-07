# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <algorithm>
# include <unistd.h>
# include <fstream>
using namespace std;
/*
1. dp数组的含义
dp[i][j] 切割从p[i]到p[j]这一块钢条的最小代价
2. 状态转移 0 <= i, j <= n + 1
dp[i][j] = min(dp[i][k] + dp[k][j] + len[i][j], dp[i][j]), i < k < j
3. dp数组初始化
因为求的是最小值，所以应该初始化为一个较大的值
dp[k][k + 1] = 0
4. 遍历顺序
根据状态转移方程可知 可以从下到上 从左到右
或者 从左到右 从下到上 遍历
5. 验证dp数组 略
*/
void MinCost(int L, int n, int* p) {
    sort(p, p + n + 2);

    vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0x3f3f3f3f));
    for (int i = 0; i < n + 1; ++i) {
        dp[i][i + 1] = 0;
    }  

    for (int i = n + 1; i >= 0; --i) {
        for (int j = i + 1; j < n + 2; ++j) {
            cout << dp[i][j] << " ";
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][k] + dp[k][j] + p[j] - p[i], dp[i][j]);
            }
        }
        cout << endl;
    }

    cout << dp[0][n + 1];
}

int main() {
    int L, n;
    string path = get_current_dir_name();
    ifstream in(path + "/lab2.in", ios::in); 
    in >> L >> n;
    int *p = new int[n + 2];
    p[0] = 0, p[n + 1] = L;
    for (int i = 1; i < n + 1; ++i) {
        in >> p[i];
    }

    MinCost(L, n, p);

    return 0;
}