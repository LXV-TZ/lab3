#include "application.h"
#include "position.h"
#include <iostream>
#include <vector>

using namespace std;

// 静态局部变量来模拟成员变量
static vector<vector<bool>> board(8, vector<bool>(8, false));
static int currentRow = 0;

// 初始化棋盘
void Application::initialize() {
    board.assign(8, vector<bool>(8, false));
    currentRow = 0;
}

// 获取起始位置
Position Application::getStartPosition() {
    return Position(0, -1);
}

// 检查位置是否有效
bool Application::isValid(const Position& p) {
    int row = p.getRow();
    int col = p.getCol();

    // 检查列
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) return false;
    }

    // 检查左上对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }

    // 检查右上对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; --i, ++j) {
        if (board[i][j]) return false;
    }

    return true;
}

// 进行下一步
void Application::progress(const Position& p) {
    board[p.getRow()][p.getCol()] = true;
    currentRow++;
}

// 检查是否成功
bool Application::success(const Position& p) {
    return currentRow == 8;
}

// 回退
void Application::goBack(const Position& p) {
    board[p.getRow()][p.getCol()] = false;
    currentRow--;
}

// 打印棋盘
void Application::print() {
    for (const auto& row : board) {
        for (bool cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Iterator类的定义
Application::Iterator::Iterator() : currItrPosPtr(nullptr) {}

Application::Iterator::Iterator(const Position& currP) : currItrPosPtr(nullptr) {}

Application::Iterator::~Iterator() {}

Position Application::Iterator::getNextPosition() {
    // 实现获取下一个位置的逻辑
    return Position(0, 0);
}

bool Application::Iterator::noNextPosition() {
    // 实现检查是否没有下一个位置的逻辑
    return true;
}
