//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_ELEM_INIT_H
#define LAB_2_ELEM_INIT_H
#include "init_list.h"
#include "init_iterator.h"
#include "errors.h"

//template <typename T> class List;

template <typename T>
class List_elem
{
private:
    std::shared_ptr<List_elem> next;
    T data;

public:
    List_elem();
    //List_elem(T data);

    ~List_elem(); // деструктор

    T get_data() const;
    void set_data(T data);
    std::shared_ptr<List_elem> get_next();

    friend class List<T>;
    friend class List_iterator<T>;
};

#endif //LAB_2_ELEM_INIT_H
