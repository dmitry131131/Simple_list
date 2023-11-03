/**
 * @file
 * @brief Methods of list allows append and delete operations with list
*/
#ifndef LIST_METHODS_H
#define LIST_METHODS_H

listErrorCode list_insert_in_tail(ListData* list, elem_t element, ssize_t* index = NULL);

listErrorCode list_insert_by_index(ListData* list, elem_t element, ssize_t index, ssize_t* retIndex);

listErrorCode list_remove_by_index(ListData* list, ssize_t index);

#endif