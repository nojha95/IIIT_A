#include<stdio.h>
#include<stdlib.h>

struct Pqueue{
    int *arr;
    int size;
    int capacity;
};

struct Pqueue* newPqueue(int capacity){
    int *arr = (int*)malloc(capacity*(sizeof(int)));
    struct Pqueue* new_heap = (struct Pqueue*)malloc(sizeof(struct Pqueue*));

    new_heap->arr = arr;
    new_heap->capacity = capacity;
    new_heap->size = 0;
    return new_heap;
}

void enqueue(struct Pqueue *maxheap,int val){
    if(maxheap->capacity == maxheap->size){
        printf("Pqueue Full");
        return;
    }
    maxheap->size++;
    int i = maxheap->size -1;
    maxheap->arr[i] = val;
    int parent = (i-1)/2;

    while(i != 0 && maxheap->arr[parent] < maxheap->arr[i]){
        int temp = maxheap->arr[parent];
        maxheap->arr[parent] = maxheap->arr[i];
        maxheap->arr[i] = temp;

        i = parent;
        parent = (i-1)/2;
    }
}

void heapify(int *arr,int size,int i){
    int maximum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && *(arr + left) > *(arr + maximum)){
        maximum = left;
    }
    if(right < size && *(arr + right) > *(arr + maximum)){
        maximum = right;
    }

    if(maximum != i){
        int temp = *(arr + maximum);
        *(arr + maximum) = *(arr + i);
        *(arr + i) = temp;
        heapify(arr,size,maximum);
    }

    
}

void dequeue(struct Pqueue *heap){
    if(heap->size == 0){
        return;
    }

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapify(heap->arr,heap->size,0);

}

void printPqueue(struct Pqueue *heap){
    for(int i = 0; i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    struct Pqueue* queue = newPqueue(n);
    int val= 0;
    for(int i =0;i<n;i++){
        scanf("%d",&val);
        enqueue(queue,val);
    }
    printPqueue(queue);
}


