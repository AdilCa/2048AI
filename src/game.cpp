//
// Created by caowei on 2024/4/27.
//

#include "game.h"
#include <vector>
#include <cmath>
#include <random>

using namespace std;

Color colorArr;

/*
 * 构造函数: 1. 无参初始化，2. 含参初始化
 */
Game2048::Game2048() {

    // 初始化数值部分
    this->_maxGrid = 4;
    this->_maxPower = 11;
    // 初始化可能值数组
    this->_gridVal.push_back(0);
    for (int i = 1; i < this->_maxPower; ++i) {
        this->_gridVal.push_back(pow(2, i));
    }
    // 初始化每格内的值
    for (int i = 0; i < this->_maxGrid; ++i) {
        this->_map.emplace_back(this->_maxGrid, 0);
    }
    // 两个初始随机位置填入



    // 初始化UI部分
    this->_gridWidth = 100;
    this->_interval = 15;
    for (int row = 0; row < this->_maxGrid; ++row) {
        this->_ltPos.push_back(vector<POINT>(this->_maxGrid, {0, 0}));
        for (int col = 0; col < this->_maxGrid; ++col) {
            this->_ltPos[row][col].x = col*this->_gridWidth + (col+1)*this->_interval;
            this->_ltPos[row][col].y = row*this->_gridWidth + (row+1)*this->_interval;
        }
    }
    initgraph(this->_maxGrid * this->_gridWidth + (this->_maxGrid+1) * this->_interval,
              this->_maxGrid * this->_gridWidth + (this->_maxGrid+1) * this->_interval);
    setbkcolor(back);
    cleardevice();
}

Game2048::Game2048(int maxGrid, int maxPower) {
    // 初始化数值部分
    this->_maxGrid = maxGrid;
    this->_maxPower = maxPower;
    // 初始化可能值数组
    this->_gridVal.push_back(0);
    for (int i = 1; i < this->_maxPower; ++i) {
        this->_gridVal.push_back(pow(2, i));
    }
    // 初始化每格内的值
    for (int i = 0; i < this->_maxGrid; ++i) {
        this->_map.emplace_back(this->_maxGrid, 0);
    }



    // 初始化UI部分
    this->_gridWidth = 100;
    this->_interval = 15;
    for (int row = 0; row < this->_maxGrid; ++row) {
        this->_ltPos.push_back(vector<POINT>(this->_maxGrid, {0, 0}));
        for (int col = 0; col < this->_maxGrid; ++col) {
            this->_ltPos[row][col].x = col*this->_gridWidth + (col+1)*this->_interval;
            this->_ltPos[row][col].y = row*this->_gridWidth + (row+1)*this->_interval;
        }
    }
    initgraph(this->_maxGrid * this->_gridWidth + (this->_maxGrid+1) * this->_interval,
              this->_maxGrid * this->_gridWidth + (this->_maxGrid+1) * this->_interval);
    setbkcolor(back);
    cleardevice();
}


/*
 * 功能函数
 */

// 获取当前空格坐标
vector<POINT> Game2048::EmptyGrid() {
    vector<POINT> emptyPos;
    for (int row = 0; row < this->_maxGrid; ++row) {
        for (int col = 0; col < this->_maxGrid; ++col) {
            if (this->_map[row][col] == 0) {
                emptyPos.push_back({row, col});
            }
        }
    }
    return emptyPos;
}

// 输入空格坐标数组，从空格中选一个空格填入数字
void Game2048::CreateNumber(vector<POINT> emptyPos) {
    mt19937 rng;
    rng.seed(GetTickCount());
    uniform_int_distribution<int> uniDis(0, emptyPos.size());
    int posInd = uniDis(rng);   // 从空格中取一个空格
    this->_map[emptyPos[posInd].x][emptyPos[posInd].y] = 2;
}
// 输入坐标，在当前坐标填入数字
void Game2048::CreateNumber(int row, int col) {
    this->_map[row][col] = 2;
}