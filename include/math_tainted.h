//---------------------------------------------------------------------//
// Bounds-safe interfaces for functions in math.h that                 //
// take pointer arguments.                                             //
//                                                                     //
// These are listed in the same order that they occur in the C11       //
// specification.                                                      //
/////////////////////////////////////////////////////////////////////////


#include_next <math.h>

#ifdef __checkcbox
#ifndef __MATH_TAINTED_H
#define __MATH_TAINTED_H

double frexp(double value, _TPtr<int> exp);
float frexpf(float value, _TPtr<int> exp);
long double frexpl(long double value, _TPtr<int> exp);

double modf(double value, _TPtr<double> iptr);
float modff(float value, _TPtr<float> iptr);
long double modfl(long double value,
                  _TPtr<long double> iptr);

double remquo(double x, double y, _TPtr<int> quo);
float remquof(float x, float y, _TPtr<int> quo);
long double remquol(long double x, long double y, _TPtr<int> quo);

double nan(_TNt_array_ptr<const char> t);
float nanf(_TNt_array_ptr<const char> t);
long double nanl(_TNt_array_ptr<const char>t);

#endif // guard
#endif // Tainted C
