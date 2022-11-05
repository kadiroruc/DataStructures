
#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int x;
    struct N* next;
}node;

void yazdir(node* r){
    node* iter=r;
    if(iter->next==NULL){
        printf("There is no element");
    }
    else{
        printf("%d\n",iter->x);
        iter=iter->next;
        while(iter!=r){
            printf("%d\n",iter->x);
            iter=iter->next;
        }
        printf("\n");
    }
}

node* siraliEkle(node* r,int x){
    node* iter=r;

    if(iter==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=x;
        r->next=r;
        return r;
    }
    if(iter->x>x){
        node* temp=(node*)malloc(sizeof(node));
        temp->x=x;
        temp->next=iter;
        while(iter->next!=r)
            iter=iter->next;
        iter->next=temp;
        return temp;
    }
    iter=r;
    while(iter->next!=r&&iter->next->x<x){
        iter=iter->next;
    }
    node* temp=(node*)malloc(sizeof(node));
    temp->x=x;
    temp->next=iter->next;
    iter->next=temp;
    return r;
}

node* sil(node* r,int x){
    node* iter=r;
    if(r->x==x){
        while(iter->next!=r)
            iter=iter->next;
        iter->next=r->next;
        free(r);
        return iter->next;
    }
    iter=r;
    while(iter->next!=r&&iter->next->x!=x){
        iter=iter->next;
    }
    if(iter->next==r){
        printf("The serached value cannot be found!\n");
        return r;
    }
    else{
        node* temp=iter->next;
        iter->next=iter->next->next;
        free(temp);
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

    root=sil(root,35);
    yazdir(root);

}
