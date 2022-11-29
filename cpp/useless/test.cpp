# include <iostream>
# include <queue>
using namespace std;

class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int v): val(v), left(nullptr), right(nullptr) { };
};

int main() {
	TreeNode* root = new TreeNode(0), *cur = root;
	for (int i = 0; i < 100; ++i) {
		TreeNode* tmp = new TreeNode(i + 1);
		cur->left = tmp;
		cur = cur->left;
	}

	while (root) {
		cout << root->val << endl;
		root = root->left;
	}

	system("pause");
	return 0;
}