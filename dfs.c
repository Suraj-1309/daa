#include<stdio.h>
#include<stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n;

void dfs(int u){
    visited[u] = true;
    printf("%d ",u);

    // visit all unvisited neighbours
    for(int v = 0;v < n;v++){
        if(adj[u][v] == 1 && !visited[v]){
            dfs(v);
        }
    }
}

int main(){
    printf("Enter number of veritces: ");
    scanf("%d", &n);

    printf("Enter adjancency martix (1 if connected, 0 if not): \n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &adj[i][j]);
        }
    }

    printf("DFS traversal: ");
    dfs(0);
    printf("\n");
    
    return 0;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 // Time Complexity: Best: O(V + E), Average: O(V + E), Worst: O(V + E)
 // Space Complexity: O(V)
 // Explanation: DFS explores each vertex and edge once (recursively or via a stack),
 // so time is O(V+E). Recursion/stack and visited array use O(V) space.

/*
4 vertices
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
*/