/*
模拟约瑟夫环 用循环链表进行模拟即可
*/
# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class list_node {
public:
    int val;
    int index;
    list_node* next;
    list_node(int v): val(v), next(nullptr) { };
};

void input(int& n, int& m, vector<int>& psds) {
    ifstream infile;
    string infile_name = "./5_in.txt";
    infile.open(infile_name, ios::in);
    if (!infile) {
        cout << "open failed!" << endl;
    }

    cout << "是否自定义数据(y/n): " << endl;
    char x;
    infile >> x;
    if (x != 'y') {
        cout << "默认数据如下: " << endl;
        cout << "人数为7 报数上限为20 密码表如下:" << endl;
        for_each(psds.begin(), psds.end(), [] (const int& x) { cout << x << " "; });
        cout << endl;
    }
    else {
        psds.clear();
        cout << "请输入人数: " << endl;
        infile >> n;
        cout << "请输入报数上限: " << endl;
        infile >> m;
        cout << "请输入每个人的密码: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "请输入第" << i + 1 << "个人的密码: " << endl;
            int tmp;
            infile >> tmp;
            psds.push_back(tmp);
        }
    }
}

void create_list(list_node*& head, const vector<int>& psds) {
    head->val = psds[0];
    head->index = 1;
    for (int i = 1; i < psds.size(); ++i) {
        list_node* tmp = new list_node(psds[i]);
        tmp->index = i + 1;
        head->next = tmp;
        head = tmp;
    }
}

int main() {
    int n = 7, m = 20;
    vector<int> psds{3, 1, 7, 2, 4, 8, 4};
    input(n, m, psds);

    list_node* head = new list_node(0), *cur = head;
    create_list(cur, psds);
    cur->next = head;
    cur = head;

    int cnt = 0;
    vector<int> ret;
    while (cur) {
        ++cnt;
        if (cnt == m - 1) {
            ret.push_back(cur->next->index);
            if (cur->index != cur->next->index) { 
                m = cur->next->val;
                cur->next = cur->next->next;
                cnt = 0;
            }
            else { 
                break;
            }
        }
        cur = cur->next;
    }

    ofstream outfile;
    string outfile_name = "./5_out.txt";
    outfile.open(outfile_name, ios::out | ios::trunc);
    if (!outfile) {
        cout << "open failed!" << endl;
    }


    outfile << "出列人编号序列如下: " << endl;
    for (int i = 0; i < psds.size(); ++i) {
        outfile << ret[i] << " ";
    }
    cout << "Result has been saved in 5_out.txt" << endl;

    system("pause");
    return 0;
}