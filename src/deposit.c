#include <stdio.h>
#include "deposit.h"

int data(double m, int d)
{
	if (d > 365 || d < 0 || m < 10000) {

		return -1;
	}
	
	return 0;
}

int result(double m, int d)
{
	if (m <= 100000) {
		if (d >= 0 && d <= 30) {
			m *= 0.9;
		}
		if (d > 30 && d <= 120) {
			m *= 1.02;
		}
		if (d > 120 && d <= 240) {
			m *= 1.06;
		}
		if (d > 240 && d <= 365) {
			m *= 1.12;
		}
		//printf("Money: %.2lf", m);

		return m;
	}
	if (m > 100000) {
		if (d >= 0 && d <= 30) {
			m *= 0.9;
		}
		if (d > 30 && d <= 120) {
			m *= 1.03;
		}
		if (d > 120 && d <= 240) {
			m *= 1.08;
		}
		if (d > 240 && d <= 365) {
			m *= 1.15;
		}
		//printf("Money: %.2lf", m);

		return m;
	}
	
	return 0;

}
