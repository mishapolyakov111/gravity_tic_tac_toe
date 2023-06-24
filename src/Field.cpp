#include "../includes/Field.h"

#define CUR_CELL arr[size_ - y][x - 1]
#define LEFT_CELL arr[size_ - y][x - 2]
#define RIGHT_CELL arr[size_ - y][x]
#define UP_CELL arr[size_ - y + 1][x - 1]
#define DOWN_CELL arr[size_ - y - 1][x - 1]

void Field::Print() {
    for (auto& i: arr) {
        for (auto& j: i) {
            std::cout << j.value_ << " ";
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

        if (arr[size_ - y][x - 1].value_ != Empty) {
            std::cerr << "Try Enter Again\n";
            continue;
        }

        DoGravity(x, y);
        if (cross_input) {
            arr[size_ - y][x - 1].value_ = Cross;
        } else {
            arr[size_ - y][x - 1].value_ = Zero;
        }


        cross_input = !cross_input;
        Print();
    }
}

void Field::DoGravity(int& x, int& y) {
    if (y == 1) {
        return;
    }
    while (y != 1 and arr[size_ - y + 1][x - 1].value_ == Empty) {
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
    }

    return false;
}

