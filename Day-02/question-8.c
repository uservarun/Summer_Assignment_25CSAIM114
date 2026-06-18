#include<stdio.h>
int main(){
    int n, rev=0, rem,original;
    printf("Enter the number ");
    scanf("%d",&n);
    original=n;
    while(n>0){
        rem = n%10;
        rev= rev*10+rem;
        n/=10;
    }
    if(rev==original){
        printf("Number is palindrome");
    } else{
        printf("Number is not palindrome");
    }
    return 0;
} 