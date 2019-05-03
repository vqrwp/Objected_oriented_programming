#ifndef __LINKED_LIST_ITERATOR__
#define __LINKED_LIST_ITERATOR__

template<typename T>
class Iter
{
public:
    Iter<T>(std::shared_ptr<List_elem<T>> a);

    bool operator==(Iter<T> a);
    bool operator!=(Iter<T> a);

    T& operator*();
    T& operator->();
    operator bool();

    Iter<T>& operator=(Iter<T> a);

    Iter<T>& operator++(); // сдвиг
    Iter<T> operator++(int); // сдвиг на число шагов

private:
    std::weak_ptr<List_elem<T>> element;
};

#include "iterator.hpp"

template<typename T>
class ConstIter
{
public:
    ConstIter<T>(std::shared_ptr<List_elem<T>> a);

    bool operator==(ConstIter<T> a);
    bool operator!=(ConstIter<T> a);

    const T& operator*();
    const T& operator->();
    operator bool();

    ConstIter<T>& operator++();
    ConstIter<T> operator++(int);

private:
    std::weak_ptr<List_elem<T>> element;
};

#include "constiterator.hpp"

#endif
