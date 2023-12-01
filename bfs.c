#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

void bfs(int **graph, size_t num_cities, int start) {
   // int visited[num_cities][num_cities];
    int visited[num_cities];
    int path[num_cities];
    // integer array to keep track of shorest visited

    for(int i = 0; i < num_cities; i++){
        // for(int j = 0; j < num_cities; j++){
        //     visited[num_cities][num_cities] = 0;

        // }
        visited[i] = 0;
        path[i] = -1;
    }
    Queue* q = createQueue((int)num_cities);
    enqueue(q, start);
    while(isEmpty(q) == 0){
        int currCity = dequeue(q);
       // printf("%d\n", currCity);
       // printf("%d\n",graph[currCity][num_cities-1] != 0);
       // 
        for(int i = 0; i < num_cities; i++){
            if((graph[currCity][i] != 0) && (visited[currCity][i] == 0)){
                printf("%d\n", graph[currCity][i]);
                visited[currCity][i] == 1;
                path[i] = currCity;
                enqueue(q, i);
                if(i == n -1)

                
            }

        }
    }
    freeQueue(q);

}