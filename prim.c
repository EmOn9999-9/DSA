#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];
    int count, u, v;
    
    for (count = 0; count < V; count++) {
        key[count] = INT_MAX;
        mstSet[count] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    
    for (count = 0; count < V - 1; count++) {
        u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printf("Edge \t Weight\n");
    int i;
    for ( i = 1; i < V; i++) {
        printf("%d - %d \t %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 7, 0},
        {4, 0, 6, 0, 3},
        {0, 6, 0, 5, 8},
        {7, 0, 5, 0, 2},
        {0, 3, 8, 2, 0}
    };
    primMST(graph);
    return 0;
}
