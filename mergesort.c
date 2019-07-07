#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
void printArray();
void getArray();
void getRandomArray();
void mergeSort();
void merge();
void printArray(int arr[],int start,int end){
    for(int i=0;i<=end-start;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n\n ");
}
void getArray(int arr[], int n){
    for (int i=0;i<n; i++)
    { printf("Enter value %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}
void getRandomArray( int arr[], int n){
    srand ( time(NULL) );
    for(int i=0;i<n;i++)
        arr[i]= rand()%100;
}
void mergeSort(int arr[],int start,int end){

    if(start<end){
        int mid=(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void merge(int arr[],int start,int mid,int end) {
    int brr[mid - start + 1], crr[end - mid ];
    int i, j, k;
    for (i = 0; i <mid-start+1; i++)
        brr[i] = arr[start+i];
    for (i = 0; i < end - mid; i++)
        crr[i] = arr[mid + 1 + i];

    i = 0;
    j = 0;
    k = start;
    while (i < mid - start + 1 && j < end - mid ) {
        if (brr[i] <= crr[j]) {
            arr[k] = brr[i];
            i++;
        } else
        {
            arr[k] = crr[j];
            j++;
        }
        k++;
    }
    while(i<mid - start + 1)
    {
        arr[k]=brr[i];
        k++;
        i++;
    }
    while(j<end - mid){
        arr[k]=crr[j];
        k++;
        j++;
    }


}
int main() {
    int n,choice,again=1;
    while(again==1){
    printf("Enter value of n : ");
    scanf("%d",&n);
    int arr[n];
    printf("Want to fill values or use random values ;\n1. User input\n2. Random values\nDefault is random");
    scanf("%d",&choice);
    (choice==1)?getArray(arr,n):getRandomArray(arr,n);
    printf("Unsorted array : ");
    printArray(arr,0,n-1);
    mergeSort(arr,0,n-1);
    printf("Sorted array : ");
    printArray(arr,0,n-1);
    printf("Another try, press 1 for yes or any other number for no : ");
        scanf("%d",&again);
}
    getch();
}