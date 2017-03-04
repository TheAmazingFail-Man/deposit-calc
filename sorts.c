#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand (int mini, int maxi)
{
    return (double)rand() / (RAND_MAX + 1.0) * (maxi - mini) + mini;
}

void countingsort (int counting[], int n)
{
	int i;
    double t;

    t = wtime();
    
	int min, max;
  	min = counting[0];
  	max = counting[0];
  	for (i = 1; i < n; i++) {
  	  if ( counting[i] < min ) {
  	  	min = counting[i];
  	  } else if ( counting[i] > max ) {
  	    	max = counting[i];
    	}
  	}
  	int j, z;
  	int range = max - min + 1;
  	int cow[range];
  	for (i = 0; i < range; i++) {
  		cow[i] = 0;
  	}
  	for (i = 0; i < n; i++) {
  		cow[counting[i] - min]++;
  	}
  	for (i = min, z = 0; i <= max; i++) {
    	for (j = 0; j < cow[i - min]; j++) {
    	  counting[z++] = i;
    	}
	}
    
    t = wtime() - t;
	printf ("\nCounting: ");
	/*for (i = 0; i < n; i++) {
		printf ("%d ", counting[i]);
	}*/
    printf ("\nElapsed time: %.20f sec.\n", t);  
}

void bubblesort (uint32_t *mas[], uint32_t n)
{
    uint32_t i, temp, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (*mas[i] < *mas[i - 1]) {
                t = mas[i];
                *mas[i] = *mas[i - 1];
                *mas[i - 1] = t;
                s = 1;
            }
        }
    }
}

int main()
{
	double time;
	uint32_t n = atoi(argv[1]);
	for (; n < 1000000; n += 50000) {
		uint32_t *mas = (uint32_t*)malloc(n * sizeof(uint32_t));
		for (int i = 0; i < n; i++) {
			mas[i] = getrand(0, 100000);
		}
		time = wtime();
		countingsort (mas, n);
		time = wtime() - time;
		FILE *file = fopen ("countingsort.txt", "a");
		fprintf (file, "Size of the array: %d	Elapsed time: %.6f\n", n, time);
		fclose (file);
	
		time = wtime();
		bubblesort (mas, n);
		time = wtime() - time;
		FILE *file = fopen ("bubblesort.txt", "a");
		fprintf (file, "Size of the array: %d	Elapsed time: %.6f\n", n, time);
		fclose (file);
	
		time = wtime();
		mergesort (*mas, 0, n - 1);
		time = wtime() - time;
		FILE *file = fopen ("mergesort.txt", "a");
		fprintf (file, "Size of the array: %d	Elapsed time: %.6f\n", n, time);
		fclose (file);
	}
	
	return 0;
}