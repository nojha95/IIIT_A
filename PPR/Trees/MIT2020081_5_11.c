#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node* insert(struct Node* root,int val){
    if(root == NULL){
        return newNode(val);
    }

    if(val < root->val){
        root->left = insert(root->left,val);
    }

    else if(val > root->val){
        root->right = insert(root->right,val);
    }
    return root;
}

void inorderList(struct Node* root,int *arr,int *size){
    if( root == NULL){
        return ;
    }

    inorderList(root->left,arr,size);
    *(arr + *size) = root->val;
    *size = *size + 1;
    inorderList(root->right,arr,size);
}

void inorderSucc(int val,int *arr,int size){
    for(int i = 0;i<size-1;i++){
        if(val == *(arr + i)){
            printf("%d \n",*(arr + i +1));
            return;
        }
    }

    printf("Inorder succesor doesnt exist \n");
}

void inorderPred(int val,int *arr,int size){
    for(int i =1;i<size;i++){
        if(val == *(arr + i)){
            printf("%d ", *(arr + i - 1));
            printf("\n");
            return;
        }
    }

    printf("Inorder predecessor doesnt exist \n");
}

int main(){
    char input[50];
    int num;
    struct Node* root = NULL;
    scanf("%[^\n]%*c",input);
    char *token=strtok(input," ");
    int i =0;
    while(token)
    {
        root=insert(root,atoi(token));
        token=strtok(NULL," ");
        i++;
        
    }
    int val;
    scanf("%d",&val);
    int *arr = (int*)malloc(i*sizeof(int));
    int size =0;
    inorderList(root,arr,&size);
    inorderSucc(val,arr,size);
    inorderPred(val,arr,size);
    
}
