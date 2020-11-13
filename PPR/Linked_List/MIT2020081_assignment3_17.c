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

void print(struct Node *head){
    struct Node *it = head;
    while(it != NULL){
        printf("%d ",it->val);
        it = it->next;
    }
    printf("\n");
    return;
}

int size(struct Node *head){
    struct Node *it = head;
    int length=0;
    if(head == NULL){
        return 0;
    }
    while(it != NULL){
        length++;
        it = it->next;
    }
    return length;

}


void pairWiseSwap(struct Node **head){
    //struct Node *temp = *head;
    int len = size(*head);
    int temp = 0;
    struct Node *it = *head;
    if(len % 2 == 0){
        while(it != NULL){
            temp = it->val;
            it->val = it->next->val;
            it->next->val = temp;
            it = it->next->next;
        }
    }
    else{
        while(it->next != NULL){
            temp = it->val;
            it->val = it->next->val;
            it->next->val = temp;
            it = it->next->next;
        }
    }
    print(*head);
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
    pairWiseSwap(&head);
    
}