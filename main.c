#include <stdio.h>
#include "parts.h"

int main()
{
	int d;
	double m;
	printf ("Enter the number days: ");
	scanf ("%d", &d);
	printf ("Enter the amount (k): ");
	scanf ("%lf", &m);
	while (d > 365 || m < 10) {
		printf ("Error404\n");
	}
	if (m > 100){
		more (&m, d);
	} else if (m <= 100){
		less (&m, d);
	}
	printf ("Money: %.1lf", m);
}
