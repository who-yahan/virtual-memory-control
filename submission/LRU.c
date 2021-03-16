#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include "LRU.h"

LRU* newNode(int val) 
{ 
    LRU* temp = (LRU*)malloc(sizeof(Job)); 
    temp->next = NULL;
    temp->prev = NULL;
    temp->val = val;
    return temp; 
}

void freeALRU(LRU *j) { // Deconstruction
    free(j);
}


Queue* newQueue() { // constructing function for Queue
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void freeAQueue(Queue *q) { // Deconstruction function for an old job
    LRU *temp = q->head;
    while (temp != NULL) {
        LRU *current = temp;
        temp = temp->next;
        freeALRU(current);
    }
    free(q);
}

LRU* pushBack(Queue *q, int val) { // push a job in the queue
    LRU* j = newNode(val); 
    if (q->head == NULL) { // if queue is empty
        q->head = j;
        q->tail = j;
    }
    else {
        j->prev=q->tail;
        q->tail->next = j;
        q->tail = q->tail->next;
    }
    q->size += 1;
    return j;
}

void deleteHead(Queue *q) {
    if (q->size == 0) return;
    LRU* j = q->head;
    q->head = q->head->next;
    q->head->prev=NULL;
    q->size -= 1;
    freeALRU(j);
}

// move the LRU to the end
void delAndPush(Queue* q, LRU* j){
    if(j == q->tail){ // if j is the tail
        return;
    }

    // j disconnect with next
    j->next->prev = j->prev;

    if(j != q->head){ 
        j -> prev -> next = j->next;
    }else{ // if j is the head
        q->head = j->next;
    }
    
    j->next = NULL;
    j->prev = q->tail;
    q->tail->next = j;
    q->tail = j;    
}




