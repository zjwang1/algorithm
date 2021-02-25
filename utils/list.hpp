#include <random>
#include <algorithm>
#include <iostream>

#include "random_vec.hpp"

struct Node
{
    Node(int v): v_(v), next_(nullptr) {}
    int v_;
    Node *next_;
};

template<bool IS_SORTED = false, size_t LIST_SIZE = 1024, size_t L = 1, size_t R = 100>
class List
{
public:
    List()
    {
        static_assert(LIST_SIZE >= 1, "List size must be >= 1");
        RandomVector<IS_SORTED, LIST_SIZE, L, R> vec;
        auto v = vec.getVec();
        getListFromVec(v);
    }

    List(const std::vector<int> &v) {
        getListFromVec(v);
    }
    
    Node *getListHead() {
        return root_;
    }
    void print() {
        Node *tmp = root_;
        while(tmp != nullptr) {
            std::cout << tmp->v_ << " ";
            tmp = tmp->next_;
        }
        std::cout << "\n";
    }
    ~List() {
        while(root_ != nullptr) {
            Node *tmp = root_;
            root_ = root_->next_;
            delete tmp;
        }
    }
private:
    Node *root_;

    void getListFromVec(const std::vector<int> &v) {
        if (v.size() == 0) {
            root_ = nullptr;
        }
        root_ = new Node(v[0]);
        Node *tmp = root_;
        for (int i = 1; i <= v.size() - 1; ++i) {
            Node *n = new Node(v[i]);
            tmp -> next_ = n;
            tmp = n;
        }
    }
};