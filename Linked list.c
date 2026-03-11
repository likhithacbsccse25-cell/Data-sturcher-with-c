#include <stdio.h>
#include <stdlib.h>

struct Node {
    int bookID;
    struct Node* next;
};

void insert_at_beginning(struct Node** head_ref, int id) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->bookID = id;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insert_at_end(struct Node** head_ref, int id) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->bookID = id;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void delete_node(struct Node** head_ref, int id) {
    struct Node *temp = *head_ref, *prev = NULL;

   
    if (temp != NULL && temp->bookID == id) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->bookID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void traverse(struct Node* node) {
    if (node == NULL) {
        printf("No books currently issued.\n");
        return;
    }
    printf("Issued Book IDs: ");
    while (node != NULL) {
        printf("%d -> ", node->bookID);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* library = NULL;

    insert_at_end(&library, 101);       
    insert_at_end(&library, 102);       
    insert_at_beginning(&library, 99);  
    traverse(library);                  
    delete_node(&library, 101);         
    traverse(library);                  

    return 0;
}
