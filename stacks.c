#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ------------------ Adjacency List ------------------

struct Node {
    int vertex;
    struct Node* next;
};

struct GraphList {
    int numVertices;
    struct Node* adjLists[MAX];
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph using adjacency list
struct GraphList* createGraphList(int vertices) {
    struct GraphList* graph = (struct GraphList*) malloc(sizeof(struct GraphList));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdgeList(struct GraphList* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print adjacency list
void printGraphList(struct GraphList* graph) {
    printf("\nAdjacency List:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ------------------ Adjacency Matrix ------------------

struct GraphMatrix {
    int numVertices;
    int adjMatrix[MAX][MAX];
};

// Create a graph using adjacency matrix
struct GraphMatrix* createGraphMatrix(int vertices) {
    struct GraphMatrix* graph = (struct GraphMatrix*) malloc(sizeof(struct GraphMatrix));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;

    return graph;
}

// Add edge (undirected)
void addEdgeMatrix(struct GraphMatrix* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Print adjacency matrix
void printGraphMatrix(struct GraphMatrix* graph) {
    printf("\nAdjacency Matrix:\n    ");
    for (int i = 0; i < graph->numVertices; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d | ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// ------------------ Main Function ------------------

int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct GraphList* graphList = createGraphList(vertices);
    struct GraphMatrix* graphMatrix = createGraphMatrix(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdgeList(graphList, src, dest);
        addEdgeMatrix(graphMatrix, src, dest);
    }

    printGraphList(graphList);
    printGraphMatrix(graphMatrix);

    return 0;
}