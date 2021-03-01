#ifndef CSTRING_H
#define CSTRING_H

#include <stdlib.h>

#define _STRING_GROWTH_FACTOR 2

#ifndef MIN
  #define MIN(x, y) (x<y ? x : y) /* Returns the minimum number (x or y). */
#endif

#ifndef MAX
  #define MAX(x, y) (x>y ? x : y) /* Returns the maximum number (x or y). */
#endif

typedef char** String;

typedef struct{
  size_t sz, cap; /* size, capacity */
  unsigned short auto_shrink; /* automatic shrink on(1) / off(0) */
} StringData;

static const size_t string_npos = -1;

/*----------------------------------Auxiliaries----------------------------------*/
/* Verifies whether the String is valid */
unsigned short string_valid(String str);

/* Returns the String's Data Address */
StringData* string_data(String str);
/*==============================================================================*/

/*----------------------------------Constructor----------------------------------*/
/* Creates the String and returns its address */
String string_new_cfg(unsigned short auto_shrink);
#define string_new() (string_new_cfg(0))
/*==============================================================================*/

/*-----------------------------------Pointers-----------------------------------*/
/* Returns pointer to the beginning of String */
char* string_begin(String str);

/* Returns pointer to the end of String */
char* string_end(String str);
/*==============================================================================*/

/*----------------------------------Dimensions----------------------------------*/
/* Returns String's size */
size_t string_size(String str);

/* Returns String's Total Capacity */
size_t string_capacity(String str);

/* Verifies whether the String is empty */
unsigned short string_empty(String str);

/* Sets String's Size
 * Returns: Pointer to the beginning of String */
char* string_set_size(String str, size_t new_size);

/* Sets String's Capacity
 * Returns: Pointer to the beginning of String's array */
char* string_set_capacity(String str, size_t new_cap);

/* Requests the container to reduce its capacity to fit its size. 
 * Shrinks in such a way that the following statement is true: 
 * (size<=capacity && size>=(capacity/_STRING_GROWTH_FACTOR))
 * Returns: Pointer to the beginning of String's array */
char* string_shrink_to_fit(String str);
/*==============================================================================*/

/*--------------------------------Element Access--------------------------------*/
/* Returns a reference to the element at position n in the vector. */
char string_at(String str, size_t index);

/* Returns the first element in the vector, or 0 if it's empty */
char string_front(String str);

/* Returns the last element in the vector, or 0 if it's empty */
char string_back(String str);
/*==============================================================================*/

#endif