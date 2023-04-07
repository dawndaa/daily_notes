# include <iostream>
# include <fstream>
# include <string>
# include <cmath>
# include <vector>
# include <algorithm>
# include <unistd.h>
using namespace std;

/*
第一行为 n d
接下来有n行 
    每行第一个数字是 该节点相连的节点数 为0代表是叶子结点
    后面每两个数字为一组 其中第一个是节点编号 第二个是边权
*/

class dTree {
public:
    dTree(int n, int d) {
        
    }
};

int main() {
    int n, d;
    string path = get_current_dir_name();
    ifstream in(path + "/lab3.in", ios::in);

    in >> n >> d;

    return 0;
}