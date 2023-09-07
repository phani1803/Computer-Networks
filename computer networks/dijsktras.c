#include <stdio.h>
#define INFINITY 9999
#define max 10
void dijkstra(int G[max][max], int n, int startnode)
{
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 0;
    while (count < n)
    {
        mindistance = INFINITY;
        nextnode = -1; // Initialize to invalid value
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        if (nextnode == -1)
            break; // No more reachable nodes
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i] && mindistance + cost[nextnode][i] < distance[i])
            {
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;
            }
        }
        count++;
    }
    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            printf("\nDistance of node %d = %d", i + 1, distance[i]);
            printf("\nPath = %d", i + 1);
            j = i;
            do
            {
                j = pred[j];
                printf(" <- %d", j + 1);
            } while (j != startnode);
        }
}
int main()
{
    int ord, i, j, u, G[max][max];
    printf("Enter the required order of the matrix:");
    scanf("%d", &ord);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < ord; i++)
        for (j = 0; j < ord; j++)
            scanf("%d", &G[i][j]);
    printf("Enter where you want to start (1-%d):", ord);
    scanf("%d", &u);
    dijkstra(G, ord, u - 1);
    return 0;
}
