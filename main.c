#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bfs.h"
#include "dijkstra.h"
#include "stdbool.h"


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
    fclose(fptr);

    int comm;
    bool flag = true;
    scanf("%d\n", &comm);
    while(flag){
        switch(comm){
            case 0:
                printf("Command is zero\n");
                bfs(graph, numCities, 0);
                scanf("%d\n", &comm);
                break;

            case 1:
                //printf("Command is one\n");
                scanf("%d\n", &comm);
                // QUESTION: what value can we assume k will be when it is just command 1
                dijkstra(graph, numCities, 0, -1);
                break;

            case 2:
                //printf("Command is two\n");
                int comm2;
                scanf("%d\n", &comm2);
                dijkstra(graph, numCities, 0, comm2);
                scanf("%d\n", &comm);
                break;
            case 3:
                //printf("Command is tree\n");
                flag = false;
                printf("Goodbye!\n");
                break;
            default:
                //printf("in the default\n");
                scanf("%d\n", &comm);
                break;
        }


    }


    //bfs(graph, numCities, 0);
    //dijkstra(graph, numCities, 0, 5);
    
}