#include <stdio.h>
#include <stdlib.h>
#define MAX 10
 
int queue[MAX];
int front = 0, rear = -1, count = 0;
 
void insert_rear(int value)
{
    if (count == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;
    printf("Inserted element: %d\n", value);
}
 
void insert_front(int value)
{
    if (count == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }
    front = (front - 1 + MAX) % MAX;
    queue[front] = value;
    count++;
    printf("Inserted element: %d\n", value);
}
 
void delete_front()
{
    if (count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    int value = queue[front];
    front = (front + 1) % MAX;
    count--;
    printf("Deleted element: %d\n", value);
}
 
void delete_rear()
{
    if (count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    int value = queue[rear];
    rear = (rear - 1 + MAX) % MAX;
    count--;
    printf("Deleted element: %d\n", value);
}
 
void status()
{
    if (count == 0)
        printf("Queue is Empty (Underflow condition)\n");
    else if (count == MAX)
        printf("Queue is Full (Overflow condition)\n");
    else
        printf("Queue is neither full nor empty. Elements: %d/%d\n", count, MAX);
}
 
void display()
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < count; i++)
        printf("%d ", queue[(front + i) % MAX]);
    printf("\n");
}
 
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Insert at rear\n2. Insert at front\n3. Delete from front\n4. Delete from rear\n5. Display queue\n6. Check status\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert at rear: ");
            scanf("%d", &value);
            insert_rear(value);
            break;
        case 2:
            printf("Enter element to insert at front: ");
            scanf("%d", &value);
            insert_front(value);
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            status();
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}