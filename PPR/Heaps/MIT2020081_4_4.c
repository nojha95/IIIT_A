#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Heap{
    int val;
    struct Heap *left, *right, *parent;
};



struct Heap *root = NULL;
int heapsize = 0;

void bfs(){
    int qsize = 1000;
    struct Heap **queue = (struct Heap**) malloc(sizeof(struct Heap*) * qsize);

    for (int i = 0; i < qsize; i++){
        queue[i] = NULL;
    }
    queue[0] = root;
    int front = 0, rear = 0;
    while(queue[front]){
        printf("%d ", queue[front] -> val);
        if(queue[front] -> left){
            if((rear + 1) % qsize == front) {
                printf("overflow");
                exit(1);
            }
            rear = (rear + 1) % qsize;
            queue[rear] = queue[front] -> left;
        }
        if(queue[front] -> right){
            if((rear + 1) % qsize == front) {
                printf("overflow");
                exit(1);
            }
            rear =  (rear + 1) % qsize;
            queue[rear] = queue[front] -> right;
        }
        front = (front + 1) % qsize;
    }
    printf("\n");
}


int getLastNode(struct Heap *r, int cur){
    if(!(r -> left) && !(r -> right)) return cur;
    if(!(r -> right)) return cur + 1;
    return getLastNode(r -> right, cur + 1);
}


int getRightMost(struct Heap *root, int currentLevel){
    if(!root){
        return currentLevel;
    }else{
        return getRightMost(root -> right, currentLevel + 1);
    }
}

void heapifyDown(struct Heap *r){
    struct Heap *min = NULL;
    while(r){
        min = r;
        if((r -> left) && (r -> left -> val) < min -> val){
            min = r -> left;
        }
        if((r -> right) && (r -> right -> val) < min -> val){
            min = r -> right;
        }

        if(min == r) return;
        int temp = min -> val;
        min -> val = r -> val;
        r -> val = temp;
        r = min;
    }
}

void deleteMin(struct Heap *r){
    if(!(r -> left) && !(r -> right)){
        struct Heap *par = r -> parent;
        if(r == root){
            root = NULL;
            free(r);
            return;
        }else if((par -> right)){
            par -> right = NULL;
            root -> val = r -> val;
            free(r);
            heapsize--;
        }else{
            par -> left = NULL;
            root -> val = r -> val;
            free(r);
            heapsize--;
        }
        heapifyDown(root);
    }else if(!(r -> right)){
        deleteMin(r -> left);
    }else{
        int left = getLastNode(r -> left, 0);
        int right = getLastNode(r -> right, 0);
        if(left == right){
            deleteMin(r -> right);
        }else{
            deleteMin(r -> left);
        }
    }
}


void heapifyUp(struct Heap *child){
    while(child -> parent){
        struct Heap* parent = child -> parent;
        if(parent -> val > child ->  val){
            int temp = child -> val;
            child -> val = parent -> val;
            parent -> val = temp;
        }
        child = parent;
    }
}

void insert(struct Heap *r, int val){
    if(!r){
        r = (struct Heap *) malloc (sizeof(struct Heap));
        r -> val = val;
        r -> left = r -> right = r -> parent = NULL;
        root = r;
        heapsize++;
    }else if(!(r -> left)){
        struct Heap *temp = (struct Heap *) malloc (sizeof(struct Heap));
        temp -> val = val;
        temp -> left = temp -> right = NULL;
        temp -> parent = r;
        r -> left = temp;
        heapsize++;
        heapifyUp(temp);
    }else if(!(r -> right)){
        struct Heap *temp = (struct Heap *) malloc (sizeof(struct Heap));
        temp -> val = val;
        temp -> left = temp -> right = NULL;
        temp -> parent = r;
        r -> right = temp;
        heapsize++;
        heapifyUp(temp);
    }else{
        int leftLevel = getRightMost(r -> left, 0);
        int righLevel = getRightMost(r -> right, 0);
        if(leftLevel <= righLevel){
            insert(r -> left, val);
        }else {
            insert(r -> right, val);
        }
    }
}

int isEmpty(){
    if(root) return 0;
    else return 1;
}

int isFull(){
    int t = heapsize + 1;
    int numberOfSetBits = 0;
    printf("%d", t);
    for (int i = 0; i < 31; i++){
        if((t & (1 << i))){
            numberOfSetBits++;
        }
    }
    return numberOfSetBits == 1 ? 1 : 0;
}

int main(){
    int decision, val;
    while(1){
        scanf("%d", &decision);
        if(decision == 1){
            scanf("%d", &val);
            insert(root, val);
            bfs(root);
        }else if(decision == 2){
            if(!root){
                printf("Empty\n");
            }else{
                deleteMin(root);
                bfs(root);
            }
        }else if(decision == 3){
            if(isFull()){
                printf("Full\n");
            }else{
                printf("Not Full\n");
            }
        }else if(decision == 4){
            if(isEmpty()){
                printf("Empty\n");
            }else{
                printf("Not Empty\n");
            }
        }else{
            return 1;
        
        }
    }
    return 0;
}
