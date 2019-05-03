//
// Created by Margo on 14.04.2019.
//

#ifndef LAB_2_LIST_H
#define LAB_2_LIST_H

#include <iostream>
#include "init_list.h"
#include "memory.h"
#include <ctime>

//using namespace std;

template <typename T>
List<T>::List() // инициализация списка
{
    this->head = nullptr;
    this->tail = nullptr;
};

template<typename T>
List<T>::List(List<T>&& list)
{
    head = list.head;
    tail = list.tail;
    list.head = nullptr;
    list.tail = nullptr;
}

template <typename T>
List<T>::~List() // деструктор
{
    if (this->head)
    {
        std::shared_ptr<List_elem<T>> next;
        for (; this->head; this->head = next)
        {
            next = this->head->next;
            head.reset();
        }
    }
    this->head = nullptr;
    this->tail = nullptr;
};

template <typename T>
List<T>::List(T data)
{
    int n = 1;
    time_t t_time = time(NULL);
    std::shared_ptr<List_elem<T>> sp(new List_elem<T>);
    head = sp;
    if (!head)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    head.get()->data = data;  //head->set(data);
    this->head = head;
    std::shared_ptr<List_elem<T>> item(new List_elem<T>);
    if (!item)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    head->next = item;
    tail = item;
    tail.get()->data = data;
};

template <typename T>
List<T>::List(T *arr, int n)
{
    time_t t_time = time(NULL);
    if (arr == nullptr || n == 0)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        std::shared_ptr<List_elem<T>> new_head(new List_elem<T>);

        if (!new_head)
            throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

        head = new_head;
        this->head->data = arr[0];
        std::shared_ptr<List_elem<T>> c(head);

        for (size_t i = 1; i < n; i++)
        {
            std::shared_ptr<List_elem<T>> item(new List_elem<T>);

            if (!item)
                throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

            item->data = arr[i];
            c->next = item;
            c = item;
        }
        this->tail = c;
    }
};

template <typename T>
List<T>::List(std::initializer_list<T> list)
{
    time_t t_time = time(NULL);
    if (list.size() == 0)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        std::shared_ptr <List_elem<T>> head(new List_elem<T>);

        if (!head)
            throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

        auto elem = list.begin();

        this->head = head;
        this->head.get()->data = *elem++;
        std::shared_ptr <List_elem<T>> c(head);

        for (auto i = 1; i < list.size(); elem++, i++)
        {
            std::shared_ptr<List_elem<T>> item(new List_elem<T>);

            if (!item)
                throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

            item->set_data(*elem);
            c->next = item;
            c = item;
        }
        this->tail = c;
    }
}

template <typename T>
List<T>::List(const List<T> &list)
{
    time_t t_time = time(NULL);
    if (list.head == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        std::shared_ptr<List_elem<T>> c;
        std::shared_ptr<List_elem<T>> sp(new List_elem<T>);
        head = sp;

        if (!head)
            throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

        List_iterator <T> iter(*this);
        head.get()->data = list.head.get()->data;
        this->head = head;
        std::shared_ptr<List_elem<T>> tmp(head);
        c = list.head->next;

        for (; c; c = c.get()->next)
        {
            std::shared_ptr<List_elem<T>> item(new List_elem<T>);

            if (!item)
                throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

            tmp->next = item;
            item->data = c->data;
            this->tail = item;
            tmp = tmp->next;
        }
    }
};

/*
template <typename T>
void List<T>::insert_by_ind(const size_t ind, const T &value)
{
    time_t t_time = time(NULL);
    if (ind == 0)
    {
        std::shared_ptr<List_elem<T>> item(new List_elem<T>);

        if (!item)
            throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

        item->data = value;
        item->next = this->head;
        this->head = item;

    }
    else
    {
        List_iterator<float> iter(*this);
        for (int i = 0; i < ind - 1; i++, iter.next())
            ;

        std::shared_ptr<List_elem<T>> find(iter.current);
        std::shared_ptr<List_elem<T>> item(new List_elem<T>);

        if (!item)
            throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

        item->data = value;
        item->next = find->next;
        find->next = item;

        if (find->next == this->tail)
            this->tail = item;
    }
};
 */

template <typename T>
void List<T>::add_to_head(const T &data)
{
    time_t t_time = time(NULL);
    std::shared_ptr<List_elem<T>> item(new List_elem<T>);
    if (!item)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    item->data = data;
    item->next = this->head;
    this->head = item;
};

template <typename T>
void List<T>::add_to_tail(const T &data)
{
    time_t t_time = time(NULL);
    std::shared_ptr<List_elem<T>> item(new List_elem<T>);
    if (!item)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    item->data = data;
    this->tail->next = item;
    this->tail = item;
};

