#include <stdio.h>
#include "stack.c"

void hanoi_stack(int n, int a[], int *size_a, int *top_a, int b[], int *size_b, int *top_b,
int c[], int *size_c, int *top_c, char from_rod, char aux_rod, char to_rod) 
{
    if (n == 1)
    {
        int disk = pop(a, size_a, top_a);
        push(c, size_c, top_c, disk);
        printf("Move disk %d from %c to %c\n", disk, from_rod, to_rod);
        return;
    }
    hanoi_stack(n - 1, a, size_a, top_a, c, size_c, top_c, b, size_b, top_b,from_rod, to_rod, aux_rod);
    int disk = pop(a, size_a, top_a);
        push(c, size_c, top_c, disk);
        printf("Move disk %d from %c to %c\n", disk, from_rod, to_rod);
        /*displaystack(a, *size_a, *top_a);
        displaystack(b, *size_b, *top_b);
        displaystack(c, *size_c, *top_c);*/
        
    hanoi_stack(n - 1, b, size_b, top_b, a, size_a, top_a, c, size_c, top_c, aux_rod, from_rod, to_rod);
}

int main() {
    int a[MAX];
    int b[MAX];
    int c[MAX];
    int size_a = 0;
    int size_b = 0;
    int size_c = 0;
    int top_a = -1;
    int top_b = -1;
    int top_c = -1;

    int n =3;

    for (int i = n; i > 0; i--)
    {
        push(a, &size_a, &top_a, i);
    }

    displaystack(a, size_a, top_a);
    hanoi_stack(n, a, &size_a, &top_a, b, &size_b, &top_b, c, &size_c, &top_c, 'a', 'b', 'c');
    return 0;
}


