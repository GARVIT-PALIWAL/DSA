#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Basic operations
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int isEmpty() {
    return top == -1;
}

int peek() {
    if (isEmpty()) return -1;
    return stack[top];
}

// ✅ Recursive function to print stack elements from top to bottom
void printStack(int index) {
    if (index < 0) return;
    printf("%d ", stack[index]);
    printStack(index - 1);
}

// ✅ Insert element at bottom of stack using recursion
void insertAtBottom(int x) {
    if (isEmpty()) {
        push(x);
        return;
    }
    int temp = pop();
    insertAtBottom(x);
    push(temp);
}

// ✅ Reverse the stack using recursion
void reverseStack() {
    if (isEmpty()) return;
    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}

// ✅ Main Function
int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Original Stack:\n");
    printStack(top);
    printf("\n");

    reverseStack();

    printf("Reversed Stack:\n");
    printStack(top);
    printf("\n");

    return 0;
}