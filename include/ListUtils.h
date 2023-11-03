/**
 * @file
 * @brief Utils functions 
*/
#ifndef LIST_UTILS_H
#define LIST_UTILS_H

listErrorCode list_verify(ListData* list);

listErrorCode list_ctor(ListData* list, size_t capacity);

listErrorCode list_dtor(ListData* list);

listErrorCode list_dump(ListData* list);


#endif