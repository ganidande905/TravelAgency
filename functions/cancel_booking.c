#include "../header/travel.h"

void cancelBooking(User loggedInUser) {
    int bookingChoice;
    int found = 0;

    printf("\nYour current bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].user.username, loggedInUser.username) == 0) {
            printf("%d. %s\n", i + 1, bookings[i].transport.name);
            found = 1;
        }
    }

    if (!found) {
        printf("No bookings found for your account.\n");
        return;
    }

    printf("\nEnter the number of the booking you want to cancel: ");
    scanf("%d", &bookingChoice);

    if (bookingChoice < 1 || bookingChoice > bookingCount) {
        printf("Invalid choice.\n");
        return;
    }

    for (int i = bookingChoice - 1; i < bookingCount - 1; i++) {
        bookings[i] = bookings[i + 1];
    }

    bookingCount--;
    printf("Booking cancelled successfully.\n");
}
