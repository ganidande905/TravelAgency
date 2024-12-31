#include "../header/travel.h"

void bookTransport(User loggedInUser) {
    int transportChoice;

    printf("\nAvailable transports to book:\n");
    for (int i = 0; i < transportCount; i++) {
        printf("%d. %s\n", i + 1, transports[i].name);
    }

    printf("\nEnter the number of the transport you want to book: ");
    scanf("%d", &transportChoice);

    if (transportChoice < 1 || transportChoice > transportCount) {
        printf("Invalid choice.\n");
        return;
    }

    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking limit reached. Cannot make more bookings.\n");
        return;
    }

    bookings[bookingCount].transport = transports[transportChoice - 1];
    bookings[bookingCount].user = loggedInUser;
    bookingCount++;

    printf("Booking successful! Enjoy your trip.\n");
}
