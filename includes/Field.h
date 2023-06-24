#pragma once
#include <iostream>
#include <vector>

enum CLUSTER_TYPE_IDX{
    Vertical = 0,
    Horizontal = 1,
    DiagonalUp = 2,
    DiagonalDown = 3
};

enum {
    Zero = 48,
    Cross = 120,
    Empty = 46
};

struct Cluster {
    int size_;
    CLUSTER_TYPE_IDX type_;
};

struct Cell {
    char value_ = Empty;
    bool type_[4]{};
    int cluster_idx_[4]{};
};

class Field {

private:
    int size_ = 10;
    Cell arr[10][10]{};
    std::vector<Cluster> clusters;

public:
    Field() {
        clusters.reserve(100);
    }

    void Print();
    void Play();
    bool Check(int x, int y);
    void DoGravity(int& x, int& y);
};

