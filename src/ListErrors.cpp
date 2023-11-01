/**
 * @file
 * @brief List error handling functions sources
*/
#include <stdio.h>

#include <Color_output.h>
#include "ListErrors.h"

void print_list_error(FILE* stream, listErrorCode error)
{
    print_list_error_message(stream, error);
}

void print_list_error_message(FILE* stream, listErrorCode error)
{
    color_fprintf(stream, COLOR_RED, STYLE_BOLD, "List error: ");

    #define CHECK_CODE(code, message)               \
        case code:                                  \
            fprintf(stream, message);               \
            break;                                  \

    switch (error)
    {
    case NO_LIST_ERRORS:
        break;
    

    default:
        fprintf(stream, "Unknown error!\n");
        break;
    }

    #undef CHECK_CODE
}