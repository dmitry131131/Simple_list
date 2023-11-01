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
    long long int* next;
    long long int* prev;

    long long int head;
    long long int tail;

    long long int free; 
};

#endif