#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
#include "common.h"
#include "common_threads.h"
*/

void *incrementArray(int *arr, int start, int end) {
    for(int i=start; i<=end; ++i){
        printf("%d\n", i);
    }
}

int main(int argc, char *argv[]) {                    
    if (argc != 1) {
	fprintf(stderr, "usage: main\n");
	exit(1);
    }

    pthread_t p1, p2;
    printf("main: begin\n");
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Pthread_create(&p1, NULL, incrementArray, arr, 0, 5); 
    Pthread_create(&p2, NULL, incrementArray, arr, 6, 10);
    // join waits for the threads to finish
    Pthread_join(p1, NULL); 
    Pthread_join(p2, NULL); 
    printf("main: end\n");
    return 0;
}

// gcc -o main main.c -Wall -pthread