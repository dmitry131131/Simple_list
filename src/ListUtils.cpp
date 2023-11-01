/**
 * @file 
 * @brief Sources of List utils functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

listErrorCode list_verify(ListData* list)
{
    assert(list);
    if (!list->data || !list->next || !list->prev)
    {
        return NULL_PTR_IN_LIST;
    }

    for (size_t i = 1; i < list->len - 1; i++)
    {
        if ((list->data)[((list->next)[i])] != (list->data)[((list->prev)[i+1])])
        {
            return LIST_LINK_ERROR;
        }
    }

    if ((list->prev)[list->free] != -1)
    {
        return FREE_PTR_ERROR;
    }

    return NO_LIST_ERRORS;
}

listErrorCode list_ctor(ListData* list, size_t capacity)
{
    assert(list);
    if (capacity < 0)
    {
        return WRONG_LEN;
    }

    list->capacity = capacity;

    list->data = (elem_t*)  calloc(sizeof(elem_t),  capacity);
    list->next = (ssize_t*) calloc(sizeof(ssize_t), capacity);
    list->prev = (ssize_t*) calloc(sizeof(ssize_t), capacity);

    if (!list->data || !list->next || !list->prev)
    {
        return CALLOC_ERROR;
    }

    for (size_t i = 1; i < capacity; i++)
    {
        list->next[i] = i + 1;
    }

    for (size_t i = 1; i < capacity; i++)
    {
        list->prev[i] = -1;
    }

    list->head = 0;
    list->tail = 0;
    list->len  = 0;

    list->free = 1;

    return NO_LIST_ERRORS;
}

listErrorCode list_dtor(ListData* list)
{  
    assert(list);

    free(list->data);
    free(list->next);
    free(list->prev);

    list->head      = -1;
    list->tail      = -1;
    list->free      = -1;
    list->len       = -1;
    list->capacity  = -1;

    return NO_LIST_ERRORS;
}

listErrorCode list_dump(ListData* list)
{
    assert(list);

    return NO_LIST_ERRORS;
}