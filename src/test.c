#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int data;
    struct list_node *next;
} t_stack_node;

// Enqueue function to add a new node at the end
void enqueue(t_stack_node **stack, int value) {
    t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*stack == NULL) {
        *stack = new_node;
    } else {
        t_stack_node *current = *stack;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to transform argc and argv into a stack
void argc_argv_to_stack(int argc, char **argv, t_stack_node **stack) {
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        enqueue(stack, value);
    }
}

// Helper function to print the stack
void print_stack(t_stack_node *stack) {
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Free the stack
void free_stack(t_stack_node *stack) {
    t_stack_node *temp;
    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main(int argc, char **argv) {
    t_stack_node *stack = NULL;

    // Convert command-line arguments to stack
    argc_argv_to_stack(argc, argv, &stack);

    // Print the stack
    printf("Stack: ");
    print_stack(stack);

    // Free the stack
    free_stack(stack);

    return 0;
}
