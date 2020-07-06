#ifndef _DEF_iry21dz2835647vr3u564wih_
#define _DEF_iry21dz2835647vr3u564wih_

#include "JacobiMethodBase.hpp"

#include "Matrix.hpp"
#include "Vector.hpp"

#include <stdio.h>

class GaussSeidelMethod : public JacobiMethodBase{
    public:
        GaussSeidelMethod() : JacobiMethodBase() {}
        GaussSeidelMethod(Matrix A, Vector b) : JacobiMethodBase(A, b) {}
        //Implemented method
        void run(int max_iteration, bool debug_mode){
            int n = b.dimension().row;
            for(int m = 0; m < max_iteration; m++){
                x_old = x;
                for(int i = 1; i <= n; i++){
                    double front_sum = 0;
                    for(int j = 1; j <= i - 1; j++){
                        front_sum += A.at(i, j) * x.at(j);
                    }
                    double back_sum = 0;
                    for(int j = i + 1; j <= n; j++){
                        back_sum += A.at(i, j) * x_old.at(j);
                    }
                    x.set(i, (1 / A.at(i, i)) * (b.at(i) - front_sum - back_sum));
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