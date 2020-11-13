#include<stdio.h>
#include<stdlib.h>

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
void printArr(int *arr,int len){
    for(int i =0;i<len;i++){
        printf("%d ", *(arr + i));
    }
}

void printPathRecurr(struct Node* root,int *arr,int len){
    if(root == NULL){
        return;
    }
    *(arr + len) = root->val;
    len++;
    if(root->left == NULL && root->right == NULL){
        printArr(arr,len);
        printf("\n");
    }

    printPathRecurr(root->left,arr,len);
    printPathRecurr(root->right,arr,len);
    
}

void printPath(struct Node* root){
    int arr[100] ;
    printPathRecurr(root,arr,0);
}

int main(){
    int n = 0;
    scanf("%d",&n);
    struct Node *root = NULL;
    int val =0;
    for(int i =0;i<n;i++){
        scanf("%d",&val);
        root = insert(root,val);    
    }
    printPath(root);
    
    return 0; 

}