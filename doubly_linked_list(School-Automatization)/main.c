#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "linked_list.h"


int main()
{
    char name[20],surname[20],department[20];
    long long* number;
    int* year;

    int process = 1;

    while(process != 0){
        printf("======== Main Menu ========\n");
        printf("\n1 -> Adding Node\n2 -> Search Node\n3 -> Delete Node\n4 -> Destroy List\n5 -> Print List\n6 -> Exit\n");
        printf("\nSelect The Process:\n");
        scanf("%d",&process);

        switch(process){
            case 1:
                year=(int *)malloc(sizeof(int));
                number=(long long *)malloc(sizeof(long long));
                printf("Student's Name:\n");
                scanf("%s",name);
                printf("Student's Surname:\n");
                scanf("%s",surname);
                printf("Student's Department:\n");
                scanf("%s",department);
                printf("Student's Number:\n");
                scanf("%lld",number);
                printf("Student's Year:");
                scanf("%d",year);

                addNode(name , surname , department , number , year);
                break;

            case 2:
                printf("Enter the student's number to be searched:\n");
                long long x;
                scanf("%lld",&x);
                long long* p1;
                p1=&x;
                searchNode(p1);
                break;

            case 3:
                printf("Enter the student's number to be deleted:\n");
                long long y;
                scanf("%lld",&y);
                long long* p2;
                p2=&y;
                deleteNode(p2);
                break;

            case 4:
                destroyList();
                break;

            case 5:
                printf("Students' Informations:\n\n");
                printList();
                break;

            case 6:
                process=0;
                break;

            default:
                printf("Invalid Value!\n");
                break;
        }

   }
    return 0;
}
