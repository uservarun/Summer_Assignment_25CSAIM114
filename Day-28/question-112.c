#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
};
void addContact(FILE *fp) {
    struct Contact c;
    printf("Enter Contact ID: ");
    scanf("%d", &c.id);
    getchar();
    printf("Enter Name: ");
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = 0;
    printf("Enter Phone Number: ");
    fgets(c.phone, 15, stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;
    printf("Enter Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = 0;
    fseek(fp, 0, SEEK_END);
    fwrite(&c, sizeof(struct Contact), 1, fp);
    printf("Contact added successfully!\n");
}
void displayContacts(FILE *fp) {
    struct Contact c;
    rewind(fp);
    printf("\nID\tName\t\tPhone\t\tEmail\n");
    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        printf("%d\t%s\t\t%s\t\t%s\n", c.id, c.name, c.phone, c.email);
    }
}
void searchContact(FILE *fp) {
    char name[50];
    int found = 0;
    struct Contact c;
    getchar();
    printf("Enter Name to search: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    rewind(fp);
    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcasecmp(c.name, name) == 0) {
            printf("\nContact Found:\nID: %d\nName: %s\nPhone: %s\nEmail: %s\n", c.id, c.name, c.phone, c.email);
            found = 1;
        }
    }
    if (!found) printf("Contact not found.\n");
}
void deleteContact(FILE *fp) {
    int id, found = 0;
    struct Contact c;
    FILE *tempfp = fopen("temp.dat", "wb");
    if (tempfp == NULL) {
        printf("Error processing deletion.\n");
        return;
    }
    printf("Enter Contact ID to delete: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread