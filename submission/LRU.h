#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct lru_ // job node definition
{   
    int val; /*identifier of job*/
    struct lru_ *next; /* next job in the list */
    struct lru_ *prev;
    int commandCount;
} LRU;

typedef struct queue { // queue definition
    LRU *head; // head Pointer
    LRU *tail; // tail Pinter
    int size;
} Queue;

// functions about a job
LRU* newNode(int val) ; // construction function for a new job
void freeALRU(LRU *j) // Deconstruction function for an old job


// functions about a queue
Queue* newQueue(); // constructing function for Queue
void freeAQueue(Queue *q); // Deconstruction function for an old queue
LRU* pushBack(Queue *q, int val); // push a job in the queue
void deleteHead(Queue *q); // delete a job currenlt in the queue
void delAndPush(Queue* q, LRU* j);

#endif