#include <stdio.h>
#include "cstring.h"

void printString(const String *str){
  if(str!=NULL)
    printf("{%s} // Size: %lu, Capacity: %lu\n", *str, string_size(str), string_capacity(str));
}

int main(){
  String *s1 = string_new_copy_cfg("Hello World!", CSTRING_TP_ARR, CSTR_CAPMAN_LOG, 0);
  size_t i;

  printf("==========Auto-Shrink off==========\n");
  printString(s1);
  string_erase_n(s1, 5, 6); printString(s1);

  string_append_n(s1, " Testing Str", 8);
  string_append_one(s1, '.'); printString(s1);

  string_erase_n(s1, 0, 7); printString(s1);

  printf("\n\n==========Auto-Shrink on / Equal Size==========\n");
  string_set_auto_shrink(s1, 1); string_set_cap_man(s1, CSTR_CAPMAN_EQ_SZ); printString(s1);
  string_append_all(s1, *s1, CSTRING_TP_STRING);
  string_insert_all(s1, i = string_size(s1)/2," -=- ", CSTRING_TP_ARR);
  printString(s1);

  string_erase(s1, string_size(s1)-1); string_erase_n(s1, i+1, 4); printString(s1);
  string_append_all(s1, " String!", CSTRING_TP_ARR); printString(s1);
  
  string_clear(s1); printString(s1);

  string_free(s1);

  return 0;
}