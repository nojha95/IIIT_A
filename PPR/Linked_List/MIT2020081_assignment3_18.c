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


void middleElement(struct Node *head){
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast->next == NULL){
        printf("%d \n",slow->val);
        return;
    }
    printf("%d \n", slow->next->val);
    

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
    middleElement(head);
}

