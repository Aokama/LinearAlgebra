#include <stdio.h>

#include "Dimension.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "JacobiMethod.hpp"
#include "GaussSeidelMethod.hpp"

#include <math.h>

//function to assign values of 演習課題9
void assign(Matrix& A, int a){
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 20; j++){
            if(i == j){
                A.set(i, j, a);
            }
            else if(abs(i - j) <= 2){
                A.set(i, j, -1);
            }
            else{
                A.set(i, j, 0);
            }
        }
    }
}

int main(void){

    Matrix A = Matrix(Dimension(20, 20));
    assign(A, 10);
    Vector b = Vector(Dimension(20, 1));
    for(int i = 1; i <= 20; i++){
        b.set(i, 1);
    }

    JacobiMethod jm = JacobiMethod(A, b);
    jm.set_convergense_condition(1.0e-8);
    jm.run(100, true);
    Vector x1 = jm.get_solution_vector();
    (A * x1).show("A * x1");

    GaussSeidelMethod gsm = GaussSeidelMethod(A, b);
    gsm.set_convergense_condition(1.0e-8);
    gsm.run(100, true);
    Vector x2 = gsm.get_solution_vector();
    (A * x2).show("A * x2");

    return 0;
}