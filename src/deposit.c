#include <stdio.h>
#include "deposit.h"

void less(double *m, int d)
{
	if (d >= 0 && d <= 30) {
		*m *= 0.9;
	}
	if (d > 30 && d <= 120) {
		*m *= 1.02;
	}
	if (d > 120 && d <= 240) {
		*m *= 1.06;
	}
	if (d > 240 && d <= 365) {
		*m *= 1.12;
	}
}

void more(double *m, int d)
{
	if (d >= 0 && d <= 30) {
		*m *= 0.9;
	}
	if (d > 30 && d <= 120) {
		*m *= 1.03;
	}
	if (d > 120 && d <= 240) {
		*m *= 1.08;
	}
	if (d > 240 && d <= 365) {
		*m *= 1.15;
	}
}
