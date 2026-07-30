#include<stdio.h>
#define MAX 5
char queue[MAX];
int f=0, r=-1,count=0;
void enqueue(char value)
{
    if(count==MAX)
    {
        printf("Queue Overflow\n");
        return;
    }
    r=(r+1)%MAX;
    queue[r]=value;
    count++;
    printf("Inserted element: %c\n", value);
}
void dequeue()
{
    if(count==0)
    {
        printf("Queue Underflow\n");
        return;
    }
    char value=queue[f];
    f=(f+1)%MAX;
    count--;
    printf("Deleted element: %c\n", value);
}
void display()
{
    if(count==0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i=0;i<count;i++)
    {
        int index=(f+i)%MAX;
        printf("%c ", queue[index]);
    }
    printf("\n");
}
int main()
{
    int choice;
    char value;
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to enqueue: ");
                scanf(" %c", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}