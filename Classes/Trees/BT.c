#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value)
{
    struct node *newnode = createnode(value);
    if (root == NULL)
        return newnode;

    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct node *temp = queue[front++];

        if (temp->left == NULL)
        {
            temp->left = newnode;
            return root;
        }
        else
            queue[rear++] = temp->left;

        if (temp->right == NULL)
        {
            temp->right = newnode;
            return root;
        }
        else
            queue[rear++] = temp->right;
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    struct node *left_result = search(root->left, key);
    if (left_result != NULL)
        return left_result;

    return search(root->right, key);
}

int main()
{
    struct node *root = NULL;
    struct node *found = NULL;
    int choice, value, key;

    while (1)
    {
        printf("\n1. Insert Element\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter integer value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d inserted\n", value);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter element to search: ");
            scanf("%d", &key);
            found = search(root, key);
            if (found != NULL)
                printf("Element %d found in tree\n", found->data);
            else
                printf("Element %d not found\n", key);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}