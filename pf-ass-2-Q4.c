#include<stdio.h>
#include<stdlib.h>
void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main(){
int maxSize;

printf("Enter Maximum size of your stack: ");
if(scanf("%d",&maxSize)!=1|| maxSize<=0){
    printf("\nInvalid size. Please! enter valid siz.e");
    return 1;
}
int *stack=malloc( maxSize *sizeof(int));
if(!stack){
    printf("\nMemory allocation failed.\n");
    return 0;
}

int choice;
int top =-1;
do{
    printf("\nMENU\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.PEEK\n");
    printf("4.DISPLAY\n");
    printf("5.EXIT\n");
    
    printf("Enter your choice(1-5): ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
      push(stack,&top,maxSize); 
        break;
    case 2:
     pop(stack,&top);
    break;
    case 3:
     peek(stack,top);
    break;
    case 4:
     display(stack,top);
    break;
    case 5:
     printf("Exiting the system.....\n");
    break;
    default:
    printf("Invalid choice. Please enter correct choice.\n");
        break;
    }
}while (choice!=5);
 free(stack);
 
}

void push(int stack[], int *top, int maxSize){
    if (*top == maxSize - 1) {
        printf("\nStack Overflow! Cannot push more.\n");
    } else {
        int value;
        printf("\nEnter the value to push: ");
        scanf("%d",&value);
        (*top)++;
        stack[*top] =value;
        printf("\n%d inserted into stack.", value);
    }
   
}
void pop(int stack[],int *top){
  if (*top == -1) {
        printf("\nStack Underflow! No element to pop\n");
    } else {
        printf("\nElement %d poped sucessfully.",stack[*top]);
        (*top)--;
    }
}
void peek(int stack[],int top){
  if(top==-1){
    printf("\nNo element at top. Stack is empty");
  }
  else{
    printf("\nPeek element is :%d",stack[top]);
  }
}
void display(int stack[], int top){
     if(top==-1){
    printf("\nStack is empty! Nothing to display");
  }else{
    printf("\nCurrent stack element arranged top to bottom");
    for (int i = 0; i < top; i++)
    {
        printf("\n%d",stack[i]);
    }
    
  }
}