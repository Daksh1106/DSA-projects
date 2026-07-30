#include <stdio.h>
int create_arr(int arr[])
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return n;
}
int display_arr(int arr[], int n)
{
    int i;
    printf("\nIndex\tElement\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, arr[i]);
    printf("\n");
}
int insert_element(int arr[], int n, int element, int pos)
{
    int i;
    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = element;
    printf("Element %d inserted at position %d\n", element, pos);
    return n + 1;
}
int delete_element(int arr[], int n, int pos)
{
    int i;
    printf("Element %d deleted from position %d\n", arr[pos], pos);
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}
int main()
{
    int arr[100], n, choice, element, pos;
    while (1)
    {
        printf("1. Create array\n2. Display array\n3. Insert element\n4. Delete element\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            n = create_arr(arr);
            break;
        case 2:
            display_arr(arr, n);
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > n)
                printf("Invalid position\n");
            else
                n = insert_element(arr, n, element, pos);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= n)
                printf("Invalid position\n");
            else
                n = delete_element(arr, n, pos);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}