#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define MAX 30

int parent[MAX];

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b; // Merge the sets
}

int main() {
    int n;
    int cost[MAX][MAX];
    int i, j, a, b, u, v;
    int ne = 0, mincost = 0, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) // Avoid setting diagonal to INF
                cost[i][j] = INT_MAX;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i; // Initialize parent array

    printf("Edge \tWeight\n");
    while (ne < n - 1) {
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (min == INT_MAX) {
            printf("No more edges to add.\n");
            break; // No more edges to add
        }

        union_set(u, v);
        printf("%d - %d\t%d\n", a, b, min);
        mincost += min;
        ne++;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}
