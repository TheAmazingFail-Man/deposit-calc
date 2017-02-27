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
	for (i = 0; i < n; i++) {
		printf ("%d ", counting[i]);
	}
    printf ("\nElapsed time: %.20f sec.\n", t);  
}

void bubblesort (int bubble[], int n)
{
	int i;
    double time;

    time = wtime();
    
    int t, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (bubble[i] < bubble[i - 1]) {
                t = bubble[i];
                bubble[i] = bubble[i - 1];
                bubble[i - 1] = t;
                s = 1;
            }
        }
    }
    
    time = wtime() - time;
	printf ("\nBubble: ");
	for (i = 0; i < n; i++) {
		printf ("%d ", bubble[i]);
	}
    printf ("\nElapsed time: %.20f sec.\n", time);  
}

void mergeend (int merge[], int l, int m, int n)
{
	int i, low, r;
    double t;

    t = wtime();
    
    int merge2[n];
    for (i = l; i < n; i++) {
    	merge2[i] = merge[i];
    }
    low = l;
    r = m + 1;
    i = l;
    while (l <= m && r <= n){
    	if (merge2[l] <= merge2[r]){
    		merge[i] = merge2[l];
    		low++;
    	} else {
    			merge[i] = merge2[r];
    			r++;
    	}
    	i++;
    }
    while(low <= m){
    	merge[i] = merge2[l];
    	l++;
    	i++;
    }
    while(r <= n){
    	merge[i] = merge2[r];
    	r++;
    	i++;
    }
    
    t = wtime() - t;
	printf("\nMerge: ");
	for(i = 0; i < n; i++){
		printf("%d ", merge[i]);
	}
    printf("\nElapsed time: %.20f sec.\n", t);  
}

void mergebegin (int merge[], int l, int m, int n)
{
	if (l < n) {
		m = floor((l + n)/2); //округляет числа
		mergebegin (merge, l, m, n);
		mergebegin (merge, l, m + 1, n);
		mergeend (merge, l, m, n);
	}
}

int main()
{
	int i, l, m, n;
	printf ("Enter the number of elements of the sorting: ");
	scanf ("%d", &n);
	int counting[n], bubble[n], merge[n];
	for (i = 0; i < n; i++) {
		counting[i] = getrand(0, 100000);
		bubble[i] = getrand(0, 100000);
		merge[i] = getrand(0, 100000);
	}
	countingsort (counting, n);
	bubblesort (bubble, n);
	mergebegin (merge, l, m, n);
	mergeend (merge, l, m, n);
}