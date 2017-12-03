#ifndef TREMOVECRITERIAALL_H
#define TREMOVECRITERIAALL_H
#include "tremovecriteria.h"

template <class T>
class TRemoveCriteriaAll : public TRemoveCriteria<T> {
public:
    TRemoveCriteriaAll() {}
    bool doesFit(std::shared_ptr<T> &val) override {
        return true;
    }
};

#endif // TREMOVECRITERIAALL_H
