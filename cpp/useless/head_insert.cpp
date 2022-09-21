# include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(nullptr) { } ; 
};

void head_insert(ListNode*& head, int val) {
    ListNode* tmp = new ListNode(val);
    tmp->next = head;
    head = tmp;
}

void print(ListNode* node) {
    ListNode* tmp = node;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    // head->val = 1;

    for (int i = 0; i < 10; ++i) {
        head_insert(head, i);
    }
    print(head);

    system("pause");
    return 0;
}