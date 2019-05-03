#ifndef __LINKED_LIST_EXCEPTIONS__
#define __LINKED_LIST_EXCEPTIONS__

#include <time.h>

class LinkedListException : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Linked List error";
    }

    LinkedListException(const char *function_name, 
                        int line_number,
                        const char *file_name)
    {
        when = time(NULL);
        this->function_name = function_name;
        this->line_number = line_number;
        this->file_name = file_name;
    }

    time_t when;
    const char *function_name;
    int line_number;
    const char *file_name;
};

class LinkedListOutOfBoundsException : public LinkedListException
{
public:
    LinkedListOutOfBoundsException(const char *a, int b, const char *c) : LinkedListException(a, b, c) {};
    const char* what() const noexcept
    {
        return "Out of bounds exception";
    }

};

class LinkedListElementDoesntExistException : public LinkedListException
{
public:
    LinkedListElementDoesntExistException(const char *a, int b, const char *c) : LinkedListException(a, b, c) {};
    const char* what() const noexcept
    {
        return "Element doesn't exist";
    }
};

#endif
