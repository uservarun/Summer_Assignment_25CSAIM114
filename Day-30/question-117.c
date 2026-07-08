#include<stdio.h>
#include<string.h>
struct Student{
    int roll;
    char name[50];
    float marks;
};
int main(){
    struct Student students[100];
    int count=0,choice;
    while(1){
        printf("\n1.Add\n2.Display\n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter roll: ");
            scanf("%d",&students[count].roll);
            printf("Enter name: ");
            scanf("%s",students[count].name);
            printf("Enter marks: ");
            scanf("%f",&students[count].marks);
            count++;
        }else if(choice==2){
            for(int i=0;i<count;i++){
                printf("Roll: %d, Name: %s, Marks: %.2f\n",students[i].roll,students[i].name,students[i].marks);
            }
        }else if(choice==3){
            break;
        }else{
            printf("Invalid choice\n");
        }
    }
    return 0;
}