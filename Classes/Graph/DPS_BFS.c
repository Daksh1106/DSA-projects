#include <stdio.h>
int graph[20][20];
int visited[20];
int n;
/* BFS Traversal */
void BFS(int start)
{
    int queue[20];
    int front = 0, rear = 0;
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
/* DFS Traversal */
void DFS_Traversal(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS_Traversal(i);
    }
}
/* DFS for Connectivity */
void DFS(int v)
{
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}
int main()
{
    int choice, start;
    int i, j;
    printf("Enter Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    while (1)
    {
        printf("1. BFS Traversal\n2. DFS Traversal\n3. Check Connectivity using DFS\n4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Starting Vertex: ");
            scanf("%d", &start);
            BFS(start);
            break;
        case 2:
            printf("Enter Starting Vertex: ");
            scanf("%d", &start);
            for (i = 0; i < n; i++)
                visited[i] = 0;
            printf("DFS Traversal: ");
            DFS_Traversal(start);
            printf("\n");
            break;
        case 3:
            for (i = 0; i < n; i++)
                visited[i] = 0;
            DFS(0);
            for (i = 0; i < n; i++)
            {
                if (visited[i] == 0)
                {
                    printf("Graph is NOT Connected\n");
                    break;
                }
            }
            if (i == n)
                printf("Graph is Connected\n");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid Choice\n");
        }
    }
}
