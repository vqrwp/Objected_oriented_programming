//
// Created by Margo on 26.04.2019.
//

#ifndef LAB_2_INIT_BASE_LIST_H
#define LAB_2_INIT_BASE_LIST_H

#include <iostream>

class baseList
{
        public:
            explicit baseList();

            virtual ~baseList();

            bool is_empty() const;

            size_t size_l() const;

        protected:
            size_t element_count;
};

#endif //LAB_2_INIT_BASE_LIST_H
