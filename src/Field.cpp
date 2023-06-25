#include "../includes/Field.h"

#define CUR_CELL arr[y][x]
#define LEFT_CELL arr[y][x - 1]
#define RIGHT_CELL arr[y][x + 1]
#define UP_CELL arr[y + 1][x]
#define DOWN_CELL arr[y - 1][x]

void Field::Print() {
    for (int i = size_ - 1; i >=0; --i) {
        for (int j = 0; j < size_; ++j) {
            std::cout << arr[i][j].value_ << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Field::Play() {
    int x, y;
    bool cross_input = true;
    while (true) {
        std::cin >> x >> y;
        if (x == 0 or y == 0) {
            std::cout << "Program finished";
            break;
        }

        --x;
        --y;

        if (arr[y][x].value_ != Empty) {
            std::cerr << "Try Enter Again\n";
            continue;
        }

        DoGravity(x, y);
        if (cross_input) {
            arr[y][x].value_ = Cross;
        } else {
            arr[y][x].value_ = Zero;
        }


        cross_input = !cross_input;
        Print();
    }
}

void Field::DoGravity(int& x, int& y) {
    if (y == 0) {
        return;
    }
    while (y != 0 and arr[y - 1][x].value_ == Empty) {
        --y;
    }
}


bool Field::Check(int x, int y) {
    if (LEFT_CELL.value_ == CUR_CELL.value_ or RIGHT_CELL.value_ == CUR_CELL.value_) {
        if (LEFT_CELL.value_ == CUR_CELL.value_ and LEFT_CELL.type_[Horizontal]) {
            int idx = LEFT_CELL.cluster_idx_[Horizontal];
            CUR_CELL.cluster_idx_[Horizontal] = idx;
            ++clusters[idx].size_;
        }

        if (RIGHT_CELL.value_ == CUR_CELL.value_ and RIGHT_CELL.type_[Horizontal]) {
            int idx = RIGHT_CELL.cluster_idx_[Horizontal];
            CUR_CELL.cluster_idx_[Horizontal] = idx;
            ++clusters[idx].size_;
        }
    }

    return false;
}

