#include<stdio.h>
#define MAX 100
#define INF 9999

int main(){
    int n;
    int dist[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjancency matrix: \n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &dist[i][j]);
            if(i != j && dist[i][j] == 0)
                dist[i][j] = INF;
        }
    }

    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\n Shortest distance Matrix: \n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}




















// Time Complexity: Best: O(n^3), Average: O(n^3), Worst: O(n^3)
// Space Complexity: O(n^2)
// Explanation: Floyd-Warshall uses three nested loops over all vertices to
// update the distance matrix, so time is cubic and space stores the n x n matrix.