#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str1[100], str2[100];
    int choice, result;
    while(1) {
        printf("\n1. Length of String\n2. Copy String\n3. Concatenate Strings\n4. Compare Strings\n5. Reverse String\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();
        if(choice == 6) {
            exit(0);
        }
        switch(choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Length: %lu\n", strlen(str1));
                break;
            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                result = strcmp(str1, str2);
                if(result == 0) {
                    printf("Strings are equal.\n");
                } else if(result > 0) {
                    printf("First string is greater.\n");
                } else {
                    printf("Second string is greater.\n");
                }
                break;
            case 5:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                result = strlen(str1);
                for(int i = 0; i < result / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[result - i - 1];
                    str1[result - i - 1] = temp;
                }
                printf("Reversed string: %s\n", str1);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}