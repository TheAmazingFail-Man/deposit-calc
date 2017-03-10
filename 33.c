#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define max 1000000
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
int getrand(int mini, int maxi)
{
    return (double)rand() / (RAND_MAX + 1.0) * (maxi - mini) + mini;
}
void  maxheapsort (int a[], int i, int heapsize)
{
    int temp, largest;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if ((l <= heapsize) && (a[l] > a[i])) {
         largest = l;
    } else {
		largest = i;
	}
    if ((r <= heapsize) && (a[r] > a[largest])) {
    	largest = r ;
    }
    if (largest != i) {
    	temp = a[i];
    	a[i] = a[largest];
        a[largest] = temp;
        maxheapsort (a, largest, heapsize);
    }

	}
void  buildmaxheap (int a[], int heapsize)
{
    int i;
    for (i = heapsize / 2; i >= 0; i--) {
    	maxheapsort(a, i, heapsize);
    }
}

void heapsort (int a[], int heapsize)
{
    double t;
    int g;
    int log = 50000;
    t = wtime();
    int i, temp, l = 950000;
    buildmaxheap (a, heapsize);
    FILE *file;
    file = fopen("heapsort.dat","w");
    for (i = heapsize; i > 0; i--)
    {
        if (i == l){
    		log = log + 50000;
                g = t;
                t = wtime() - t;
                fprintf(file, "%d %.6f\n", log,t);
                printf ("%.6f\n", t);
                t = g;
                l = l - 50000;
        }
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapsize--;
        maxheapsort (a, 0, heapsize);
    }
    fclose(file);
}

int main()
{
    int i, r, heapsize;
    int *a = (int*)malloc(max*sizeof(int));
    double t;
    for (i = 0; i < max; i++){
        a[i] = getrand(1,1001);
    }
    heapsize = max - 1;
    heapsort (a, heapsize);

    return 0;
}
