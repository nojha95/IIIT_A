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


int max(struct Node *head){
    int max = head->val;
    while(head != NULL){
        if(head->val > max){
            max = head->val;
        }
        head = head->next;
    }
    return max;
}

int min(struct Node *head){
    int min = head->val;
    while(head != NULL){
        if(head->val < min){
            min = head->val;
        }
        head = head->next;
    }
   return min;
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
    int MIN = min(head);
    int MAX = max(head);
    printf("MIN = %d \n",MIN);
    printf("MAX = %d \n",MAX);
    printf("MAX - MIN = %d \n",MAX-MIN);

}