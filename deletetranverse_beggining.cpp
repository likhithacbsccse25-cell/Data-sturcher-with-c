#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void add_to_beggining(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = head; // Circular link
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        new_node->next = head;
        head = new_node;
        last->next = head;
    }
}

void delete_at_beggining() {
    struct node* last, *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last = head;
        while (last->next != head) {
            last = last->next;
        }
        temp = head;
        head = head->next;
        last->next = head;
        free(temp);
    }
}

void traverse() {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    add_to_beggining(10); // Add a node to the list
    traverse();
    delete_at_beggining();
    delete_at_beggining(); // Second call demonstrates empty list handling
    traverse(); // This will print "List is empty"
    return 0;
}
