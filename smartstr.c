#include "smartstr.h"

char** smartstr_split(char *str, char *search, int *length){
    char *p, *q, array[0x100][0x100];
    char **p_res;
    int i;
    p = str;
    *length = 0;
    while((q = strstr(p, search)) != NULL){
        *q = '\0';
        strcpy(array[*length], p);
        p = ++q;
        (*length)++;
    }
    strcpy(array[*length], p);
    (*length)++;

    char **res = (char **)malloc(sizeof(char*) * (*length));
    p_res = res;

    for(i = 0; i < *length; i ++){
        char *temp = (char *)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(temp, array[i]);
        *res = temp;
        res++;
    }

    return p_res;
}

#ifdef test
int main (){
    char **p;
    int length, index;
    SMARTSTR_SET(a, "hello world");
    SMARTSTR_APPEND(a, "!I am sanjin");
    p = smartstr_split (a, "o" , &length);
    for(index = 0; index < length; index++){
        printf("%s\n",  *p, length);
        p++;
    }
    SMARTSTR_FREE(a);
    return 0;
}
#endif

