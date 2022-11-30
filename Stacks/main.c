#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int process = 1;
    int* temp;
    stack* s1=NULL;
    
    while(process != 0){
        printf("======== Main Menu ========\n");
        printf(" 1 -> Create Stack\n 2 -> Push Stack\n 3 -> Pop Stack\n 4 -> Stack Top\n 5 -> Is Empty? \n 6 -> Stack Count\n 7 -> Destroy Stack\n 8 -> Print Stack\n");
        printf("Select The Process:");
        scanf("%d",&process);

        switch(process){
            case 1:
                s1=createStack();
                break;
                
            case 2:
                printf("Enter the value:\n");
                temp = (int*)malloc(sizeof(int));
                scanf("%d",temp);
                if(pushStack(s1, temp)){
                    printf("Added succesfully!\n");
                }
                else
                    printf("It cannot be added!\n");
                break;

            case 3:
                
                temp = (int*)malloc(sizeof(int));
                temp=popStack(s1);
                
                if(temp==NULL)
                    printf("It cannot be popped!");
                else
                    printf("Popped succesfully!\n");
                    
                break;
            case 4:
                temp=stackTop(s1);
                if(temp==NULL)
                    printf("There is no element in this stack!\n");
                else
                    printf("The top of this stack is:%d\n",*temp);
                
                break;
                
            case 5:
                if(isEmpty(s1))
                    printf("This stack is empty\n");
                else
                    printf("This stack is not empty\n");
                
                break;

            case 6:
                printf("%d\n",stackCount(s1));
                break;
            case 7:
                
                s1=destroyStack(s1);
                
                if(s1==NULL){
                    printf("Stack was destroyed!\n");
                }
                else{
                    printf("Stack cannot be destroyed!\n");
                }
                break;
                
            case 8:
                printStack(s1);
                break;
                
            default:
                printf("Invalid Value!\n");
                break;
        }

    }
    
    
    
    
    return 0;
}
