# include <iostream>
# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

void print(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void insert_sort(vector<int> nums) { // 插入排序
    cout << "insert_sort:" << endl;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        print(nums);
        for (int j = i; j > 0; --j) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
            }
            else break;
        }
    }
    print(nums);
}

void bubble_sort(vector<int> nums) { // 冒泡排序
    cout << "bubble_sort:" << endl;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        print(nums);
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    print(nums);
}

void select_sort(vector<int> nums) { // 选择排序
    cout << "select_sort:" << endl;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        print(nums);
        int id = i;
        for (int j = i; j < n; ++j) {
            id = nums[j] < nums[id] ? j : id;
        }
        swap(nums[id], nums[i]);
    }
    print(nums);
}

void gap_print(vector<int> nums, int gap) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
        if ((i + 1) % gap == 0) 
            cout << endl;
    }
    cout << endl;
}

void shell_sort(vector<int> nums) { // 希尔排序
    cout << "shell_sort:" << endl;
    print(nums);
    int n = nums.size();
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            for (int j = i; j >= gap; j -= gap) {
                if (nums[j] < nums[j - gap]) {
                    swap(nums[j], nums[j - gap]);
                }
                else break;
            }
        }
        cout << "gap = " << gap << endl;
        gap_print(nums, gap);
    }    
}

int partition(int l, int r, vector<int>& nums) {
    int pivot = nums[l];
    while (l < r && pivot < nums[r]) --r;
    nums[l] = nums[r];
    while (l < r && nums[l] < pivot) ++l;
    nums[r] = nums[l];
}

void quick_sort(vector<int> nums) { // 快速排序

}

int main() {
    vector<int> nums{55, 77, 33, 88, 22, 99, 11, 66, 44};
    insert_sort(nums);
    bubble_sort(nums);
    select_sort(nums);
    shell_sort(nums);

    system("pause");
    return 0;
}