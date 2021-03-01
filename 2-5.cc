// 反转部分单向链表
#include "utils/list.hpp"

Node *reversePartSingleList(Node *head, int from, int to) {
    Node *cur = head;
    Node *from_pre = nullptr, *from_ = nullptr, *to_ = nullptr;
    int step = 0;
    while (cur != nullptr) {
        ++step;
        if (step == from - 1) {
            from_pre = cur;
        }
        if (step == from) {
            from_ = cur;
        }
        if (step == to) {
            to_ = cur;
        }
        cur = cur->next_;
    }
    if (from_ == nullptr || to_ == nullptr) {
        return head;
    }
    Node *pre = nullptr;
    Node *next = nullptr;
    cur = from_;
    std::cout << to_->next_ << std::endl;
    Node *x = to_->next_;
    while (cur != x) {
        next = cur->next_;
        cur->next_ = pre;
        pre = cur;
        cur = next;
    }
    if (from_pre != nullptr) {
        from_pre->next_ = pre;
    } else {
        head = pre;
    }
    from_->next_ = x;
    return head;
}

int main() {
    List<> list({1, 2, 3, 4, 5});

    reversePartSingleList(list.getListHead(), 2, 3)->print();
    return 0;
}