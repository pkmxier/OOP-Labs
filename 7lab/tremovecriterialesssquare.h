#ifndef TREMOVECRITERIALESSSQUARE_H
#define TREMOVECRITERIALESSSQUARE_H
#include "tremovecriteria.h"

template <class T>
class TRemoveCriteriaLessSquare : public TRemoveCriteria<T> {
private:
    double val;
public:
    TRemoveCriteriaLessSquare(double val) {
        this->val = val;
    }
    bool doesFit(std::shared_ptr<T> &fig) override {
        return fig->Square() <= val;
    }
};

#endif // TREMOVECRITERIALESSSQUARE_H
