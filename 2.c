#include <stdio.h>

int main()
{
	int d, m;
	printf("Enter the number days: ");
	scanf("%d", &d);
	printf("Enter the amount (k)");
	scanf("%d", &m);
	if(d > 365 || m < 10){
		printf("Error404\n");
		return 0;
	}
	if(m <= 100){
		if(d <= 30){
			m = m  * 0.9;
		}
		if(d > 30 && d <= 120){
			m = m * 1.02;
		}
		if(d > 120 && d <= 240){
			m = m * 1.06;
		}
		if(d > 240 && d <= 365){
			m = m * 1.12;
		}
	}
	if(m > 100){
		if(d <= 30){
			m = m * 0.9;
		}
		if(d > 30 && d <= 120){
			m = m * 1.03;
		}
		if(d > 120 && d <= 240){
			m = m * 1.08;
		}
		if(d > 240 && d <= 365){
			m = m * 1.15;
		}
	}
}
