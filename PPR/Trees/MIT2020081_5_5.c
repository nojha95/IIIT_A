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


int totalLeaves(struct Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return (totalLeaves(root->left)+totalLeaves(root->right));
}


int main(){
    int n = 0;
    scanf("%d",&n);
    struct Node *root = NULL;
    int val =0;
    for(int i =0;i<n;i++){
        scanf("%d",&val);
        if(i ==0){
            root = insert(root,val);
        }else{
            insert(root,val);
        }    
    }
    printf("%d",totalLeaves(root));
    
    return 0; 

}