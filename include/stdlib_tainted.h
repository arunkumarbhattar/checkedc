//---------------------------------------------------------------------//
// Bounds-safe interfaces for functions in stdlib.h that               //
// take pointer arguments.                                             //
//                                                                     //
// These are listed in the same order that they occur in the C11       //
// specification.                                                      //
/////////////////////////////////////////////////////////////////////////

//will later change this to tainted -c
#ifdef __checkedc
#ifndef __STDLIB_TAINTED_H
#define __STDLIB_TAINTED_H


#include <stddef.h>
static void* c_malloc(char* pointer_name, size_t size);

static void* c_realloc(char* pointer_name, size_t size);

static void c_free(char* pointer_name);

// TODO: express alignment constraints once where clauses have been added.
_Itype_for_any(T) _TArray_ptr<T> t_malloc(size_t size, char* assignment_name)
{
        void* temp = (void*)c_malloc(assignment_name, size);
        return (_TArray_ptr<T>) temp;
};

_Itype_for_any(T) void t_free(char* assignment_name)
{
      return c_free(assignment_name);
};

_Itype_for_any(T) _TArray_ptr<T> t_realloc(size_t size, char* assignment_name)
{
  return (_TArray_ptr<T>)c_realloc(assignment_name, size);
};


#endif  // guard
#endif  // Tainted C
