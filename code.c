#include <stdio.h>
#include <string.h>

int main(void){
    long ccNumber;

    do{
        printf("Insert CC Number: \n");
        scanf("%ld", &ccNumber);
    } while (ccNumber <= 0);

    long ccCopy = ccNumber;
    int sum;
    int count = 0;
    long divisor = 10;
    char result[16];

    while(ccCopy > 0){
        int lastDigit = ccCopy % 10;
        sum = sum + lastDigit;
        ccCopy = ccCopy / 100;
        printf("%i\n", sum);
    }

    ccCopy = ccNumber / 10;

    while(ccCopy > 0){
        int lastDigit = ccCopy % 10;
        int timesTwo = lastDigit * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        ccCopy = ccCopy / 100;
    }
    
    ccCopy = ccNumber;

    while(ccCopy != 0){
        ccCopy = ccCopy / 10;
        count++;
    }

    for(int i = 0; i < count - 2; i++){
        divisor = divisor * 10;
    }

    int firstDigit = ccNumber / divisor;
    int firstTwo = ccNumber / (divisor / 10);

    if(sum % 10 == 0){
        if(firstDigit == 4 && (count == 13 || count == 16)){
            strcpy(result, "VISA");
        } else if((firstTwo == 34 || firstTwo == 37) && count == 15){
            strcpy(result, "AMEX");
        } else if((firstTwo > 50 || firstTwo < 56) && count == 16){
            strcpy(result, "MASTERCARD");
        } else {
            strcpy(result, "INVALID");
        }
    }

    else {
        strcpy(result, "INVALID lol");
    }

    printf("%i\n", sum);
    printf("%s\n", result);
