#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
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

    if( val < root->val){
        root->left = insert(root->left,val);
    }else if( val > root->val){
        root->right = insert(root->right,val);
    }

    return root;
}

void mirror(struct Node* root){
    if( root == NULL){
        return;
    }else{
        struct Node* temp;

        mirror(root->left);
        mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
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
        
    }

    mirror(root);
    inorder(root);
}