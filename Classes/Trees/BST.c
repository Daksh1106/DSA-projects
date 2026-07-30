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
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

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
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    struct node *root = NULL;
    struct node *found = NULL;
    int choice, value, key;
    int i;

    int dataset[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(dataset) / sizeof(dataset[0]);

    printf("Creating BST with: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2\n");
    for (i = 0; i < n; i++)
    {
        root = insert(root, dataset[i]);
        printf("%d inserted\n", dataset[i]);
    }

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