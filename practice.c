#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void InsertEnd(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void DeleteNode(int value) 
{
    struct Node* temp = head;

    while (temp != NULL && temp->data != value) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("\nValue %d not found in the list.\n", value);
        return;
    }

    if (temp == head) 
    {
        head = temp->next;
        if (head != NULL) 
            head->prev = NULL;
    } 
    else 
    {
        temp->prev->next = temp->next; 
        
        if (temp->next != NULL)   
            temp->next->prev = temp->prev; 
    }

    free(temp);
    printf("\nValue %d deleted successfully.\n", value);
}

void Traverse() 
{
    struct Node* temp = head;

    if (temp == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    InsertEnd(10);
    InsertEnd(20);
    InsertEnd(30);
    InsertEnd(40);

    printf("Initial list: ");
    Traverse();

    DeleteNode(20);
    printf("After deleting 20: ");
    Traverse();

    DeleteNode(10);
    printf("After deleting head (10): ");
    Traverse();

    return 0;
}
