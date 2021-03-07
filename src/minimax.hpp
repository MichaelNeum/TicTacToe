#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include <vector>

class Cells
{
    public:
        int x;
        int y;
        Cells(int X, int Y): x(X), y(Y) {}
};

class Minimax
{
    private:
        bool checkWin(std::tuple<int, int> lastTick, std::array<std::array<int,3>,3> field);
        int row(std::tuple<int,int> lastTick);
        int column(std::tuple<int,int> lastTick);
        std::vector<Cells> emptyCells(std::array<std::array<int,3>,3> state);
        int place(int player);
    public:
        int depth(std::array<std::array<int,3>,3> state);
        std::array<int,3> minimax(std::array<std::array<int,3>,3> state, int depth, int player, std::tuple<int,int> lastPlay);

};

int Minimax::depth(std::array<std::array<int,3>,3> state) {
    int result = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(state[i][j] == 0) result++;
        }
    }
    return result;
}

std::array<int,3> Minimax::minimax(std::array<std::array<int,3>,3> state, int depth, int player, std::tuple<int,int> lastPlay) {
    std::array<int,3> best;
    if(player == 1) best = {-1, -1, -10000};
    else best = {-1, -1, 10000};

    if(depth == 0 || checkWin(lastPlay, state)) {
        std::array<int,3> result = {-1, -1, checkWin(lastPlay, state) * (-1)*player};
        return result;
    }
    //std::cout << "Player: " << player << std::endl;
    std::vector<Cells> empty = emptyCells(state);
    for(int i = 0; i < empty.size(); i++) {
        int x = empty[i].x;
        int y = empty[i].y;
        state[x][y] = place(player);
        lastPlay = {x,y};
        std::array<int, 3> score = minimax(state, depth - 1, (-1)*player, lastPlay);
        state[x][y] = 0;
        score[0] = x;
        score[1] = y;
        //std::cout << "Score: " << x << y << score[2] << std::endl;
        if(player == 1) {
            if(score[2] > best[2]) best = score;
        }
        else {
            if(score[2] < best[2]) best = score;
        }
    }
    return best;
}

bool Minimax::checkWin(std::tuple<int, int> lastTick, std::array<std::array<int,3>,3> field) {
    if(row(lastTick) == -1) return false;
    bool result = false;
    for(int i = 0; i < 2; i++) {
        if(field[row(lastTick)][i] != field[row(lastTick)][i+1]) {
            result = false;
            break;
        }
        result = true;
    }
    if(result) return result;
    for(int i = 0; i < 2; i++) {
        if(field[i][column(lastTick)] != field[i+1][column(lastTick)]) {
            result = false;
            break;
        }
        result = true;
    }
    if(result) return result;
    for(int i = 0; i < 2; i++) {
        if(field[i][i] != field[i+1][i+1] || field[1][1] == 0) {
            result = false;
            break;
        }
        result = true;
    }
    if(result) return result;
    for(int i = 0; i < 2; i++) {
        if(field[i][2-i] != field[i+1][2-i-1] || field[1][1] == 0) {
            result = false;
            break;
        }
        result = true;
    }
    return result;
}

int Minimax::row(std::tuple<int,int> lastTick) {
    return std::get<0>(lastTick);
}

int Minimax::column(std::tuple<int,int> lastTick) {
    return std::get<1>(lastTick);
}

std::vector<Cells> Minimax::emptyCells(std::array<std::array<int,3>,3> state) {
    std::vector<Cells> result;
    int count = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(state[i][j] == 0) {
                count++;
                result.push_back(Cells(i,j));
            }
        }
    }
    return result;
}

int Minimax::place(int player) {
    if(player == 1) return 2;
    else return 1;
}