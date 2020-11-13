#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t>0){
        int n=0,window =0;
        scanf("%d",&n);
        int input[n];
        for(int i=0;i<n;i++){
            scanf("%d",&input[i]);
        }
        scanf("%d",&window);
    
        for(int i = 0;i<n-window+1;i++){
                int flag = 0;
                for(int j =i;j<window+i;j++){
                    if(input[j]<0){
                        printf("%d ", input[j]);
                        flag = 1;
                        break;
                    }
                    if( (j==i+ window -1) && flag==0){
                        printf("0 ");
                }
                
            }
        }
    }
}




/*void main (){
    //int t;
    //scanf("%d", &t);
    //while(t>0){
      //  int n=0,window =0;
       // scanf("%d",&n);
        //int input[n];
        //for(int i=0;i<n;i++){
        //    scanf("%d",&input[i]);
        //}
        //scanf("%d",&window);
        int n = 8;
        int input[] = {12,-1,-7,8,-15,30,16,28}; 
        int window = 3;
        for(int i = 0;i<n-window+1;i++){
            int flag = 0;
            for(int j =i;j<window+i;j++){
                if(input[j]<0){
                    printf("%d ", input[j]);
                    flag = 1;
                    break;
                }
                if( (j==i+ window -1) && flag==0){
                    printf("0 ");
                }
                
            }
        }

        
        //t--;
    //}
}*/