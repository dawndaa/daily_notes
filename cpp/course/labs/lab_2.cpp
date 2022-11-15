/*
��Ŀ����: ũ���������
��Ŀ����: ���Ѽ���
*/
# include <iostream>
# include <fstream>
# include <vector>
# include <unordered_set>
# include <algorithm>
using namespace std;

vector<int> ret;
void bfs(const unordered_set<int>& forbid, unordered_set<int> used, 
const vector<int>& move, int status, const int& ending, vector<int> path) {
    if (status == ending) {
        ret = path;
        return ;
    }

    for (int i = 0; i < move.size(); ++i) {
        int next = status ^ move[i];
        if (!forbid.count(next) && !used.count(next)) {
            path.emplace_back(i);
            used.insert(next);
            bfs(forbid, used, move, next, ending, path);
            used.erase(next);
            path.pop_back();
        }
    }
}

void print(int status, ofstream& out_file) {
    if (!out_file) {
        cout << "open failed" << endl;
    }

    vector<int> masks{0b1000, 0b0100, 0b0010, 0b0001};
    vector<string> name{"ũ��", "��", "��", "�ײ�"};
    
    for (int i = 0; i < masks.size(); ++i) {
        if (status & masks[i]) 
            out_file << name[i] + "���ϰ�" << endl;
        else out_file << name[i] + "�ڱ���" << endl;
    }
    out_file << endl;
}

int main() {
    unordered_set<int> forbid{3, 6, 7, 8, 9, 12};
    unordered_set<int> used;
    vector<int> move{8, 9, 10, 12};
    int status = 0, ending = 15;
    
    vector<int> path;
    used.insert(0);
    bfs(forbid, used, move, status, ending, path);

    ofstream out_file;
    string out_name = "./2_out.txt";
    out_file.open(out_name, ios::out | ios::trunc);

    int tmp = 0;
    print(tmp, out_file);
    for_each(ret.begin(), ret.end(), [&] (const int& x) {
        tmp = tmp ^ move[x];
        print(tmp, out_file);
    });
    cout << "Result has been saved in 2_out.txt" << endl;

    system("pause");
    return 0;
}