#include <stdio.h>
 
int linear_iter(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
 
int linear_recur(int arr[], int size, int target, int index)
{
    if (index >= size)
        return -1;
    if (arr[index] == target)
        return index;
    return linear_recur(arr, size, target, index + 1);
}
 
int main()
{
    int arr[100], size, target, result = -1, choice;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter target element to search: ");
    scanf("%d", &target);
    printf("1. Iterative\n2. Recursive\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        result = linear_iter(arr, size, target);
        printf("Iterative search: ");
        break;
    case 2:
        result = linear_recur(arr, size, target, 0);
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