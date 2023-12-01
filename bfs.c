#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

void bfs(int **graph, size_t num_cities, int start) {
   // int visited[num_cities][num_cities];
    int visited[num_cities];
    int paths[num_cities];
    // integer array to keep track of shorest visited

    for(int i = 0; i < num_cities; i++){
        for(int j = 0; j < num_cities; j++){
            printf("LLLLLLLLL\n");
            printf("%d\n", graph[i][j]);
        }
    }

    for(int i = 0; i < num_cities; i++){
        visited[i] = 0;
        paths[i] = -1;
    }
    Queue* q = createQueue((int)num_cities);
    enqueue(q, start);
    paths[0] = 0;
    while(isEmpty(q) == 0){
        int currCity = dequeue(q);
        if(currCity == num_cities -1){
            printf("the shortest distance %d\n", paths[currCity] - 1);
            return;
        }
        for(int i = 0; i < num_cities; i++){
            if((graph[currCity][i] != 0) && (visited[i] == 0)){
                printf("%d\n", graph[currCity][i]);
                visited[i] == 1;
                paths[i] = paths[currCity] + 1;
                enqueue(q, i);
            }
        }
    }
    freeQueue(q);
}