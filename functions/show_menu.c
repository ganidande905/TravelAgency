#include "../header/travel.h"

void showMenu(User loggedInUser) {
    printf("\n==== Travel Agency Menu ====\n");
    if (isAdmin(loggedInUser)) {
        printf("1. View Transports (Admin)\n");
        printf("6. Add Transport (Admin)\n");
        printf("7. Remove Transport (Admin)\n");
        printf("8. Modify Transport Cost (Admin)\n");
        printf("9. Exit\n");
    } else {
        printf("1. View Travel Packages\n");
        printf("2. Book a Transport\n");
        printf("3. View Your Bookings\n");
        printf("4. Cancel Your Booking\n");
        printf("5. Search Transport by Destination\n");
        printf("6. Exit\n");
    }
}
