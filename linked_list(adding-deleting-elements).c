
#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int x;
    struct N* next;
}node;

void yazdir(node* r){
    node* iter=r;
    if(iter==NULL){
        printf("Eleman yok!");
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
    node* iter=r;

    if(iter==NULL){
        node* temp=(node*)malloc(sizeof(node));
        r=temp;
        r->x=x;
        r->next=NULL;
        return r;
    }
    if(iter->x>x){
        node* temp=(node*)malloc(sizeof(node));
        temp->x=x;
        temp->next=iter;
        r=temp;
        return r;
    }

    while(iter->next!=NULL&&iter->next->x<x){
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
    if(iter->x==x){
        node* temp=(node*)malloc(sizeof(node));
        temp=iter;
        iter=iter->next;
        free(temp);
        return iter;
    }
    while(iter->next!=NULL&&iter->next->x!=x){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("Aranan deger bulunamadi!");
    }
    else{
        node* temp=(node*)malloc(sizeof(node));
        temp=iter->next;
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
