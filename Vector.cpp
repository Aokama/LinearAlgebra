#include "Vector.hpp"

#include "Dimension.hpp"

#include <vector>
#include <stdio.h>
#include <math.h>

Vector::Vector(){

}
Vector::Vector(std::vector<double> array){
    vector = array;
    dim = Dimension(array.size(), 1);
}

Vector::Vector(Dimension dimension){
    if(dimension.col != 1){
        printf("Column dimension %d cannot be vector.\n", dimension.col);
    }
    else{
        vector = std::vector<double>(dimension.row);
        dim = dimension;
    }
}

Dimension Vector::dimension(){
    return dim;
}

double Vector::at(int index){
    if(dim.row < index){
        printf("You cannot assign index %d, this vector is %d-dimensional.\n", index, dimension().row);
        return -1;
    }
    return vector[index - 1];
}

void Vector::set(int index, double value){
    if(dim.row < index){
        printf("You cannot assign index %d, this vector is %d-dimensional.\n", index, dimension().row);
    }
    vector[index - 1] = value;
}

double Vector::norm(int n){
    if(n == 0){
        double max = 0;
        for(int i = 1; i <= dim.row; i++){
            if(abs(at(i)) > max){
                max = abs(at(i));
            }
        }
        return max;
    }
    else{
        double sum = 0;
        for(int i = 1; i <= dim.row; i++){
            sum += pow(abs(at(i)), n);
        }
        return pow(sum, 1 / n);
    }
}

Vector Vector::operator + (Vector right){
    if(!dimension().equals(right.dimension())){
        printf("Unable to add vector with a different dimension.\n");
        return Vector();
    }
    else{
        Vector result = Vector(dimension());
        for(int i = 1; i <= dim.row; i++){
            result.set(i, at(i) + right.at(i));
        }
        return result;
    }
}
Vector Vector::operator - (Vector right){
    if(!dimension().equals(right.dimension())){
        printf("Unable to subtract vector with a different dimension.\n");
        return Vector();
    }
    else{
        Vector result = Vector(dimension());
        for(int i = 1; i <= dim.row; i++){
            result.set(i, at(i) - right.at(i));
        }
        return result;
    }
}

void Vector::show(const char name[]){
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dim.row; i++){
        printf("%1.2e\n", at(i));
    }
    printf("======== %s ========\n", name);
}