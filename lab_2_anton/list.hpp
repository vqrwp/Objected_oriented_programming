template<typename T>
List<T>::List(void) : BaseList()
{
    this->size = 0;
}

template<typename T>
List<T>::List(T a) : BaseList()
{
    this->size = 0;
    this->add(a);
}

template<typename T>
List<T>::List(std::initializer_list<T> a) : BaseList()
{
    this->size = 0;

    for(auto &i : a)
    {
        this->append(i);
    }
}

// Makes list empty
template<typename T>
void List<T>::clear()
{
    this->head.reset();
    this->last.reset();
    this->size = 0;
}

template <typename T>
List<T>::List(const List<T> &list)
{
    time_t t_time = time(NULL);
    if (list.head == nullptr)
    {
        this->head = nullptr;
        this->last = nullptr;
    }
    else
    {
        std::shared_ptr<List_elem<T>> c;
        std::shared_ptr<List_elem<T>> sp(new List_elem<T>);
        head = sp;

        if (!head)
            throw LinkedListElementDoesntExistException(__FUNCTION__, __LINE__, __FILE__);

        head.get()->get() = list.head->get();
        this->head = head;
        std::shared_ptr<List_elem<T>> tmp(head);
        c = list.head->nextShared();

        for (; c; c = c.get()->nextShared())
        {
            std::shared_ptr<List_elem<T>> item(new List_elem<T>);

            if (!item)
                throw LinkedListElementDoesntExistException(__FUNCTION__, __LINE__, __FILE__);

            tmp->nextShared() = item;
            item->setChild(c->get());
            this->last = item;
            tmp = tmp->nextShared();
        }
    }
}

template<typename T>
List<T>::List(List<T>&& list)
{
    head = list.head;
    last = list.last;
    list.head = nullptr;
    list.last = nullptr;
}

// Adds initial element to empty list
template<typename T>
void List<T>::initialElement(T arg)
{
    head = std::shared_ptr<List_elem<T>>(new List_elem<T>(arg));
    last = std::shared_ptr<List_elem<T>>(head);
}

// Appends element to the end of the list
template<typename T>
void List<T>::append(T arg)
{
    if (this->last)
    {
        this->last->setChild(std::shared_ptr<List_elem<T>>(new List_elem<T>(arg)));
        this->last = std::shared_ptr<List_elem<T>>(this->last->nextShared());
    }
    else
    {
        this->initialElement(arg);
    }

    ++(this->size);
}

// Adds element to the begining of the list
template<typename T>
void List<T>::add(T arg)
{
    ++(this->size);
    if (this->head) 
    {
        this->head = std::shared_ptr<List_elem<T>>(new List_elem<T>(this->head, arg));
    }
    else
    {
        this->initialElement(arg);
    }
}
//
// Removes <pos> element
template<typename T>
void List<T>::remove(unsigned int pos)
{
    // Empty list
    if (!this)
    {
        throw LinkedListElementDoesntExistException(__FUNCTION__, __LINE__, __FILE__);
    }
    
    else if (pos >= this->size)
    {
        throw LinkedListOutOfBoundsException(__FUNCTION__, __LINE__, __FILE__);
    }

    // One element list
    else if (this->getSize() == 1)
    {
        this->clear();
    }

    // Deleting first element
    else if (!pos)
    {
        this->head = this->head->nextShared();
        --(this->size);
    }

    else
    {
        std::shared_ptr<List_elem<T>> prev;
        std::shared_ptr<List_elem<T>> next(this->head);

        while (pos)
        {
            --pos;
            prev = next;
            next = std::shared_ptr<List_elem<T>>(prev->nextShared());
            
        }
        prev->setChild(next->nextShared());
        
        // If we deleted last element
        if (prev == this->last)
        {
            this->last = prev;
        }
        --(this->size);
    }

}

