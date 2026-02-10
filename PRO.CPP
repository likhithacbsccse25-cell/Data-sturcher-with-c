#include<stdio.h>
struct Node{
int data;
struct Node*next;
};
struct Node*top=NULL;
int empty(){
return top==NULL;
}
void push(int data){
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
if (newNode==NULL){
printf("stack overview\n");
return;
}
newNode->data=data;
newNode->next=top;
top = newNode;
printf("%d pushed\n",data);
}