#include "position.h"

// 构造函数
Position::Position(int r, int c) : row(r), col(c) {}

// 获取行
int Position::getRow() const {
    return row;
}

// 获取列
int Position::getCol() const {
    return col;
}
