// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*head=NULL;

void insert_at_beggining(int data){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=head;
    
    if (head !=NULL){
        head->prev=newNode;

    }
    head = newNode;
}
void insert_at_end(int data)
{struct node*newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=data;
newNode->next=NULL;
if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    struct node*temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void traverse_forward(){
    struct node*temp=head;
    printf("Forward Traversal:");
    while (temp !=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    // Write C code here
    insert_at_beggining(10);
    insert_at_beggining(20);
    insert_at_end(30);
    insert_at_end(40);
    traverse_forward();
    return 0;
}
