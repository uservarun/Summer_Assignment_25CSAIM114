#include<stdio.h>
int main(){
    int n, p=1, rem;
    printf("Enter the number ");
    scanf("%d",&n);
    while(n>0){
        rem = n%10;
        p *= rem;
        n/=10;
    }
    printf("product of its digit is %d",p);
}