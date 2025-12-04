/*学籍番号:1TE23939R 氏名:室原碧人*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* prev;
    struct node* next;
} node;

node* create_node(int key) {
    node *new_node = (node*)malloc(sizeof(node));
    (*new_node).key = key;
    (*new_node).prev = NULL;
    (*new_node).next = NULL;
    return new_node;
}
void insert(node** head, int key, int insert_index) {

    if (insert_index <= 0)
    {
        printf("insert_index is bigger than 0.\n");
        return;
    }

    node* insert_node = create_node(key);
    if (insert_index ==1)
    {
        (*insert_node).next = *head;
        (*insert_node).prev = NULL;
        *head = insert_node;
        return;
    }
    
    node *current_node = *head;
    int index = 1;

    while (current_node != NULL && index < insert_index - 1)
    {
        current_node = (*current_node).next;
        index++;
    }
    
    (*insert_node).next = (*current_node).next;
    (*insert_node).prev = current_node;
    (*current_node).next = insert_node;

    
    
}

void delete(node** head, int delete_index) {
        node* delete_node;
        if (delete_index <= 0)
        {
            printf("delete_index is bigger than 1.\n");
            return;
        }

        if (delete_index == 1)
        {
            delete_node = *head;
            *head = (*(*head)).next;
            free(delete_node);
            return;
        }
        
        node* current_node = *head;
        int index = 1;
        while ((*current_node).next != NULL && index < delete_index - 1)
        {
            current_node = (*current_node).next;
            index++;
        }

        delete_node = (*current_node).next;
        if ((*delete_node).next == NULL)
        {
            (*current_node).next = (*delete_node).next;
            free(delete_node);
            return;
        }
        
        (*current_node).next = (*delete_node).next;
        (*(*delete_node).next).prev = current_node;
        //動目メモリの開放
        free(delete_node);
        return;
        
}

int search(node* head, int key) {
    int search_index = 1;
    while (head != NULL)
    {
        if ((*head).key == key)
        {
            return search_index;
        }
        head = (*head).next;
        search_index++;
    }
    return -1; //見つからないことを表す
}

void displaydoublylinkedlist(node* head) {
    
    if (head == NULL)
    {
        printf("empty\n");
    }
    
    while (head != NULL)
    {
        printf("%d ", (*head).key);
        head = (*head).next;
    }
    
}

int main() {
    node* head = NULL;
    insert(&head, 1, 0);
    insert(&head, 1, 1);
    insert(&head, 3, 1);
    insert(&head, 10, 0);
    insert(&head, 5, 2);
    insert(&head, 23, 3);

    displaydoublylinkedlist(head);
    printf("\n");

    int search_index = search( head, 5);
    printf("search index : %d\n", search_index);

    delete(&head, 4);
    delete(&head, 1);

    displaydoublylinkedlist(head);

}