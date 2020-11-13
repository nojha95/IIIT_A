#include<stdio.h>
#include<stdlib.h>

struct Stack{
    char value;
    struct Stack* next;
};

void push(struct Stack** top, char value){
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

char peek(struct Stack** top){
    return (*top)->value;
}

void printStack(struct Stack** top){
    printf("HERE \n");
    while(*top!=NULL){
        printf("%c ", peek(&(*top)));
        pop(&(*top));
    }
}

void main(){
    //char alphabet[26];
    //int t;
    //scanf("%d",&t);
    //while(t>0){
        char str[100];
        scanf("%s",str);
        struct Stack* tempStack;
        for(int i =0;i<10;i++ ){
            printf("%c ",str[i]);
            push(&tempStack,str[i]);
            
        }
        printf("%c" ,peek(&tempStack));
        printStack(&tempStack);
        //t--;
    //}
}