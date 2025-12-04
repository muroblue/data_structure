#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* parent;

} node;

node* create_node(int key, node* parent) {
    node *new_node = (node*)malloc(sizeof(node));
    (*new_node).key = key;
    (*new_node).left = NULL;
    (*new_node).right = NULL;
    (*new_node).parent = parent;
    return new_node;
}
node* insert(node* root, int key, node* parent) {

    if (root == NULL)
    {
        return create_node(key, parent);
    }
    if (key < (*root).key)
    {
       
        (*root).left = insert((*root).left, key, root);
        
    }
    else if ((*root).key < key)
    {
        (*root).right = insert((*root).right, key, root);
    }
    return root;
}

node* minimum(node* root) {
    while ((*root).left != NULL)
    {
        root = (*root).left;
    }
    return root;
}


node* delete(node* root, int key) {

        if (root == NULL)
        {
            return root;
        }
        if (key < (*root).key)
        {
            (*root).left = delete((*root).left, key);
        }
        else if (key > (*root).key)
        {
            (*root).right = delete((*root).right, key);
        }
        else {
        if((*root).left == NULL) {
            node* temp = (*root).right;
            free(root);
            return temp;
        }
        else if ((*root).right == NULL)
        {
            node* temp = (*root).left;
            free(root);
            return temp; 
        } 
        node* temp = minimum((*root).right);
        (*root).key = (*temp).key;
        (*root).right = delete((*root).right, (*temp).key);     
        }   
         
}

node* search(node* root, int key) {
    
        if (root == NULL || (*root).key == key)
        {
            return root;
        }
        if (key < (*root).key)
        {
            return search((*root).left, key);
        }
        if (key > (*root).key)
        {
            search((*root).right, key);
        } 
        
}

void display_binary_search_tree(node* root) {
    if (root != NULL)
    {
        display_binary_search_tree((*root).left);
        printf("%d ", (*root).key);
        display_binary_search_tree((*root).right);
    }
    
}

int main() {
    node* root = NULL;

    root = insert(root, 50, NULL);
    root = insert(root, 30, NULL);
    root = insert(root, 70, NULL);
    root = insert(root, 20, NULL);
    root = insert(root, 40, NULL);
    root = insert(root, 60, NULL);
    root = insert(root, 80, NULL);

    printf("Tree: ");
    display_binary_search_tree(root);
    printf("\n");

    root = delete(root, 50);
    printf("Tree: ");
    display_binary_search_tree(root);
    printf("\n");

    node* found = search(root, 40);
    if (found) {
        printf("Found: %d\n", found->key);
    } else {
        printf("Not found\n");
    }

    return 0;
}