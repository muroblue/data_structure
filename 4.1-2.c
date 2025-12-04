#include <stdio.h>
#define MAX 10
void enqueue(int Q[], int *size, int *head, int *tail, int x) {
    if (*size  == MAX)
    {
        printf("overflow\n");
        return;
    }
    
    Q[*tail] = x;
    *tail = (*tail + 1) % MAX;
    (*size)++;
       
}

int dequeue(int Q[], int *size, int *head, int *tail) {
    if (*size == 0)
    {
        printf("underflow\n");
        return -1;
    }
      
    int x = Q[*head];
    *head = (*head + 1) % MAX;
    (*size)--;
    return x;
    
}

int displayqueue(int Q[], int size, int head, int tail) {

        printf("Queue: ");
        int j = head;
        for (size_t i = 0; i < size; i++)
        {
        printf("%d ", Q[j]);
        j = (j + 1) % MAX;
        }
    
        printf("\n");
        printf("head: %d, tail: %d\n", head, tail);
    
}

int main() {
    int Q[MAX];
    int head = 0;
    int tail = 0;
    int size = 0;

    printf("%d\n", dequeue(Q, &size, &head, &tail));
    enqueue(Q, &size, &head, &tail, 15);
    enqueue(Q, &size, &head, &tail, 6);
    enqueue(Q, &size, &head, &tail, 9);
    enqueue(Q, &size, &head, &tail, 8);
    enqueue(Q, &size, &head, &tail, 3);
    enqueue(Q, &size, &head, &tail, 5);
    enqueue(Q, &size, &head, &tail, 3);
    enqueue(Q, &size, &head, &tail, 5);
    enqueue(Q, &size, &head, &tail, 7);
    enqueue(Q, &size, &head, &tail, 21);
    //ここで満杯
    enqueue(Q, &size, &head, &tail, 0);
    //overflow
    displayqueue(Q, size, head, tail);

    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    printf("%d\n", dequeue(Q, &size, &head, &tail));
    //ここで空
    displayqueue(Q, size, head, tail);

    enqueue(Q, &size, &head, &tail, 8);
    enqueue(Q, &size, &head, &tail, 3);
    enqueue(Q, &size, &head, &tail, 5);
    enqueue(Q, &size, &head, &tail, 3);

    displayqueue(Q, size, head, tail);

}
