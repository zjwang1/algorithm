// 删除单链表a/b处的节点.
#include <iostream>

#include "utils/list.hpp"

Node *removeMidNode(Node *head) {
    if (head == nullptr || head->next_ == nullptr) {
        return head;
    }
    if (head->next_->next_ == nullptr) {
        return head->next_;
    }
    Node *pre = head;
    Node *cur = head->next_->next_;
    while(cur->next_ != nullptr && cur->next_->next_ != nullptr) {
        pre = pre->next_;
        cur = cur->next_->next_;
    }
    Node *x = pre->next_;
    pre->next_ = pre->next_->next_;
    delete x;
    return head;
}

int main() {
    List<> list({1, 2, 3, 4, 5});
    removeMidNode(list.getListHead())->print();
    return 0;
}