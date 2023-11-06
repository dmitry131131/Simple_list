/**
 * @file 
 * @brief Sources of List utils functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"
#include "DataBuffer.h"
#include "ListLog.h"

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

    for (size_t i = 1; i < capacity - 1; i++)
    {
        list->next[i] = (ssize_t) i + 1;
    }
    list->next[capacity - 1] = 0;

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

    outputBuffer buffer = {};

    buffer_ctor(&buffer, list->capacity * 1000);

    FILE* file = NULL;
    if (create_output_file(&file, "list_test.dot", TEXT))
    {
        printf("Create error!\n");
    }

    if (write_dot_header(&buffer))
    {
        printf("header error!\n");
    }

    if (write_dot_body(&buffer, list))
    {
        printf("body error!\n");
    }

    write_dot_footer(&buffer, list);

    printf("%lu\n", buffer.bufferPointer);

    write_buffer_to_file(file, &buffer);

    buffer_dtor(&buffer);

    return NO_LIST_ERRORS;
}