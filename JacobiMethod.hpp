#ifndef _DEF_iry21dzl5o0o47vr3u564wih_
#define _DEF_iry21dzl5o0o47vr3u564wih_

#include "Matrix.hpp"
#include "Vector.hpp"
#include "Dimension.hpp"

#include <stdio.h>

#include "JacobiMethodBase.hpp"

class JacobiMethod : public JacobiMethodBase{
    public:
        JacobiMethod() : JacobiMethodBase() {}
        JacobiMethod(Matrix A, Vector b) : JacobiMethodBase(A, b) {}
        //Implemented method
        void run(int max_iteration, bool debug_mode){
            int n = b.dimension().row;
            for(int m = 0; m < max_iteration; m++){
                x_old = x;
                for(int i = 1; i <= n; i++){
                    double sum = 0;
                    for(int j = 1; j <= n; j++){
                        if(i != j){
                            sum += A.at(i, j) * x_old.at(j);
                        }
                    }
                    x.set(i, (1 / A.at(i, i)) * (b.at(i) - sum));
                }
                if(((x_old - x).norm(0) / x.norm(0)) <= epsilon){
                    if(debug_mode){
                        printf("Iteration took : %d\n", m);
                    }
                    break;
                }
            }
            step = JacobiMethodSteps::COMPLETED;
        }
};

#endif