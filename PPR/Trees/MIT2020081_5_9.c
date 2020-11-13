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

void deleteTree(struct Node* root){
    if(root == NULL){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    root->left = NULL;
    root->right = NULL;

    printf("%d ",root->val);
    free(root);
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

    deleteTree(root);
    return 0; 

}

