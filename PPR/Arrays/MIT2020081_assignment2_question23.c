#include<stdio.h>
#include<stdlib.h>

//Implement a stack using linked list. 

struct Stack{
    int value;
    struct Stack* next;
};

void push(struct Stack** top, int value){
    struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack*));
    new_node->value = value;
    new_node->next = *top;
    *top = new_node;
}

void pop(struct Stack** top){
    if(top == NULL){
        printf("Empty stack");
        return;
    }
    struct Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
}

int peek(struct Stack** top){
    return (*top)->value;
}
