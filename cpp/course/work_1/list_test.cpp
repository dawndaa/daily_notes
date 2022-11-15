# include "list.h"
# include <utility>
using namespace std;

list_node* reverse(list_node* head) { // 反转链表
    list_node* pre = nullptr, *cur = head, *tmp = nullptr;

    while (cur) {
        tmp = cur;
        cur = cur->next;
        tmp->next = pre;
        pre = tmp;
    }

    return pre;
}
// 下标从0开始

int delete_at_index(list_node* head, int index) { // 删除给定下标处节点
    list_node* cur = head;

    --index;
    while (index && cur) { // 到达index - 1
        cur = cur->next;
        --index;
    }

    if (cur && cur->next) {
        cur->next = cur->next->next;
        return 1;
    }
    else return 0;
    // 返回1 说明删除成功 返回0 说明删除失败
}

// 返回给定下标前后节点
pair<list_node*, list_node*> get_near(list_node* head, int index) { 
    list_node* cur = head;

    --index;
    while (index && cur) {
        cur = cur->next;
        --index;
    }

    if (cur && cur->next) { 
        return make_pair(cur, cur->next->next);
    }
    else if (cur) {
        return make_pair(cur, nullptr);
    }
    else return make_pair(nullptr, nullptr);
}

int main() {
    list_node* head = new list_node(0), *cur = head;

    for (int i = 1; i < 20; ++i) {
        list_node* tmp = new list_node(i);
        cur->next = tmp;
        cur = cur->next;
    }
    head->print();
    cout << endl;

    head = reverse(head);
    head->print();
    cout << endl;

    head = reverse(head);
    auto p = get_near(head, 5);
    cout << p.first->val << " " << p.second->val << endl;

    delete_at_index(head, 5);
    head->print();
    cout << endl;

    system("pause");
    return 0;
}