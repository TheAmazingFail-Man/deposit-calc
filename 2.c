#include <stdio.h>

int main()
{
	int d, m;
	error:
	printf("Enter the number days: ");
	scanf("%d", &d);
	printf("Enter the amount (k)");
	scanf("%d", &m);
	if(d > 365 || m < 10){
		printf("Error404\n");
		goto error;
	}
}