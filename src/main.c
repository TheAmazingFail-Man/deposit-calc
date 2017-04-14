#include <stdio.h>
#include "deposit.h"

int main()
{
	int d;
	double m;
	printf("Enter the number days: ");
	scanf("%d", &d);
	printf("Enter the amount: ");
	scanf("%lf", &m);
	data(m, d);
	result(m, d);

	return 0;
}
