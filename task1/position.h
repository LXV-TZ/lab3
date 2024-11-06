#ifndef POSITION_H
#define POSITION_H

class Position {
private:
    int row;
    int col;

public:
    // 构造函数
    Position(int r = 0, int c = 0);

    // 获取行
    int getRow() const;

    // 获取列
    int getCol() const;
};

#endif // POSITION_H
