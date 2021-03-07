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
    int result = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if((*_field)[i][j] == 0) result++;
        }
    }
    return result;
}