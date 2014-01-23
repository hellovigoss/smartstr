smartstr
========

a smart string lib for c

usage
========
* step 1 
load ```<smartstr.h>``` 
* step 2
use it with macros & methods

macros 
=======
```SMARTSTR_SET(str, src)```init your str with src 

```SMARTSTR_APPEND(str, src)```append your str with src 

```SMARTSTR_FREE(str)```free your smart str 

methods
=======
```c
char** smartstr_split(char *str, char *search, int *length);
``` 
split the smart string with string search
you can get the count of result and the result point to char *  
```c
int smartstr_replace(char *str, char *search, char *replace);
```
search `str` for `search`, and replace it with `replace` 
you can get the match count from return intval

about 
=======
author: hellovigoss`<hellovigoss#gmail.com>`
