/*
 * SMARTSTR
 * this is a lib for string
 *
 * you can have a smarter String Manipulation
 * @author hellovigoss<hellovigoss@gmail.com>
 * @since 2014-01-22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SMARTSTR_SET(str, src)   \
    char *str = (char *)malloc(sizeof(char) * (strlen(src) + 1));   \
    memset(str, 0, sizeof(char) * (strlen(src) + 1));   \
    strcpy(str, src);

#define SMARTSTR_APPEND(str, src)  \
    str = (char *)realloc(str, sizeof(char) * (strlen(str) + strlen(src) + 1)); \
    memset(str + strlen(str), 0, strlen(src) + 1); \
    strcpy(str + strlen(str), src);

#define SMARTSTR_CLEAR(str) do{ \
    memset(str, 0, strlen(str));    \
}while(0);

#define SMARTSTR_FREE(str)  do{ \
    free(str);  \
}while(0);

char** smartstr_split(char *str, char *search, int *length);

char *smartstr_replace(char *str, char *search, char *replace, int *matched);

