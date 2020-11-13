#include<stdio.h>

//For an n*n matrix diagonal elements are given. 
//All non-diagonal elements are equal,  say x. 
//Find out the minimum value of x such that the sum of diagonal elements is less  than the sum of non diagonal elements. 

void main(){
    int n ;
    scanf("%d",&n);
    int input[n];
    int sum =0;
    for(int i =0;i<n;i++){
        scanf("%d",&input[i]);
        sum = sum + input[i];
    }
    int ans = (sum/(n*n - n)) + 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                printf("%d ",*(input + i));
            }else{
                printf("%d ",ans);
            }
        }
        printf("\n");
    }

}