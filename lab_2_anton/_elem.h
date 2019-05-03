#ifndef __NODE__
#define __NODE__

#include <memory>

template <typename T>
class List_elem
{
public:
    List_elem(T arg);
    List_elem(std::shared_ptr<List_elem<T>> n, T arg);

    T& get(void);

    void setChild(std::shared_ptr<List_elem<T>> child);
    std::shared_ptr<List_elem<T>> nextShared(void);

private:
    std::shared_ptr<List_elem<T>> next_node;
    T data;
};

#include "elem.hpp"

#endif
