# ifndef LIST_H
# define LIST_H
# include <iostream>

class list_node {
public:
    int val;
    list_node* next;

    list_node(int v): val(v), next(nullptr) { } // 构造函数
    void print() { // 打印链表
        list_node* tmp = this;
        while (tmp) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }
};

# endif