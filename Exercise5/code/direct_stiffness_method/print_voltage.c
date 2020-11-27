#include "print_voltage.h"
void print_voltage(FILE* fp, vector* un)
{
	fprintf(fp,"Voltages at node 1 to 5 are:\nu1=%5.4f\tu2=%5.4f\tu3=%5.4f\tu4=%5.4f\tu5=%5.4f\n",
			un->value[0],un->value[1],un->value[2],un->value[3],un->value[4]);
}