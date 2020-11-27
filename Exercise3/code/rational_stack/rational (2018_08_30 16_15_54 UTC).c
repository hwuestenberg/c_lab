#include "rational.h"
#include <stdlib.h>

rational rat_add (rational a, rational b)
{
	return ((rational){a.n*b.d+b.n*a.d, a.d*b.d});
}

rational rat_sub (rational a, rational b)
{
	return ((rational){a.n*b.d-b.n*a.d, a.d*b.d});
}

rational rat_mul (rational a, rational b)
{
	return ((rational){a.n*b.n, a.d*b.d});
}

rational rat_div (rational a, rational b)
{
	return ((rational){a.n*b.d, a.d*b.n});
}

int rat_eq(rational a, rational b) {
	int c,d;
	c = a.n*b.d;
	d = b.n*a.d;
	
	if( c == d ) {
		return 1;
	}
	else {
		return 0;
	}
}

int rat_lt(rational a, rational b) {
	int c,d;
	c = a.n*b.d;
	d = b.n*a.d;
	
	if( c > d ) {
		return 1;
	}
	else {
		return 0;
	}
}

int rat_st(rational a, rational b) {
	int c,d;
	c = a.n*b.d;
	d = b.n*a.d;
	
	if( c < d ) {
		return 1;
	}
	else {
		return 0;
	}
}

double rat2f(rational a) {
  return (double)a.n/a.d;
}

int gcd(int a,int b) {
	int divisor = abs(a);
	
	// Begin with smaller number of numerator and denominator
	if( abs(a) > abs(b) ) {
		divisor = abs(b);
	}
	
	while( divisor > 0 ) { 	// Break loop, if divisor is < 1
		if( a%divisor == 0 && b%divisor == 0 ) {
			return divisor;
		}
		else{
			divisor--;
		}
	}
	// default
	return divisor;
}

rational rat_cancel(rational a) {
	// find gcd to cancel the rational number
	int GCD = gcd(a.n,a.d);
	return ((rational){a.n/GCD, a.d/GCD});
}

rational rat_normal(rational a) {
	// First cancel
	a = rat_cancel(a);
	// Ensure a positive divisor
	if( a.d < 0 ) {
		a.n *= -1;
		a.d *= -1;
	}
	return ((rational){a.n,a.d});
}

