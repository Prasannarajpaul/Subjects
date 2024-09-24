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

void row(int c, int *ptr1, int *ptr2) {
    *ptr1 = (c - 1) / 2;
    *ptr2 = (c - 1) % 2;
}

int main() {
    int A, B;

    printf("A NOT Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("NOT %d = %d, NOT %d = %d\n", A, NOT(A), B, NOT(B));
    }
    
    printf("A AND B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d AND %d = %d\n", A, B, AND(A, B));
    }

    printf("A OR B Operation\n");
    for (int i = 1; i <= 4; i++) {
        row(i, &A, &B);
        printf("%d OR %d = %d\n", A, B, OR(A, B));
    }


    return 0;
}
