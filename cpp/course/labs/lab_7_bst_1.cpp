# include <iostream>
# include <queue>
# include <fstream>
using namespace std;

ofstream outfile;
class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int v): val(v), left(nullptr), right(nullptr) { };
};

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
void inorder(TreeNode* root) {
    if (!root) return ;

    inorder(root->left);
    outfile << root->val << " ";
    inorder(root->right);
}

void insert(TreeNode*&, int);
// 建树
void create_bst(TreeNode*& root, const vector<int>& vals) {
    for (int i = 0; i < vals.size(); ++i) {
        insert(root, vals[i]);
    }
}

// 二叉查找树 插入节点
void insert(TreeNode*& root, int k) {
    if (!root) {
        root = new TreeNode(k);
        return ;
    }
    
    if (k == root->val) return ;
    else if (k < root->val) 
        insert(root->left, k);
    else 
        insert(root->right, k);
}

// 二叉查找树 删除节点
TreeNode* delete_node(TreeNode* cur, int key, bool& flag) {
    if (!cur) { // 当遇到空节点时 说明没有找到key 直接返回即可
        flag = false;
        outfile << "未找到节点值为" << key << "的节点" << endl;
        return nullptr;
    }

    if (cur->val > key) cur->left = delete_node(cur->left, key, flag);
    // key 小于当前节点值时 说明它在左子树上
    else if (cur->val < key) cur->right = delete_node(cur->right, key, flag);
    // key 大于当前节点值时 说明它在右子树上
    else {  // 否则 就cur 就是我们要删除的那个节点
        if (cur->left && !cur->right) cur = cur->left; 
        // 当 cur 左子树不为空 右子树为空时 直接将左子树接上去即可
        else if (!cur->left && cur->right) cur = cur->right;
        // 当左子树为空 右子树不为空时 直接将右子树接上去
        else if (!cur->left && !cur->right) cur = NULL;
        // 当左右子树均为空时 删除cur即可
        else {
            TreeNode* tmp = cur->right;
            while (tmp->left) tmp = tmp->left;
            tmp->left = cur->left;
            cur = cur->right;
        }
        // 当左右子树均不为空时 将左子树 作为右子树的最左侧的节点的左孩子   并令cur = cur->right
        // 原因： 左子树上的值均小于右子树 而 右子树上最左侧的节点的值是右子树上最小的
        // 接上去之后 仍然是满足二叉搜索树的
    }

    return cur;
}

// 按照存储了待删除结点的数组 对树进行删除节点
void Delete(TreeNode* root, const vector<int>& de_vals) {
    for (int i = 0; i < de_vals.size(); ++i) {
        bool flag = true;
        delete_node(root, de_vals[i], flag);
        if (flag) {
            outfile << "删除" << de_vals[i] << "后,中序遍历结果:" << endl;
            inorder(root);
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
void acc_len(TreeNode* root) {
    vector<int> num;
    queue<TreeNode*> que;
    if (root) 
        que.push(root);

    while (!que.empty()) {
        int size = que.size();
        num.push_back(size);
        for (int i = 0; i < size; ++i) {
            TreeNode* tmp = que.front();
            que.pop();

            if (tmp->left)
                que.push(tmp->left);
            if (tmp->right)
                que.push(tmp->right);
        }
    }

    int sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < num.size(); ++i) {
        sum_1 += (i + 1) * num[i];
        sum_2 += num[i];
    }
    int tmp = gcd(sum_1, sum_2);
    outfile << "查找成功的平均查找长度为 " << sum_1 / tmp << "/" << sum_2 / tmp << endl << endl;
}

int vec_left[100] = {0};

void exchange(TreeNode* root) {
    if (!root) return ;

    exchange(root->left);
    exchange(root->right);
    swap(root->left, root->right);
}

// 显示二叉树的函数，只要调用Display(root, 0)即可
void Display(TreeNode* root, int ident)
{
    if(ident > 0)
    {
        for(int i = 0; i < ident - 1; ++i)
        {
            outfile << (vec_left[i] ? "|   " : "   ");
        }
        outfile << (vec_left[ident-1] ? "├── " : "└── ");
    }

    if(!root)
    {
        outfile << "(null)" << endl;
        return;
    }

    outfile << root->val << endl;
    if(!root->left && !root->right)
    {
        return;
    }

    vec_left[ident] = 1;
    Display(root->left, ident + 1);
    vec_left[ident] = 0;
    Display(root->right, ident + 1);
}


int main() {
    string outname = "./bst_out_1.txt";
    outfile.open(outname, ios::out | ios::trunc);
    if (!outfile) 
        cout << "open failed!" << endl;

    vector<int> vals, de_vals;
    input(vals, "./bst_in.txt");
    input(de_vals, "./bst_de.txt");

    TreeNode* root = nullptr;
    create_bst(root, vals);

    outfile << "中序遍历序列如下：" << endl;
    inorder(root);
    outfile << endl << endl;

    outfile << "树形如下：" << endl;
	Display(root, 0);
    outfile << endl << endl;

    acc_len(root);
    Delete(root, de_vals);

	system("pause");
	return 0;
}