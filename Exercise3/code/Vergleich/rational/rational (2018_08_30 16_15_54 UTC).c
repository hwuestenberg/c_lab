#include "rational.h"

#include <stdio.h>
#include <stdlib.h>

rational rat_add (rational a, rational b)
{
  /*example code for addition*/
  return ((rational){a.n*b.d+b.n*a.d,a.d*b.d});
}

rational rat_sub (rational a, rational b)
{
  return ((rational){a.n*b.d-b.n*a.d,a.d*b.d});
}

rational rat_mul (rational a, rational b)
{
  return ((rational){a.n*b.n, a.d*b.d});
}

rational rat_div (rational a, rational b)
{
  return ((rational){a.n*b.d, a.d*b.n});
}

int rat_eq(rational a, rational b)
{
	if(a.d != b.d) {
		// auf gleichen Nenner bringen, sodass vergleich möglich.
		a.n *= b.d;
		b.n *= a.d;
	}
	if(a.n == b.n)
		return 1;
	return 0;
}

int rat_lt(rational a, rational b)
{
	if(a.d != b.d) {
		// auf gleichen Nenner bringen, sodass vergleich möglich.
		a.n *= b.d;
		b.n *= a.d;
	}
	if(a.n > b.n)
		return 1;
	return 0;
}

int rat_st(rational a, rational b)
{
	if(a.d != b.d) {
		// auf gleichen Nenner bringen, sodass vergleich möglich.
		a.n *= b.d;
		b.n *= a.d;
	}
	if(a.n < b.n)
		return 1;
	return 0;
}

double rat2f(rational a)
{
  return (double) a.n / a.d;
}

int gcd(int a,int b)
{
	// smaller value, default is a
	a = abs(a);
	b = abs(b);
	int small = a;

	// if both are equal, the gcd is simply their value
	if(a == b)
		return a;

	// change smaller value if b is smaller
	if(a > b) 
		small = b;

	// find gcd
	for(int i = small; i > 1; --i)
		if(b % i == 0 && a % i == 0)
			return i;

	// default case
	return 1;
}

rational rat_cancel(rational a)
{
	int this_gcd = gcd(a.n, a.d);
	return (rational) {a.n / this_gcd, a.d / this_gcd};	 
}

rational rat_normal(rational a)
{
	// first cancel the rational number
	a = rat_cancel(a);

	// ensure that the denominator is positive
	if(a.d < 0) {
		a.n = -a.n;
		a.d = -a.d;
	}
	
	// return normalised ration number
	return a;
}

