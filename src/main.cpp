#include <stdio.h>

#include "List.h"

int main()
{
    #define RETURN(code) do{                    \
        print_list_error(stderr, code);         \
        list_dtor(&list);                       \
        return code;                            \
    }while(0)

    ListData list = {};
    listErrorCode err = NO_LIST_ERRORS;

    if ((err = list_ctor(&list, 10)))
    {
        RETURN(err);
    }

    ssize_t in = 0;

    if ((err = list_insert_in_tail(&list, 15, &in)))
    {
        RETURN(err);
    }

    if ((err = list_insert_in_tail(&list, 118, &in)))
    {
        RETURN(err);
    }

    printf("index: %ld\n", in);
    printf("data: %d\n",  list.data[in]);

    if ((err = list_insert_in_tail(&list, 10)))
    {
        RETURN(err);
    }

    if ((err = list_remove_by_index(&list, 3)))
    {
        RETURN(err);
    }

    if ((err = list_insert_in_tail(&list, 11)))
    {
        RETURN(err);
    }

    if ((err = list_insert_in_tail(&list, 1)))
    {
        RETURN(err);
    }

    list_dump(&list);

    RETURN(NO_LIST_ERRORS);
    #undef RETURN
}