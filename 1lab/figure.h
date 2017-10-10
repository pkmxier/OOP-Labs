#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual void Print() = 0;
    virtual double Square() = 0;
    virtual ~Figure() {}
};

#endif // FIGURE_H
