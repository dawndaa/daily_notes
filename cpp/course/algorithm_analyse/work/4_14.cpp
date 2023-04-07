# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <unistd.h>
# include <algorithm>
# include <queue>
using namespace std;

/*
最大花费是 每次取出最大的两堆合并
最小花费是 每次取出最小的k堆合并
*/

int main() {
    string path = get_current_dir_name();
    string inName = "/cpp/course/algorithm_analyse/4_14_input.txt";
    string outName = "/cpp/course/algorithm_analyse/4_14_ouput.txt";

    ifstream in;
    ofstream out;
    in.open(path + inName, ios::in);
    out.open(path + outName, ios::out);

    while (!in.eof()) {
        int n, k;
        in >> n >> k;
        // priority_queue默认比较函数为less 是大顶堆
        // 可以自定义为greater 小顶堆
        priority_queue<int, vector<int>, greater<int>> pri_min;
        priority_queue<int> pri_max;
        for (int i = 0; i < n; ++i) {
            int tmp;
            in >> tmp;
            pri_min.push(tmp);
            pri_max.push(tmp);
        }
        
        int max_sum = 0, min_sum = 0;
        while (pri_max.size() > 1) {
            int sum = 0;
            
            for (int i = 0; i < 2; ++i) {
                sum += pri_max.top();
                pri_max.pop();
            }
            pri_max.push(sum);

            max_sum += sum;
        }
        while (pri_min.size() > 1) {
            int sum = 0;
            for (int i = 0; i < k; ++i) {
                if (!pri_min.empty()) {
                    sum += pri_min.top();
                    pri_min.pop();
                }
            }
            pri_min.push(sum);

            min_sum += sum;
        }

        out << max_sum << " " << min_sum << endl;
    }

    return 0;
}