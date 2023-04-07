# include <bits/stdc++.h>
using namespace std;

/*
实现一个大根堆
*/

const int maxn = 10000;
int heap[maxn], size = 0;

void push(int x) {
    int i = size++; // heap[i]是最后一个元素

    while (i > 0) {
        int p = (i - 1) / 2; // 父节点的index
        if (heap[p] >= x) break; // 当父节点的值大于等于x时 停止

        heap[i] = heap[p]; // 将小于x的父节点拉下来
        i = p; // i到父节点上
    }

    heap[i] = x;  // 更新
}

int pop() {
    int ret = heap[0];  // 获取最大值
    int x = heap[--size]; // 获取最后一个元素

    int i = 0;
    while (2 * i + 1 < size) {
        int a = 2 * i + 1, b = 2 * i + 2; // a b 分别为左孩子 右孩子 
        if (b < size && heap[b] > heap[a]) a = b; // 默认选择更大的孩子进行比较

        if (heap[a] <= x) break;  // 当x比两个孩子都大时 停止

        heap[i] = heap[a]; // 把节点a提上来
        i = a; // 移动到a处
    }

    heap[i] = x;  // 更新
    return ret;
}

int top() {
    return heap[0];
}

int main() {
    for (int i = 0; i < 100; ++i) push(i);
    for (int i = 0; i < 100; ++i) {
        cout << top() << " ";
        pop();
    }

    system("pause");
    return 0;
}