#include <stdio.h>
#include "cstring.h"

void printString(const String str){
  if(str!=NULL){
    StringData *sd = string_data(str);
    printf("{%s} // Size: %lu, Capacity: %lu\n", str, sd->sz, sd->cap);
  }
}

int main(){
  String *s1 = string_ptr_new();

  printf("==========Auto-Shrink off==========\n");
  printString(*s1);
  string_append(s1, "Testing New String", CSTRING_ARR_TYPE); printString(*s1);
  string_n_insert(s1, 0, string_begin(*s1)+8, 4); printString(*s1);
  string_n_erase(s1, 3, 12); string_append_c(s1, '!'); printString(*s1);

  string_set_auto_shrink(s1, 1);
  printf("\n\n==========Auto-Shrink on==========\n");
  printString(*s1);
  string_append(s1, *s1, CSTRING_STRING_TYPE); printString(*s1);
  string_clear(s1); printString(*s1);

  string_ptr_free(s1);

  return 0;
}