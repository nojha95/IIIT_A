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

void insertionSort(struct Node **head){
    struct Node *it = *head;
    struct Node *jt = *head;

    while(it != NULL){
        struct Node *min = it;
        jt = it;
        while(jt!= NULL){
            if(jt->val < min->val){
                min = jt;
            }
            jt = jt->next;
        }
        int temp = it->val;
        it->val = min->val;
        min->val = temp;
        it = it->next;
    }

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
    insertionSort(&head);
    print(head);
}