#include <random>
#include <algorithm>
#include <iostream>

struct Node
{
    Node(int v): v_(v), next_(nullptr) {}
    int v_;
    Node *next_;
};

template<bool IS_SORTED = false, size_t LIST_SIZE = 1024, size_t L = 1, size_t R = 100>
class RandomList
{
public:
    RandomList()
    {
        static_assert(LIST_SIZE >= 1, "List size must be >= 1");
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(L, R);
        std::vector<int> v;
        for (int i = 0; i < LIST_SIZE; ++i) {
            v.emplace_back(distrib(gen));
        }
        if (IS_SORTED) {
            std::sort(v.begin(), v.end());
        }
        root_ = new Node(v[0]);
        Node *tmp = root_;
        for (int i = 1; i < LIST_SIZE - 1; ++i) {
            Node *n = new Node(v[i]);
            tmp -> next_ = n;
            tmp = n;
        }
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
    ~RandomList() {
        while(root_ != nullptr) {
            Node *tmp = root_;
            root_ = root_->next_;
            delete tmp;
        }
    }
private:
    Node *root_;
};