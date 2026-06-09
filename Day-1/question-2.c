#include<stdio.h>
int main(){
    int a,b;
    printf(" Enter the number for the multiplication table ");
    scanf("%d",&a);
    for(b=1;b<=10;b++){
        printf("%d\n",a*b);
    }
    return 0;
}