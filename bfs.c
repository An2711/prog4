#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

void bfs(int **graph, size_t num_cities, int start) {
   // int visited[num_cities][num_cities];
    int visited[num_cities];
    int paths[num_cities];
    // integer array to keep track of shorest visited

    for(int i = 0; i < num_cities; i++){
        visited[i] = 0;
        paths[i] = -1;
    }
    Queue* q = createQueue((int)num_cities);
    enqueue(q, start);
    // set the first value in the paths to be 0
    paths[0] = 0;
    // while the q is not empty.
    while(isEmpty(q) == 0){
        int currCity = dequeue(q);
      //  printf("I just DEQUEUING city %d\n", currCity);
        if(currCity == num_cities -1){
            printf("the number of cities in the shortest path is %d\n", paths[currCity]);
            return;
        }
        for(int i = 0; i < num_cities; i++){
            if((graph[currCity][i] != 0) && (visited[i] == 0)){
                //printf("We are exploring the link is between city %d and city %d\n", currCity, i);
                visited[i] = 1;
                paths[i] = paths[currCity] + 1;
                enqueue(q, i);
                //printf("I just ENQUEUED city %d\n", i);
            }
        }
    }
    freeQueue(q);
}