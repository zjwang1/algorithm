// 删除单链表倒数第k个节点
#include "utils/list.hpp"

Node *deleteKNode(Node *head, int k) {
    Node *tmp = head;
    while(tmp != nullptr) {
        --k;
        tmp = tmp->next_;
    }
    if (k > 0) {
        return head;
    } else if (k == 0) {
        head = head->next_;
    } else {
        tmp = head;
        while(++k != 0) {
            tmp = tmp->next_;
        }
        Node * x = tmp->next_;
        tmp->next_ = tmp->next_->next_;
        delete x;
    }
    return head;
}

int main() {
    List<> list({1, 2, 3, 4});

    std::cout << list.getListHead() << " " << list.getListHead()->next_ << "\n";
    deleteKNode(list.getListHead(), 5)->print();
    
}

