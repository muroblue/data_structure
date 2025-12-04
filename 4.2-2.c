/*学籍番号:1TE23939R 氏名:室原碧人*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* next;
} node;

node* create_node(int key) {
    node *new_node = (node*)malloc(sizeof(node));
    (*new_node).key = key;
    (*new_node).next = NULL;
    return new_node;
}

//ここからスタック
void push(node** head, int key) {
    node* push_node = create_node(key);
    (*push_node).next = *head;
    *head = push_node;
    return;
}

void pop(node** head) {

    if (head == NULL)
    {
        printf("underflow.\n");
    }
    
    node* pop_node;
    pop_node = *head;
    *head = (*(*head)).next;
    free(pop_node);
    
}

void displaystack(node* head) {
    
    printf("Stack: ");
    while (head != NULL)
    {
        printf("%d ", (*head).key);
        head = (*head).next;
    }
    
    printf("\n");
}

int test_stack() {
    node* head = NULL;

    push(&head, 4);
    push(&head, 1);
    push(&head, 3);

    displaystack(head);
   
    pop(&head);
    
    displaystack(head);

    push(&head, 8);
    
    displaystack(head);

    pop(&head);

    displaystack(head);
   
    return 0;
    
}

//キュー
void enqueue(node** head, node** tail, int key) {
    node* enqueue_node = create_node(key);
    if (*tail == NULL)
    {
        *head = enqueue_node;
        *tail = enqueue_node;
        
    }
        
    else
    {

        (*(*tail)).next = enqueue_node;
        *tail = enqueue_node;        
    }
    
}
void dequeue(node** head, node** tail) {
    if (*head == NULL)
    {
        printf("underflow.\n");
        return;
    }
    
    node* delete_node = *head;
    *head= (*(*head)).next;
    if (*head == NULL)
    {
        *tail = NULL;
    }
    free(delete_node);
}

void displayqueue(node* head) {
    
    printf("Queue: ");
    while (head != NULL)
    {
        printf("%d ", (*head).key);
        head = (*head).next;
    }
    printf("\n");
    
}

int test_queue() {
    node* head = NULL;
    node* tail = NULL;
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 1);
    enqueue(&head, &tail, 3);

    displayqueue(head);

    dequeue(&head, &tail);

    displayqueue(head);

    enqueue(&head, &tail, 8);

    displayqueue(head);

    dequeue(&head, &tail);

    displayqueue(head);
}

int main() {
    test_stack();
    test_queue();
}