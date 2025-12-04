/*学籍番号:1TE23939R 氏名:室原碧人*/
#include <stdio.h>
#include <ctype.h>
#define MAX 10

void push(int S[], int *top, int *size, int x) {
   
    if (*size == MAX)
    {
        printf("overflow\n"); 
    }
    (*top)++;
    (*size)++;
    S[*top] = x;   
    
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

int conversion_c_i(char c) {
       int i = c - '0';
       return i;
}


int reverse_polish_notation(char calculation_formul[100]) {
    int S[MAX];
    int size = 0;
    int top = -1;
    for (int i = 0; calculation_formul[i] != '\0'; i++)
    {
        if (isdigit(calculation_formul[i]))
        {
            push(S, &top, &size, conversion_c_i(calculation_formul[i]));
        }
        else {
            int result;
            int value1 = pop(S, &size, &top);
            int value2 = pop(S, &size, &top);
                if (calculation_formul[i] == '+')
            {
                
                result = value1 + value2;
            }
            else if (calculation_formul[i] == '-')
            {
            
                result = value2 - value1;
            }
            else if (calculation_formul[i] == '*')
            {
                
                result = value1 * value2;
            }
            else if (calculation_formul[i] == '/')
            {
                
                result = value2 / value1;
            }
            push(S, &top, &size, result);
        }
          
    }
    return pop(S, &size, &top);
}

int main() {

    char calculation_formul1[100] = {'4', '5', '+', '\0'}; 
    char calculation_formul2[100] = {'3', '2', '-','\0'}; 
    char calculation_formul3[100] = {'4', '5', '*','\0'}; 
    char calculation_formul4[100] = {'6', '1', '/','\0'}; 
    char calculation_formul5[100] = {'4', '5', '+', '2', '4', '*', '-','\0'}; 
    int result1 = reverse_polish_notation(calculation_formul1);
    int result2 = reverse_polish_notation(calculation_formul2);
    int result3 = reverse_polish_notation(calculation_formul3);
    int result4 = reverse_polish_notation(calculation_formul4);
    int result5 = reverse_polish_notation(calculation_formul5);
    printf("result: %d\n", result1);
    printf("result: %d\n", result2);
    printf("result: %d\n", result3);
    printf("result: %d\n", result4);
    printf("result: %d\n", result5);
}