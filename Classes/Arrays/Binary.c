#include <stdio.h>
 
int binary_iter(int arr[], int size, int target)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
 
int binary_recur(int arr[], int size, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binary_recur(arr, size, target, mid + 1, high);
    else
        return binary_recur(arr, size, target, low, mid - 1);
}
 
int main()
{
    int arr[100], size, target, result = -1, choice;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array in sorted order: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter target element to search: ");
    scanf("%d", &target);
    printf("1. Iterative\n2. Recursive\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        result = binary_iter(arr, size, target);
        printf("Iterative search: ");
        break;
    case 2:
        result = binary_recur(arr, size, target, 0, size - 1);
        printf("Recursive search: ");
        break;
    default:
        printf("Invalid choice\n");
        return 0;
    }
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}