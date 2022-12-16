
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  void* dataPtr;
  struct node* next;
}NODE;

typedef struct{
  NODE* front;
  NODE* rear;
  int count;
}QUEUE;

QUEUE* createQueue();
QUEUE* destroyQueue(QUEUE* queue);

bool dequeue(QUEUE* queue, void** itemPtr);
bool enqueue(QUEUE* queue, void* itemPtr);
bool queueFront(QUEUE* queue, void** itemPtr);
bool queueRear(QUEUE* queue, void** itemPtr);
void printQueue(QUEUE* queue);


int main() {


    int* number;
    number=(int*)malloc(sizeof(int));
    *number=5;

    int* number2;
    number2=(int*)malloc(sizeof(int));
    *number2=7;

    QUEUE* x=createQueue();
    if(enqueue(x, number)){
        printf("Enqueue successful\n");
    }
     if(enqueue(x, number2)){
        printf("Enqueue successful\n");
    }

    printQueue(x);

    if(dequeue(x, (void*)&number)){
        printf("\nDequeue successful");
    }
    printQueue(x);
    if(dequeue(x, (void*)&number)){
        printf("\nDequeue successful");
    }
    printQueue(x);

    return 0;
}


QUEUE* createQueue(){

    QUEUE* queue;
    queue=(QUEUE*)malloc(sizeof(QUEUE));

    if (queue) {
        queue->front=NULL;
        queue->rear=NULL;
        queue->count=0;
    }

    return queue;

}

bool enqueue(QUEUE* queue, void* itemPtr){

    NODE* newPtr;
    if(!(newPtr=(NODE*)malloc(sizeof(NODE))))
        return false;

    newPtr->dataPtr = itemPtr;
    newPtr->next = NULL;
    if (queue->count == 0){
        queue->front = newPtr;
        queue->rear = newPtr;
    }
    else{
        queue->rear->next = newPtr;
    }
    (queue->count)++;
    queue->rear = newPtr;
    return true;
}

bool dequeue (QUEUE* queue, void** itemPtr)
{
  NODE* deleteLoc;

  if (!queue->count)
      return false;
  *itemPtr  = queue->front->dataPtr;
  deleteLoc = queue->front;

  if (queue->count == 1)
     queue->rear  = queue->front = NULL;
  else
     queue->front = queue->front->next;
  (queue->count)--;
  free (deleteLoc);
  return true;
}

bool queueFront (QUEUE* queue, void** itemPtr){
  if (!queue->count)
      return false;
else {
      *itemPtr = queue->front->dataPtr;
       return true;
     }
}

bool queueRear (QUEUE* queue, void** itemPtr){
    if (!queue->count)
        return true;
    else {
        *itemPtr = queue->rear->dataPtr;
        return false;
    }
}

QUEUE* destroyQueue (QUEUE* queue){
  NODE* deletePtr;
if (queue) {
      while (queue->front != NULL)
         {
          free (queue->front->dataPtr);
          deletePtr = queue->front;
          queue->front = queue->front->next;
          free (deletePtr);
         }
      free (queue);
     }
  return NULL;
}

void printQueue(QUEUE* queue){

    NODE* iter=queue->front;
    while (iter!=NULL){
        int* temp=(int*)(iter->dataPtr);
        printf("\n%d",*temp);
        iter=iter->next;
    }
    return ;
}
