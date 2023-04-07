# include <iostream>
# include <fstream>
# include <string>
# include <cmath>
# include <vector>
# include <algorithm>
# include <unistd.h>
using namespace std;

void WeightMedian(int length, vector<int> num, vector<double> weight, int index) {
    if (length == 0) return ;
    if (length == 1) cout << num[0];
    else if (length == 2) {
        if (weight[0] >= weight[1]) cout << num[0];
        else cout << num[1];
    }
    else {
        int mid = random() % length;

        double l_sum = 0, r_sum = 0;
        for (int i = 0; i < length; ++i) {
            if (num[i] < num[mid]) l_sum += weight[i];
            else if (num[i] > num[mid]) r_sum += weight[i];
        }
        if (l_sum <= 0.5 && r_sum <= 0.5) {
            cout << num[mid];
            return ;
        } 
        else if (l_sum > 0.5) {
            weight[mid] += r_sum;
            vector<int> sub_num;
            vector<double> sub_weight;
            for (int i = 0; i < length; ++i) {
                if (num[i] <= num[mid]) {
                    sub_num.push_back(num[i]);
                    sub_weight.push_back(weight[i]);
                } 
            }
            WeightMedian(sub_num.size(), sub_num, sub_weight, 0);
        }
        else {
            weight[mid] += l_sum;
            vector<int> sub_num;
            vector<double> sub_weight;
            for (int i = 0; i < length; ++i) {
                if (num[i] >= num[mid]){
                    sub_num.push_back(num[i]);
                    sub_weight.push_back(weight[i]);
                }
            }
            WeightMedian(sub_num.size(), sub_num, sub_weight, 0);
        }
    } 
    
}
/*

void data_sort(vector<int> num, vector<double> weight) {
    int size = num.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (num[i] > num[j]) {
                swap(num[i], num[j]);
                swap(weight[i], weight[j]);
            }
        }
    }
    
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += weight[i];
        cout << endl << num[i] << ": " << weight[i] << "  " << sum;
    }
}

*/
int main() {
    ifstream in;
    string path = get_current_dir_name();
    in.open(path + "/lab1.in", ios::in);
    int len = 0;
    in >> len;
    vector<int> num(len);
    vector<double> weight(len);
    for (int i = 0; i < len; ++i) {
        in >> num[i];
    }
    for (int i = 0; i < len; ++i) {
        in >> weight[i];
    }

    int index = 0;
    WeightMedian(len, num, weight, index);

    return 0;
} 