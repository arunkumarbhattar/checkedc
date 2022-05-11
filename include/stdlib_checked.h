//---------------------------------------------------------------------//
// Bounds-safe interfaces for functions in stdlib.h that               //
// take pointer arguments.                                             //
//                                                                     //
// These are listed in the same order that they occur in the C11       //
// specification.                                                      //
/////////////////////////////////////////////////////////////////////////

#ifdef __checkedc
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE off
#endif

#include_next <stdlib.h>
#include <stddef.h> // define wchar_t for wcstoimax and wcstoumax

#ifdef __checkedc
#pragma CHECKED_SCOPE pop
#endif

#ifdef __checkedc
#ifndef __STDLIB_CHECKED_H
#define __STDLIB_CHECKED_H

#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE on

double atof(const char *s : itype(_Nt_array_ptr<const char>));
double t_atof(_TNt_array_ptr<const char>);

int atoi(const char *s : itype(_Nt_array_ptr<const char>));
int t_atoi(_TNt_array_ptr<const char>);

long int atol(const char *s : itype(_Nt_array_ptr<const char>));
long int t_atol(_TNt_array_ptr<const char>);

long long int atoll(const char *s : itype(_Nt_array_ptr<const char>));
long long int t_atoll(_TNt_array_ptr<const char>);

double strtod(const char * restrict nptr :
                itype(restrict _Nt_array_ptr<const char>),
              char ** restrict endptr :
                itype(restrict _Ptr<_Nt_array_ptr<char>>));

double t_strtod(restrict _TNt_array_ptr<const char>,
                restrict _TPtr<_TNt_array_ptr<char>>);

float strtof(const char * restrict nptr :
               itype(restrict _Nt_array_ptr<const char>),
             char ** restrict endptr :
                itype(restrict _Ptr<_Nt_array_ptr<char>>));

float t_strtof(restrict _TNt_array_ptr<const char>,
             restrict _TPtr<_TNt_array_ptr<char>>);

long double strtold(const char * restrict nptr :
                      itype(restrict _Nt_array_ptr<const char>),
                    char ** restrict endptr :
                       itype(restrict _Ptr<_Nt_array_ptr<char>>));

long double t_strtold(restrict _TNt_array_ptr<const char>,
                    restrict _TPtr<_TNt_array_ptr<char>>);

long int strtol(const char * restrict nptr :
                  itype(restrict _Nt_array_ptr<const char>),
                char ** restrict endptr :
                  itype(restrict _Ptr<_Nt_array_ptr<char>>),
                int base);

long int t_strtol(restrict _TNt_array_ptr<const char>,
                  restrict _Ptr<_TNt_array_ptr<char>>,
                  int base);

long long int strtoll(const char * restrict nptr :
                        itype(restrict _Nt_array_ptr<const char>),
                      char ** restrict endptr :
                        itype(restrict _Ptr<_Nt_array_ptr<char>>),
                      int base);

long long int t_strtoll(const char * restrict nptr :
                        itype(restrict _TNt_array_ptr<const char>),
                      char ** restrict endptr :
                        itype(restrict _TPtr<_TNt_array_ptr<char>>),
                      int base);

unsigned long int strtoul(const char * restrict nptr :
                            itype(restrict _Nt_array_ptr<const char>),
                          char ** restrict endptr :
                            itype(restrict _Ptr<_Nt_array_ptr<char>>),
                          int base);

unsigned long int t_strtoul(restrict _TNt_array_ptr<const char>,
                            restrict _TPtr<_TNt_array_ptr<char>>,
                            int base);

unsigned long long int strtoull(const char * restrict nptr :
                                  itype(restrict _Nt_array_ptr<const char>),
                                char ** restrict endptr:
                                   itype(restrict _Ptr<_Nt_array_ptr<char>>),
                                int base);

unsigned long long int t_strtoull(restrict _TNt_array_ptr<const char>,
                                  restrict _TPtr<_TNt_array_ptr<char>>,
                                int base);

