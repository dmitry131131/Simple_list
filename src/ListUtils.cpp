/**
 * @file 
 * @brief Sources of List utils functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

// TODO Make every element verify
listErrorCode list_verify(ListData* list)
{
    assert(list);
    if (!list->data || !list->next || !list->prev)
    {
        return NULL_PTR_IN_LIST;
    }

    elem_t key = list->data[0];
    ssize_t adress = 0;

    for (size_t _ = 0; _ < list->len - 1; _++)
    {
        adress = list->next[adress];
        //printf("%ld\n", adress);
    }
    for (size_t _ = 0; _ < list->len - 1; _++)
    {
        adress = list->prev[adress];
       // printf("%ld\n", adress);
    }
    if (key != list->data[adress])
    {
        return LIST_LINK_ERROR;
    }

    adress = list->free;
    for (size_t _ = 0; _ < (list->capacity - list->len); _++)
    {
        if ((list->prev)[adress] != -1)
        {
            return FREE_PTR_ERROR;
        }
        adress = list->next[adress];
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

    list->data = (elem_t*)  calloc(sizeof(elem_t),  capacity + 1);
    list->next = (ssize_t*) calloc(sizeof(ssize_t), capacity + 1);
    list->prev = (ssize_t*) calloc(sizeof(ssize_t), capacity + 1);

    if (!list->data || !list->next || !list->prev)
    {
        return CALLOC_ERROR;
    }

    list->data[0] = __INT_MAX__;
    list->next[0] = 1;
    list->prev[0] = 0;

    for (size_t i = 1; i < capacity; i++)
    {
        list->next[i] = (ssize_t) i + 1;
    }

    for (size_t i = 1; i < capacity; i++)
    {
        list->prev[i] = -1;
    }

    list->head = 0;
    list->tail = 0;
    list->len  = 1;

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
    list->len       = 0;
    list->capacity  = 0;

    return NO_LIST_ERRORS;
}

listErrorCode list_dump(ListData* list)
{
    assert(list);

    printf("Free: %ld\n", list->free);
    printf("Head: %ld\n", list->head);
    printf("Tail: %ld\n", list->tail);

    return NO_LIST_ERRORS;
}