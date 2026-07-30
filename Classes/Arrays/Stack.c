#include <stdio.h>
#include <stdlib.h>
#define MAX 10
 
int stack[MAX];
int type_flag[MAX]; /* 0 = integer, 1 = character */
int top = -1;
 
void push()
{
    int type;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element type (1=Integer, 2=Character): ");
    scanf("%d", &type);
    if (type == 1)
    {
        int value;
        printf("Enter integer element: ");
        scanf("%d", &value);
        stack[++top] = value;
        type_flag[top] = 0;
    }
    else if (type == 2)
    {
        char value;
        printf("Enter character element: ");
        scanf(" %c", &value);
        stack[++top] = (int)value;
        type_flag[top] = 1;
    }
    else
    {
        printf("Invalid type\n");
    }
}
 
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    if (type_flag[top] == 1)
        printf("Popped element: %c\n", (char)stack[top]);
    else
        printf("Popped element: %d\n", stack[top]);
    top--;
}
 
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        if (type_flag[i] == 1)
            printf("%c ", (char)stack[i]);
        else
            printf("%d ", stack[i]);
    }
    printf("\n");
}
 
int main()
{
    int choice;
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
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
}