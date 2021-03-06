// 打印两个有序链表的公共部分.

#include <iostream>

#include "utils/random_list.hpp"

void print(Node *list1, Node *list2) {
    while(list1 != nullptr && list2 != nullptr) {
        
        if (list1->v_ == list2->v_) {
            std::cout << list1->v_ << "\n";
            list1 = list1->next_;
            list2 = list2->next_;
        } else if (list1->v_ > list2->v_) {
            list2 = list2->next_;
        } else {
            list1 = list1->next_;
        }
    }
}

int main() {
    // 初始化一个排序，个数为10, 随机值范围为[1, 10]的单链表
    RandomList<true, 10, 1, 10> list1;
    list1.print();
    RandomList<true, 20, 1, 20> list2;
    list2.print();
    print(list1.getListHead(), list2.getListHead());
    return 0;
}

