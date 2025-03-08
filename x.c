#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_TOKENS 100 // Adjust as needed

// Structure for a stack
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void init_stack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top < MAX_STACK_SIZE - 1)
        s->data[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (!is_empty(s))
        return s->data[(s->top)--];
    return -1;
}

// Function to print stacks visually
void print_stacks(Stack *a, Stack *b, const char *operation) {
    printf("-----------------------------------------------\n");
    printf("MOVE: %s\n", operation);
    printf("STACK A: ");
    for (int i = a->top; i >= 0; i--)
        printf("%d ", a->data[i]);
    printf("\n");
    printf("STACK B: ");
    for (int i = b->top; i >= 0; i--)
        printf("%d ", b->data[i]);
    printf("\n\n");
//    usleep(200000); // Pause for visualization
}

// Function to perform swap operation on a stack
void swap(Stack *s) {
    if (s->top > 0) {
        int temp = s->data[s->top];
        s->data[s->top] = s->data[s->top - 1];
        s->data[s->top - 1] = temp;
    }
}

// Function to perform push from stack A to stack B
void push_to(Stack *from, Stack *to) {
    if (!is_empty(from)) {
        push(to, pop(from));
    }
}

// Function to perform rotate operation
void rotate(Stack *s) {
    if (s->top > 0) {
        int temp = s->data[s->top];
        for (int i = s->top; i > 0; i--)
            s->data[i] = s->data[i - 1];
        s->data[0] = temp;
    }
}

// Function to perform reverse rotate operation
void reverse_rotate(Stack *s) {
    if (s->top > 0) {
        int temp = s->data[0];
        for (int i = 0; i < s->top; i++)
            s->data[i] = s->data[i + 1];
        s->data[s->top] = temp;
    }
}

// Function to execute operations
void execute_operations(Stack *a, Stack *b, char *operation) {
    if (strcmp(operation, "sa") == 0)
        swap(a);
    else if (strcmp(operation, "sb") == 0)
        swap(b);
    else if (strcmp(operation, "pa") == 0)
        push_to(b, a);
    else if (strcmp(operation, "pb") == 0)
        push_to(a, b);
    else if (strcmp(operation, "ra") == 0)
        rotate(a);
    else if (strcmp(operation, "rb") == 0)
        rotate(b);
    else if (strcmp(operation, "rra") == 0)
        reverse_rotate(a);
    else if (strcmp(operation, "rrb") == 0)
        reverse_rotate(b);
    print_stacks(a, b, operation);
}

int main(int argc, char *argv[]) {
    Stack a, b;
    init_stack(&a);
    init_stack(&b);
    setbuf(stdout, NULL);

	char *argv2[argc];
    char *tokens[MAX_STACK_SIZE];  // Array to store tokens
    int count = 0;

    // First pass: Store tokens in an array
    char *token = strtok(argv[1], " ");
    while (token && count < MAX_STACK_SIZE) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    // Second pass: Push elements onto the stack in reverse order
    for (int i = count - 1; i >= 0; i--) {
        push(&a, atoi(tokens[i]));
    }
//    for (int i = 1; i < argc; i++) {
//        argv2[i] = argv[argc - i]; // Copy in reverse order
//    }

    // Read initial stack values from a single argument
//    if (argc == 2) {
//        char *token = strtok(argv[1], " ");
//        while (token) {
//            push(&a, atoi(token));
//            token = strtok(NULL, " ");
//        }
//    }

    print_stacks(&a, &b, "Initial");
    
    // Read and execute moves from stdin
    char operation[10];
    while (scanf("%s", operation) != EOF) {
        execute_operations(&a, &b, operation);
    }
    
    return 0;
}
