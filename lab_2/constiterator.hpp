template<typename T>
ConstIter<T>::ConstIter(std::shared_ptr<List_elem<T>> a)
{
    this->element = a;
}

template<typename T>
bool ConstIter<T>::operator==(ConstIter<T> a)
{
    return element == a.element;
}

template<typename T>
bool ConstIter<T>::operator!=(ConstIter<T> a)
{
    return element.lock() != a.element.lock();
}

template<typename T>
const T& ConstIter<T>::operator*()
{
    time_t t_time = time(NULL);
    if (!element.expired())
    {
        return element.lock()->get();
    }
    throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

template<typename T>
const T& ConstIter<T>::operator->()
{
    time_t t_time = time(NULL);
    if (element)
    {
        return element->get();
    }
    throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

template<typename T>
ConstIter<T>::operator bool()
{
    return !this->element.expired();
}


template<typename T>
ConstIter<T>& ConstIter<T>::operator++()
{
    time_t t_time = time(NULL);
    if (!this->element.expired())
    {
        this->element = std::weak_ptr<List_elem<T>>(this->element.lock()->nextShared());
        return *this;
    }
    throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

template<typename T>
ConstIter<T> ConstIter<T>::operator++(int)
{
    List_iterator<T> a = *this;
    ++(*this);
    return a;
}

template<typename T>
ConstIter<T>& ConstIter<T>::operator+=(const unsigned int a)
{
    for (unsigned int i = 0; i < a; i++)
    {
        ++(*this);
    }
    return *this;
}
