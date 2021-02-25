// 反转单向链表.
#include <iostream>

#include "utils/list.hpp"

Node *reverseSingleList(Node *head) {
    Node *pre = nullptr;
    Node *next = nullptr;
    while (head != nullptr) {
        next = head->next_;
        head->next_ = pre;
        pre = head;
        head = next;
    }
    return pre;
}

int main() {
    List<> list({1, 2, 3, 4, 5});

    reverseSingleList(list.getListHead())->print();
    return 0;
}
