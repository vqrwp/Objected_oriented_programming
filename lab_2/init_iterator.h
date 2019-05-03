//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_ITERATOR_INIT_H
#define LAB_2_ITERATOR_INIT_H

#include <memory>
#include "init_list.h"
#include "init_elem.h"
#include "errors.h"
#include "memory.h"

template <typename T> class List;
template <typename T> class List_elem;

class Iterator_base
{
public:
    virtual void first()             = 0;
    virtual void next()              = 0;
    virtual void last()              = 0;
    virtual bool range()             = 0;
};

template <typename T>
class List_iterator : public Iterator_base
{

    public:
        friend class List<T>;
        friend class List_elem<T>;
        List_iterator(std::shared_ptr<List<T>> head);

        ~List_iterator(); // деструктор

        List_iterator<T>& operator=(List_iterator<T> a);
        void first() override ;  // T*
        void last() override ;
        void next() override ;
        bool range() override ;
        const T cur();

        operator bool();
        T& operator*();
        const T& operator*() const;
        T* operator->();
        const T* operator->() const;

        List_iterator<T> operator ++(int);

        bool check(int line) const;
        bool operator != (List_iterator<T> &iterator);

    protected:
        T* get_cur_ptr() const;
    private:
        std::weak_ptr <T> current;
        const List<T> *list;
};

#include "list_iterator.h"

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
    ConstIter<T>& operator+=(const unsigned int a);

private:
    std::weak_ptr<List_elem<T>> element;
};

#include "constiterator.hpp"

#endif //LAB_2_ITERATOR_INIT_H
