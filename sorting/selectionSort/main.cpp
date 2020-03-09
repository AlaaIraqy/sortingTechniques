#include <iostream>
#include<time.h>

using namespace std;
void selectionSort(int arr[],int n)
{
    int min;
    for(int i=0; i<n; i++)
    {
        min=i;
        for(int j=i; j<n; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(arr[min],arr[i]);
    }
}

int main()
{
    clock_t t;
    FILE *p=fopen("500000.txt","r");
    int x[500000];
    int i=0;
    while(!feof(p)){
        fscanf(p,"%d",&x[i]);
        i++;
    }
    t=clock();
    selectionSort(x,sizeof(x)/sizeof(x[0]));
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    /*for(int i=0; i<sizeof(x)/sizeof(x[0]); i++)
    {
        printf("%d\n",x[i]);
    }*/
    printf("%f",time_taken);
    return 0;
}