// TODO: express alignment constraints once where clauses have been added.
void *aligned_alloc(size_t alignment, size_t size) : byte_count(size);
_Itype_for_any(T) void *calloc(size_t nmemb, size_t size) : itype(_Array_ptr<T>) byte_count(nmemb * size);
_Itype_for_any(T) _TArray_ptr<T> t_calloc(size_t nmemb, size_t size);
_Itype_for_any(T) void free(void *pointer : itype(_Array_ptr<T>) byte_count(0));
_Itype_for_any(T) void t_free(_TArray_ptr<T> pointer);
_Itype_for_any(T) void *malloc(size_t size) : itype(_Array_ptr<T>) byte_count(size);
_Itype_for_any(T) _TArray_ptr<T> t_malloc(size_t size);
_Itype_for_any(T) void *realloc(void *pointer : itype(_Array_ptr<T>) byte_count(1), size_t size) : itype(_Array_ptr<T>) byte_count(size);
_Itype_for_any(T) _TArray_ptr<T>realloc(_TArray_ptr<T>, size_t size);
char *getenv(const char *n : itype(_Nt_array_ptr<const char>)) : itype(_Nt_array_ptr<char>);

int atexit(void ((*func)(void)) : itype(_Ptr<void (void)>));
int atquick_exit(void ((*func)(void)) : itype(_Ptr<void (void)>));

int system(const char *s : itype(_Nt_array_ptr<const char>));
int t_system(_TNt_array_ptr<const char>);
// TODO: compare needs to have an itype that has bounds
// on parameters based on size.  Currently we are requiring that
// bounds in parameters lists be closed with respect to variables
// in the parameter list.
_Itype_for_any(T) void *bsearch(const void *key : itype(_Ptr<const T>),
                                const void *base : itype(_Array_ptr<const T>) byte_count(nmemb * size),
                                size_t nmemb, size_t size,
                                int ((*compar)(const void *, const void *)) :
                                  itype(_Ptr<int(_Ptr<const T>, _Ptr<const T>)>)
                                ) : itype(_Ptr<T>);

_Itype_for_any(T) _TPtr<T> t_bsearch(_TPtr<const T> key,
                                _Array_ptr<const T> base,
                                size_t nmemb, size_t size,
                                _TPtr<int(_TPtr<const T>, _TPtr<const T>)>
				);

// TODO: compar needs to have an itype that has bounds
// on parameters based on size.  Currently we are requiring that
// types be closed.
void qsort(void *base : byte_count(nmemb * size),
           size_t nmemb, size_t size,
           int ((*compar)(const void *, const void *)) :
             itype(_Ptr<int (_Ptr<const void>, _Ptr<const void>)>));

_Itype_for_any(T) void t_qsort(_TArray_ptr<T> base : byte_count(nmemb * size),
           size_t nmemb, size_t size,
           _TPtr<int (_TPtr<const void>, _TPtr<const void>)>);

int mblen(const char *s : count(n), size_t n);
_Itype_for_any(T) int t_mblen(_TArray_ptr<const char> : count(n), size_t n);

int mbtowc(wchar_t * restrict output : itype(restrict _Ptr<wchar_t>),
           const char * restrict input : count(n),
           size_t n);

int t_mbtowc(restrict _TPtr<wchar_t>,
           	restrict _TArray_ptr<const char> : count(n),
           size_t n);
// MB_CUR_MAX is a macro that becomes a function call, so is banned
// in bounds annotations. 
// 
// int wctomb(char *s : count(MB_CUR_MAX), wchar_t wc);

size_t mbstowcs(wchar_t * restrict pwcs : count(n),
                const char * restrict s :
                  itype(restrict _Nt_array_ptr<const char>),
                size_t n);

size_t t_mbstowcs(restrict _TArray_ptr<wchar_t> pwcs : count(n),
                  restrict _Nt_array_ptr<const char>,
                  size_t n);

size_t wcstombs(char * restrict output : count(n),
                const wchar_t * restrict pwcs :
                  itype(restrict _Nt_array_ptr<const wchar_t>),
	         size_t n);

size_t t_wcstombs(restrict _TArray_ptr<char> output : count(n),
                restrict _TNt_array_ptr<const wchar_t>,
                size_t n);

#pragma CHECKED_SCOPE pop

#endif  // guard
#endif  // Checked C
