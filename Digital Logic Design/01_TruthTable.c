#include<stdio.h>

void row(int, int*, int*);

void row(int c, int *ptr1, int *ptr2){
    switch(c){
        case 1: *ptr1=0;*ptr2=0;
                break;
        case 2: *ptr1=0;*ptr2=1;
                break;
        case 3: *ptr1=1;*ptr2=0;
                break;
        case 4: *ptr1=1;*ptr2=1;
                break;
        default:printf("Something Went Wrong");
                break;
    }
}


int main(){
    int A, B;
    int *ptr1=&A, *ptr2=&B;
    row(1, ptr1, ptr2);
    printf("%d    %d\n", A, B);
    row(2, ptr1, ptr2);
    printf("%d    %d\n", A, B);
    row(3, ptr1, ptr2);
    printf("%d    %d\n", A, B);
    row(4, ptr1, ptr2);
    printf("%d    %d\n", A, B);
    return 0;
}