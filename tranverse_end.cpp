// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;
void insert_at_end(int x)
{
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL)
    {
        newnode->next=newnode;
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next !=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
}
}
void traverse()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=head;
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        while(temp !=head);
        printf("\n");
    }
}
int main() 
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);

    traverse();
    return 0;
}
