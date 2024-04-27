//
// Created by caowei on 2024/4/27.
//

#include "game.h"
#include "utils.h"
#include <vector>
#include <cmath>
#include <random>
#include <conio.h>

using namespace std;

Color colorArr[13] = {twoTo1, twoTo2, twoTo3, twoTo4, twoTo5, twoTo6,
                      twoTo7, twoTo8, twoTo9, twoTo10, twoTo11};

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
    for (int i = 0; i < 2; ++i) {
        // 初始化两个随机位置
        vector<POINT> emptyPos = EmptyGrid();
        CreateNumber(emptyPos);
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
    Draw();
}

Game2048::Game2048(int maxGrid, int maxPower) {
    // 初始化数值部分
    this->_maxGrid = maxGrid;
    this->_maxPower = maxPower;
    // 初始化可能值数组
    this->_gridVal.push_back(0);
    for (int i = 1; i <= this->_maxPower; ++i) {
        this->_gridVal.push_back(pow(2, i));
    }
    // 初始化每格内的值
    for (int i = 0; i < this->_maxGrid; ++i) {
        this->_map.emplace_back(this->_maxGrid, 0);
    }
    for (int i = 0; i < 2; ++i) {
        // 初始化两个随机位置
        vector<POINT> emptyPos = EmptyGrid();
        CreateNumber(emptyPos);
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
    Draw();
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

int Game2048::NewNum(int mode) {
    if (mode == one) {
        return 2;
    }
    else if (mode == two) {
        return pow(2, uniformIntRand(1, 2));
    }
}

// 输入空格坐标数组，从空格中选一个空格填入数字
void Game2048::CreateNumber(vector<POINT> emptyPos) {
    int posInd = uniformIntRand(0, emptyPos.size()-1);   // 从空格中取一个空格
    this->_map[emptyPos[posInd].x][emptyPos[posInd].y] = this->NewNum(this->_genMode);
}
// 输入坐标，在当前坐标填入数字
void Game2048::CreateNumber(int row, int col) {
    this->_map[row][col] = this->NewNum(this->_genMode);
}

// 画图
void Game2048::Draw() {
    for (int row = 0; row < this->_maxGrid; ++row) {
        for (int col = 0; col < this->_maxGrid; ++col) {
            // 上面两层循环遍历每格中的数值
            for (int i = 0; i < this->_maxPower; ++i) {
                // 这个循环用于检查格内的值与可能值数组中哪个相等，并取其索引以获得该值对应的格子颜色
                if (this->_map[row][col] == this->_gridVal[i]) {
                    setfillcolor(colorArr[i]);
                    solidrectangle(this->_ltPos[row][col].x, this->_ltPos[row][col].y,
                                   this->_ltPos[row][col].x + this->_gridWidth, this->_ltPos[row][col].y + this->_gridWidth);
                }
            }
            // 给每格标记数字
            if (this->_map[row][col] != 0) {
                const char *numStr = to_string(this->_map[row][col]).c_str();
                settextstyle(50, 0, "黑体");
                setbkmode(TRANSPARENT);
//                settextcolor(RGB(0, 0, 0));
                int offsetWidth = (this->_gridWidth - textwidth(numStr)) / 2;
                int offsetHeight = (this->_gridWidth - textheight(numStr)) / 2;
                outtextxy(this->_ltPos[row][col].x + offsetWidth, this->_ltPos[row][col].y + offsetHeight, numStr);
            }
        }
    }
}