
#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int x;
    struct N* next;
    struct N* prev;
}node;

void yazdir(node* r){
    node* iter=r;
    if(iter->next==NULL){
        printf("There is no element");
    }
    else{
        while(iter!=NULL){
            printf("%d\n",iter->x);
            iter=iter->next;
        }
        printf("\n");
    }
}

node* siraliEkle(node* r,int x){

    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=x;
        r->next=NULL;
        r->prev=NULL;
        return r;
    }
    if(r->x>x){
        node* temp=(node*)malloc(sizeof(node));
        temp->x=x;
        temp->next=r;
        r->prev=temp;
        temp->prev=NULL;
        return temp;

    }
    node* iter=r;
    while(iter->next!=NULL&&iter->next->x<x){
        iter=iter->next;
    }
    node* temp=(node*)malloc(sizeof(node));
    temp->x=x;
    temp->next=iter->next;
    iter->next=temp;
    temp->prev=iter;
    if(temp->next!=NULL)
        temp->next->prev=temp;
    return r;
}

node* sil(node* r,int x){
    node* temp;
    node* iter=r;
    if(r->x==x){
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }

    while(iter->next!=NULL&&iter->next->x!=x){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("The searched value cannot be found!\n");
        return r;
    }
    else{
        temp=iter->next;
        iter->next=iter->next->next;
        free(temp);
        if(iter->next!=NULL)
            iter->next->prev=iter;
        return r;
    }
}

int main ()
{
    node* root;
    root=NULL;
    root=siraliEkle(root,30);
    root=siraliEkle(root,20);
    root=siraliEkle(root,10);
    root=siraliEkle(root,40);
    root=siraliEkle(root,35);
    yazdir(root);

    root=sil(root,10);
    yazdir(root);

}
