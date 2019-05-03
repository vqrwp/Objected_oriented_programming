//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_LIST_ITERATOR_H
#define LAB_2_LIST_ITERATOR_H

#include <iostream>
#include "init_iterator.h"
#include "ctime"

template <typename T>
List_iterator<T>::List_iterator(std::shared_ptr<List<T>> head)
{
    //this->list = &list;
    //auto sp = l.
    this->current = head; // текущий указывает на голову
};


template <typename T>
List_iterator<T>::~List_iterator() // деструктор
{
    this->list = nullptr;
    this->current = nullptr;
};

template <typename T>
void List_iterator<T>::first() // первый член списка становится текущим
{
    this->current = this->list->head;
    // return this->list->head;
}

template <typename T>
void List_iterator<T>::next() // следующий член списка становится текущим
{
    time_t t_time = time(NULL);
    if (!this->range())
    {
        throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    auto sp = this->current.lock();
    this->current = sp.get()->get_next();
}

template <typename T>
void List_iterator<T>::last() // последний член списка становится текущим
{
    this->current = this->list->tail;
    // return this->list->tail;
}

template<typename T>
List_iterator<T>& List_iterator<T>::operator=(List_iterator<T> a)
{
    this->current = a.current;
}

template <typename T>
bool List_iterator<T>::range() // входит ли текущий элемент в список
{
    auto sp = this->current.lock();
    return sp.get() != nullptr;
};


template <typename T>
const T List_iterator<T>::cur() // возвращаются данные текущего элемента
{
    time_t t_time = time(NULL);
    if (!this->range())
    {
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    std::shared_ptr <List_elem <T>> sp = this->current.lock();
    return sp.get()->get_data();
};

// то же, что и next()
template <typename T>
List_iterator<T> List_iterator<T>::operator ++(int) // следующий член списка становится текущим
{
    time_t t_time = time(NULL);
    if (!this->range())
    {
        throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    List_iterator<T> substitute(*this);
    this->next();
    return substitute;
}

template <typename T>
bool List_iterator<T>::operator !=(List_iterator<T> &iterator)
{
    return this->current.lock().get() != iterator.current.lock().get();
};

template <typename T>
List_iterator<T>::operator bool()
{
    auto sp = this->current.lock();
    return nullptr != sp.get();
}

template<class T>
T* List_iterator<T>::get_cur_ptr() const
{
    std::shared_ptr<T> copy_ptr = current.lock();
    return copy_ptr.get();
}

template<class T>
T& List_iterator<T>::operator*()
{
    check(__LINE__);

    std::shared_ptr<T> copy_ptr = current.lock();
    return *get_cur_ptr();
}

template<class T>
const T& List_iterator<T>::operator*() const
{
    check(__LINE__);

    std::shared_ptr<T> copy_ptr = current.lock();
    return *get_cur_ptr();
}

template<class T>
T* List_iterator<T>::operator->()
{
    check(__LINE__);

    return get_cur_ptr();
}

template<class T>
const T* List_iterator<T>::operator->() const
{
    check(__LINE__);

    return get_cur_ptr();
}

template<class T>
bool List_iterator<T>::check(int line) const
{
    time_t t_time = time(NULL);
    if (!current.expired())
        return true;

    throw deletedObj(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    return false;
}

#endif //LAB_2_LIST_ITERATOR_H