template<typename T>
const T& List<T>::get_head() const
{
    if (head != nullptr)
        return head->get_data();
}

template <typename T>
T &List<T>::get_from_head()
{
    time_t t_time = time(NULL);
    if (empty())
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    T data = head->get_data();
    std::shared_ptr<List_elem<T>> tmp(this->head);
    this->head = this->head->next;
    return data;
};

template <typename T>
T &List<T>::get_from_tail()
{
    time_t t_time = time(NULL);
    T data;
    if (this->empty())
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    if (this->size() == 1)
    {
        data = this->head->data;
        std::shared_ptr<List_elem<T>> tmp(this->tail);
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        std::shared_ptr<List_elem<T>> tmp(this->tail);
        std::shared_ptr<List_elem<T>> c(this->head);
        for (; c->next != tmp; c = c->next); // доходим до конца списка
        data = this->tail->data;
        this->tail = c;
        this->tail->next = nullptr;
    }
    return data;
};

/*
template <typename T>
void List<T>::delete_by_ind(size_t index)
{
    time_t t_time = time(NULL);
    if (empty())
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    if (index < 0 || index >= size())
    {
        throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    if (index == 0)
    {
        get_from_head();
        return;
    }

    index--;
    std::shared_ptr<List_elem<T>> c(this->head);
    std::shared_ptr<List_elem<T>> tmp;
    if (size() == 1)
    {
        std::shared_ptr<List_elem<T>> elem(this->tail);
        this->head = nullptr;
        this->tail = nullptr;
    } else
        {
        int i = 0;
        while (i < index && c->next)
        {
            c = c->next;
            i++;
        }
        tmp = c->next;
        c->next = c->next->next;

        if (this->size() - 1 == index) // если искомый элемент последний
        {
            tmp = this->tail;
            this->tail = c;
            this->tail->next = nullptr;
        }
    }
}

template <typename T>
void List<T>::delete_elem(const T &data)
{
    time_t t_time = time(NULL);
    int flag = 0;
    if (empty())
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<List_elem<T>> c(this->head);
    std::shared_ptr<List_elem<T>> tmp;
    if (size() == 1)
    {
        std::shared_ptr<List_elem<T>> elem(this->tail);
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        int i = 0;
        while (i < this->size() && c->next)
        {
            if (c->next->data == data)
            {
                flag = 1;
                tmp = c->next;
                c->next = c->next->next;
            }
            else
                c = c->next;
            i++;
        }
        if (this->head->data == data) // если искомый элемент первый
            get_from_head();
        else if (this->tail->data == data) // если искомый элемент последний
        {
            tmp = this->tail;
            this->tail = c;
            this->tail->next = nullptr;
        }
        if (flag == 0) // если искомого элемента не найдено
        {
            throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }
};
*/
/*
// size == 1 работает
template <typename T>
void List<T>::reverse()
{
    if (empty())
        throw empty_list();
    if (size() != 1)
    {
        List_elem<T> *prev = this->head;
        List_elem<T> *c = prev->next;
        List_elem<T> *next;
        prev->next = nullptr;
        do
        {
            next = c->next;
            c->next = prev;
            prev = c;
            c = next;
        } while (c);
        this->head = prev;
    }
};
*/

// 1 return
template <typename T>
std::shared_ptr<List_elem <T>> List<T>::del(const List_elem<T> &elem)
{
    time_t t_time = time(NULL);
    if (!this->head)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    std::shared_ptr<List_elem <T>> find(this->search(elem));
    std::shared_ptr<List_elem <T>> c(this->head);
    if (c->data == elem.data)
    {
        this->head = this->head->next;
        //return c;
    }
    else
    {
        for (; c && c->next != find; c = c->next);
        if (c != nullptr)
        {
            // return nullptr;
            c->next = find->next;

            if (find == this->tail)
            {
                std::shared_ptr<List_elem <T>> tmp(this->head);
                for (; tmp->next; tmp = tmp->next);
                this->tail = tmp;
            }
        }
    }
    c = find;
    return c;//find;
};

template <typename T>
std::shared_ptr<List_elem <T>> List<T>::search(const List_elem<T> &elem) const // найти элемент в списке по значению
{
    time_t t_time = time(NULL);
    if (!this->head)
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<List_elem <T>> c(this->head);
    while (c && c->data != elem.data)
        c = c->next;
    if (!c)
        throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return c;
};

template <typename T>
size_t List<T>::size() const
{
    std::shared_ptr<List_elem<T>> c(this->head);
    size_t count = 0;
    List_iterator <T> iter(*this);
    //for (; c; c = c->next)
    for (; iter; iter++)
    {
        count++;
    }
    return count;
}

template <typename T>
int comp_inc(const void *a, const void *b)
{
    return (*(T*)a - *(T*)b);
}

