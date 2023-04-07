# include <iostream>
# include <queue>
# include <fstream>
using namespace std;

class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int v): val(v), left(nullptr), right(nullptr) { };
};

int vec_left[100] = {0};

// 显示二叉树的函数，只要调用Display(root, 0)即可
void Display(TreeNode* root, int ident, ofstream& outfile)
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
    Display(root->left, ident + 1, outfile);
    vec_left[ident] = 0;
    Display(root->right, ident + 1, outfile);
}


int main() {
	TreeNode* root = new TreeNode(0), *cur = root;
	for (int i = 0; i < 5; ++i) {
		TreeNode* tmp = new TreeNode(i + 1);
		cur->left = tmp;
		cur = cur->left;
	}
	ofstream outfile;
    string outname = "./tree.txt";
    outfile.open(outname, ios::out | ios::trunc);
    if (!outfile) 
        cout << "open failed!" << endl;

	Display(root, 0, outfile);


	system("pause");
	return 0;
}