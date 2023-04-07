# include <iostream>
# include <fstream>
# include <unistd.h>
# include <vector>
# include <string>
using namespace std;

/*
问题描述：长为n的一个数num 将其分为k段 求这k段的最大乘积
1. dp数组的含义
dp[i][j]表示 将num的前i + 1位数字组成的子数字sub_num分成j段，这j段的最大乘积
2. 状态转移
dp[i][j]可以从 dp[i - 1][j - 1], dp[i - 2][j - 1], ... , dp[j - 1][j - 1]转移而来
3. dp数组的初始化
整个dp数组可以先初始化为0(考虑到dp数组中 其实当i < j时 dp[i][j]是不存在的，因此赋为0更好些)
显然dp[i][1] = num的前i + 1位数字组成的子数字sub_num
4. dp数组的遍历顺序
可以从状态转移方程中看到 dp[i][j] 依赖于 dp[i - 1][k](i - 1 <= k < j), 
我们的遍历顺序只需要保证 在计算dp[i][j]时 它左上角的元素都是已经计算过的 
因此可以是 先在外层循环中正向遍历i 再在内层循环中正向遍历j
也可以是 先在外层循环中正向遍历j 再在内层循环中正向遍历i
5. dp数组的验证
略
*/

// sub_num用来获取 从第begin位开始 长为len的子数字
int sub_num(int num, int begin, int len) {
    return stoi(to_string(num).substr(begin, len));
}

int main() {
    int n, k, num;
    string path = get_current_dir_name();
    // cout << path << endl;
    ifstream in(path + "/cpp/course/algorithm_analyse/3_13_input.txt", ios::in);
    ofstream out(path + "/cpp/course/algorithm_analyse/3_13_output.txt", ios::out);
    
    while (!in.eof()) {
        in >> n >> k >> num;

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; ++i) dp[i][1] = sub_num(num, 0, i + 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 2; j <= k; ++j) {
                for (int l = j - 1; l <= i - 1; ++l) {
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] * sub_num(num, l, i - l));
                }
            }
        }

        out << dp[n - 1][k] << endl;
    }
    

    return 0;
}