/*
��������: �����������, �˻ʺ�, Ҫ��ʺ���ͬ��ͬ�й��Խ���

�������: ���û��ݽ��, ��һ��8*8�������ʾ�ʺ��λ�� �лʺ�Ϊ'*' û��Ϊ'o'
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
        outfile << n << "�ʺ�����ĵ�" << i + 1 << "��: " << endl;
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
    cout << "��������չ, �������n�ʺ�����(Ĭ��Ϊ8)" << endl;
    cout << "������n: " << endl;
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