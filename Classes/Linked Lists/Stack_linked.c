#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    top = top->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
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