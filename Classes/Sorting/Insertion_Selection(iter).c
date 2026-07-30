#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main()
{
    int arr[100], n, i, choice;
    printf("1. Insertion Sort\n2. Selection Sort\nEnter your choice: ");
    scanf("%d", &choice);
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    switch(choice)
    {
        case 1:
            insertionSort(arr, n);
            printf("Array after Insertion Sort:\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("Array after Selection Sort:\n");
            break;
        default:
            printf("Invalid Choice\n");
            return 0;
    }
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}