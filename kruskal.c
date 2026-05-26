#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
}Edge;

int parent[MAX];

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b){
    parent[find(a)] = find(b);
}

int compare(const void* a, const void* b){
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int main(){
    int n, e;
    Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v w):\n");
    for(int i = 0;i < e;i++){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for(int i = 0;i < n;i++)
        parent[i] = i;

    qsort(edges, e, sizeof(Edge), compare);

    int cost = 0;
    printf("Edges in MST:\n");

    for(int i = 0;i < e;i++){
        int pu = find(edges[i].u);
        int pv = find(edges[i].v);

        if(pu != pv){
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(pu, pv);
        }
    }

    printf("Total cost = %d\n", cost);
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 // Time Complexity: Best: O(E log E), Average: O(E log E), Worst: O(E log E)
 // Space Complexity: O(E)
 // Explanation: Sorting the edges dominates at O(E log E) (qsort). Union-Find
 // operations are near-linear; storing edges and parent arrays requires O(E)/O(V).