#include <stdio.h>
#include <stdlib.h>

/* Node for adjacency list */
typedef struct node
{
    int vertex;
    int weight;
    struct node *next;
}Node;

/* Graph structure */
typedef struct graph
{
    int vertices;
    Node **adjList;
}Graph;

/* Create new node */
Node* createNode(int v, int w)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

/* Create graph */
Graph* createGraph(int vertices)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = vertices;

    g->adjList = (Node**)malloc(vertices * sizeof(Node*));

    for(int i = 0; i < vertices; i++)
        g->adjList[i] = NULL;

    return g;
}

/* Add edge */
void addEdge(Graph* g, int src, int dest, int weight)
{
    Node* newNode = createNode(dest, weight);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    /* For undirected graph */
    newNode = createNode(src, weight);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

/* Display graph */
void displayGraph(Graph* g)
{
    for(int i = 0; i < g->vertices; i++)
    {
        Node* temp = g->adjList[i];

        printf("Vertex %d -> ", i);

        while(temp != NULL)
        {
            printf("(%d, w=%d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    Graph* g = createGraph(v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    int src, dest, weight;

    for(int i = 0; i < e; i++)
    {
        printf("Enter source destination weight: ");
        scanf("%d %d %d", &src, &dest, &weight);

        addEdge(g, src, dest, weight);
    }

    printf("\nAdjacency List Representation:\n");
    displayGraph(g);

    return 0;
}
