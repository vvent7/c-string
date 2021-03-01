#include<stdlib.h>
#include "cstring.h"

unsigned short string_valid(String str){
  return (str!=NULL && (*str)!=NULL);
}

StringData* string_data(String str){
  return string_valid(str) ? ((StringData*)(*str))-1 : NULL;
}

String string_new_cfg(unsigned short auto_shrink){
  StringData *sd = (StringData*) malloc(sizeof(StringData) + sizeof(char));
  String str = (String) malloc(sizeof(char*));

  sd->sz = sd->cap = 0; sd->auto_shrink = auto_shrink ? 1 : 0;
  (*str)[0] = '\0';

  return str;
}

char* string_begin(String str){
  return (*str);
}

char* string_end(String str){
  return string_valid(str) ? (*str)+(string_data(str))->sz : NULL;
}

size_t string_size(String str){
  StringData *sd = string_data(str);
  return sd ? sd->sz : (size_t)0;
}

size_t string_capacity(String str){
  StringData *sd = string_data(str);
  return sd ? sd->cap : (size_t)0;
}

unsigned short string_empty(String str){
  return (string_size(str)==0);
}

char* string_set_size(String str, size_t new_size){
  StringData *sd = string_data(str);

  if(sd==NULL) return NULL;

  new_size = MIN(new_size, string_npos-1);
  
  if(new_size!=sd->sz){
    if(new_size > sd->cap){
      size_t new_cap = MAX(sd->cap, 1);
      while(new_size > new_cap) new_cap *= _STRING_GROWTH_FACTOR;
      sd = ((StringData*) string_set_capacity(str, new_cap)) - 1;
      sd->sz = new_size;
    }
    sd->sz = new_size; str[new_size] = '\0';
    if(new_size < sd->cap && sd->auto_shrink)
      sd = ((StringData*) string_shrink_to_fit(str)) - 1;
  }

  return (char*) (sd+1);
}

char* string_set_capacity(String str, size_t new_cap){
  StringData *sd = string_data(str);

  if(sd==NULL) return NULL;

  new_cap = MIN(new_cap, string_npos-1);

  if(new_cap!=sd->cap){
    sd = realloc(sd, sizeof(StringData) + sizeof(char) * (new_cap + 1));
    sd->cap = new_cap; sd->sz = MIN(sd->cap, sd->sz);
    (*str) = (String) (sd+1);
    (*str)[new_cap] = '\0';
  }

  return (char*) (sd+1);
}

char* string_shrink_to_fit(String str){
  StringData *sd = string_data(str);

  if(sd==NULL) return NULL;

  size_t new_cap = sd->cap;
  while(sd->sz < new_cap) new_cap /= _STRING_GROWTH_FACTOR;
  return string_set_capacity(str, new_cap*_STRING_GROWTH_FACTOR);
}

char string_at(String str, size_t index){
  return (*str)[index];
}

char string_front(String str){
  return string_empty(str) ? 0 : (*str)[0];
}

char string_back(String str){
  size_t sz;
  return (sz = string_size(str))==0 ? 0 : (*str)[sz-1];
}