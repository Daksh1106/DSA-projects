#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

void insert_end(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void insert_pos(int data, int pos)
{
    struct node *newnode, *temp;
    int i;
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        insert_begin(data);
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void delete_begin()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Deleted element: %d\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void delete_end()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("Deleted element: %d\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void delete_pos(int pos)
{
    struct node *temp;
    int i;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void search(int key)
{
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, data, pos, key;
    while (1)
    {
        printf("\n1. Insert at begin");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete at begin");
        printf("\n5. Delete at end");
        printf("\n6. Delete at position");
        printf("\n7. Display");
        printf("\n8. Search");
        printf("\n9. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_begin(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_pos(data, pos);
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}