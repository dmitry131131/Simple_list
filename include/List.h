/**
 * @file
 * @brief Objects and main functions for list
*/
#ifndef LIST_H
#define LIST_H

typedef int elem_t;

#include "ListErrors.h"

struct ListData {
    elem_t* data;
    ssize_t* next;
    ssize_t* prev;

    ssize_t head;
    ssize_t tail;

    ssize_t free; 

    size_t capacity;
    size_t len;
};

#endif