/* 
问题描述: 
n件物品体积分别为w1, w2, w3, ...., wn 背包体积为T 
问是否可以用若干件物品正好装满背包, 给出所有满足条件的解

问题分析:
典型的 01背包 问题, 每件物品取或者不取, 优解为动态规划, 暴力解为回溯

输入实例:
10 6 1 8 4 3 5 2
*/
# include <algorithm>
# include <iostream>
# include <fstream>
# include <vector>
using namespace std;

vector<vector<int>> rets;

void traceback(const vector<int>& w, const int& t, vector<int> path, int index, int sum) {
    if (sum > t) return ;
    if (sum == t) {
        rets.push_back(path);
        return ;
    }

    for (int i = index; i < w.size(); ++i) {
        path.push_back(w[i]);
        sum += w[i];
        traceback(w, t, path, i + 1, sum);
        path.pop_back();
        sum -= w[i];
    }
}

void print(const vector<vector<int>>& rets) {
    ofstream outfile;
    string outname = "./1_out.txt";
    outfile.open(outname, ios::out | ios::trunc);
    if (!outfile) 
        cout << "open failed!" << endl;

    for_each(rets.begin(), rets.end(), [&outfile] (const vector<int>& v) {
        for (const auto& n: v) 
            outfile << n << " ";
        outfile << endl;
    });
}

int main() {
    int t, n;
    ifstream infile;
    string inname = "./1_in.txt";
    infile.open(inname, ios::in);
    if (!infile) 
        cout << "open failed!" << endl;

    cout << "Please enter T: " << endl;
    infile >> t;
    cout << "Please enter n: " << endl;
    infile >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cout << "Please enter the weight: " << endl;
        infile >> weights[i];
    }
    sort(weights.begin(), weights.end());

    vector<int> path;
    traceback(weights, t, path, 0, 0);

    cout << endl << "results: " << endl;
    print(rets);
    cout << "result have been saved in 1_out.txt" << endl;

    system("pause");
    return 0;   
}