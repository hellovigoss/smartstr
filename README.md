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

```SMARTSTR_CLEAR(str)```set your str to empty 

```SMARTSTR_FREE(str)```free your smart str 

methods
=======
```c
char** smartstr_split(char *str, char *search, int *length);
``` 
split the `str` with `search`
you can get the count of result `length` and the result point to char *  
```c
char *smartstr_replace(char *str, char *search, char *replace, int *matched);
```
search `str` for `search`, and replace it with `replace` 
you can get the new string from return charval and get the matched count by the 4th argument

about 
=======
author: hellovigoss`<hellovigoss#gmail.com>`
