//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_LIST_ELEM_H
#define LAB_2_LIST_ELEM_H

#include <iostream>
#include "init_elem.h"

template <typename T>
List_elem<T>::List_elem() // конструктор
{
    this->next = nullptr;
};

template <typename T>
List_elem<T>::~List_elem() // деструктор
{
    this->next = nullptr;
};

template <typename T>
T List_elem<T>::get_data() const
{
    return this->data;
}

template <typename T>
void List_elem<T>::set_data(T data)
{
    this->data = data;
}

template <typename T>
std::shared_ptr<List_elem<T>> List_elem<T>::get_next()
{
    return this->next;
}

#endif //LAB_2_LIST_ELEM_H
