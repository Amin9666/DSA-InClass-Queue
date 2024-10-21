#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxQ 10 

typedef struct {
    int head, tail;
    int QA[MaxQ];
} QType, *Queue;

// Initialize the queue
Queue initQueue() {
    Queue qp = (Queue)malloc(sizeof(QType));
    qp->head = qp->tail = 0;
    return qp;
}

int empty(Queue Q) {
    return (Q->head == Q->tail);
}

int dequeue(Queue Q) {
    if (empty(Q)) {
        printf("\nAttempt to remove from an empty queue\n");
        exit(1);
    }
    if (Q->head == MaxQ - 1) 
        Q->head = 0;
    else 
        ++(Q->head);
    return Q->QA[Q->head];
}

void enqueue(Queue Q, int n) {
    if (Q->tail == MaxQ - 1) 
        Q->tail = 0;
    else 
        ++(Q->tail);
    if (Q->tail == Q->head) {
        printf("\nQueue is full\n");
        exit(1);
    }
    Q->QA[Q->tail] = n;
}

void printQueueStatus(Queue Q) {
    printf("Queue status: [");
    int i = Q->head;
    while (i != Q->tail) {
        if (i == MaxQ - 1) i = 0;
        else i++;
        printf("%c", Q->QA[i]);
        if (i != Q->tail) {
            printf(", ");
        }
    }
    printf("] (Head: %d, Tail: %d)\n", Q->head, Q->tail);
}

int main() {
    Queue Q = initQueue();
    char sequence[] = "Boo*kof**AlgorithmsAnd**Data*Stru***cture";  
    int length = strlen(sequence);

    printf("Processing sequence: %s\n\n", sequence);

    for (int i = 0; i < length; i++) {
        char input = sequence[i];

        if (input == '*') { 
            int dequeued = dequeue(Q);
            printf("Dequeued '%c'\n", dequeued);
        } else {  
            enqueue(Q, input);
            printf("Enqueued '%c'\n", input);
        }

        printQueueStatus(Q);
    }

    printf("\nProgram ended.\n");

    return 0;
}
