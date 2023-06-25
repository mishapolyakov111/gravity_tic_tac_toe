struct AbstractDsu{

    int parents_arr_[100];
    int sizes_[100];

    void makeSet  (int index);
    void unionSet (int index1, int index2);
    int  findSet  (int index);
    int  getSize  (int index);

};

struct DsuDispatch {

    AbstractDsu   horizontal_dsu_ ;
    AbstractDsu   vertical_dsu_   ;
    AbstractDsu   diag_up_dsu_    ;
    AbstractDsu   diag_down_dsu   ;

}; 