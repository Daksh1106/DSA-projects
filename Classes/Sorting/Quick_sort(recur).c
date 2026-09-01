#include <stdio.h>

void quickSort(int arr[], int firstIndex, int lastIndex)
{
    int pivotIndex, temp, index1, index2;

    if(firstIndex < lastIndex)
    {
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        while(index1 < index2)
        {
            while(arr[index1] <= arr[pivotIndex] && index1 < lastIndex)
            {
                index1++;
            }

            while(arr[index2] > arr[pivotIndex])
            {
                index2--;
            }

            if(index1 < index2)
            {
                temp = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = temp;
            }
        }

        temp = arr[pivotIndex];
        arr[pivotIndex] = arr[index2];
        arr[index2] = temp;

        quickSort(arr, firstIndex, index2 - 1);
        quickSort(arr, index2 + 1, lastIndex);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Array after Quick Sort:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}