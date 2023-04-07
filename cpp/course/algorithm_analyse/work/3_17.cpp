# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <unistd.h>
using namespace std;

/*
1. dp数组的含义
dp[i][j] 是指A前i个字符组成的子串sub_a 与 B前j个字符组成的子串sub_b的扩展距离
2. 状态转移
dp[i][j] 可以由 dp[i - 1][j] dp[i][j - 1] dp[i - 1][j - 1]转移得到
3. dp数组的初始化
因为求得是最小值，因此数组初始化时均设置为一个较大的数 
dp[0][j]初始化为 k * j, dp[i][0]初始化为 k * i
4. 遍历顺序
根据状态转移方程，先正向遍历i，再正向遍历j 或者 先正向遍历j，再正向遍历i 均可
5. 验证dp数组
略
*/

int main() {
    string A, B;
    int k;
    string path = get_current_dir_name();
    ifstream in(path + "/cpp/course/algorithm_analyse/3_17_input.txt", ios::in);
    ofstream out(path + "/cpp/course/algorithm_analyse/3_17_output.txt", ios::out);
    
    while (!in.eof()) {
        in >> A >> B >> k;

        int al = A.size(), bl = B.size();
        vector<vector<int>> dp(al + 1, vector<int> (bl + 1, 0x3f3f3f3f));
        for (int i = 0; i <= al; ++i) dp[i][0] = i * k;
        for (int i = 0; i <= bl; ++i) dp[0][i] = i * k;

        for (int i = 1; i <= al; ++i) {
            for (int j = 1; j <= bl; ++j) {
                dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + k, min(dp[i][j - 1] + k, dp[i - 1][j - 1] + abs(A[i - 1] - B[j - 1]))));
            }
        }

        out << dp[al][bl] << endl;
    }

    return 0;
}