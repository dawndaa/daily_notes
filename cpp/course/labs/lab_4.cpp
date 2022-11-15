/*
问题描述: 经典回溯问题, 八皇后, 要求皇后不能同行同列共对角线

问题分析: 采用回溯解决, 用一个8*8的数组表示皇后的位置 有皇后为'*' 没有为'o'
*/
# include <vector>
# include <string>
# include <iostream>
# include <fstream>
using namespace std;

void back_track(vector<vector<string>>& ret, vector<string>& tmp, vector<bool>& cols,
vector<bool>& ldiag, vector<bool>& rdiag, int x, int n){
    if (x == n) {
        ret.push_back(tmp);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cols[i] || ldiag[i + x] || rdiag[n + x - 1 - i]) continue;
        tmp[x][i] = '*';
        cols[i] = ldiag[x + i] = rdiag[n + x - 1 - i] = true;
        back_track(ret, tmp, cols, ldiag, rdiag, x + 1, n);
        tmp[x][i] = 'o';
        cols[i] = ldiag[x + i] = rdiag[n + x - 1 - i] = false;
    }
}

void print(const vector<vector<string>>& rets, int n) {
    ofstream outfile;
    string outfile_name = "./4_out.txt";
    outfile.open(outfile_name, ios::out | ios::trunc);
    if (!outfile) {
        cout << "open failed!" << endl;
    }

    for (int i = 0; i < rets.size(); ++i) {
        outfile << n << "皇后问题的第" << i + 1 << "解: " << endl;
        for (int j = 0; j < rets[i].size(); ++j) {
            outfile << rets[i][j] << endl;
        }
        outfile << endl;
    }
}

int main() {
    ifstream infile;
    string infile_name = "./4_in.txt";
    infile.open(infile_name, ios::in);
    if (!infile) {
        cout << "open failed!" << endl;
    }

    int n = 8;
    cout << "进行了扩展, 可以求解n皇后问题(默认为8)" << endl;
    cout << "请输入n: " << endl;
    infile >> n;

    vector<bool> cols(n, false), ldiag(2*n - 1, false), rdiag(2*n - 1, false);
    vector<vector<string>> ret;
    vector<string> tmp(n, string(n, 'o'));
    back_track(ret, tmp, cols, ldiag, rdiag, 0, n);

    print(ret, n);
    cout << "Results have been saved in 4_out.txt" << endl;

    system("pause");
    return 0;
}