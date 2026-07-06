#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Ticket {
    int ticket_id;
    char passenger_name[50];
    char movie_title[50];
    int seat_number;
    double price;
};
void bookTicket(FILE *fp) {
    struct Ticket t;
    printf("Enter Ticket ID: ");
    scanf("%d", &t.ticket_id);
    getchar();
    printf("Enter Passenger Name: ");
    fgets(t.passenger_name, 50, stdin);
    t.passenger_name[strcspn(t.passenger_name, "\n")] = 0;
    printf("Enter Movie/Event Title: ");
    fgets(t.movie_title, 50, stdin);
    t.movie_title[strcspn(t.movie_title, "\n")] = 0;
    printf("Enter Seat Number: ");
    scanf("%d", &t.seat_number);
    printf("Enter Ticket Price: ");
    scanf("%lf", &t.price);
    fseek(fp, 0, SEEK_END);
    fwrite(&t, sizeof(struct Ticket), 1, fp);
    printf("Ticket booked successfully!\n");
}
void displayTickets(FILE *fp) {
    struct Ticket t;
    rewind(fp);
    printf("\nID\tPassenger\t\tEvent/Movie\t\tSeat\tPrice\n");
    while (fread(&t, sizeof(struct Ticket), 1, fp)) {
        printf("%d\t%s\t\t%s\t\t%d\t%.2f\n", t.ticket_id, t.passenger_name, t.movie_title, t.seat_number, t.price);
    }
}
void cancelTicket(FILE *fp) {
    int id, found = 0;
    struct Ticket t;
    FILE *tempfp = fopen("temp.dat", "wb");
    if (tempfp == NULL) {
        printf("Error processing cancellation.\n");
        return;
    }
    printf("Enter Ticket ID to cancel: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&t, sizeof(struct Ticket), 1, fp)) {
        if (t.ticket_id == id) {
            found = 1;
        } else {
            fwrite(&t, sizeof(struct Ticket), 1, tempfp);
        }
    }
    fclose(fp);
    fclose(tempfp);
    remove("tickets.dat");
    rename("temp.dat", "tickets.dat");
    fp = fopen("tickets.dat", "rb+");
    if (found) {
        printf("Ticket cancelled successfully!\n");
    } else {
        printf("Ticket ID not found.\n");
    }
}
int main() {
    FILE *fp = fopen("tickets.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("tickets.dat", "wb+");
        if (fp == NULL) {
            printf("Error creating database file.\n");
            return 1;
        }
    }
    int choice;
    while (1) {
        printf("\n=== Ticket Booking System ===\n");
        printf("1. Book Ticket\n2. View Booked Tickets\n3. Cancel Ticket\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) bookTicket(fp);
        else if (choice == 2) displayTickets(fp);
        else if (choice == 3) {
            cancelTicket(fp);
            fp = fopen("tickets.dat", "rb+");
        }
        else if (choice ==