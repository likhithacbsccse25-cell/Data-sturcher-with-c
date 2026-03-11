#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_beginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insert_at_end(struct Node**head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}
void delete_node(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void traverse(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* library = NULL;

    insert_at_end(&library, 101);
    insert_at_end(&library, 102);
    insert_at_beginning(&library, 99);

    printf("Issued Books: ");
    traverse(library); // 99 -> 101 -> 102 -> NULL

    delete_node(&library, 101);
    printf("After returning 101: ");
    traverse(library); // 99 -> 102 -> NULL

    return 0;
}
