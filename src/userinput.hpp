#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>

class UserInput
{
    private:
        std::array<std::array<int,3>,3>* _field;
        enum stringCode {
            eQ, eW, eE,
            eA, eS, eD,
            eY, eX, eC,
            eError
        };
        int* _count;
        bool checkField(int x, int y);
        stringCode hashit(std::string const& input);
    public:
        std::tuple<int, int> handleUserInput(std::string input, int player);
        UserInput(std::array<std::array<int,3>,3>* field, int* count): _field(field), _count(count) {}
};

bool UserInput::checkField(int x, int y) {
    if((*_field)[x][y] != 0) {
        std::cout << "Field already placed. Try another one!" << std::endl;
        (*_count)--;
        return true;
    }
    return false;
}

UserInput::stringCode UserInput::hashit(std::string const& input) {
    if(input == "q") return eQ;
    else if(input == "w") return eW;
    else if(input == "e") return eE;
    else if(input == "a") return eA;
    else if(input == "s") return eS;
    else if(input == "d") return eD;
    else if(input == "y") return eY;
    else if(input == "x") return eX;
    else if(input == "c") return eC;
    else return eError;
}

std::tuple<int, int> UserInput::handleUserInput(std::string input, int player) {
    std::tuple<int, int> result = {-1, -1};
    if(input.length() > 1) {
        std::cout << "Invalid input. Try again!" << std::endl;
        (*_count)--;
        return result;
    }
    switch(hashit(input)){
        case eQ:
            if(checkField(0,0)) break;
            (*_field)[0][0] = player;
            result = {0,0};
            break;
        case eW:
            if(checkField(0,1)) break;
            (*_field)[0][1] = player;
            result = {0,1};
            break;
        case eE:
            if(checkField(0,2)) break;
            (*_field)[0][2] = player;
            result = {0,2};
            break;
        case eA:
            if(checkField(1,0)) break;
            (*_field)[1][0] = player;
            result = {1,0};
            break;
        case eS:
            if(checkField(1,1)) break;
            (*_field)[1][1] = player;
            result = {1,1};
            break;
        case eD:
            if(checkField(1,2)) break;
            (*_field)[1][2] = player;
            result = {1,2};
            break;
        case eY:
            if(checkField(2,0)) break;
            (*_field)[2][0] = player;
            result = {2,0};
            break;
        case eX:
            if(checkField(2,1)) break;
            (*_field)[2][1] = player;
            result = {2,1};
            break;
        case eC:
            if(checkField(2,2)) break;
            (*_field)[2][2] = player;
            result = {2,2};
            break;
        default:
            (*_count)--;
            break;
    }
    return result;
}