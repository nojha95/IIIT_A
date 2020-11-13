#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
    int coeff; 
    int pow; 
    struct Node *next; 
}; 

struct Node* newNode(int coeff,int pow){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    return temp;
}

void generate(struct Node **head,int coeff,int pow){
    struct Node *new_node = newNode(coeff,pow);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    new_node->next = *head;
    *head = new_node;
    return;

}

void print(struct Node *head) 
{ 
while(head != NULL) 
    { 
    printf("%dx^%d", head->coeff, head->pow); 
    if(head->next != NULL) 
        printf(" + "); 
    
    head = head->next; 
    }

} 

void polyadd(struct Node *poly1, struct Node *poly2, struct Node **poly) {

    while(poly1 != NULL && poly2 != NULL){
        if(poly1->pow > poly2->pow){
            generate(poly,poly1->coeff,poly1->pow);
            poly1 = poly1->next;
        }else if(poly1->pow < poly2->pow){
            generate(poly,poly2->coeff,poly2->pow);
            poly2 = poly2->next;
        }else{
            generate(poly,poly1->coeff + poly2->coeff,poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

    }

    while(poly1 != NULL){
        generate(poly,poly1->coeff,poly1->pow);
        poly1 = poly1->next;
    }

    while(poly2 != NULL){
        generate(poly,poly2->coeff,poly2->pow);
        poly2 = poly2->next;
    }
}

void insertionSort(struct Node **head){
    struct Node *it = *head;
    struct Node *jt = *head;

    while(it != NULL){
        struct Node *max = it;
        jt = it;
        while(jt!= NULL){
            if(jt->pow > max->pow){
                max = jt;
            }
            jt = jt->next;
        }
        int temppow = it->pow;
        int tempcoeff = it->coeff;
        it->pow = max->pow;
        it->coeff = max->coeff;
        max->pow = temppow;
        max->coeff = tempcoeff;
        it = it->next;
    }

}



int main() 
{ 
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
      
    // Create first list of 5x^2 + 4x^1 + 2x^0 
    generate(&poly1,2,2); 
    generate(&poly1,3,1); 
    generate(&poly1,4,0); 
      
    // Create second list of 5x^1 + 5x^0 
    generate(&poly2,1,3); 
    generate(&poly2,2,1);
    generate(&poly2,1,0); 
      
    printf("1st Number: ");  
    print(poly1); 
      
    printf("\n2nd Number: "); 
    print(poly2); 
      
    //poly = (struct Node *)malloc(sizeof(struct Node)); 
      
    //Function add two polynomial numbers 
    polyadd(poly1, poly2, &poly); 
    insertionSort(&poly);  
    //Display resultant List 
    printf("\nAdded polynomial: "); 
    print(poly); 
  
return 0; 
} 