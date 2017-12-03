#ifndef TREMOVECRITERIA_H
#define TREMOVECRITERIA_H
#include <memory>

template <class T>
class TRemoveCriteria {
public:
    virtual bool doesFit(std::shared_ptr<T> &val) = 0;
};

#endif // TREMOVECRITERIA_H
