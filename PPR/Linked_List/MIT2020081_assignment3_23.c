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

void swapKth(struct Node **head,int pos){
    int length = size(*head);
    struct Node *array[length];
    struct Node *it = *head;
    for(int i =0;i<length;i++){
        array[i] = it;
        it = it->next;
    }
    pos = pos-1;
    int temp = array[pos]->val;
    array[pos]->val = array[length - 1 - pos]->val;
    array[length - 1 - pos]->val = temp;

}

int main(){
    int n;
    int k;
    printf("k = \n");
    scanf("%d",&k);
    printf("Enter number of elements : \n");
    scanf("%d",&n);
    struct Node* head = NULL;
    for(int i =0;i<n;i++){
        int val;
        scanf("%d",&val);
        push_back(&head,val);

    }
    swapKth(&head,k);
    print(head);
}
