#include <stdio.h>
#define MAX 10
void enqueue(int QB[], int *size, int *head, int *tail, int data);
int dequeue(int QB[], int *size, int *head, int *tail);
int displayqueue(int QB[], int size, int head, int tail);
int main() {
    int Q[MAX];
    int head = 0;
    int tail = 0;
    int size = 0;

    printf("=== キューのテストプログラム ===\n\n");

    // テスト1: 空のキューからのdequeue
    printf("【テスト1】空のキューからdequeue\n");
    printf("結果: %d\n", dequeue(Q, &size, &head, &tail));
    displayqueue(Q, size, head, tail);
    printf("\n");

    // テスト2: 要素を順次追加
    printf("【テスト2】要素を10個追加(MAX容量まで)\n");
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
    displayqueue(Q, size, head, tail);
    printf("\n");

    // テスト3: 満杯のキューにenqueue
    printf("【テスト3】満杯のキューに追加を試みる\n");
    enqueue(Q, &size, &head, &tail, 0);
    displayqueue(Q, size, head, tail);
    printf("\n");

    // テスト4: 全要素をdequeue
    printf("【テスト4】全要素を取り出す\n");
    for (int i = 0; i < 10; i++) {
        printf("dequeue: %d\n", dequeue(Q, &size, &head, &tail));
    }
    displayqueue(Q, size, head, tail);
    printf("\n");

    // テスト5: 空になった後、再度追加
    printf("【テスト5】空になった後、再度要素を追加\n");
    enqueue(Q, &size, &head, &tail, 8);
    enqueue(Q, &size, &head, &tail, 3);
    enqueue(Q, &size, &head, &tail, 5);
    enqueue(Q, &size, &head, &tail, 3);
    displayqueue(Q, size, head, tail);
    printf("\n");

    // テスト6: 循環動作の確認
    printf("【テスト6】循環動作の確認\n");
    printf("2つ取り出す:\n");
    printf("dequeue: %d\n", dequeue(Q, &size, &head, &tail));
    printf("dequeue: %d\n", dequeue(Q, &size, &head, &tail));
    displayqueue(Q, size, head, tail);
    printf("再度5つ追加:\n");
    enqueue(Q, &size, &head, &tail, 100);
    enqueue(Q, &size, &head, &tail, 200);
    enqueue(Q, &size, &head, &tail, 300);
    enqueue(Q, &size, &head, &tail, 400);
    enqueue(Q, &size, &head, &tail, 500);
    displayqueue(Q, size, head, tail);
    printf("\n");

    printf("=== テスト完了 ===\n");

    return 0;

}

void enqueue(int QB[], int *size, int *head, int *tail, int data) {
    if (*size  == MAX)
    {
        printf("overflow\n");
        return;
    }
    
    QB[*tail] = data;
    *tail = (*tail + 1) % MAX;
    (*size)++;
       
}

int dequeue(int QB[], int *size, int *head, int *tail) {
    if (*size == 0)
    {
        printf("underflow\n");
        return -1;
    }
      
    int data = QB[*head];
    *head = (*head + 1) % MAX;
    (*size)--;
    return data;
    
}

int displayqueue(int QB[], int size, int head, int tail) {
        if(size == 0) {
        printf("Queue is empty\n");
        } else {
            printf("Queue array: ");
            int j = head;
        for (size_t i = 0; i < size; i++)
        {
        printf("%d ", QB[j]);
        j = (j + 1) % MAX;
        }
        }

        printf("\n");
        printf("head: %d, tail: %d\n", head, tail);
    
}

