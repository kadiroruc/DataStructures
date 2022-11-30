#ifndef stack_h
#define stack_h


#endif /* stack_h */
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    void *dataPtr;
    struct Node* link;
}node;

typedef struct Stack{
    int count;
    node* top;
}stack;


stack* createStack(void){
    stack* temp=(stack *)malloc(sizeof(stack));
    if(temp){
        temp->count=0;
        temp->top=NULL;
    }
    printf("Stack has been created.\n");
    return temp;
    
}

bool pushStack(stack* s,void* dataPtr){
    
    if(s){
        node* temp=(node*)malloc(sizeof(node));
        if(!temp)
            return false;
        
        temp->dataPtr=dataPtr;
        temp->link=s->top;
        s->top=temp;
        (s->count)++;
        return true;
    }
    else
        return  false;
}

void* popStack(stack* s){
    node* temp;
    void* dataOutPtr;
    if(s->count==0)
        dataOutPtr= NULL;
    
    else{
    temp=s->top;
    dataOutPtr=s->top->dataPtr;
    s->top=s->top->link;
    free(temp);
    s->count=s->count-1;
        
    }
    return dataOutPtr;
}

void* stackTop(stack* s){
    if(s->count==0){
        return NULL;
    }
    else{
        return s->top->dataPtr;
    }
}

bool isEmpty(stack* s){
    return (s->count==0);
}

int stackCount(stack* s){
    return s->count;
}

stack* destroyStack(stack* s){
        
    stack* temp;
    
    if(s!=NULL){
        
        while (s->top!=NULL) {
            free(s->top->dataPtr);
            temp=s->top;
            s->top=s->top->link;
            free(temp);
            (s->count)--;
        }
        return NULL;
    }
    else{
        return s;
    }
        
}

void printStack(stack* s){
    if(s!=NULL){
        node* temp=s->top;
        while (temp!=NULL) {
            printf("%d\t\n",*((int*)temp->dataPtr));
            temp=temp->link;
        }
    }
    else{
        printf("There is no stack!\n");
    }
    
    
}
