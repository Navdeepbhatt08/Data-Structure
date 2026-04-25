#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

typedef struct graph
{
    int vertices;
    Node **adjList;
    int *visited;
} Graph;

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));

    g->vertices = vertices;

    g->adjList = (Node **)malloc(vertices * sizeof(Node *));
    g->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}

void addEdge(Graph *g, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

void DFS(Graph *g, int vertex)
{
    Node *temp;

    g->visited[vertex] = 1;
    printf("%d ", vertex);

    temp = g->adjList[vertex];

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (!g->visited[connectedVertex])
        {
            DFS(g, connectedVertex);
        }

        temp = temp->next;
    }
}

int main()
{
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph *g = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dest);

        addEdge(g, src, dest);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(g, start);

    return 0;
}