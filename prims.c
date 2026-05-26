#include<stdio.h>
#include<limits.h>

#define V 5

int minKey(int key[], int mstSet[]){
    int min = INT_MAX, min_index = -1;

    for(int v = 0; v < V; v++){
        if(!mstSet[v] && key[v] < min){
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]){
    printf("Edge \tWeight\n");
    int total = 0;
    for(int i = 1;i < V;i++){
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total weight of MST: %d\n", total);
}

void primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    int mstSet[V];

    for(int i = 0;i < V;i++){
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for(int v = 0; v < V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main(){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}




















// Time Complexity: Best: O(V^2), Average: O(V^2), Worst: O(V^2)
// Space Complexity: O(V^2)
// Explanation: This implementation uses an array-based min selection (`minKey`) and
// adjacency matrix representation; selecting the minimum key takes O(V) per iteration
// and we do V iterations, giving O(V^2). The graph is stored as VxV matrix.
