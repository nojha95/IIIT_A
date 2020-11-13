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

    if(root->val > val){
        root->left = insert(root->left,val);
    }else if(root->val < val){
        root->right = insert(root->right,val);
    }

    return root;

}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d_",root->val);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d_",root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d_",root->val);
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
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    
    return 0; 

}