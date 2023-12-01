#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCity(int t[], int p[], int num_cities){
    int min = INT_MAX;
    int ind;
    for(int i = 0; i < num_cities - 1; i++){
        if(p[i] == 0 && t[i] < min){
            ind = i;
            min = t[i];
        }
    }
    return ind;
}

// Function to perform Dijkstra's algorithm on a graph represented as an adjacency matrix
void dijkstra(int **graph, int num_cities, int src, int K) {
    int parent[num_cities];
    int time[num_cities];
    int processed[num_cities];
    int U;
    for(int i = 0; i < num_cities; i++){
        for(int j = 0; j < num_cities; j++){
            printf("THe values is %d\n", graph[i][j]);
        }
    }

    for(int i = 0; i < num_cities; i++){
        parent[i] = -1;
        time[i] = INT_MAX;
        processed[i] = 0;
    }
    // for(int i = 0; i < num_cities; i++){
    //     printf("%d\n", time[i]);
    // }
    time[0] = 0;
    for(int i = 1; i < num_cities; i++){
        // select the minimum value
        U = minCity(time, processed, num_cities);
        processed[U] = 1;
    
    // select adjacent verrtices not yet includes
        for(int j = 0; j < num_cities; j++){
            // printf("HHHH\n");
            // printf("j is %d\n", j);
            // printf("%d\n", graph[U][j]);
            printf("U is %d\n", U);
            if((graph[U][j] != 0) && (processed[j]==0) && (time[U] != INT_MAX) && (time[U]+graph[U][j] < time[j])){
                // printf("Im here\n");
                time[j] = time[U] + graph[U][j];
               
                parent[j] = U;
            }
        }
    }
    for(int i = 0; i < num_cities; i++){
        printf("%d\n", time[i]);
    }
    int sum = 0;
    int curr = num_cities -1;
    int p = parent[curr];
    while(p != -1){
        sum += time[curr];
        curr = p;
        p = parent[curr];
    }
    printf("\n");
    printf("The shortest time is %d\n", sum);
}