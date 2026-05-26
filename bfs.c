#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

// queue 
int queue[MAX];
int front = 0, rear = 0;

// graph
int adj[MAX][MAX];
bool visited[MAX];
int n; // number of vertices

void enqueue(int x){
    queue[rear++] = x;
}

int dequeue(){
    return queue[front++];
}

bool isEmpty(){
    return front == rear;
}

void bfs(int start){
    visited[start] = true;
    enqueue(start);

    while(!isEmpty()){
        int u = dequeue();
        printf("%d ", u);

        for(int v = 0; v < n;v++){
            if(adj[u][v] == 1 && !visited[v]){
                visited[v] = true;
                enqueue(v);
            }
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjanceny matrix (1 if connected, 0 if not): \n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &adj[i][j]);
        }
    }

    printf("BFS traversal: ");
    bfs(0);
    printf("\n");

    return 0;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 // Time Complexity: Best: O(V + E), Average: O(V + E), Worst: O(V + E)
 // Space Complexity: O(V)
 // Explanation: BFS visits each vertex and edge at most once; the queue
 // and visited array store up to V vertices, so time is O(V+E) and space is O(V).

/*
4 vertices
Adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
*/