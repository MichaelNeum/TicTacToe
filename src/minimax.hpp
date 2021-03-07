#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>

class Minimax
{
    private:
        std::array<std::array<int,3>,3>* _field;
    public:
        Minimax(std::array<std::array<int,3>,3>* field): _field(field) {}
        int depth();

};

int Minimax::depth() {
    return 0;
}