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

int XOR(int A, int B){
    return A^B;
}
int XNOR(int A, int B){
    return !(A^B);
}
//implementing by basic gates
int XOR_usingBasicGates(int A,int B){
    return OR(AND(A, NOT(B)), AND(NOT(A), B));//(A AND !B) OR (!A AND B)
}
int XNOR_usingBasicGates(int A,int B){
    return OR(AND(A, B), AND(NOT(A), NOT(B)));//(A AND B) OR (!A AND !B)
}



void row(int c, int *ptr1, int *ptr2) {
    *ptr1 = (c - 1) / 2;
    *ptr2 = (c - 1) % 2;
}

int main() {
    int A, B;

    printf("A XOR B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d AND %d = %d\n", A, B, XOR(A, B));
    }

    printf("A XNOR B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d OR %d = %d\n", A, B, XNOR(A, B));
    }

    printf("Implementing by Basic Gates\n");

    printf("A XOR B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d AND %d = %d\n", A, B, XOR_usingBasicGates(A, B));
    }

    printf("A XNOR B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d OR %d = %d\n", A, B, XNOR_usingBasicGates(A, B));
    }

    return 0;
}
