#include <stdio.h>
#define MAX 10

void push(int S[], int *size, int *top, int x) {
    if (*size == MAX)
    {
        printf("overflow\n"); 
    }
    else
    {
        (*top)++;
        (*size)++;
        S[*top] = x;   
    }
}

int pop(int S[], int *size, int *top) {
    if (*size ==0)
    {
        printf("under flow\n");
        return -1;
    }
    else {
        (*top)--;
        (*size)--;
        int x = S[(*top) + 1];
        return x;
    }
}

int displaystack(int S[], int size, int top) {
        printf("stack array is ");
    for (int i = 0; i < top + 1; i++)
    {
        printf("%d ", S[i]); 
    }
    printf("\n");
    printf("S.top: %d", top);
    printf("\n");

}

int main() {
    
    int S[MAX];
    int top = -1;
    int size = 0;

    push(S, &size, &top, 15);
    push(S, &size, &top, 6);
    push(S, &size, &top, 2);
    push(S, &size, &top, 1);
    push(S, &size, &top, 2);
    push(S, &size, &top, 3);
    push(S, &size, &top, 4);
    push(S, &size, &top, 5);
    push(S, &size, &top, 6);
    push(S, &size, &top, 7);
    //ここで満杯になる
    push(S, &size, &top, 0);
    displaystack(S, size, top);
   
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    printf("pop: %d\n",pop(S, &size, &top));
    //ここで空になる
    printf("pop: %d\n",pop(S, &size, &top));
    push(S, &size, &top, 3);
    
    displaystack(S, size, top);
   
    return 0;
    
}
