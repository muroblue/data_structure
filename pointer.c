#include <stdio.h>

// ポインタを使わない版(間違った実装)
void enqueue_wrong(int QB[], int size, int head, int tail, int data) {
    if (size == 10) {
        printf("overflow\n");
        return;
    }
    
    QB[tail] = data;
    tail = (tail + 1) % 10;  // ここで変更しても...
    size++;                   // ここで変更しても...
    
    printf("  関数内: size=%d, tail=%d\n", size, tail);
}

// ポインタを使う版(正しい実装)
void enqueue_correct(int QB[], int *size, int *head, int *tail, int data) {
    if (*size == 10) {
        printf("overflow\n");
        return;
    }
    
    QB[*tail] = data;
    *tail = (*tail + 1) % 10;  // ポインタ経由で本体を変更
    (*size)++;                  // ポインタ経由で本体を変更
    
    printf("  関数内: size=%d, tail=%d\n", *size, *tail);
}

int main() {
    printf("=== ポインタを使わない場合(間違い) ===\n\n");
    {
        int Q[10] = {0};
        int size = 0;
        int head = 0;
        int tail = 0;
        
        printf("初期状態: size=%d, tail=%d\n", size, tail);
        
        enqueue_wrong(Q, size, head, tail, 15);
        printf("main関数: size=%d, tail=%d\n", size, tail);
        printf("→ 値が変わっていない!\n\n");
        
        enqueue_wrong(Q, size, head, tail, 6);
        printf("main関数: size=%d, tail=%d\n", size, tail);
        printf("→ まだ変わっていない!\n\n");
        
        printf("結果: Q[0]=%d, Q[1]=%d\n", Q[0], Q[1]);
        printf("→ データは上書きされてしまう!\n\n");
    }
    
    printf("\n=== ポインタを使う場合(正しい) ===\n\n");
    {
        int Q[10] = {0};
        int size = 0;
        int head = 0;
        int tail = 0;
        
        printf("初期状態: size=%d, tail=%d\n", size, tail);
        
        enqueue_correct(Q, &size, &head, &tail, 15);
        printf("main関数: size=%d, tail=%d\n", size, tail);
        printf("→ 正しく変更されている!\n\n");
        
        enqueue_correct(Q, &size, &head, &tail, 6);
        printf("main関数: size=%d, tail=%d\n", size, tail);
        printf("→ さらに増えている!\n\n");
        
        printf("結果: Q[0]=%d, Q[1]=%d\n", Q[0], Q[1]);
        printf("→ 正しく別の場所に格納されている!\n\n");
    }
    
    printf("\n=== 図解 ===\n");
    printf("ポインタを使わない場合:\n");
    printf("  main: size=0  →コピー→  関数: size=0\n");
    printf("                          関数: size=1 (変更)\n");
    printf("  main: size=0  ←戻る←   (変更は失われる)\n\n");
    
    printf("ポインタを使う場合:\n");
    printf("  main: size=0  →アドレス→  関数: *size=0\n");
    printf("  main: size=1  ←同じ場所←  関数: *size=1 (変更)\n");
    printf("  (同じメモリを参照しているので変更が反映される)\n");
    
    return 0;
}