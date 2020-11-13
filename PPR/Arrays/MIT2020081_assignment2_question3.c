#include<stdio.h>


void Transpose(int *arr,int m,int n){
    for(int j=0;j<n;j++){
        for(int i =0;i<m;i++){
            printf("%d ", *((arr + i*n)+j));
        }
        printf("\n");
    }
}

void main(){
    int m,n;
    printf("Input m,n : \n");
    scanf("%d",&m);
    scanf("%d",&n);
    int input[m][n];
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&input[i][j]);
        }
    }

    Transpose(&input,m,n);

}