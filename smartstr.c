#include "smartstr.h"

char** smartstr_split(char *str, char *search, int *length){
    char *p, *q, array[0x100][0x100];
    char **p_res;
    int i, search_size;
    p = strdup(str);
    *length = 0;
    search_size = strlen(search);
    while((q = strstr(p, search)) != NULL){
        *q = '\0';
        strcpy(array[*length], p);
        q += search_size;
        p = q;
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

int smartstr_replace(char *str, char *search, char *replace){
    char **p;
    int length, index;
    p = smartstr_split(str, search, &length);
    SMARTSTR_CLEAR(str);
    for(index = 0; index < length - 1 ; index++){
        SMARTSTR_APPEND(str, *p);
        SMARTSTR_APPEND(str, replace);
        p++;
    }
    SMARTSTR_APPEND(str, *p);
    return length - 1;

}

#ifdef test
int main (){
    char **p;
    int length, index, matched;
    printf("==============================\n");
    SMARTSTR_SET(a, "hello world");
    SMARTSTR_APPEND(a, "!I am dy");
    printf("smartstr:%s\n", a);
    printf("==============================\n");
    printf("smartstr_split:split with \"o\"\n");
    p = smartstr_split (a, "o" , &length);
    for(index = 0; index < length; index++){
        printf("index%d:%s\n", index, *p);
        p++;
    }
    printf("==============================\n");
    printf("smartstr_replace:replace \"hello\" with \"lol\"\n");
    matched = smartstr_replace(a, "hello", "lol");
    printf("new string:\"%s\"\nmatche:%d \n", a, matched);
    printf("==============================\n");
    SMARTSTR_FREE(a);
    return 0;
}
#endif

