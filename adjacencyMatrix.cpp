#include<bits/stdc++.h>
#define MAX_VERTICES 50
#define MAX_DEGREE 50
using namespace std;

struct graph {
    int V;              //Number of Vertices
    int E;              //Number of Edges
    int **adjMatrix;    //Adjacency Matrix
};

typedef struct graph Graph;

struct edge {
    int source;
    int destination;
};

typedef struct edge Edge;

void randInit() {
    //Initializes the random generator rand()
    time_t t;
    srand((unsigned) time(&t));
}

Graph *createGraph(const int numVertices) {
    assert(numVertices >= 0);
    //Create an empty graph with numVertices
    int i, j;
    Graph *G = new Graph();
    G->V = numVertices;
    G->E = 0;

    //Allocate memory for each row
    G->adjMatrix = new int *[numVertices*sizeof(int)];

    assert(G != NULL);

    //allocate memory with each column 
    for(i=0; i<numVertices; i++) {
        G->adjMatrix[i] = new int[numVertices*sizeof(int)];
        assert(G->adjMatrix[i] != NULL);
    }

    return G;
}

void displayGraph(const Graph *G) {
    // Display the Graph (adjMatrix)
    int i, j, v;

    v = G->V;
    cout << "Vertices: " << G->V << " Edges: " << G->E << "\n";
    for(i=0; i<v; i++) {
        for(j=0; j<v; j++)
            cout << G->adjMatrix[i][j] << " ";

        cout << "\n";
    }
}

void displayEdges(const Graph *G) {
    int v,i,j;

    v = G->V;
    for(i=0; i<v; i++) {
        for(j=0; j<v; j++)
            if(G->adjMatrix[i][j] == 1) cout << "(" << i << " " << j << ")\n" ;

        cout << "\n";
    }
}

void insertEdge(Graph *G, const Edge E) {
    int v, x, y;
    v = G->V;
    x = E.source;
    y = E.destination;

    if(x >= v || y >= v) {
        cout << "Error when adding edge";
        return;
    }

    if(G->adjMatrix[x][y] == 0) { //For undirected graph set both the bits
        G->adjMatrix[x][y] = 1;
        G->adjMatrix[x][y] = 1;
        G->E += 1;
    }
}

void removeEdges(Graph *G, const Edge E) {
    int v, x, y;
    v = G->V;
    x = E.source;
    y = E.destination;

    if(x >= v || y >= v) {
        cout << "Error when deleting edge";
        return;
    }

    if(G->adjMatrix[x][y] == 1) {
        G->adjMatrix[x][y] = 0;
        G->adjMatrix[x][y] = 0;
        G->E -= 1;
    }
}

void destroyGraph(Graph *G) { //To Free Memory
    if(G) {
        if(G->adjMatrix) {
            for(int i=0; i<G->V; i++) {
                delete [] G->adjMatrix[i];
            }

            delete G->adjMatrix;
        }

        delete G;
    }
}

Edge newEdge(int x, int y){
    Edge E;
    E.source = x;
    E.destination = y;

    return E;
}

Graph *randomGraph (const int N, const float p) {
    //A random graph with N vertices and Probability p for each edge
    Edge E;
    Graph *G = createGraph(N);
    randInit();

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(rand() < p*RAND_MAX) { //rand() return between 0 and RAND_MAX
                E = newEdge(i, j);
                insertEdge(G, E);
            }
        }
    }

    return G;
}

int main() {
    Edge E;
    Graph *G = randomGraph(10, 0.15);
    displayGraph(G);
    E = newEdge(5, 6);
    insertEdge(G, E);
    displayGraph(G);
    cout << "\n";
    displayEdges(G);
    removeEdges(G, E);
    displayGraph(G);
    cout << "\n";
    displayEdges(G);
    displayGraph(G);
}