//---------------------------------------------------------------------//
// Bounds-safe interfaces for compiler-defined builtin functions       //
// corresponding to stdio.h functions                                  //
//                                                                     //
// These are given in the order they appear in clang's Builtins.def.   //
// Functions that do not appear can not have checked interfaces        //
// defined.                                                            //
//                                                                     //
// These are based on the types as declared within clang               //
// and https://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html    //
/////////////////////////////////////////////////////////////////////////

#include "_builtin_common.h"

#if _USE_FORTIFY_LEVEL > 0

#ifndef __has_builtin
#define _undef__has_builtin
#define __has_builtin(x) 0
#endif


#if __has_builtin(__builtin___sprintf_chkcbx) || defined(__GNUC__)
// sprintf
int __sprintf_chkcbx(  _TNt_array_ptr<char> restrict buffer,
                  int flag,
                  size_t obj_size,
                    _TNt_array_ptr<const char> restrict format,
                  ...);

int __builtin___sprintf_chkcbx( _TNt_array_ptr<char> restrict buffer,
                            int flag,
                            size_t obj_size,
                            restrict _TNt_array_ptr<const char> format,
                            ...);
#endif

#if __has_builtin(__builtin___snprintf_chkcbx) || defined(__GNUC__)
// snprintf
int __snprintf_chkcbx(_TNt_array_ptr<char> restrict buffer : count(maxlen),
                   size_t maxlen,
                   int flag,
                   size_t obj_size,
                   _TNt_array_ptr<const char> restrict format,
                   ...);

int __builtin___snprintf_chkcbx(_TNt_array_ptr<char> restrict buffer : count(maxlen),
                             size_t maxlen,
                             int flag,
                             size_t obj_size,
                             _TNt_array_ptr<const char> restrict format,
                             ...);
#endif

#if __has_builtin(__builtin___vsprintf_chkcbx) || defined(__GNUC__)
// vsprintf

int __vsprintf_chkcbx(_TNt_array_ptr<char> restrict buffer,
                   int flag,
                   size_t obj_size,
                   restrict _TNt_array_ptr<const char> restrict format,
                   va_list);



int __builtin___vsprintf_chkcbx(itype(restrict _TNt_array_ptr<char> restrict buffer,
                             int flag,
                             size_t obj_size,
                             _TNt_array_ptr<const char> restrict format,
                             va_list arg);
#endif


#if __has_builtin(__builtin___vsnprintf_chkcbx) || defined(__GNUC__)
// vsnprintf
int __vsnprintf_chkcbx(_TNt_array_ptr<char> restrict buffer : count(maxlen),
                    size_t maxlen,
                    int flag,
                    size_t obj_size,
                    _TNt_array_ptr<const char> restrict format,
                    va_list);

int __builtin___vsnprintf_chkcbx(_TNt_array_ptr<char> restrict buffer : count(maxlen),
                              size_t maxlen,
                              int flag,
                              size_t obj_size,
                              _TNt_array_ptr<const char> restrict format ,
                              va_list arg);
#endif

#if __has_builtin(__builtin___fprintf_chkcbx) || defined(__GNUC__)
// fprintf
int __fprintf_chkcbx(_Ptr<FILE> restrict stream,
                  int flag,
                  _TNt_array_ptr<const char> restrict format,
                  ...);

int __builtin___fprintf_chkcbx(_Ptr<FILE> restrict stream,
                            int flag,
                            _TNt_array_ptr<const char> restrict format,
                            ...);
#endif

#if __has_builtin(__builtin___printf_chkcbx) || defined(__GNUC__)
// printf
int __printf_chkcbx(int flag,
                    _TNt_array_ptr<const char> restrict format,
                 ...);

_Unchecked
int __builtin___printf_chkcbx(int flag,
                              _TNt_array_ptr<const char> restrict format,
                           ...);
#endif

#if __has_builtin(__builtin___vfprintf_chkcbx) || defined(__GNUC__)
// vfprintf
int __vfprintf_chkcbx(_Ptr<FILE> restrict stream,
                   int flag,
                   _TNt_array_ptr<const char> restrict format,
                   va_list);

int __builtin___vfprintf_chkcbx(_Ptr<FILE> restrict stream,
                             int flag,
                             _TNt_array_ptr<const char> restrict format,
                             va_list);
#endif

#if __has_builtin(__builtin___vprintf_chkcbx) || defined(__GNUC__)
// vprintf
int __vprintf_chk(int flag,
                  _TNt_array_ptr<const char> restrict format,
                  va_list);

int __builtin___vprintf_chk(int flag,
                            _TNt_array_ptr<const char> restrict format,
                            va_list);
#endif

#ifdef _undef__has_builtin
#undef _undef__has_builtin
#undef __has_builtin
#endif

#endif
