#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];      // To track visited nodes
int parent[MAX];       // To reconstruct path
int found = 0;         // Flag to indicate if destination is found

// Recursive DFS function
void dfs(int current, int end, int n) {
    visited[current] = 1;

    if (current == end) {
        found = 1;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            parent[i] = current;
            dfs(i, end, n);
            if (found) return; // stop recursion when path is found
        }
    }
}

// Function to print the path from start to end
void printPath(int start, int end) {
    int path[MAX];
    int len = 0;

    for (int v = end; v != -1; v = parent[v])
        path[len++] = v;

    printf("Path Found: ");
    for (int i = len - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("\n");
}

int main() {
    int n, e;
    printf("Enter number of locations (nodes): ");
    scanf("%d", &n);

    printf("Enter number of roads (edges): ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter roads (pairs of connected locations):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // since roads are two-way
    }

    int start, end;
    printf("Enter start and end location: ");
    scanf("%d %d", &start, &end);

    // Initialize visited and parent arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    dfs(start, end, n);

    if (found)
        printPath(start, end);
    else
        printf("No path found from %d to %d\n", start, end);

    return 0;
}
