---
title: 容器适配器--优先队列(堆)
date: 2022-09-18
categories:
- 数据结构与算法
tags:
- 容器适配器
- 数据结构
---



#### 1. priority_queue

```cpp
template<
    class T,
    class Container = std::vector<T>, // 底层容器是vector或者deque
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

<!-- more -->优先队列，也可以叫做堆；默认的优先队列为大根堆，使用less进行比较，每次取出的都是最大的元素；

堆是一棵二叉树，对于大根堆来说，根节点是最大的，对于小根堆来说，根节点是最小的

底层容器需要满足的条件

```cpp
front();
push_back();
pop_back();
```

支持的操作

```cpp
priority_queue<int> pri;
int x;
pri.push(x);
pri.pop();
pri.top();
pri.size();
pri.empty();
pri.emplace(x);
pri.swap(pri_other);
```

示例：使用数组实现堆

​	前置知识: 

​		Q:如何通过下标来找到某一节点的子节点或父节点?

​		A:根节点是heap[0]，它的左孩子是heap[1], 右孩子是heap[2]; 依次类推

​		    某一个节点 i 的左孩子是2 * i + 1, 右孩子是2 * i + 2, 其父节点是 (i - 1) / 2；

​		Q:如何完成push和pop操作?

​		A:以大根堆为例，如果要push一个元素，我们需要将它放在最后一处，并和父节点进行比较 直到 该元素小于父节点或者成为根节点

​			如果要pop堆顶，我们需要将堆顶元素删除，然后将最后一个元素放至堆顶，将其和最大的孩子比较 直到 它比两个孩子都大或者没有孩子时

```cpp
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
```