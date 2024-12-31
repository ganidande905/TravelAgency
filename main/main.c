#include "../header/travel.h"

// Global Variables
Transport transports[MAX_TRANSPORTS];
Booking bookings[MAX_BOOKINGS];
int transportCount = 0;
int bookingCount = 0;

int main() {
    int userChoice;
    User loggedInUser;
    int choice;

    // Load transports from file
    loadTransportsFromFile();

    while (1) {
        printf("\nWelcome to the Travel Agency System!\n");
        printf("1. Login as Admin\n");
        printf("2. Login as User\n");
        printf("3. Register as User\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 1) {
            if (adminLogin(&loggedInUser)) break;
            else printf("Admin login failed! Try again.\n");
        } else if (choice == 2) {
            if (userLogin(&loggedInUser)) break;
            else printf("User login failed! Try again.\n");
        } else if (choice == 3) {
            userRegistration();
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    while (1) {
        showMenu(loggedInUser);
        printf("Enter your choice: ");
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (isAdmin(loggedInUser)) {
            switch (userChoice) {
                case 1: viewPackages(); break;
                case 6: addTransport(); break;
                case 7: removeTransport(); break;
                case 8: modifyTransportCost(); break;
                case 9: return 0;
                default: printf("Invalid choice.\n");
            }
        } else {
            switch (userChoice) {
                case 1: viewPackages(); break;
                case 2: bookTransport(loggedInUser); break;
                case 3: break; // View Bookings (Not implemented)
                case 4: cancelBooking(loggedInUser); break;
                case 5: searchTransportByDestination(); break;
                case 6: return 0;
                default: printf("Invalid choice.\n");
            }
        }
    }
}
