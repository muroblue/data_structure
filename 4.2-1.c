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
    (*current_node).next = insert_node;
    
}

void delete(node** head, int delete_index) {
    node* temp;
    if (delete_index <= 0)
    {
        printf("delete_index is bigger than 1.\n");
        return;
    }
    
    if (delete_index == 1)
    {
        temp = *head;
        *head = (*(*head)).next;
        free(temp);
        return;
    }
    
    node* current_node = *head;
    int index = 1;
    while ((*current_node).next != NULL && index < delete_index - 1)
    {
        current_node = (*current_node).next;
        index++;
    }
    
    temp = (*current_node).next;
    (*current_node).next = (*(*current_node).next).next;
    free(temp);
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

void displaysinglylinkedlist(node* head) {
    if (head == NULL);
    {
        printf("empty\n");
    }
    while (head != NULL)
    {
        printf("%d -> ", (*head).key);
        head = (*head).next;
    }
    printf("\n");
}
    
//test
int main() {
    node* head = NULL;

    insert(&head, 1, 1);
    insert(&head, 4, 1);
    insert(&head, 9, 2);
    insert(&head, 16, 3);

    displaysinglylinkedlist(head);

    int search_index = search(head, 16);
    printf("search index: %d\n", search_index);
 
    delete(&head, 1);
    delete(&head, 2);

    displaysinglylinkedlist(head);

    search_index = search(head, 1);
    printf("search index: %d\n", search_index);

    return 0;

}

