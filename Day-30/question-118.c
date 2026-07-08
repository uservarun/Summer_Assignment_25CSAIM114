#include<stdio.h>
#include<string.h>
struct Book{
    int id;
    char title[100];
    char author[50];
    int available;
};
int main(){
    struct Book library[100];
    int count=0,choice,searchId;
    while(1){
        printf("\n1.Add Book\n2.Display Books\n3.Search Book\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter Book ID: ");
            scanf("%d",&library[count].id);
            getchar();
            printf("Enter Title: ");
            fgets(library[count].title,sizeof(library[count].title),stdin);
            library[count].title[strcspn(library[count].title,"\n")]=0;
            printf("Enter Author: ");
            fgets(library[count].author,sizeof(library[count].author),stdin);
            library[count].author[strcspn(library[count].author,"\n")]=0;
            library[count].available=1;
            count++;
        }else if(choice==2){
            if(count==0){
                printf("Library is empty.\n");
            }else{
                for(int i=0;i<count;i++){
                    printf("ID: %d | Title: %s | Author: %s | Status: %s\n",library[i].id,library[i].title,library[i].author,library[i].available?"Available":"Borrowed");
                }
            }
        }else if(choice==3){
            printf("Enter Book ID to search: ");
            scanf("%d",&searchId);
            int found=0;
            for(int i=0;i<count;i++){
                if(library[i].id==searchId){
                    printf("Found! Title: %s | Author: %s | Status: %s\n",library[i].title,library[i].author,library[i].available?"Available":"Borrowed");
                    found=1;
                    break;
                }
            }
            if(!found)printf("Book not found.\n");
        }else if(choice==4){
            break;
        }else{
            printf("Invalid choice.\n");
        }
    }
    return 0;
}