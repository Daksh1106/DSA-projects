#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int temp[100];
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}
void mergeSort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = arr[low];
    i = low + 1;
    j = high;
    while(i <= j)
    {
        while(i <= high && arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int arr[], int low, int high)
{
    int p;
    if(low < high)
    {
        p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
int main()
{
    int arr[100], n, i, choice;
    printf("1. Merge Sort\n2. Quick Sort\nEnter your choice: ");
    scanf("%d", &choice);
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    switch(choice)
    {
        case 1:
            mergeSort(arr, 0, n - 1);
            printf("Array after Merge Sort:\n");
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            printf("Array after Quick Sort:\n");
            break;
        default:
            printf("Invalid Choice");
            return 0;
    }
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}