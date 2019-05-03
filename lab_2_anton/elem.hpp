template <typename T>
List_elem<T>::List_elem(T arg)
{
    data = arg;
}

template <typename T>
List_elem<T>::List_elem(std::shared_ptr<List_elem<T>> n, T arg)
{
    data = arg;
    next_node = std::shared_ptr<List_elem<T>>(n);
}

template <typename T>
void List_elem<T>::setChild(std::shared_ptr<List_elem<T>> child)
{
    this->next_node = child;
}

template <typename T>
T& List_elem<T>::get(void)
{
    return this->data;
}

template <typename T>
std::shared_ptr<List_elem<T>> List_elem<T>::nextShared(void)
{
    return std::shared_ptr<List_elem<T>>(this->next_node);
}
