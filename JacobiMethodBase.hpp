#ifndef _DEF_sgyr8pdzz38x5twdli8fozvh_
#define _DEF_sgyr8pdzz38x5twdli8fozvh_

#include "Vector.hpp"
#include "Matrix.hpp"

enum JacobiMethodSteps{
    INITIALIZED,
    COMPLETED,
};

class JacobiMethodBase{
    protected:
        Matrix A;
        Vector b;
        Vector x;
        Vector x_old;
        double epsilon;
        JacobiMethodSteps step;
    public:
        JacobiMethodBase();
        JacobiMethodBase(Matrix A, Vector b);
        void set_initial_vector(Vector initiali_vector);
        void set_convergense_condition(double epsilon);
        virtual void run(int max_iteration, bool debug_mode);
        Vector get_solution_vector();
        JacobiMethodSteps get_step();
};

#endif