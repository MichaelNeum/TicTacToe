#include <iostream>
#include <algorithm>
#include <array>

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

        bool checkField(int x, int y);
        stringCode hashit(std::string const& input);
    public:
        void handleUserInput(std::string input);
        UserInput(std::array<std::array<int,3>,3>* field): _field(field) {}
};

bool UserInput::checkField(int x, int y) {
    if((*_field)[x][y] != 0) {
        std::cout << "Field already placed. Try another one!" << std::endl;
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

void UserInput::handleUserInput(std::string input) {
    if(input.length() > 1) {
        std::cout << "Invalid input. Try agian!" << std::endl;
        return;
    }
    switch(hashit(input)){
        case eQ:
            if(checkField(0,0)) return;
            (*_field)[0][0] = 1;
            break;
        case eW:
            if(checkField(0,1)) return;
            (*_field)[0][1] = 1;
            break;
        case eE:
            if(checkField(0,2)) return;
            (*_field)[0][2] = 1;
            break;
        case eA:
            if(checkField(1,0)) return;
            (*_field)[1][0] = 1;
            break;
        case eS:
            if(checkField(1,1)) return;
            (*_field)[1][1] = 1;
            break;
        case eD:
            if(checkField(1,2)) return;
            (*_field)[1][2] = 1;
            break;
        case eY:
            if(checkField(2,0)) return;
            (*_field)[2][0] = 1;
            break;
        case eX:
            if(checkField(2,1)) return;
            (*_field)[2][1] = 1;
            break;
        case eC:
            if(checkField(2,2)) return;
            (*_field)[2][2] = 1;
            break;
        default:
            break;
    }
}