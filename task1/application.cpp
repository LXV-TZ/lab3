#include "application.h"
#include "position.h"
#include <iostream>
#include <vector>

using namespace std;

// 静态局部变量来模拟成员变量
static vector<vector<int>> board(8, vector<int>(8, 0));

// 初始化棋盘
void Application::initialize() {
    board.assign(8, vector<int>(8, 0));
}

// 获取起始位置
Position Application::getStartPosition() {
    return Position(0, 0);
}

// 检查位置是否有效
bool Application::isValid(const Position& p) {
    int row = p.getRow();
    int col = p.getColumn();

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
    board[p.getRow()][p.getColumn()] = 1;
}

// 检查是否成功
bool Application::success(const Position& p) {
    return p.getRow() == 8;
}

// 回退
void Application::goBack(const Position& p) {
    board[p.getRow()][p.getColumn()] = 0;
}

// 打印棋盘
void Application::print() {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Iterator类的定义
Application::Iterator::Iterator() : currItrPosPtr(nullptr) {}

Application::Iterator::Iterator(const Position& currP) {
    currItrPosPtr = new Position(currP.getRow() + 1, 0); // 从下一行开始
}

Application::Iterator::~Iterator() {
    delete static_cast<Position*>(currItrPosPtr);
}

Position Application::Iterator::getNextPosition() {
    Position* curr = static_cast<Position*>(currItrPosPtr);
    Position next(curr->getRow(), curr->getColumn());
    curr->setColumn(curr->getColumn() + 1);
    return next;
}

bool Application::Iterator::noNextPosition() {
    Position* curr = static_cast<Position*>(currItrPosPtr);
    return curr->getColumn()>=8;//所有列都尝试了吗
}
