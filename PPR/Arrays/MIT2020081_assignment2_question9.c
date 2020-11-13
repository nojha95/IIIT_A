#include<stdio.h>

//You are given a list of n-1 integers and these integers are in the range of 1 to n.  There are no duplicates in the list. 
//One of the integers is missing in the list. Write an  efficient code to find the missing integer

void main(){
    int n,val,sum = 0;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&val);
        sum = sum + val;
    }
    n = n + 1;
    int total = (n*(n+1))/2;
    val = total -sum;
    printf("%d",val);
}