/**
 * @file
 * @brief Functions and objects for list errors handling
*/
#ifndef LIST_ERRORS_H
#define LIST_ERRORS_H

enum listErrorCode {
    NO_LIST_ERRORS,
    NULL_PTR_IN_LIST,
    LIST_LINK_ERROR,
    FREE_PTR_ERROR,
    WRONG_LEN,
    CALLOC_ERROR,
    BAD_INDEX

};

void print_list_error(FILE* stream, listErrorCode error);

void print_list_error_message(FILE* stream, listErrorCode error);

#endif