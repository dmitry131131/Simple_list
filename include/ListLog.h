/**
 * @file
 * @brief List logs functions
*/
#ifndef LIST_LOG_H
#define LIST_LOG_H

listErrorCode write_dot_header(outputBuffer* buffer);

listErrorCode write_dot_body(outputBuffer* buffer, ListData* list);

listErrorCode write_dot_footer(outputBuffer* buffer, ListData* list);

#endif