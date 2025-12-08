#include <stdio.h>
#define MAX 10
void push(int SB[], int *size, int *SP, int data);
int pop(int SB[], int *size, int *SP);
int displaystack(int SB[], int size, int SP);
/*int main() {
    int S[MAX];
    int top = -1;
    int size = 0;

    printf("=== Test 1: 初期状態の確認 ===\n");
    displaystack(S, size, top);

    printf("\n=== Test 2: 基本的なpush操作 ===\n");
    printf("Pushing 10, 20, 30\n");
    push(S, &size, &top, 10);
    push(S, &size, &top, 20);
    push(S, &size, &top, 30);
    displaystack(S, size, top);

    printf("\n=== Test 3: 基本的なpop操作 ===\n");
    printf("Popped: %d\n", pop(S, &size, &top));
    printf("Popped: %d\n", pop(S, &size, &top));
    displaystack(S, size, top);

    printf("\n=== Test 4: オーバーフローのテスト ===\n");
    printf("Filling the stack...\n");
    push(S, &size, &top, 1);
    push(S, &size, &top, 2);
    push(S, &size, &top, 3);
    push(S, &size, &top, 4);
    push(S, &size, &top, 5);
    push(S, &size, &top, 6);
    push(S, &size, &top, 7);
    push(S, &size, &top, 8);
    push(S, &size, &top, 9);
    displaystack(S, size, top);
    printf("Trying to push to full stack:\n");
    push(S, &size, &top, 100);  // これはオーバーフロー
    
    printf("\n=== Test 5: スタックを空にする ===\n");
    printf("Popping all elements:\n");
    while (size > 0) {
        printf("Popped: %d\n", pop(S, &size, &top));
    }
    displaystack(S, size, top);

    printf("\n=== Test 6: アンダーフローのテスト ===\n");
    printf("Trying to pop from empty stack:\n");
    int result = pop(S, &size, &top);
    printf("Result: %d\n", result);

    printf("\n=== Test 7: push/popの繰り返し ===\n");
    push(S, &size, &top, 100);
    push(S, &size, &top, 200);
    displaystack(S, size, top);
    printf("Popped: %d\n", pop(S, &size, &top));
    push(S, &size, &top, 300);
    displaystack(S, size, top);

    printf("\n=== All tests completed ===\n");
    
    return 0;
}*/

void push(int SB[], int *size, int *SP, int data) {
    if (*size == MAX)
    {
        printf("overflow\n"); 
    }
    else
    {
        (*SP)++;
        (*size)++;
        SB[*SP] = data;   
    }
}

int pop(int SB[], int *size, int *SP) {
    if (*size ==0)
    {
        printf("under flow\n");
        return -1;
    }
    else {
        (*SP)--;
        (*size)--;
        int data = SB[(*SP) + 1];
        return data;
    }
}

int displaystack(int SB[], int size, int SP) {
    if(size == 0) {
        printf("stack is empty\n");
    } else {
        printf("stack array: ");
        for(int i = 0; i <= SP; i++) {
            printf("%d ", SB[i]);
        }
        printf("\n");
    }
    printf("current pointer: %d, size: %d\n", SP, size);
    printf("------------------------\n");
}

