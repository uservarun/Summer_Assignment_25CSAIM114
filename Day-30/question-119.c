#include<stdio.h>
#include<string.h>
struct Employee{
    int id;
    char name[50];
    char designation[50];
    float salary;
};
int main(){
    struct Employee emp[100];
    int count=0,choice,searchId;
    while(1){
        printf("\n1.Add Employee\n2.Display All\n3.Search Employee\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter ID: ");
            scanf("%d",&emp[count].id);
            getchar();
            printf("Enter Name: ");
            fgets(emp[count].name,sizeof(emp[count].name),stdin);
            emp[count].name[strcspn(emp[count].name,"\n")]=0;
            printf("Enter Designation: ");
            fgets(emp[count].designation,sizeof(emp[count].designation),stdin);
            emp[count].designation[strcspn(emp[count].designation,"\n")]=0;
            printf("Enter Salary: ");
            scanf("%f",&emp[count].salary);
            count++;
        }else if(choice==2){
            if(count==0){
                printf("No employee records found.\n");
            }else{
                for(int i=0;i<count;i++){
                    printf("ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",emp[i].id,emp[i].name,emp[i].designation,emp[i].salary);
                }
            }
        }else if(choice==3){
            printf("Enter Employee ID to search: ");
            scanf("%d",&searchId);
            int found=0;
            for(int i=0;i<count;i++){
                if(emp[i].id==searchId){
                    printf("Found! Name: %s | Dept: %s | Salary: %.2f\n",emp[i].name,emp[i].designation,emp[i].salary);
                    found=1;
                    break;
                }
            }
            if(!found)printf("Employee not found.\n");
        }else if(choice==4){
            break;
        }else{
            printf("Invalid choice.\n");
        }
    }
    return 0;
}