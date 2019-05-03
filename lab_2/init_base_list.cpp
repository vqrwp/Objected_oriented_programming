//
// Created by Margo on 26.04.2019.
//

#include <iostream>
#include "init_base_list.h"

baseList::baseList()
        : element_count(0) {}

baseList::~baseList()
{
    this->element_count = 0;
}

bool baseList::is_empty() const
{
    return element_count == 0;
}

size_t baseList::size_l() const
{
    return element_count;
}