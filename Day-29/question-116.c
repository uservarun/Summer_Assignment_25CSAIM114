#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Item {
    int id;
    char name[50];
    int quantity;
    double price;
};
int main() {
    struct Item inventory[100];
    int count = 0, choice, i, id, found;
    while(1) {
        printf("\n1. Add Item\n2. Display Inventory\n3. Search Item\n4. Update Quantity\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 5) {
            exit(0);
        }
        switch(choice) {
            case 1:
                if(count >= 100) {
                    printf("Inventory full.\n");
                } else {
                    printf("Enter Item ID: ");
                    scanf("%d", &inventory[count].id);
                    getchar();
                    printf("Enter Item Name: ");
                    fgets(inventory[count].name, sizeof(inventory[count].name), stdin);
                    inventory[count].name[strcspn(inventory[count].name, "\n")] = 0;
                    printf("Enter Quantity: ");
                    scanf("%d", &inventory[count].quantity);
                    printf("Enter Price: ");
                    scanf("%lf", &inventory[count].price);
                    count++;
                    printf("Item added successfully.\n");
                }
                break;
            case 2:
                if(count == 0) {
                    printf("Inventory empty.\n");
                } else {
                    printf("\nID\tName\t\tQty\tPrice\n");
                    for(i = 0; i < count; i++) {
                        printf("%d\t%-15s\t%d\t%.2lf\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;
            case 3:
                printf("Enter Item ID to search: ");
                scanf("%d", &id);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(inventory[i].id == id) {
                        printf("Found! Name: %s, Qty: %d, Price: %.2lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Item not found.\n");
                }
                break;
            case 4:
                printf("Enter Item ID to update: ");
                scanf("%d", &id);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(inventory[i].id == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Quantity updated.\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Item not found.\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}