//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_LIST_INIT_H
#define LAB_2_LIST_INIT_H

#include <iostream>
#include "list.h"
#include "init_elem.h"
#include "init_iterator.h"
#include "errors.h"
#include "init_base_list.h"

template <typename T> class List_elem;

template <typename T>
class List : public baseList
{
public:
    friend class List_iterator<T>;
    List();
    List(T data); // инициализация одним элементом
    List(T *arr, int n = 1); // инициализация массивом
    explicit List(const List<T> &list);  // конструктор копирования
    List(List<T>&& list); // копирование когда предыдущее удаляется
    List(std::initializer_list<T> list); // инициализация через фигурные скобки

    ~List(); // деструктор

    List<T> &operator=(const List<T> &list);
    List<T> &operator=(List<T> &&list);

    bool operator ==(const List<T> &list) const; // проверка на равенство
    bool equal(const List<T> &list) const; // проверка на равенство
    bool operator !=(const List<T> &list) const; // проверка на неравенство

    void merge(const List<T> & list); // слияние двух списков
    List<T> &operator +(const List<T> &list); // слияние двух списков

//    void insert_by_ind(const size_t ind, const T &value);
    void add_to_head(const T &data);
    void add_to_tail(const T &data);
    T& get_from_head();
    T& get_from_tail();
    const T& get_head() const;
//    void delete_elem(const T &data);
//    void delete_by_ind(size_t index);

    T* to_array() const;
//    void sort(bool increase = true);
    size_t size() const;
    void clear();
    bool empty() const;

protected:
    std::shared_ptr<List_elem <T>> del(const List_elem<T> &elem);
    std::shared_ptr<List_elem <T>> search(const List_elem<T> &elem) const;

private:
    std::shared_ptr<List_elem<T>> head;
    std::shared_ptr<List_elem<T>> tail;
};


#endif //LAB_2_LIST_INIT_H
