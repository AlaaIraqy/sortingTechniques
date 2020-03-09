#include <iostream>
#include <time.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int root=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[root]){
        root=left;
    }
    if(right<n && arr[right]>arr[root]){
        root=right;
    }
    if(root!=i){
        swap(arr[i],arr[root]);
        heapify(arr,n,root);
    }

}
void heapSort(int arr[], int n)
{
	for (int i = n ; i >=0; i--){
		heapify(arr, n, i);
		}

	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
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
    heapSort(x,sizeof(x)/sizeof(x[0]));
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f",time_taken);
	/*for(int i=0;i<10;++i){
        printf("%d\n",x[i]);
	}*/
}
