#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

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

int countingsort (int mas1[], int n)
{
	int i, min, max;
  	min = mas1[0];
  	max = mas1[0];
  	for (i = 1; i < n; i++) {
  		if ( mas1[i] < min ) {
  	  		min = mas1[i];
  	  	} else if ( mas1[i] > max ) {
  	    	max = mas1[i];
    	}
  	}
  	int j, z;
  	int range = max - min + 1;
  	int cow[range];
  	for (i = 0; i < range; i++) {
  		cow[i] = 0;
  	}
  	for (i = 0; i < n; i++) {
  		cow[mas1[i] - min]++;
  	}
  	for (i = min, z = 0; i <= max; i++) {
    	for (j = 0; j < cow[i - min]; j++) {
    	  mas1[z++] = i;
    	}
	}
	
	return 0;
}

int bubblesort (int mas2[], int n)
{
    int i, temp, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (mas2[i] < mas2[i - 1]) {
                temp = mas2[i];
                mas2[i] = mas2[i - 1];
                mas2[i - 1] = temp;
                s = 1;
            }
        }
    }
	
    return 0;
}

int mergehelp (int mas3[], int mashelp[], int l, int m, int r)
{
	int i, left, right;
	for (i = l; i < r + 1; i++) {
		mashelp[i] = mas3[i];
	}
	left = l;
	right = m + 1;
	i = l;
	while ((left <= m) && (right <= r)) {
		if (mashelp[left] <= mashelp[right]) {
			mas3[i] = mashelp[left];
			left++;
		} else {
			mas3[i] = mashelp[right];
			right++;
		}
	i++;
	}			
	while (left <= m) {
		mas3[i] = mashelp[left];
		left++;
		i++;
	}		
	while (right <= r) {
		mas3[i] = mashelp[right];
		right++;
		i++;		
	}
	
	return 0;
}

int mergesort (int mas3[], int mashelp[], int l, int r)
{
	int m;
	if (l < r) {
		m = (l + r) / 2;
		mergesort (mas3, mashelp, l, m);
		mergesort (mas3, mashelp, m + 1, r);
		mergehelp (mas3, mashelp, l, m, r);
	}
	
	return 0;
}

int main()
{
	double time;
	int i, n;
	for (n = 50000; n <= 1000000; n += 50000) {
		int *mas1 = malloc(n * sizeof(int));
		int *mas2 = malloc(n * sizeof(int));
		int *mas3 = malloc(n * sizeof(int));
		int *mashelp = malloc(n * sizeof(int));
		for (i = 0; i < n; i++) {
			mas1[i] = mas2[i] = mas3[i] =  getrand(0, 100000);
		}
		
		while (n != 500000) {
		time = wtime();
		countingsort (mas1, n);
		time = wtime() - time;
		FILE *file1 = fopen ("countingsort.dat", "a");
		fprintf (file1, "%d %.6f\n", n, time);
		fclose (file1);
		}
		
		while (n != 200000) {
		time = wtime();
		bubblesort (mas2, n);
		time = wtime() - time;
		FILE *file2 = fopen ("bubblesort.dat", "a");
		fprintf (file2, "%d %.6f\n", n, time);
		fclose (file2);
		}
	
		while (n != 500000) {
		time = wtime();
		mergesort (mas3, mashelp, 0, n);
		time = wtime() - time;
		FILE *file3 = fopen ("mergesort.dat", "a");
		fprintf (file3, "%d %.6f\n", n, time);
		fclose (file3);
		}
		
		free(mas1);
		free(mas2);
		free(mas3);
		free(mashelp);
	}
	
	return 0;
}
