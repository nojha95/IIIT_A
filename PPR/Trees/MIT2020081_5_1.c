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

struct Node* searchTree(struct Node* root,int val){
    if(root == NULL || root->val == val){
        return root;
    }
    if(val < root->val){
        return searchTree(root->left,val);
    }
    return searchTree(root->right,val);
}

void search(struct Node* root,int val){
    if(searchTree(root,val) == NULL){
        printf("n");
    }else{
        printf("y");
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    int val =0;
    struct Node* root = NULL;
    for(int i =0;i<n;i++){
        scanf("%d",&val);
        if(i ==0){
            root = insert(root,val);
        }else{
            insert(root,val);
        }
    }
    int s;
    scanf("%d",&s);
    for(int i =0;i<s;i++){
        scanf("%d",&val);
        search(root,val);
    }
}