template <typename T>
int comp_dec(const void *a, const void *b)
{
    return (*(T*)b - *(T*)a);
}

template <typename T>
T* List<T>::to_array() const
{
    time_t t_time = time(NULL);
    T* arr = new T[this->size()];
    if (!arr)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr <List_elem <T>> tmp(this->head);
    for (size_t i  = 0;  i < this->size(); i++)
    {
        arr[i] = tmp->get_data();
        tmp = tmp->next;
    }

    return arr;
}

/*
template <typename T>
void List<T>::sort(bool increase)
{
    T* arr = this->to_array();
    if (increase)
        qsort(arr, this->size(), sizeof(T), comp_inc<T>);
    else
        qsort(arr, this->size(), sizeof(T), comp_dec<T>);

    std::shared_ptr <List_elem <T>> tmp(this->head);
    size_t i = 0;
    for (; tmp ; tmp = tmp->next)
    {
        tmp->set_data(arr[i]);
        this->tail = tmp;
        i++;
    }

    delete [] arr;
}
 */

template <typename T>
void List<T>::clear()
{
    std::shared_ptr<List_elem <T>> c(this->head);
    std::shared_ptr<List_elem <T>> tmp;// = this->head;
    while(c)
    {
        tmp = c->next;
        c = tmp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
bool List<T>::empty() const
{
    return (this->head == nullptr);
};

// копирование
template <typename T>
List<T> &List<T>::operator=(const List<T> &list)
{
    time_t t_time = time(NULL);
    if (this->size() <= list.size())
    {
        std::shared_ptr<List_elem<T>> clist(list.head);
        std::shared_ptr<List_elem<T>> cthis(this->head);
        for (; cthis; cthis = cthis->next)
        {
            cthis->data = clist->data;
            clist = clist->next;
        }
        int count = list.size() - this->size();
        while(count)
        {
            std::shared_ptr<List_elem<T>> tmp(new List_elem<T>);

            if (!tmp)
                throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

            tmp->data = clist->data;
            this->tail->next = tmp;
            this->tail = tmp;
            cthis = tmp;
            cthis = cthis->next;
            clist = clist->next;
            count--;
        }

    }
    else
    {
        std::shared_ptr<List_elem<T>> clist(list.head);
        std::shared_ptr<List_elem<T>> cthis(this->head);
        for (;cthis; cthis = cthis->next)
        {
            if (clist)
            {
                cthis->data = clist->data;
                this->tail = clist;
                clist = clist->next;
            }
            else
                this->del(*cthis);
        }
    }
    return (*this);
};

template <typename T>
List<T> &List<T>::operator =(List<T> &&list)
{
    this->head = list.head;
    this->tail = list.tail;

    list.head = nullptr;
    list.tail = nullptr;
    return (*this);
}

template <typename T>
bool List<T>::operator ==(const List<T> &list) const
{
    std::shared_ptr<List_elem<T>> cthis(this->head);
    std::shared_ptr<List_elem<T>> clist(list.head);
    while(cthis && clist && cthis->data == clist->data)
    {
        cthis = cthis->next;
        clist = clist->next;
    }
    return (cthis == nullptr && clist == nullptr);
};

template <typename T>
bool List<T>::equal(const List<T> &list) const
{
    std::shared_ptr<List_elem<T>> cthis(this->head);
    std::shared_ptr<List_elem<T>> clist(list.head);
    while(cthis && clist && cthis->data == clist->data)
    {
        cthis = cthis->next;
        clist = clist->next;
    }
    return (cthis == nullptr && clist == nullptr);
};

template <typename T>
bool List<T>::operator !=(const List<T> &list) const
{
    return !(*this == list);
};

template <typename T>
std::ostream &operator << (std::ostream &st, List<T> &l)
{
    st << "List: ";
    //List_iterator<T> iter(l);
    if (!iter.range())
        st << "Пустой";
    else
    {
        for (iter.first(); iter.range(); iter++)
            st << iter.cur() << " ";
    }
    return st;
};

template <typename T>
void List<T>::merge(const List<T> & list)
{
    std::shared_ptr<List_elem<T>> head2(list.head);
    std::shared_ptr<List_elem<T>> tail2(list.tail);
    while (head2 != tail2)
    {
        this->add_to_tail(head2->get_data());
        head2 = head2->get_next();
    }
    this->add_to_tail(head2->get_data());
}

template <typename T>
List<T> &List<T>::operator +(const List<T> &list)
{
    std::shared_ptr<List_elem<T>> head2(list.head);
    std::shared_ptr<List_elem<T>> tail2(list.tail);
    while (head2 != tail2)
    {
        this->add_to_tail(head2->get_data());
        head2 = head2->get_next();
    }
    this->add_to_tail(head2->get_data());
    return (*this);
}


#endif //LAB_2_LIST_H
