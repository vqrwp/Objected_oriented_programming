#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

#include "_elem.h"
#include "errors.h"
#include "_iterator.h"
#include "baseList.h"

template<typename T>
class List : BaseList
{
public:
    List();

    explicit List(T a);
    List(std::initializer_list<T> a);
    ~List();
    List_elem<T>& operator=(const List_elem<T>& a); // peremeshenie
    explicit List(const List<T> &list);  // конструктор копирования
    List(List<T>&& list); // копирование когда предыдущее удаляется
    List<T>& copy();

    explicit operator bool() override;

    List<T>& operator +(const List<T>& a); // merge
    List<T> operator +=(const List<T>& a); // merge
    List<T>& operator *(unsigned int a);
    List<T>& operator *=(unsigned int a);
    bool operator ==(const List<T>& a);
    bool operator !=(const List<T>& a);
    void append(T arg);

    Iter<T> begin();
    Iter<T> end();

    ConstIter<T> begin() const ;
    ConstIter<T> end() const ;

    void add(T arg);
    void insert(unsigned int pos, T arg);
    void remove(unsigned int pos) override;
    void clear() override;

    void concatenate(const List<T>& a);
    T& get_head();
    T& get_last();
    T pop_head();
    T pop_last();

private:
    std::shared_ptr<List_elem<T>> head;
    std::shared_ptr<List_elem<T>> last;

    void initialElement(T arg);
};


#include "list.hpp"

#endif
