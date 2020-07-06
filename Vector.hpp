#ifndef _DEF_9jpe8x3ekkdu8zzg7o0u8ifp_
#define _DEF_9jpe8x3ekkdu8zzg7o0u8ifp_

#include <vector>

#include "Dimension.hpp"
#include "Matrix.hpp"

class Dimension;
class Matrix;

class Vector{
    private:
        std::vector<double> vector;
        Dimension dim;
    public:
        Vector();
        Vector(std::vector<double> vector);
        Vector(Dimension dimension);
        
        Dimension dimension();
        
        double at(int index);
        void set(int index, double value);

        double norm(int n);

        Vector operator + (Vector right);
        Vector operator - (Vector right);

        void show(const char name[]);
};

#endif