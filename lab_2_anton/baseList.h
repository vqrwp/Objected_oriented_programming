//
// Created by Margo on 29.04.2019.
//

#ifndef LAB_2_SPISOK_BASELIST_H
#define LAB_2_SPISOK_BASELIST_H

#include <iostream>

#include "_elem.h"
#include "errors.h"
#include "_iterator.h"

class BaseList
{
public:
    virtual operator bool() = 0;
    virtual ~BaseList() = 0;
    virtual void clear() = 0;
    virtual void remove(unsigned int pos) = 0;
    size_t getSize();

protected:
    size_t size;
};

#endif //LAB_2_SPISOK_BASELIST_H
