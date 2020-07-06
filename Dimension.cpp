#include "Dimension.hpp"

#include <stdio.h>

Dimension::Dimension(){

}

Dimension::Dimension(int row_dim, int col_dim){
    this->row = row_dim;
    this->col = col_dim;
}

bool Dimension::equals(Dimension comparer){
    return (row == comparer.row && col == comparer.col) ? true : false;
}

bool Dimension::is_vector(){
    return (col == 1) ? true : false;
}

bool Dimension::can_multiply(Dimension comparer){
    return (this->col == comparer.row) ? true : false;
}

void Dimension::show(const char name[]){
    printf("Dimension of %s : %d x %d\n", name, row, col);
}