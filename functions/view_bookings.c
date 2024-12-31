#include "../header/travel.h"

void viewBookings(User loggedInUser) {
    FILE *bookingFile = fopen(BOOKING_FILE, "r");
    if (!bookingFile) {
        printf("No bookings found.\n");
        return;
    }

    char username[MAX_NAME_LENGTH], name[MAX_NAME_LENGTH], phone[MAX_NAME_LENGTH], email[MAX_NAME_LENGTH];
    char transportName[MAX_NAME_LENGTH], city[MAX_NAME_LENGTH];
    float price;
    int found = 0;

    printf("\nYour Bookings:\n");
    while (fscanf(bookingFile, "%s %s %s %s %s %s %f", 
                  username, name, phone, email, 
                  transportName, city, &price) != EOF) {
        if (strcmp(username, loggedInUser.username) == 0) {
            printf("Transport: %s\n", transportName);
            printf("City: %s\n", city);
            printf("Price: %.2f\n\n", price);
            found = 1;
        }
    }

    fclose(bookingFile);

    if (!found) {
        printf("You have no bookings.\n");
    }
}
