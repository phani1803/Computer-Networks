#include <stdio.h>
#define N 5 // Number of hosts (nodes) in the subnet
void broadcastTree(int adjacencyMatrix[N][N], int root) {
 int queue[N];
 int front = -1, rear = -1,i;
 int visited[N] = {0};
 queue[++rear] = root;
 visited[root] = 1;
 printf("Broadcast tree for the subnet:\n");
 printf("Root node: %d\n", root);
 while (front < rear) {
 int currentNode = queue[++front];
 printf("Node %d -> ", currentNode);
 for (i = 0; i < N; i++) {
 if (adjacencyMatrix[currentNode][i] && !visited[i]) {
 queue[++rear] = i;
 visited[i] = 1;
 }
 }
 }
 printf("END\n");
}
int main() {
 int adjacencyMatrix[N][N] = {
 {0, 1, 1, 0, 0},
 {1, 0, 1, 1, 0},
 {1, 1, 0, 1, 1},
 {0, 1, 1, 0, 1},
 {0, 0, 1, 1, 0}
 };
 int root = 0; // The root node for the broadcast tree
 broadcastTree(adjacencyMatrix, root);
 return 0;
}
