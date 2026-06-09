#include<stdio.h>
int sum(int a);
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("%d", sum(n));
    return 0;
    
}
int sum(int a){
    int b;
    if(a==0){
        return 0;
    }else{
        b=(a*(a+1))/2;
        return b;
    }
}