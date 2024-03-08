#include <stdbool.h>
#include <stdio.h>
 
void swap(int* aPtr, int* bPtr)
{
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
void print(int arr[],int arrctr[]) {
    for (int i=0;i<9;i++) {
        printf("%d swapped %d times \n", arr[i], arrctr[arr[i]]);
    }
    printf("%d swaps total \n", arrctr[99]);
}
 
int bubbleSort(int arr[], int n, int arrctr[])
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arrctr[arr[j]]++;
                arrctr[arr[j+1]]++;
                arrctr[99]++;
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
    return *arrctr;
}

int selectionSort(int arr[], int n, int arrctr[]) 
{ 
    int i, j, min; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
  
        // Swap the found minimum element with the first element 
            if(min != i) {
                arrctr[arr[min]]++;
                arrctr[arr[i]]++;
                arrctr[99]++;
                swap(&arr[min], &arr[i]); 
           }
           
    } 
    return *arrctr;
}

void main() {
    int arr1[9] = {97,16,45,63,13,22,7,58,72};
    int arr1ctr[100] = {0};
    int arr2[9] = {90,80,70,60,50,40,30,20,10};
    int arr2ctr[100] = {0};
    *arr1ctr = bubbleSort(arr1,9,arr1ctr);
    *arr2ctr = bubbleSort(arr2,9,arr2ctr);
    printf("Bubblesort: \n");
    print(arr1,arr1ctr);
    print(arr2,arr2ctr);
    printf("Selection sort: \n");
    int arr3[9] = {97,16,45,63,13,22,7,58,72};
    int arr4[9] = {90,80,70,60,50,40,30,20,10};
    int arr3ctr[100] = {0};
    int arr4ctr[100] = {0};
    *arr3ctr = selectionSort(arr3,9,arr3ctr);
    *arr4ctr = selectionSort(arr4,9,arr4ctr);
    print(arr3,arr3ctr);
    print(arr4,arr4ctr);
}