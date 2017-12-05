#include "tstack.h"

template <class T>
TStack<T>::TStack() : head(nullptr), _size(0) {
}

template <class T>
void TStack<T>::push(std::shared_ptr<T> &&figure) {
    std::shared_ptr< TStackItem<T> > temp(new TStackItem<T>(figure));
    temp->SetNext(this->head);
    this->head = temp;
    this->_size++;
}

template <class T>
std::shared_ptr<T> TStack<T>::pop() {
    std::shared_ptr<T> result;
    if (this->head != nullptr) {
        result = head->GetFigure();
        this->head = this->head->GetNext();
        this->_size--;
    }
    return result;
}

template<class T>
std::shared_ptr<T> TStack<T>::pop_last() {
    std::shared_ptr<T> res;

    if (head != nullptr) {
        std::shared_ptr< TStackItem<T> > cur = head;
        std::shared_ptr< TStackItem<T> > prev = nullptr;

        while (cur->GetNext() != nullptr) {
            prev = cur;
            cur = cur->GetNext();
        }

        if (prev != nullptr) {
            prev->SetNext(nullptr);
            res = cur->GetFigure();
        } else {
            res = cur->GetFigure();
            head = nullptr;
        }
    }

    return res;
}

template <class T>
unsigned int TStack<T>::size() {
    return this->_size;
}

template <class T>
bool TStack<T>::empty() {
    return this->head == nullptr;
}

template<class T>
std::shared_ptr<T> TStack<T>::operator [](int i) {
    int j = 0;
    if (size() >= 1) {
        for (auto el : *this) {
            if (i == j) {
                return el;
            }
            ++j;
        }
    }

    return std::shared_ptr<T>(nullptr);
}

template<class T>
void TStack<T>::sort() {
    if (size() > 1) {
        std::shared_ptr<T> m = pop();
        TStack<T> l, r;

        while (!empty()) {
            std::shared_ptr<T> val = pop();
            if (*val < *m) {
                l.push(std::move(val));
            } else {
                r.push(std::move(val));
            }
        }

        l.sort();
        r.sort();

        while (!l.empty()) {
            push(l.pop_last());
        }

        push(std::move(m));

        while (!r.empty()) {
            push(r.pop_last());
        }
    }
}

template<class T>
std::future<void> TStack<T>::back_sort() {
    std::packaged_task<void(void)> task(std::bind(std::mem_fn(&TStack<T>::thread_sort), this));
    std::future<void> res(task.get_future());
    std::thread thread(std::move(task));
    thread.detach();
    return res;
}

template<class T>
void TStack<T>::thread_sort() {
    if (size() > 1) {
        std::shared_ptr<T> m = pop_last();
        TStack<T> l, r;

        while (!empty()) {
            std::shared_ptr<T> val = pop_last();
            if (*val < *m) {
                l.push(std::move(val));
            } else {
                r.push(std::move(val));
            }
        }

        std::future<void> left = l.back_sort();
        std::future<void> right = r.back_sort();

        left.get();

        while (!l.empty()) {
            push(l.pop_last());
        }

        push(std::move(m));

        right.get();

        while (!r.empty()) {
            push(r.pop_last());
        }
    }
}

template <class T>
TIterator<TStackItem<T>, T> TStack<T>::begin() {
    return TIterator<TStackItem<T>, T>(head);
}

template <class T>
TIterator<TStackItem<T>, T> TStack<T>::end() {
    return TIterator<TStackItem<T>, T>(nullptr);
}

template <class T>
std::ostream & operator <<(std::ostream &os, const TStack<T> &stack) {
    std::shared_ptr< TStackItem<T> > item = stack.head;
    std::cout << "Stack:" << std::endl;
    while (item != nullptr) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

template <class T>
TStack<T>::~TStack() {
}

template class TStack<Figure>;
template std::ostream & operator <<(std::ostream &os, const TStack<Figure> &stack);
