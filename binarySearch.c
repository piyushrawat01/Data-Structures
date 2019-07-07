#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
void getArray();
int binarySearch();
void getRandomArray();
void printArray();
void mergeSort();
void merge();
int main() {
    int n,value,index,choice;
    printf("Enter value of n :");
    scanf("%d",&n);
    int arr[n];
    printf("Want to fill values or use random values ;\n1. User input\n2. Random values\nDefault is random");
    scanf("%d",&choice);
    (choice==1)?getArray(arr,n):getRandomArray(arr,n);
    printf("enter the value to be searched : ");
    scanf("%d",&value);
    mergeSort(arr,0,n-1);
    index=binarySearch(arr,0,n-1,value);
    printArray(arr,0,n-1);
    (index!=-1)?printf("Value found at : %d",index+1):printf("Value not present ");
     getch();
}

int binarySearch(int arr[],int start, int end, int value){
if(start<end) {
    int mid=(start+end)/2;
    if (arr[mid] == value)
        return mid;
    else if (arr[mid] < value)
        return binarySearch(arr, mid + 1, end, value);
    else
        return binarySearch(arr, start, mid - 1, value);
    }
return -1;
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
void printArray(int arr[],int start,int end){
    for(int i=0;i<=end-start;i++)
    {
        printf("%d , ",arr[i]);
    }
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