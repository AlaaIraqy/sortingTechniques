#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define RAND_MAX
#include <time.h>

using namespace std;

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return (i + 1);
}



void Quicksort( int array[], int first,int last )
{
    if (first < last)
    {
        int part = partition(array, first, last);
        Quicksort(array,first,part-1);
        Quicksort(array,part+1,last);

    }
}
int main(){

 clock_t t;
    FILE *p=fopen("500000.txt","r");
    int x[500000];
    int i=0;
    while(!feof(p)){
        fscanf(p,"%d",&x[i]);
        i++;
    }
    t=clock();
    Quicksort(x,0,sizeof(x)/sizeof(x[0]));
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    /*for(int i=0; i<sizeof(x)/sizeof(x[0]); i++)
    {
        printf("%d\n",x[i]);
    }*/
    printf("%f",time_taken);

return 0;
}
