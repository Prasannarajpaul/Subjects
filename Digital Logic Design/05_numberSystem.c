#include<stdio.h>
#include<math.h>
#include<string.h>

void print();
int binaryToDecimal(long long n);
long long decimalToBinary(int n);
int octalToDecimal(int n);
int decimalToOctal(int decimalNum);
int hexToDecimal(char hex[]);
void decimalToHex(int decimalNum, char hex[]);
int binaryToGray(int binary);
int grayToBinary(int gray);

int main(){
    int choice, num;
    char hex[17];

    print();
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter binary number: ");
            scanf("%lld", &num);
            printf("Decimal: %d\n", binaryToDecimal(num));
            break;
        case 2:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            printf("Binary: %lld\n", decimalToBinary(num));
            break;
        case 3:
            printf("Enter octal number: ");
            scanf("%d", &num);
            printf("Decimal: %d\n", octalToDecimal(num));
            break;
        case 4:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            printf("Octal: %d\n", decimalToOctal(num));
            break;
        case 5:
            printf("Enter hexadecimal number: ");
            scanf("%s", hex);
            printf("Decimal: %d\n", hexToDecimal(hex));
            break;
        case 6:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            decimalToHex(num, hex);
            printf("Hexadecimal: %s\n", hex);
            break;
        case 7:
            printf("Enter binary number: ");
            scanf("%d", &num);
            printf("Gray Code: %d\n", binaryToGray(num));
            break;
        case 8:
            printf("Enter Gray code: ");
            scanf("%d", &num);
            printf("Binary: %d\n", grayToBinary(num));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    

}

void print(){
    printf("Number System Conversion Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Octal to Decimal\n");
    printf("4. Decimal to Octal\n");
    printf("5. Hexadecimal to Decimal\n");
    printf("6. Decimal to Hexadecimal\n");
    printf("7. Binary to Gray Code\n");
    printf("8. Gray Code to Binary\n");
    printf("Enter your choice: ");
}

//Binary to Decimal
int binaryToDecimal(long long n){
    int decimal=0, i=0, remainder;
    while(n!=0){
        remainder = n%10;
        n/=10;
        decimal+=remainder*pow(2, i);
        i++;
    }
    return decimal;
}
//Decimal to Binary
long long decimalToBinary(int n){
    long long binary = 0;
    int remainder, i=1;
    while(n!=0){
        remainder = n%2;
        n/=2;
        binary+=remainder*i;
        i*=10;    
    }
    return binary;    
}
//Octal to Decimal
int octalToDecimal(int n) {
    int decimal = 0, i = 0, remainder;

    while (n != 0) {
        remainder = n%10;
        n /= 10;
        decimal += remainder * pow(8, i);
        i++;
    }
    return decimal;
}
//Decimal to Octal
int decimalToOctal(int n){
    int octal = 0;
    int remainder, i=1;
    while(n!=0){
        remainder = n%8;
        n/=8;
        octal+=remainder*i;
        i*=10;
    }
    return octal;
}
//Hexadecimal to Decimal
int hexToDecimal(char hex[]) {
    int decimal = 0, base = 1, len = strlen(hex);

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return decimal;
}

//Decimal to Hexadecimal
void decimalToHex(int decimalNum, char hex[]) {
    int i = 0;
    while (decimalNum != 0) {
        int temp = decimalNum % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
        } else {
            hex[i] = temp + 55;
        }
        i++;
        decimalNum /= 16;
    }
    hex[i] = '\0';

    // Reverse the hex string to get correct hex number
    strrev(hex);
}

//Binary to Gray
int binaryToGray(int binary) {
    return binary ^ (binary >> 1);
}

// Gray to Binary
int grayToBinary(int gray) {
    int binary = gray;
    while (gray >>= 1) {
        binary ^= gray;
    }
    return binary;
}