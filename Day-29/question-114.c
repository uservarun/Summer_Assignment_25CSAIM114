#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[100], n = 0, choice, i, element, position;
    while(1) {
        printf("\n1. Create Array\n2. Display Array\n3. Insert Element\n4. Delete Element\n5. Search Element\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 6) {
            exit(0);
        }
        switch(choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for(i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if(n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for(i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &position);
                if(position < 0 || position > n || n >= 100) {
                    printf("Invalid position or array full.\n");
                } else {
                    for(i = n; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = element;
                    n++;
                    printf("Element inserted.\n");
                }
                break;
            case 4:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &position);
                if(position < 0 || position >= n) {
                    printf("Invalid position.\n");
                } else {
                    for(i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Element deleted.\n");
                }
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &element);
                position = -1;
                for(i = 0; i < n; i++) {
                    if(arr[i] == element) {
                        position = i;
                        break;
                    }
                }
                if(position != -1) {
                    printf("Element found at position %d.\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}