// Inserts new element to position <pos>
template<typename T>
void List<T>::insert(unsigned int pos, T arg)
{
    if (pos >= this->size)
    {
        throw LinkedListOutOfBoundsException(__FUNCTION__, __LINE__, __FILE__);
    }

    // Empty list
    else if (!this)
    {
        this->initialElement(arg);
    }

    else if (pos == 0)
    {
        this->add(arg);
    }

    else if (pos == this->size - 1)
    {
        this->append(arg);
    }

    else
    {
        std::shared_ptr<List_elem<T>> prev;
        std::shared_ptr<List_elem<T>> next(this->head);

        while (pos)
        {
            --pos;
            prev = next;
            next = std::shared_ptr<List_elem<T>>(prev->nextShared());
        }
        std::shared_ptr<List_elem<T>> new_element(new List_elem<T>(arg));
        new_element->setChild(next);
        prev->setChild(new_element);
        ++(this->size);
    }

}

// Returns current list size
size_t BaseList::getSize()
{
    return this->size;
}

template <typename T>
List<T>::~List() // деструктор
{
    if (this->head)
    {
        std::shared_ptr<List_elem<T>> next;
        for (; this->head; this->head = next)
        {
            next = this->head->nextShared();
            head.reset();
        }
    }
    this->head = nullptr;
    this->last = nullptr;
};

template<typename T>
List_elem<T>& List<T>::operator=(const List_elem<T>& a)
{
    delete this->head;
    delete this->last;
    this->size = 0;

    for (auto &i = this->begin(); i != this->end(); i++)
    {
        concatenate(i);
    }
}

template<typename T>
List<T>::operator bool()
{
    return (bool) this->head;
}

template<typename T>
Iter<T> List<T>::begin(void)
{
    return Iter<T>(this->head);
}

template<typename T>
Iter<T> List<T>::end(void)
{
    if (this->last)
    {
        return Iter<T>(this->last->nextShared());
    }
    else
    {
        return this->last;
    }
}

template<typename T>
ConstIter<T> List<T>::begin(void) const
{
    return ConstIter<T>(this->head);
}

template<typename T>
ConstIter<T> List<T>::end(void) const
{
    if (this->last)
    {
        return ConstIter<T>(this->last->nextShared());
    }
    else
    {
        return this->last;
    }
}

template<typename T>
List<T>& List<T>::operator +(const List<T>& a)
{
    List<T> n = List<T>(this);
    n += *this;
    n += a;
    return n;
}


template<typename T>
List<T> List<T>::operator +=(const List<T>& a)
{
    for (auto &i : a)
    {
        this->append(i);
    }
    return *this;
}

template<typename T>
List<T>& List<T>::operator *(const unsigned int a)
{
    List<T> n = List<T>();

    for (int i = 0; i < a; i++)
    {
        n += *this;
    }
    
    return n;
}

template<typename T>
List<T>& List<T>::operator *=(const unsigned int a)
{
    List<T> n = List<T>(this);
    size_t size = this->getSize();

    for (int i = 0; i < size; i++)
    {
        this += n;
    }
    
    return *this;

}

template<typename T>
bool List<T>::operator ==(const List<T>& a)
{
    return this->getSize();
}

template<typename T>
bool List<T>::operator !=(const List<T>& a)
{
    return !this->getSize();
}

template<typename T>
void List<T>::concatenate(const List<T>& a)
{
    for (auto &i : a)
    {
        this->append(i);
    }
}

template<typename T>
List<T>& List<T>::copy(void)
{
    List<T> a;
    for (auto &i = this->begin(); i != this->end(); i++)
    {
        a.append(i);
    }
    return a;
}


template<typename T>
T& List<T>::get_head(void)
{
    return this->head->get();
}

template<typename T>
T& List<T>::get_last(void)
{
    return this->last->get();
}

template<typename T>
T List<T>::pop_head(void)
{
    T a = this->head->get();
    this->remove(0);
    return a;
}

template<typename T>
T List<T>::pop_last(void)
{
    T a = this->last->get();
    this->remove(this->getSize() - 1);
    return a;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, List<T>& lst)
{

    if (lst)
    {
        os << "{";
        for (auto const &i : lst)
        {
            std::cout << i << ", ";
        }
        os << "}\n";
    }
    else 
    {
        os << "Empty list\n";
    }
    return os;
}

