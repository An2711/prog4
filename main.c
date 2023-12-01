#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bfs.h"
#include "dijkstra.h"


int main() {
    char fileName[30];
    int numCities;
    int links;
    scanf("%s\n", fileName);
    FILE *fptr;
    fptr = fopen(fileName, "r");
    if(fptr == NULL){
        printf("ERROR: file not found!\n");
        exit(0);
    }
    fscanf(fptr, "%d\n", &numCities);
    int** graph;
    graph = (int**)malloc(sizeof(int*)*numCities);
    //int graph[numCities][numCities];
    // initialize the graph to have all values be 0
    for(int i = 0; i < numCities; i++){
        graph[i] = (int*)malloc(numCities*sizeof(int));
        for(int j = 0; j < numCities; j++){
            graph[i][j] = 0;
        }
    }
    fscanf(fptr, "%d\n", &links);
    for(int i = 0; i < links; i++){
        int src;
        int dest;
        int time;
        fscanf(fptr, "%d", &src);
        fscanf(fptr, ",%d\n", &dest);
        fscanf(fptr, ",%d", &time);
        graph[src][dest] = time;
    }

    bfs(graph, numCities, 0);
    
}