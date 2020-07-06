#ifndef _DEF_ie0uviw08kwgkddlks30z82p_
#define _DEF_ie0uviw08kwgkddlks30z82p_

#include "Vector.hpp"
#include "Dimension.hpp"

#include <vector>

class Vector;

class Matrix{
    private:
        std::vector<std::vector<double>> matrix;
        Dimension dim;
    public:
        Matrix();
        Matrix(std::vector<std::vector<double>> array);
        Matrix(Dimension dimension);

        Dimension dimension();

        double at(int i, int j);
        void set(int i, int j, double value);

        void show(const char name[]);
        
        Vector operator * (Vector right);
};

#endif