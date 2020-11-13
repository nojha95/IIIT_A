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

void push_front(struct Node** head,int val){
    struct Node *newNode =  makeNode(val);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
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


void insert(struct Node **head,int val, int pos){
    int length = size(*head);
    pos = pos -1;
    if(pos == 0){
        push_front(head,val);
        return;
    } 
    if(pos == length){
        push_back(head,val);
        return;
    }
    if(pos > length){
        printf("Invalid position");
        return;
    }

    struct Node *newNode = makeNode(val);

    int curr = 0;
    struct Node *it = *head;
    struct Node *prev;
    while(pos > 0){
        prev = it;
        it = it->next;
        pos--;
    }
    prev->next = newNode;
    newNode->next = it;
    return;
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

int main(){
    int s;
    struct Node* head = NULL;
    while(1){
        printf("\n");
        printf("Input 1 - Insert in Front \n");
        printf("Input 2 - Insert at back \n");
        printf("Input 3 - Insert at position K \n");
        printf("Input other - Exit \n");

        scanf("%d",&s);
        int val,pos;
        
        switch (s)
        {
        case 1:
            printf("Enter val \n");
            scanf("%d",&val);
            push_front(&head,val);
            printf("List : ");
            print(head);
            break;
        case 2:
            printf("Enter val \n");
            scanf("%d",&val);
            push_back(&head,val);
            printf("List : ");
            print(head);
            break;
        case 3:
            printf("Enter val \n");
            scanf("%d",&val);
            printf("Enter position \n");
            scanf("%d",&pos);
            insert(&head,val,pos);
            printf("List : ");
            print(head);
            break;
        
        default:
            return 0;
        }
    }
    
}
