#include "../includes/DSU.hpp"


void AbstractDsu::makeSet(int index) {
    parents_arr_[index] = index;
    sizes_[index] = 1;
}

int AbstractDsu::findSet  (int index) {

    if (parents_arr_[index] = index)
        return index;
    
    parents_arr_[index] = findSet(parents_arr_[index]);

    return parents_arr_[index];
}


void AbstractDsu::unionSet(int index1, int index2) {

    int parent1 = findSet(index1);
    int parent2 = findSet(index2);

    if (parent1 != parent2) {
        parents_arr_[parent2] = parent1;
        sizes_[parent1] += sizes_[parent2];
    }
}

int AbstractDsu::getSize(int index) {
    return sizes_[findSet(index)];
}