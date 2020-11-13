#include <stdio.h>

/* Question 10 - There are 2 sorted arrays A and B of size n each. 
Write an algorithm to find the median of the array obtained after merging the above 2 arrays 
(i.e. array of length  2n).  */

void getMedian(int *arr1,int *arr2, int n){
    int i=0,j=0,k=0;
    int merge[2*n] ;
    while(i<n && j<n){
        if (*(arr1 + i) < *(arr2 + j)){

            merge[k] = *(arr1 + i);
            i++;
            k++;
            
        }else{

            merge[k] = *(arr2 + j);
            j++;
            k++;
        }
    }

    while(i<n ){

        merge[k] = *(arr1 + i);
        i++;
        k++;
    }
    while(j<n){
        merge[k] = *(arr2 + j);
        j++;
        k++;
        
    }
   /* printf("Merged arr = ");
    for(int i =0;i<2*n;i++){
        printf( "%d ", merge[i]);
    }*/

    printf("\n");
    int median = (merge[n-1] + merge[n])/2;
    printf("Median : %d",median);
}


void main(){
    int n;
    printf(" Enter size of both array : ");
    scanf("%d",&n);
    int arr1[n];
    printf("Insert 1st array in sorted order: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Insert 2nd array in sorted order : ");
    int arr2[n];
    for(int i =0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    
    getMedian(arr1,arr2,n);
}