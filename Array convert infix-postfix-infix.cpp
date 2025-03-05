#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Struktur Stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Fungsi untuk membuat Stack baru
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Fungsi untuk memeriksa apakah Stack kosong
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk memeriksa apakah Stack penuh
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Fungsi untuk menambahkan item ke Stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Fungsi untuk mengeluarkan item dari Stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top--];
}

// Fungsi untuk mendapatkan item teratas dari Stack
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top];
}

// Fungsi untuk mendapatkan prioritas operator
int getPriority(char op) { // Mengubah "operator" menjadi "op"
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Infix ke Postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack* stack = createStack();
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && getPriority(infix[i]) <= getPriority(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
        i++;
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

// Fungsi untuk konversi Postfix ke Infix
void postfixToInfix(char postfix[], char infix[]) {
    struct Stack* stack = createStack();
    int i, j;
    i = j = 0;

    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            char temp[2];
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(stack, temp[0]);
        } else {
            char operand2 = pop(stack);
            char operand1 = pop(stack);
            char temp[MAX_SIZE];
            sprintf(temp, "(%c%c%c)", operand1, postfix[i], operand2);
            for (int k = 0; temp[k] != '\0'; k++) {
                push(stack, temp[k]);
            }
        }
        i++;
    }

    strcpy(infix, stack->items);
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX_SIZE];
    char infix2[MAX_SIZE];

    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    postfixToInfix(postfix, infix2);
    printf("Postfix: %s\n", postfix);
    printf("Infix: %s\n", infix2);

    return 0;
}
