#ifndef TREMOVECRITERIAVALUE_H
#define TREMOVECRITERIAVALUE_H
#include "tremovecriteria.h"
#include <memory>

template <class T>
class TRemoveCriteriaValue : public TRemoveCriteria<T> {
private:
    std::shared_ptr<T> val;
public:
    TRemoveCriteriaValue(const std::shared_ptr<T> &val) {
        this->val = val;
    }

    bool doesFit(std::shared_ptr<T> &val) {
        return this->val->areEqual(*val);
    }
};

#endif // TREMOVECRITERIAVALUE_H
