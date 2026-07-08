#include<stdio.h>
#include<string.h>
struct Product{
    int id;
    char name[50];
    int quantity;
    float price;
};
void addProduct(struct Product inv[],int *count){
    printf("Enter Product ID: ");
    scanf("%d",&inv[*count].id);
    getchar();
    printf("Enter Product Name: ");
    fgets(inv[*count].name,sizeof(inv[*count].name),stdin);
    inv[*count].name[strcspn(inv[*count].name,"\n")]=0;
    printf("Enter Quantity: ");
    scanf("%d",&inv[*count].quantity);
    printf("Enter Price: ");
    scanf("%f",&inv[*count].price);
    (*count)++;
    printf("Product added successfully!\n");
}
void displayInventory(struct Product inv[],int count){
    if(count==0){
        printf("Inventory is empty.\n");
        return;
    }
    for(int i=0;i<count;i++){
        printf("ID: %d | Name: %s | Qty: %d | Price: $%.2f\n",inv[i].id,inv[i].name,inv[i].quantity,inv[i].price);
    }
}
void searchProduct(struct Product inv[],int count){
    char searchName[50];
    int found=0;
    getchar();
    printf("Enter Product Name to search: ");
    fgets(searchName,sizeof(searchName),stdin);
    searchName[strcspn(searchName,"\n")]=0;
    for(int i=0;i<count;i++){
        if(strcasecmp(inv[i].name,searchName)==0){
            printf("Found! ID: %d | Name: %s | Qty: %d | Price: $%.2f\n",inv[i].id,inv[i].name,inv[i].quantity,inv[i].price);
            found=1;
        }
    }
    if(!found)printf("Product not found.\n");
}
int main(){
    struct Product inventory[100];
    int count=0,choice;
    while(1){
        printf("\n--- Store Inventory Management System ---\n");
        printf("1. Add Product\n2. Display Inventory\n3. Search Product by Name\n4. Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            addProduct(inventory,&count);
        }else if(choice==2){
            displayInventory(inventory,count);
        }else if(choice==3){
            searchProduct(inventory,count);
        }else if(choice==4){
            break;
        }else{
            printf("Invalid choice.\n");
        }
    }
    return 0;
}