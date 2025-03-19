#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge *result = (struct Edge *)malloc((V - 1) * sizeof(struct Edge)); 
    int e = 0; 
    int i = 0; 

    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;
    while (e < V - 1 && i < E) { 
        struct Edge next_edge = edges[i++]; 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) { 
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edge \t Weight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
    free(result);
}

int main() {
    int V = 4, E = 5;
    struct Edge edges[] = {
        {0, 1, 8},
    	{0, 2, 5},
    	{1, 2, 3},
    	{1, 3, 7},
    	{2, 3, 6}
    };
    kruskalMST(edges, V, E);
    return 0;
}

