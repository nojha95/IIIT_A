#include<stdio.h>

void neighbourSum(int* input,int size){
    int sumArr[size];
    for(int i = 0;i<size;i++){
        if(i == 0){
            sumArr[i] = *(input + i*size + i+1) + *(input + (i+1)*size + i) + *(input + (i+1)*size + i+1) ;
        }
        else if(i == size -1){
            sumArr[i] = *(input + i*size + i -1) + *(input + (i-1)*size + i) + *(input + (i-1)*size + i-1);
        }else{
        sumArr[i] = *(input + (i-1)*size + i-1) + *(input + (i-1)*size + i)+ *(input + (i-1)*size + i+1) + *(input + i*size + i-1) +
        *(input + i*size + i+1) + 
        *(input + (i+1)*size + i -1) + *(input + (i+1)*size + i) + *(input + (i+1)*size + i+1);
        }


    }
    int largestIndex = 0;
    for(int i =0;i<size;i++){
        if(sumArr[i] > sumArr[largestIndex]){
            largestIndex = i;
        }
        printf("%d: %d \n",*(input + i*size + i),sumArr[i]);
    }
    printf("%d ", largestIndex+1);
    
}


int main(){
    //int testCase;
    //scanf("%d",&testCase);

    //while(testCase >0){
        int size;
        scanf("%d",&size);
        int *input = (int*)malloc(size*size*sizeof(int*));
        for(int i = 0;i < size; i++){
            for(int j = 0;j < size; j++){
                scanf("%d",(input + i*size + j));
            }
        }
        neighbourSum(input,size);
        //testCase--;
   // }
    return 0;
}
