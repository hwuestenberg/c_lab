#ifndef __RATIONAL_H
#define __RATIONAL_H

/****************************************************************************/
/* structure definition for containing rational number representation       */
/*   entry n : numberator of rational number                                */
/*   entry d : denominator of rational number                               */
/****************************************************************************/
struct rational_struct{
  int n; //numerator
  int d; //denominator
};

/****************************************************************************/
/* defining type rational to be 'struct rational_struct'                    */
/****************************************************************************/
typedef struct rational_struct rational;

/****************************************************************************/
/* name  : rat_add, short form for 'rational addition'                      */
/* param : rational number a, rational number b                             */
/* return: rational number being the sum of 'a' and 'b' (a+b)               */ 
/****************************************************************************/
rational rat_add (rational a, rational b);

/****************************************************************************/
/* name  : rat_sub, short form for 'rational subtraction'                   */
/* param : rational number a, rational number b                             */
/* return: rational number being the difference of 'a' and 'b' (a-b)        */
/****************************************************************************/
rational rat_sub (rational a, rational b);

/****************************************************************************/
/* name  : rat_mul, short form for 'rational multiplication'                */
/* param : rational number a, rational number b                             */
/* return: rational number being the product of 'a' and 'b' (a*b)           */
/****************************************************************************/
rational rat_mul (rational a, rational b);

/****************************************************************************/
/* name  : rat_div, short form for 'rational division'                      */
/* param : rational number a, rational number b                             */
/* return: rational number being the quotient of 'a' and 'b' (a/b)          */
/****************************************************************************/
rational rat_div (rational a, rational b);

/****************************************************************************/
/* name  : rat_cancel, short form for 'rational cancel'                     */
/* param : rational number a                                                */
/* return: rational number being canceled representation of 'a'             */
/****************************************************************************/
rational rat_cancel(rational a);

/****************************************************************************/
/* name  : rat_normal, short form for 'rational normalise'                  */
/* param : rational number a                                                */
/* return: rational number being normalised representation of 'a'           */
/*         normalised means canceled and minus-sign exclusively in nominator*/
/****************************************************************************/
rational rat_normal(rational a);

/****************************************************************************/
/* name  : gcd, short form for 'greatest common divisor'                    */
/* param : integer number a, integer number b                               */
/* return: integer number being the gcd of 'a' and 'b'                      */
/****************************************************************************/
int      gcd(int a,int b);

/****************************************************************************/
/* name  : rat2f, short form for 'rational number to float'                 */
/* param : rational number a                                                */
/* return: floating point (fp) number beeing the fp representation of a     */
/****************************************************************************/
double   rat2f(rational a);

/****************************************************************************/
/* name  : rat_eq, short form for 'rational number equals'                  */
/* param : rational number a, rational number b                             */
/* return: integer number being '1': if a equals b                          */
/*                              '0': if a not equals b                      */
/****************************************************************************/
int rat_eq(rational a, rational b);

/****************************************************************************/
/* name  : rat_lt, short form for 'rational number larger than'             */
/* param : rational number a, rational number b                             */
/* return: integer number being '1': if a is larger than b                  */
/*                              '0': if a is not larger than b              */
/****************************************************************************/
int rat_lt(rational a, rational b);

/****************************************************************************/
/* name  : rat_st, short form for 'rational number smaller than'            */
/* param : rational number a, rational number b                             */
/* return: integer number being '1': if a is smaller than b                 */
/*                              '0': if a is not smaller than b             */
/****************************************************************************/
int rat_st(rational a, rational b);

#endif
