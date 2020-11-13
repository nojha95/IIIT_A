#include<stdio.h>
#include<stdlib.h>

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

    if(val < root->val){
        root->left = insert(root->left,val);
    }

    else if(val > root->val){
        root->right = insert(root->right,val);
    }
    return root;
}

int checkIdentical(struct Node* root1,struct Node* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }else if(root1 != NULL && root2 == NULL){
        return 0;
    }else if(root2 != NULL && root1 == NULL){
        return 0;
    }

    if(root1->val == root2->val){
        return 1;
    }else{
        return 0;
    }

    return (checkIdentical(root1->left,root2->left) && checkIdentical(root1->right,root2->right) );
}

void isIdentical(struct Node* root1,struct Node* root2){
    if(checkIdentical(root1,root2)){
        printf("y \n");
    }else{
        printf("n \n");
    }
}


int main(){
    int t;
    scanf("%d",&t);
    int n = 0;
    scanf("%d",&n);
    while(t>0){

        struct Node* root1 = NULL;
        struct Node* root2 = NULL;
        int val =0;
        for(int i =0;i<n;i++){
            scanf("%d",&val);
            root1 = insert(root1,val);
        }
        for(int i =0;i<n;i++){
            scanf("%d",&val);
            root2 = insert(root2,val);
        }
        isIdentical(root1,root2);
        t--;
    }
}