#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int cap;
    char *data;
} XStack;

char r_to_l(char c) {
    switch (c) {
        case ')':
            return '(';
            break;
        case '}':
            return '{';
            break;
        case ']':
            return '[';
            break;
    }
    return '_';
}

void push_stack(XStack *stack, char data) {
    if (stack->size < 0) {
        return;
    }

    if (stack->size >= stack->cap) {
        stack->cap *= 2;
        stack->data = realloc(stack->data, sizeof(data) * stack->cap);
    }
    stack->data[stack->size] = data;
    stack->size++;
    return;
}

void pop_stack(XStack *stack, char cmp) {
    if (stack->size <= 0) {
        stack->size--;
        return;
    }
    if (stack->data[stack->size - 1] == r_to_l(cmp)) {
        stack->size--;
        return;
    } else {
        stack->size++;
        if (stack->size >= stack->cap) {
            stack->cap *= 2;
            stack->data = realloc(stack->data, sizeof(cmp) * stack->cap);
        }
    }
}

bool isValid(char *s) {
    bool x = true;
    XStack stack = {0,
                    4,
                    malloc(sizeof(char) * 4)};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push_stack(&stack, s[i]);
        } else {
            pop_stack(&stack, s[i]);
        }
    }
    free(stack.data);
    return !stack.size;
}

int main(int, char **) {
    char *a = "()";
    printf("isvalid :%d\n", isValid(a));

    char *b = "}{";
    printf("isvalid: %d\n", isValid(b));

    char *c = "[";
    printf("isvalid :%d\n", isValid(c));
    char *d = "]";
    printf("isvalid :%d\n", isValid(d));
    char *e = "(])";
    printf("isvalid :%d\n", isValid(e));

    char *f = "([}}])";
    printf("isvalid :%d\n", isValid(f));
    return 0;
}
