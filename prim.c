#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    
    int G[v][v];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    
    printf("EDGE  -  WEIGHT\n");
    int no_edges = 0;
    bool selected[v];
    memset(selected, false, sizeof(selected));
    selected[0] = true; // Start from the first vertex

    int row, col;
    int total_weight = 0; // Variable to store the total weight of the MST

    while (no_edges < v - 1) {
        int min = INT_MAX; // Use INT_MAX for initialization
        row = 0; col = 0;

        for (int i = 0; i < v; i++) {
            if (selected[i]) {
                for (int j = 0; j < v; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            row = i;
                            col = j;
                        }
                    }
                }
            }
        }

        if (min == INT_MAX) {
            printf("No more edges to add.\n");
            break; // No more edges to add
        }

        printf("%d - %d : %d\n", row, col, G[row][col]);
        total_weight += G[row][col]; // Add the weight of the edge to total weight
        selected[col] = true;
        no_edges++;
    }

    printf("Total weight of the Minimum Spanning Tree: %d\n", total_weight); // Print total weight
    return 0;
}

