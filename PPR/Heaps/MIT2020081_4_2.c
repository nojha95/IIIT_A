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
    new_heap->size = 0;
    return new_heap;
}

void insert(struct Heap *maxheap,int val){
    if(maxheap->capacity == maxheap->size){
        printf("Heap Full");
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

void buldMaxHeap(struct Heap *heap){
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

int search(struct Heap* heap,int val)
{
    int i;
    for(i=0;i<heap->size;i++)
    {
        if(heap->arr[i] == val)
        return i;
    }
    return -1;
}

void delete(struct Heap* heap,int val)
{ int loc = search(heap,val);
  if(loc == -1)
   {
       printf("Not found \n");
       return;
   }
   heap->arr[loc] = heap->arr[heap->size-1];
   heap->size--;
   heapify(heap->arr,heap->size,loc);
   printf("deleted\n");
   
}


void printHeap(struct Heap *heap){
    for(int i = 0; i<heap->size;i++){
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("a. Insert \n");
    printf("b. Delete \n");
    printf("c. Print \n");
    printf("d. Quit \n");
    
    char c;
    int val;
    int del;
    struct Heap* maxheap = newHeap(50);

    while(1){  
        scanf("%c",&c);
        switch(c)
        {
            case 'a': scanf("%d",&val);
                    insert(maxheap,val);
                    printf("inserted\n");
                    break;
            case 'b':scanf("%d",&del);
                        delete(maxheap,del);
                        break;
            case 'c':printHeap(maxheap);
                        break;
            case 'd': return 1;                  
        }
    }
}


