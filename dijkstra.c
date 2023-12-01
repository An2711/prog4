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
    int paths[num_cities];
    for(int i = 0; i < num_cities; i++){
        parent[i] = -1;
        time[i] = INT_MAX;
        processed[i] = 0;
        paths[i] = 0;
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
            if((graph[U][j] != 0) && (processed[j]==0) && (time[U] != INT_MAX) && (time[U]+graph[U][j] < time[j])){
                // printf("Im here\n");
                time[j] = time[U] + graph[U][j];
                parent[j] = U;
                paths[j] = paths[U]+1;
            }
        }
    } 
    // int sum = 0;
    // for(int i = 0; i < num_cities; i++){
    //     printf("the path for %d is %d\n", i, paths[i]);
    // }
    
    //printf("The shortest time is %d\n", sum);
    if(K != -1){
        if((paths[num_cities - 1]) > K){
            printf("%d\n", -1);
            
        }
        else{
            printf("you can reach the destination is less than %d cities\n", K);
        }
    }
    else{
        int sum = 0;
        sum = time[num_cities - 1];
        printf("The shortest time is %d\n", sum);
    }
}