#include<stdio.h>
#include<stdlib.h>

void heapify(int *arr,int size,int rootindex){
    int largest = rootindex;
    int left = 2*rootindex + 1;
    int right = 2*rootindex + 2;

    if(left < size && *(arr + left) > *(arr + largest)){
        largest = left;
    }
    if(right < size && *(arr + right) > *(arr + largest)){
        largest = right;
    }

    if(largest != rootindex){
        int temp = *(arr + largest);
        *(arr + largest) = *(arr + rootindex);
        *(arr + rootindex) = temp;
        heapify(arr,size,largest);
    }
}

void buildHeap(int *arr , int size){
    int i = (size/2)-1;
    for(i;i >=0;i--){
        heapify(arr,size,i);
    }
}

void heapSort(int *arr,int size){
    buildHeap(arr,size);

    while(size >0){
        int top = *(arr);
        *(arr) = *(arr + size - 1);
        size--;
        heapify(arr,size,0);
        *(arr + size) = top;
    }

}

void printarr(int *arr,int size){
    for(int i =0;i<size;i++){
        printf("%d ",*(arr + i));
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int size;
        scanf("%d",&size);
        int *arr = (int*)malloc(size*(sizeof(int*)));

        for(int i =0;i<size;i++){
            scanf("%d",(arr+i));
        }

        heapSort(arr,size);
        printarr(arr,size);

    }
}