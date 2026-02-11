#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert_at_beginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct Node* insert_at_end(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Fixed your delete function syntax and typos
struct Node* delete_node(struct Node* head, int data) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Case: Node to delete is the head
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the node
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", data);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Fixed function names to match definitions
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);

    traverse(head);
    head = delete_node(head, 20);
    traverse(head);

    return 0;
}

