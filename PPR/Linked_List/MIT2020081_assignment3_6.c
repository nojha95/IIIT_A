#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node* makeNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push_back(struct Node **head,int val){
    struct Node *newNode = makeNode(val);
    struct Node *it = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(it->next != NULL){
        it = it->next;
    }

    it->next = newNode;
    newNode->next = NULL;
}

void sumEven(struct Node *head){
    int sum =0;
    while (head != NULL){
        if(head->val % 2 == 0){
            sum = sum + head->val;
        }
        head = head->next;
    }
    printf("%d \n",sum);
}

int main(){
    int n;
    printf("Enter number of elements : \n");
    scanf("%d",&n);
    struct Node* head = NULL;
    for(int i =0;i<n;i++){
        int val;
        scanf("%d",&val);
        push_back(&head,val);

    }
    sumEven(head);
}
