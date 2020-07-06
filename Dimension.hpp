#ifndef _DEF_hwl58n4rfls9cszaxxzrnxji43kpho6t_
#define _DEF_hwl58n4rfls9cszaxxzrnxji43kpho6t_

class Dimension{
    public:
        int row;
        int col;

        Dimension();
        Dimension(int row_dim, int col_dim);

        bool equals(Dimension comparer);
        bool is_vector();

        bool can_multiply(Dimension comparer);

        void show(const char name[]);
};

#endif