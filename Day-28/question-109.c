#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Book {
    int id;
    char title[50];
    char author[50];
    int is_issued;
};
void addBook(FILE *fp) {
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar();
    printf("Enter Title: ");
    fgets(b.title, 50, stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(b.author, 50, stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    b.is_issued = 0;
    fseek(fp, 0, SEEK_END);
    fwrite(&b, sizeof(struct Book), 1, fp);
    printf("Book added successfully!\n");
}
void displayBooks(FILE *fp) {
    struct Book b;
    rewind(fp);
    printf("\nID\tTitle\t\tAuthor\t\tStatus\n");
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        printf("%d\t%s\t\t%s\t\t%s\n", b.id, b.title, b.author, b.is_issued ? "Issued" : "Available");
    }
}
void issueBook(FILE *fp) {
    int id, found = 0;
    struct Book b;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (b.is_issued) {
                printf("Book is already issued.\n");
            } else {
                b.is_issued = 1;
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("Book issued successfully!\n");
            }
            break;
        }
    }
    if (!found) printf("Book not found.\n");
}
void returnBook(FILE *fp) {
    int id, found = 0;
    struct Book b;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (!b.is_issued) {
                printf("Book was not issued.\n");
            } else {
                b.is_issued = 0;
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("Book returned successfully!\n");
            }
            break;
        }
    }
    if (!found) printf("Book not found.\n");
}
int main() {
    FILE *fp = fopen("library.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("library.dat", "wb+");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
    }
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addBook(fp);
        else if (choice == 2) displayBooks(fp);
        else if (choice == 3) issueBook(fp);
        else if (choice == 4) returnBook(fp);
        else if (choice == 5) break;
        else printf("Invalid choice.\n");
    }
    fclose(fp);
    return 0;
}