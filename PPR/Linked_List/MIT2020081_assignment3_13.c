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

void deleteDups(struct Node **head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    struct Node *i = *head;
    struct Node *j,*dup;

    while(i != NULL && i->next != NULL){
        j = i;
        while(j->next != NULL){
            if(i->val == j->next->val){
                
                dup = j->next;
                j->next = j->next->next;
                free(dup);
            }else{
                j = j->next;
            }
        }
        i = i->next;
    }
    print(*head);
    return;

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
    deleteDups(&head);
}