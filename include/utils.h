//
// Created by caowei on 2024/4/28.
//

#pragma once

#include <random>
#include <vector>


/*
 * 随机数生成器
 */

int uniformIntRand(int a, int b);       // 生成均匀整形随机数，区间为[a, b]
std::vector<int> uniformIntRandArr(int a, int b, int size); // 生成均匀整形随机数组，区间为[a, b]， 长度为size


/*
 * 二维vector数组的矩阵运算
 */

std::vector<int> RotateClockWise ();        // 方阵顺时针旋转90°
std::vector<int> RotateCounterClockWise (); // 方阵逆时针旋转90°