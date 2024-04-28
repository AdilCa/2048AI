//
// Created by caowei on 2024/4/28.
//

#include "utils.h"
#include <random>
#include <vector>

/*
 * 随机数生成器
 */

int uniformIntRand(int a, int b) {
    // 生成均匀整形随机数，区间为[a, b]
    std::mt19937 rng;
    std::random_device rd;
    rng.seed(rd());
    std::uniform_int_distribution uniIntGen(a, b);
    return uniIntGen(rng);
}

std::vector<int> uniformIntRandArr(int a, int b, int size) {
    // 生成均匀整形随机数组，区间为[a, b]， 长度为size
    std::vector<int> randArr;
    for (int i = 0; i < size; ++i) {
        randArr.push_back(uniformIntRand(a, b));
    }
    return randArr;
}


/*
 * 二维vector矩阵运算
 */

// 方阵顺时针旋转90°
std::vector<std::vector<int>> RotateClockWise (std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    auto tmpMat = matrix;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmpMat[j][n-1-i] = matrix[i][j];
        }
    }
    return tmpMat;
}

// 方阵逆时针旋转90°
std::vector<std::vector<int>> RotateCounterClockWise (std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    auto tmpMat = matrix;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmpMat[n-1-j][i] = matrix[i][j];
        }
    }
    return tmpMat;
}
