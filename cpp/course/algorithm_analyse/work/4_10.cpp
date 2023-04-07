# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include <algorithm>
# include <unistd.h>
using namespace std;

/*
每次都以最小的数字为区间的左端点，跳过那些被覆盖的点
*/

int main() {
    string path = get_current_dir_name();
    string inName = "/cpp/course/algorithm_analyse/4_10_input.txt";
    string outName = "/cpp/course/algorithm_analyse/4_10_ouput.txt";

    ifstream in;
    ofstream out;
    in.open(path + inName, ios::in);
    out.open(path + outName, ios::out);

    while (!in.eof()) {
        int n, k;
        in >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            in >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int cnt = 1;
        int begin = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] <= begin + k) continue;
            else {
                begin = arr[i];
                ++cnt;
            }
        }

        out << cnt << endl;
    }



    return 0;
}