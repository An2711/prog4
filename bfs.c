#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

void bfs(int **graph, size_t num_cities, int start) {
    int visited[num_cities][num_cities];
    for(int i = 0; i < num_cities; i++){
        for(int j = 0; j < num_cities; j++){
            visited[num_cities][num_cities] = 0;
        }
    }
    Queue* q = createQueue((int)num_cities);
    enqueue(q, start);
    while(isEmpty(q) != 0){
        int currCity = dequeue(q);
        for(int i = 0; i < num_cities; i++){
            if((graph[currCity][i] != 0) && (visited[currCity][i] == 0)){
                
            }
        }
    }

}