#include<stdio.h>//factorial
int main(){
    int fact =1;
    int n;
    printf("Enter the number");
    scanf("%d",&n);
    if(n<0){
        printf("Enter value greater than 0");
    }else{
        for(int i =n; i>=1;i--){
        fact=fact*i;}
        printf("factorial of %d is %d",n,fact);
    }
    return 0;
}