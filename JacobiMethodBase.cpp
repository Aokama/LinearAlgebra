#include "JacobiMethodBase.hpp"

#include "Dimension.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

#include <stdio.h>

JacobiMethodBase::JacobiMethodBase(){

}
JacobiMethodBase::JacobiMethodBase(Matrix A, Vector b){
    this->A = A;
    this->b = b;
    //if the initial vector is not defined explicitly, the vector will be {1, 1, ...}
    this->x = Vector(b.dimension());
    this->x_old = Vector(b.dimension());
    for(int i = 1; i <= b.dimension().row; i++){
        x.set(i, 1); 
        x_old.set(i, 1);
    }
    //if the convergense condition is not defined explicitly, the value will be 10^-16
    this->epsilon = 1.0e-16;
    this->step = JacobiMethodSteps::INITIALIZED;
}
void JacobiMethodBase::set_initial_vector(Vector initial_vector){
    this->x = initial_vector;
    this->x_old = initial_vector;
}
void JacobiMethodBase::set_convergense_condition(double epsilon){
    this->epsilon = epsilon;
}
void JacobiMethodBase::run(int max_iteration, bool debug_mode){

}
Vector JacobiMethodBase::get_solution_vector(){
    if(step == JacobiMethodSteps::COMPLETED){
        return x;
    }
    else{
        printf("The solution is yet to calculated.\n");
        return Vector();
    }
}
JacobiMethodSteps JacobiMethodBase::get_step(){
    return step;
}