#include "Matrix.hpp"

#include "Vector.hpp"
#include "Dimension.hpp"

#include <stdio.h>
#include <vector>

Matrix::Matrix(){

}

Matrix::Matrix(std::vector<std::vector<double>> array){
    matrix = array;
    dim = Dimension(array.size(), array.at(0).size());
}

Matrix::Matrix(Dimension dimension){
    matrix = std::vector<std::vector<double>>(dimension.row, std::vector<double>(dimension.col));
    dim = dimension;
}

Dimension Matrix::dimension(){
    return dim;
}

double Matrix::at(int i, int j){
    if(i > dim.row || j > dim.col){
        printf("(%d, %d) is out of bound in this matrix.\n", i, j);
        return 0;
    }
    else{
        return matrix[i - 1][j - 1];
    }
}

void Matrix::set(int i, int j, double value){
    if(i > dim.row || j > dim.col){
        printf("(%d, %d) is out of bound in this matrix.\n", i, j);
    }
    else{
        matrix[i - 1][j - 1] = value; 
    }
}

Vector Matrix::operator * (Vector right){
    if(!dim.can_multiply(right.dimension())){
        printf("Unable to multiply.\n");
        return Vector();
    }
    Vector result = Vector(right.dimension());
    for(int i = 1; i <= dim.row; i++){
        double sum = 0;
        for(int k = 1; k <= dim.col; k++){
            sum += at(i, k) * right.at(k);
        }
        result.set(i, sum);
    }
    return result;
}

void Matrix::show(const char name[]){
    printf("================ %s ================\n", name);
    for(int i = 1; i <= dim.row; i++){
        for(int j = 1; j <= dim.col; j++){
            printf("%1.2e  ", at(i, j));
        }
        printf("\n");
    }
    printf("================ %s ================\n", name);
}