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
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E-1; i++) {
        for (int j = 0; j < E-i-1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

void Kruskal(struct Edge edges[], int V, int E) {
    sortEdges(edges, E);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Edges in MST:\n");

    for (int i = 0; i < E; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            Union(subsets, x, y);
        }
    }
}

int main() {
    int V = 4, E = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Kruskal(edges, V, E);

    return 0;
}