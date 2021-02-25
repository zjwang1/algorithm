#include <random>
#include <vector>
#include <iostream>

template<bool IS_SORTED = false, size_t VEC_SIZE = 1024, size_t L = 1, size_t R = 100>
class RandomVector
{
public:
    RandomVector()
    {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(L, R);
        for (int i = 0; i < VEC_SIZE; ++i) {
            v_.emplace_back(distrib(gen));
        }
        if (IS_SORTED) {
            std::sort(v_.begin(), v_.end());
        }
    }
    std::vector<int> getVec() {
        return v_;
    }
    ~RandomVector() {}
private:
    std::vector<int> v_; 
};