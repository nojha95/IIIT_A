#include<stdio.h>
#include<stdlib.h>

int heapify(int *arr,int size,int i){
    int count = 0;
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
        count = 1 + heapify(arr,size,maximum);
    }

    return count;
}

int buldMinHeap(int *arr,int size){
    int count =0;
    int i = (size)/2 - 1;
    int total =0;
    for(i; i>=0 ; i--){
        count = heapify(arr,size,i);
        total = total + count;
    }

    return total;
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int *arr = (int*)malloc(n *sizeof(int));
        for(int i =0;i<n;i++){
            scanf("%d",(arr+i));
        }
        int count = buldMinHeap(arr,n);
        printf("%d \n",count);
    }
}
