#include<stdio.h>
int main(){
    int n;
    printf("Enter the number to count its digit\n");
    scanf("%d",&n);
    int original =n;
    int count = 0;
    if(n==0){
        count =1;
    }else {
        if (n < 0) {
            n = -n;
        }
        while (n != 0) {
            n = n / 10;
            count++;}}
    printf("digits in %d is %d",original,count);           
    return 0;
}