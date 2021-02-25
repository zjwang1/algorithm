#include <random>
#include <algorithm>
#include <iostream>

#include "random_vec.hpp"


struct INode
{
    INode() = default;
    virtual ~INode() = default;
    virtual void init(int v) = 0;
};

struct Node
{
    Node(int v): v_(v), next_(nullptr) {}
    int v_;
    Node *next_;

    void print() {
        Node *cur = this;
        while (cur != nullptr) {
            std::cout << cur->v_ << " ";
            cur = cur->next_;
        }
        std::cout << "\n";
    }
};

struct DoubleNode
{
    DoubleNode(int v): v_(v), next_(nullptr), prev_(nullptr) {}
    int v_;
    DoubleNode *next_;
    DoubleNode *prev_;


};

template<typename T = Node, bool IS_SORTED = false, size_t LIST_SIZE = 8, size_t L = 1, size_t R = 100>
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
        root_->print();
    }
    ~List() {
        while(root_ != nullptr) {
            Node *tmp = root_;
            root_ = root_->next_;
            delete tmp;
        }
    }
private:
    T *root_;

    void getListFromVec(const std::vector<int> &v) {
        if (v.size() == 0) {
            root_ = nullptr;
        }
        root_ = new T(v[0]);
        T *tmp = root_;
        for (int i = 1; i <= v.size() - 1; ++i) {
            T *n = new T(v[i]);
            tmp -> next_ = n;
            tmp = n;
        }
    }
};