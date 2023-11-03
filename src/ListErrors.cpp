/**
 * @file
 * @brief List error handling functions sources
*/
#include <stdio.h>

#include "Color_output.h"
#include "ListErrors.h"

void print_list_error(FILE* stream, listErrorCode error)
{
    print_list_error_message(stream, error);
}

void print_list_error_message(FILE* stream, listErrorCode error)
{
    #define CHECK_CODE(code, message)                                               \
        case code:                                                                  \
            color_fprintf(stream, COLOR_RED, STYLE_BOLD, "List error: ");           \
            fprintf(stream, message);                                               \
            break;                                                                  \

    switch (error)
    {
    case NO_LIST_ERRORS:
        break;

    CHECK_CODE(NULL_PTR_IN_LIST,   "Null pointer in list arrays!\n");
    CHECK_CODE(LIST_LINK_ERROR,    "List prev don't match with list next!\n");
    CHECK_CODE(FREE_PTR_ERROR,     "Free object doesn't free(prev value isn't -1)!\n");
    CHECK_CODE(WRONG_LEN,          "Wrong len of list!\n");
    CHECK_CODE(CALLOC_ERROR,       "Calloc error in alloc memory for list!\n");
    CHECK_CODE(BAD_INDEX,          "Wrong index(out of len or element with this indext doesn't exist)!\n");
    
    

    default:
        fprintf(stream, "Unknown error!\n");
        break;
    }

    #undef CHECK_CODE
}