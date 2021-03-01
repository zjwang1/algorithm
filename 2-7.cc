// 判断一个链表是否是回文结构
#include <stack>

#include "utils/list.hpp"

// 带上O(N / 2)的空间复杂度
bool checkSingleListIsPalindrome(Node *head) {
    if (head == nullptr || head->next_ == nullptr) {
        return true;
    } 
    // 找到链表的中点
    Node *mid = head->next_;
    Node *cur = head;
    while (cur->next_ != nullptr && cur->next_->next_ != nullptr) {
        mid = cur->next_;
        cur = cur->next_->next_;
    }
    std::stack<Node *> stack;
    while(mid != nullptr) {
        stack.push(mid);
        mid = mid->next_;
    }
    cur = head;
    while(!stack.empty()) {
        if (cur->v_ != stack.top()->v_) {
            return false;
        }
        stack.pop();
        cur = cur->next_;
    }
    return true;
}

// 不带上那么重的空间复杂度
bool checkSingleListIsPalindromeWithoutStack(Node *head) {
    if (head == nullptr || head->next_ == nullptr) {
        return true;
    } 
    // 找到链表的中点
    Node *mid = head->next_;
    Node *cur = head;
    while(cur->next_ != nullptr && cur->next_->next_ != nullptr) {
        mid = cur->next_;
        cur = cur->next_->next_;
    }
    // 反转后半部分
    cur = mid ->next_;
    
    Node *next = nullptr;
    Node *pre = nullptr;
    while (cur != nullptr) {
        next = cur->next_;
        cur->next_ = pre;
        pre = cur;
        cur = next;
    }
   
    mid->next_ = pre;
    // 两根指针同时走
    cur = pre;
    Node *cur2 = head;
    while(cur != nullptr) {
        if (cur2->v_ != cur->v_) {
            return false;
        }
        cur = cur->next_;
        cur2 = cur2->next_;
    }
    return true;
}

int main() {
    List<> list({1, 2, 2, 1});
    List<> list2({1, 2, 2, 1});
    std::cout << checkSingleListIsPalindrome(list.getListHead()) << std::endl;
    std::cout << checkSingleListIsPalindromeWithoutStack(list2.getListHead()) << std::endl;
    return 0;
}