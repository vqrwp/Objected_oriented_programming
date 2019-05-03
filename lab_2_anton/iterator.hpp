template<typename T>
Iter<T>::Iter(std::shared_ptr<List_elem<T>> a)
{
    this->element = a;
}

template<typename T>
bool Iter<T>::operator==(Iter<T> a)
{
    return element.lock() == a.element.lock();
}

template<typename T>
bool Iter<T>::operator!=(Iter<T> a)
{
    return element.lock() != a.element.lock();
}

template<typename T>
T& Iter<T>::operator*()
{
    if (!element.expired())
    {
        return element.lock()->get();
    }
    throw LinkedListElementDoesntExistException("A", __LINE__, "A");
}

template<typename T>
T& Iter<T>::operator->()
{
    if (!element.expired())
    {
        return element->get();
    }
    throw LinkedListElementDoesntExistException(__FUNCTION__, __LINE__, __FILE__);
}

template<typename T>
Iter<T>::operator bool()
{
    return !this->element.expired();
}

template<typename T>
Iter<T>& Iter<T>::operator=(Iter<T> a)
{
    element = a.element;
}

template<typename T>
Iter<T>& Iter<T>::operator++()
{
    if (!this->element.expired())
    {
        this->element = std::weak_ptr<List_elem<T>>(this->element.lock()->nextShared());
        return *this;
    }
    throw LinkedListOutOfBoundsException(__FUNCTION__, __LINE__, __FILE__);
}

template<typename T>
Iter<T> Iter<T>::operator++(int)
{
    Iter<T> a = *this;
    ++(*this);
    return a;
}