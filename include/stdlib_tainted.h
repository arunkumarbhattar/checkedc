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

double t_atof(_TNt_array_ptr<const char>);
int t_atoi(_TNt_array_ptr<const char>);
long int t_atol(_TNt_array_ptr<const char>);
long long int t_atoll(_TNt_array_ptr<const char>);
double t_strtod(restrict _TNt_array_ptr<const char>,
                restrict _TPtr<_TNt_array_ptr<char>>);
float t_strtof(restrict _TNt_array_ptr<const char>,
             restrict _TPtr<_TNt_array_ptr<char>>);
long double t_strtold(restrict _TNt_array_ptr<const char>,
                    restrict _TPtr<_TNt_array_ptr<char>>);
long int t_strtol(restrict _TNt_array_ptr<const char>,
                  restrict _Ptr<_TNt_array_ptr<char>>,
                  int base);
long long int t_strtoll(const char * restrict nptr :
                        itype(restrict _TNt_array_ptr<const char>),
                      char ** restrict endptr :
                        itype(restrict _TPtr<_TNt_array_ptr<char>>),
                      int base);
unsigned long int t_strtoul(restrict _TNt_array_ptr<const char>,
                            restrict _TPtr<_TNt_array_ptr<char>>,
                            int base);
unsigned long long int t_strtoull(restrict _TNt_array_ptr<const char>,
                                  restrict _TPtr<_TNt_array_ptr<char>>,
                                int base);

// TODO: express alignment constraints once where clauses have been added.
void *aligned_alloc(size_t alignment, size_t size) : byte_count(size);
_Itype_for_any(T) _TArray_ptr<T> t_calloc(size_t nmemb, size_t size);
_Itype_for_any(T) void t_free(_TArray_ptr<T> pointer);
_Itype_for_any(T) _TArray_ptr<T> t_malloc(size_t size) {return NULL;};
_Itype_for_any(T) _TArray_ptr<T>realloc(_TArray_ptr<T>, size_t size);
_TArray_ptr<char> t_getenv(_TNt_array_ptr<const char>) : itype(_TNt_array_ptr<char>);

int t_atexit(_TPtr<void (void)>);
int t_atexit(_TPtr<void (void)>);
int t_atquick_exit(_Ptr<void (void)>);

int t_system(_TNt_array_ptr<const char>);
// TODO: compare needs to have an itype that has bounds
// on parameters based on size.  Currently we are requiring that
// bounds in parameters lists be closed with respect to variables
// in the parameter list.

_Itype_for_any(T) _TPtr<T> t_bsearch(_TPtr<const T> key,
                                _Array_ptr<const T> base,
                                size_t nmemb, size_t size,
                                _TPtr<int(_TPtr<const T>, _TPtr<const T>)>
				);

// TODO: compar needs to have an itype that has bounds
// on parameters based on size.  Currently we are requiring that
// types be closed.
_Itype_for_any(T) void t_qsort(_TArray_ptr<T> base : byte_count(nmemb * size),
           size_t nmemb, size_t size,
           _TPtr<int (_TPtr<const void>, _TPtr<const void>)>);

_Itype_for_any(T) int t_mblen(_TArray_ptr<const char> : count(n), size_t n);

int t_mbtowc(restrict _TPtr<wchar_t>,
           	restrict _TArray_ptr<const char> : count(n),
           size_t n);
// MB_CUR_MAX is a macro that becomes a function call, so is banned
// in bounds annotations. 
// 
// int wctomb(char *s : count(MB_CUR_MAX), wchar_t wc);

size_t t_mbstowcs(restrict _TArray_ptr<wchar_t> pwcs : count(n),
                  restrict _Nt_array_ptr<const char>,
                  size_t n);

size_t t_wcstombs(restrict _TArray_ptr<char> output : count(n),
                restrict _TNt_array_ptr<const wchar_t>,
                size_t n);

#endif  // guard
#endif  // Tainted C
