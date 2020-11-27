#include "rational.h"
#include "assert.h"
#include "stdio.h"

int main ()
{
  rational a=(rational){10,20};
  rational b=(rational){30,40};
  
  /* ADD && NORMAL TEST */
  rational test=rat_add(a,b);
  assert(test.n==1000&&test.d==800);
  test=rat_normal(test);
  assert(test.n==5&&test.d==4);

  /* SUB TEST */
  test=rat_normal(rat_sub(a,b));	
  assert(test.n==-1&&test.d==4);

  /* MUL TEST */
  test=rat_normal(rat_mul(a,b));
  assert(test.n==3&&test.d==8);

  /* DIV TEST */
  test=rat_normal(rat_div(a,b));
  assert(test.n==2&&test.d==3);

  /* EQ TEST */
  assert(!rat_eq(a,b));
  assert(rat_eq(a,(rational){1,2}));
  
  /* LT TEST */
  assert(!rat_lt(a,a));
  assert(!rat_lt(a,b));
  assert(rat_lt(b,a));

  /* ST TEST */
  assert(!rat_st(a,a));
  assert(!rat_st(b,a));
  assert(rat_st(a,b));
  
  /* RAT2F TEST */
  assert(0.5f==rat2f(a));

  printf("Test Succeeded!\n");
  return 0;
}
