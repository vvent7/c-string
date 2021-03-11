#include <stdio.h>
#include "cstring.h"

void printString(const String *str){
  if(str!=NULL)
    printf("{%s} // Size: %lu, Capacity: %lu\n", *str, string_size(str), string_capacity(str));
}

int main(){
  String *s1 = string_new_copy_cfg("Hello World!", CSTRING_TP_ARR, CSTRING_CAPMAN_EQUAL_SIZE, 0);

  printf("==========Auto-Shrink off==========\n");
  printString(s1);
  string_n_erase(s1, 5, 6); printString(s1);

  string_n_append(s1, " Testing Str", 8, CSTRING_TP_ARR); 
  string_append_c(s1, '.'); printString(s1);

  string_n_erase(s1, 0, 7); printString(s1);

  printf("\n\n==========Auto-Shrink on==========\n");
  string_set_auto_shrink(s1, 1); printString(s1);
  string_append(s1, *s1, CSTRING_TP_STRING);
  string_insert_c(s1, string_size(s1)/2,' '); printString(s1);

  string_erase(s1, string_size(s1)-1); printString(s1);
  string_append(s1, " String!", CSTRING_TP_ARR); printString(s1);
  
  string_clear(s1); printString(s1);

  string_free(s1);

  return 0;
}