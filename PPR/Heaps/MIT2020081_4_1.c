#include<stdio.h>
#include<stdlib.h>

struct Heap{
    int *arr;
    int size;
    int capacity;
};

struct Heap* newHeap(int capacity){
    int *arr = (int*)malloc(capacity*(sizeof(int)));
    struct Heap* new_heap = (struct Heap*)malloc(sizeof(struct Heap*));

    new_heap->arr = arr;
    new_heap->capacity = capacity;
    new_heap->size = capacity;
    return new_heap;
}

void heapify(int *arr,int size,int i){
    int minimum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && *(arr + left) < *(arr + minimum)){
        minimum = left;
    }
    if(right < size && *(arr + right) < *(arr + minimum)){
        minimum = right;
    }

    if(minimum != i){
        int temp = *(arr + minimum);
        *(arr + minimum) = *(arr + i);
        *(arr + i) = temp;
        heapify(arr,size,minimum);
    }

    
}

void buldMinHeap(struct Heap *heap){
    int i = (heap->size)/2 - 1;

    for(i; i>=0 ; i--){
        heapify(heap->arr,heap->size,i);
    }
}

void deleteRoot(struct Heap *heap){
    if(heap->size == 0){
        return;
    }

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapify(heap->arr,heap->size,0);

}

void printHeap(struct Heap *heap){
    for(int i = 0; i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int k;
        scanf("%d",&k);
        
        struct Heap *minheap = newHeap(n);

        for(int i = 0;i<n ;i++){
            scanf("%d",&minheap->arr[i]);
        }

        buldMinHeap(minheap);
        printHeap(minheap);
        for(int i =0;i<k;i++){
            deleteRoot(minheap);
            
        }
        printHeap(minheap);
        
    }
    return 0;
}

