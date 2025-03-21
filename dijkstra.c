#include <stdio.h>
#include <limits.h>

#define V 6

int minDistance(int dist[], int sptSet[]) {
	int v;
    int min = INT_MAX, min_index;
    for ( v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];
    int i;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    int count;
    for ( count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        int v;
        for (v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    
    for (i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
int graph[V][V] = {
    {0, 4, 8, 0, 0, 0},
    {4, 0, 2, 6, 0, 0},
    {8, 2, 0, 3, 9, 0},
    {0, 6, 3, 0, 5, 7},
    {0, 0, 9, 5, 0, 1},
    {0, 0, 0, 7, 1, 0}
};

    dijkstra(graph, 0);
    return 0;
}
