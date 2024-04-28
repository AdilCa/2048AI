//
// Created by caowei on 2024/4/27.
//

#pragma once

#include <vector>
#include <easyx.h>
#include <random>

enum Color {
    zero    = RGB(205, 193, 180),
    twoTo1  = RGB(238, 228, 218),
    twoTo2  = RGB(237, 224, 200),
    twoTo3  = RGB(242, 177, 121),
    twoTo4  = RGB(245, 149, 99),
    twoTo5  = RGB(246, 124, 95),
    twoTo6  = RGB(246, 94, 59),
    twoTo7  = RGB(242, 177, 121),
    twoTo8  = RGB(237, 204, 97),
    twoTo9  = RGB(255, 0, 128),
    twoTo10 = RGB(145, 0, 72),
    twoTo11 = RGB(242, 17, 158),
    back    = RGB(187, 173, 160),
};

enum GenNewNumMode {one, two};

enum MoveDir {moveUp, moveDown, moveLeft, moveRight};

class Game2048 {
private:
    // 数值相关
    GenNewNumMode _genMode = one;// 生成新填充数的模式
    int _maxGrid;               // 尺寸
    int _maxPower;              // 最大幂次
    std::vector<int> _gridVal;       // 格内所有可能值
    std::vector<std::vector<int>> _map;   // 每格内的值
    int _record;                 // 得分


    // UI相关
    int _gridWidth;             // 每格宽度
    int _interval;              // 两格间隔宽度
    int _fontSize;              // 数字高度
    std::vector<std::vector<POINT>> _ltPos;        // 每格左上角坐标

public:

    Game2048();                             // 默认初始化
    Game2048(int maxGrid, int maxPower);    // 带参初始化

    std::vector<POINT> EmptyGrid();         // 获取空白格的坐标

    int NewNum(int mode);                   // 生成新数的模式
    void CreateNumber(std::vector<POINT> emptyPos);  // 在空白位置随机生成新的数
    void CreateNumber(int row, int col);        // 在指定位置生成新的数

    void Draw();    // 根据当前情况画界面

    struct PackMatRec {std::vector<std::vector<int>> mat; int record;};// 定义左移函数的返回值，mat为移动后的矩阵，record是本次移动累计的分数
    void Move();    // 根据输入移动方块
    PackMatRec LeftMove(std::vector<std::vector<int>>); // 左移函数
};
