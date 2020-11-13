#include<stdio.h>
#include<stdlib.h>

//Given a stack, the task is to sort it such that the top of the stack has the greatest element.(Using stack operations only.) 

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

void sortStack(struct Stack** input){
    struct Stack* tempStack = NULL;
    while(*input!=NULL){
        int temp = peek(&(*input));
        pop(&(*input));
        while(tempStack!= NULL && peek(&tempStack) > temp){
            push(&(*input),peek(&tempStack));
            pop(&tempStack);
        }
        push(&tempStack,temp);
    }
    printf("Sorted numbers : ");    
    while(tempStack!=NULL){
        printf ("%d ", peek(&tempStack));
        pop(&tempStack);
    }
    printf("\n");

    
}

void main(){
    struct Stack* input = NULL;
    int n,value;
    printf("Enter total elements in stack \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        push(&input,value);
    }

    sortStack(&input);

}