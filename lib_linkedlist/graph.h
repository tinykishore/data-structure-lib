#include <iostream>

void createMatrix(int graph[100][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            printf("edge between %c & %c: ", 65 + i, 65 + j);
            scanf("%d", &graph[i][j]);
            graph[j][i] = graph[i][j];
        }
    }
}

void printMatrix(int graph[100][100], int n) {
    int i, j;
    printf("\n\nAdjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void dfs(int graph[100][100], int visited[], int n, int v) {
    int i;
    printf("%c visited\n", 65 + v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, n, i);
        }
    }
}

//
//int main() {
//    //printf("hello");
//    int graph[100][100], n;
//    int visited[100];
//
//    printf("enter number of vertices: ");
//    scanf("%d", &n);
//
//    createMatrix(graph, n);
//    printMatrix(graph, n);
//
//    dfs(graph, visited, n, 1);
//
//    return 0;
//}