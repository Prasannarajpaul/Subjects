#include <stdio.h>

int NOT(int A) {
    return !A;
}
int AND(int A, int B) {
    return A && B;
}
int OR(int A, int B) {
    return A || B;
}
//Using Basic Gates
int NAND(int A, int B){
    return NOT(AND(A, B));
}
int NOR(int A, int B){
    return NOT(OR(A, B));
}

void row(int c, int *ptr1, int *ptr2) {
    *ptr1 = (c - 1) / 2;
    *ptr2 = (c - 1) % 2;
}

int main() {
    int A, B;

    printf("A NOR B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d AND %d = %d\n", A, B, NOR(A, B));
    }

    printf("A NAND B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d OR %d = %d\n", A, B, NAND(A, B));
    }


    return 0;
}
