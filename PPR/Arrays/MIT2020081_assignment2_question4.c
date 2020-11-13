#include<stdio.h>
#include<stdlib.h>

void uniqueRow(int* input,int size){
    int uniqueRow[size][size];

    for(int i = 0; i < size; i++){
        for(int j = 0;j < size; j++){
            uniqueRow[i][j] = *(input + i*size + j);
            for(int k = size-1;k > j ; k--){
                if(*(input + i*size + j) == *(input + i*size + k)){
                    uniqueRow[i][j] = __INT8_MAX__;
                }
            }
        }
    }
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size ; j++){
            if(uniqueRow[i][j] != __INT8_MAX__){
                printf("%d ",uniqueRow[i][j]);
            }
        }
        printf("\n");
    }
}

void uniqueCol(int* input,int size){
    int uniqueCol[size][size];
    for(int j = 0; j < size; j++){
        for(int i = 0;i < size; i++){
            uniqueCol[i][j] = *(input + i*size + j);
            for(int k = size-1;k > i ; k--){
                if(*(input + i*size + j) == *(input + k*size + j)){
                    uniqueCol[i][j] = __INT8_MAX__;
                }
            }
        }
    }
    for(int j = 0;j < size;j++){
        for(int i = 0;i < size ; i++){
            if(uniqueCol[i][j] != __INT8_MAX__){
                printf("%d ",uniqueCol[i][j]);
            }
        }
        printf("\n");
    }
}

void bubbleSortAsc(int* input,int size){
    int temp;
    for(int i = 0 ;i < size; i++){
        for(int j = 0;j < size-1; j++){
            if(*(input+j) > *(input + j+1)){
            temp = *(input + j);
            *(input +j) = *(input + j +1);
            *(input+j+1) = temp;   
            }
        }
    }
}

void uniqueArray(int* input,int size){
    int unique[size*size];
    for(int i = 0 ;i < size*size;i++){
        unique[i] = *(input + i);
        for(int j = size*size - 1; j > i;j-- ){
            if(*(input + i) == *(input + j)){
                unique[i] = __INT8_MAX__;
            }
            
        }
    }
    bubbleSortAsc(unique,size*size);
    for(int i =0;i<size*size;i++){
        if(unique[i] != __INT8_MAX__){
            printf("%d ",unique[i]);
        }
    }
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
        //uniqueRow(input,size);
        //printf("COL \n");
        //uniqueCol(input,size);
        //printf("unique Arr \n");
        uniqueArray(input,size);
        //testCase--;
   // }
    return 0;
}
