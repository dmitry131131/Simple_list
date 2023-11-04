/**
 * @file
 * @brief Sources of methods allows append and delete operations with list
*/
#include <stdio.h>
#include <assert.h>

#include "List.h"

listErrorCode list_insert_in_tail(ListData* list, elem_t element, ssize_t* index)
{
    assert(list);
    listErrorCode error = NO_LIST_ERRORS;

    if ((error = list_verify(list)))
    {
        return error;
    }

    ssize_t tempIndex = 0;
    ssize_t tempNext  = 0;

    tempIndex = list->free;
    tempNext  = list->next[list->free];

    list->data[list->free] = element;
    list->next[list->free] = list->head;
    list->prev[list->free] = list->tail;

    list->next[list->tail] = list->free;
    
    list->free = tempNext;
    list->tail = tempIndex;
    list->len++;

    if (index) *index = tempIndex;

    return error;
}

listErrorCode list_insert_by_index(ListData* list, elem_t element, ssize_t index, ssize_t* retIndex)
{
    assert(list);
    listErrorCode error = NO_LIST_ERRORS;

    if ((error = list_verify(list)))
    {
        return error;
    }

    if (index > ((ssize_t) list->len) || (list->prev[index] == -1))
    {
        return BAD_INDEX;
    }

    ssize_t tempFree = 0;
    ssize_t tempNext = 0;
    ssize_t newFree  = 0;

    tempFree = list->free;
    tempNext = list->next[index];
    newFree  = list->next[tempFree];

    list->data[list->free] = element;
    list->next[list->free] = tempNext;
    list->prev[list->free] = index;

    list->next[index]    = tempFree;
    list->prev[tempNext] = tempFree;

    if (retIndex) *retIndex = tempFree;

    list->free = newFree;
    list->len++;

    return error;
}

listErrorCode list_remove_by_index(ListData* list, ssize_t index)
{
    assert(list);
    listErrorCode error = NO_LIST_ERRORS;

    if ((error = list_verify(list)))
    {
        return error;
    }

    if (index > ((ssize_t) list->len) || (list->prev[index] == -1))
    {
        return BAD_INDEX;
    }

    ssize_t tempFree = list->free;
    ssize_t tempNext = list->next[index];
    ssize_t tempPrev = list->prev[index];

    list->data[index] = __INT_MAX__;
    list->prev[index] = -1;
    list->next[index] = tempFree;

    list->next[tempPrev] = tempNext;
    list->prev[tempNext] = tempPrev;

    list->free = index;
    list->len--;

    return error;
}

// TODO make remove element function