#include <stdio.h>
int main() {
    int num, rem ,sum =0, original;
    printf("Enter a number ");
    scanf("%d",&num);
    original = num;
    while(num>0){
        rem = num%10;
        sum+=rem;
        num =num/10;
    }
    printf("The sum of digits of %d is %d\n",original,sum);

    return 0;
}