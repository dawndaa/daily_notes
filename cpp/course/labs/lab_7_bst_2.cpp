# include <iostream>
# include <queue>
# include <fstream>
using namespace std;

int inf = 0x3f3f3f3f;
ofstream outfile;
vector<int> bst(1000, inf);

// 输入数组
void input(vector<int>& vals, string inname) {
    ifstream infile;
    infile.open(inname, ios::in);
    if (!infile) 
        cout << "open failed!" << endl;

    while (!infile.eof()) {
        int tmp;
        infile >> tmp;
        vals.push_back(tmp);
        cout << tmp;
    }
}

// 中序遍历
void inorder(int id) {
    if (bst[id] == inf) return ;

    inorder(2 * id + 1);
    outfile << bst[id] << " ";
    inorder(2 * id + 2);
}

void insert(int, int);
// 建树
void create_bst(int id, const vector<int>& vals) {
    for (int i = 0; i < vals.size(); ++i) {
        insert(id, vals[i]);
    }
}

// 二叉查找树 插入节点
void insert(int id, int k) {
    if (bst[id] == inf) {
        bst[id] = k;
        return ;
    }
    
    if (k == bst[id]) return ;
    else if (k < bst[id]) 
        insert(2 * id + 1, k);
    else 
        insert(2 * id + 2, k);
}

// 移动节点下标
void remove(int id, int child) {
    bst[id] = bst[child];
    bst[child] = inf;
    id = child;

    if (bst[2 * id + 1] != inf) 
        remove(id, 2 * id + 1);
    if (bst[2 * id + 2] != inf) 
        remove(id, 2 * id + 2);
}

// 二叉查找树 删除节点
void delete_node(int id, int key, bool& flag) {
    if (bst[id] == inf) { // 当遇到空节点时 说明没有找到key 直接返回即可
        flag = false;
        outfile << "未找到节点值为" << key << "的节点" << endl;
        return ;
    }

    if (bst[id] > key) delete_node(2 * id + 1, key, flag);
    // key 小于当前节点值时 说明它在左子树上
    else if (bst[id] < key) delete_node(2 * id + 2, key, flag);
    // key 大于当前节点值时 说明它在右子树上
    else {  // 否则 当前节点就是我们要删除的那个节点
        // 当左子树不为空 右子树为空时 直接将左子树接上去即可
        if (bst[2 * id + 1] != inf && bst[2 * id + 2] == inf) { 
            remove(id, 2 * id + 1);
        }
        // 当左子树为空 右子树不为空时 直接将右子树接上去
        else if (bst[2 * id + 1] == inf && bst[2 * id + 2] != inf) {
            remove(id, 2 * id + 2);
        }
        // 当左右子树均为空时
        else if (bst[2 * id + 1] == inf && bst[2 *id + 2] == inf) bst[id] = inf;
        else {
            int cur = 2 * id + 1;
            while (bst[2 * cur + 2] != inf) { // 寻找左子树的最右侧节点
                cur = 2 * cur + 2;
            }
            bst[id] = bst[cur];
            bst[cur] = inf;
        }
        // 当左右子树均不为空时 将左子树最大 或 右子树最小与其互换
    }
}

// 按照存储了待删除结点的数组 对树进行删除节点
void Delete(int id, const vector<int>& de_vals) {
    for (int i = 0; i < de_vals.size(); ++i) {
        bool flag = true;
        delete_node(id, de_vals[i], flag);
        if (flag) {
            outfile << "删除" << de_vals[i] << "后,中序遍历结果:" << endl;
            inorder(id);
            outfile << endl;
        }
    }
}

// 计算最大公因数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

/*
计算查找成功的平均查找长度 = (层数 * 节点数)之和 / 节点总数
用层序遍历进行计算
*/ 
void acc_len(int id) {
    vector<int> num;
    queue<int> que;
    if (bst[id] != inf) 
        que.push(id); // 存下标

    while (!que.empty()) {
        int size = que.size();
        num.push_back(size);
        for (int i = 0; i < size; ++i) {
            int tmp = que.front();
            que.pop();

            if (bst[2 * tmp + 1] != inf)
                que.push(2 * tmp + 1);
            if (bst[2 * tmp + 2] != inf)
                que.push(2 * tmp + 2);
        }
    }

    int sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < num.size(); ++i) {
        sum_1 += (i + 1) * num[i];
        sum_2 += num[i];
    }
    cout << sum_1 << " " << sum_2 << endl;
    int tmp = gcd(sum_1, sum_2);
    outfile << "查找成功的平均查找长度为 " << sum_1 / tmp << "/" << sum_2 / tmp << endl << endl;
}

int vec_left[100] = {0};

// 显示二叉树的函数，只要调用Display(root, 0)即可
void Display(int id, int ident)
{
    if(ident > 0)
    {
        for(int i = 0; i < ident - 1; ++i)
        {
            outfile << (vec_left[i] ? "|   " : "   ");
        }
        outfile << (vec_left[ident-1] ? "├── " : "└── ");
    }

    if(bst[id] == inf)
    {
        outfile << "(null)" << endl;
        return;
    }

    outfile << bst[id] << endl;
    if(bst[2 * id + 1] == inf && bst[2 * id + 2] == inf)
    {
        return;
    }

    vec_left[ident] = 1;
    Display(2 * id + 1, ident + 1);
    vec_left[ident] = 0;
    Display(2 * id + 2, ident + 1);
}


int main() {
    string outname = "./bst_out_2.txt";
    outfile.open(outname, ios::out | ios::trunc);
    if (!outfile) 
        cout << "open failed!" << endl;

    vector<int> vals, de_vals;
    input(vals, "./bst_in.txt");
    input(de_vals, "./bst_de.txt");

    create_bst(0, vals);

    outfile << "中序遍历序列如下：" << endl;
    inorder(0);
    outfile << endl << endl;

    outfile << "树形如下：" << endl;
	Display(0, 0);
    outfile << endl << endl;

    acc_len(0);
    Delete(0, de_vals);

	system("pause");
	return 0;
}