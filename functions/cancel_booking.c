#include "../header/travel.h"

void cancelBooking(User loggedInUser) {
    FILE *bookingFile = fopen(BOOKING_FILE, "r");
    if (!bookingFile) {
        printf("No bookings found.\n");
        return;
    }

    FILE *tempFile = fopen("temp_booking.txt", "w");
    if (!tempFile) {
        fclose(bookingFile);
        printf("Error: Could not open temporary file for updating.\n");
        return;
    }

    char username[MAX_NAME_LENGTH], transportName[MAX_NAME_LENGTH], startingPoint[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH], time[MAX_NAME_LENGTH], transportType[MAX_NAME_LENGTH];
    float price;
    int userBookings = 0, bookingToCancel;

    // Display user bookings directly from the file
    printf("\nYour current bookings:\n");
    while (fscanf(bookingFile, "%s %s %s %s %s %s %f",
                  username, transportName, startingPoint, destination, time, transportType, &price) == 7) {
        if (strcmp(username, loggedInUser.username) == 0) {
            userBookings++;
            printf("%d. %s - %s to %s at %s (Type: %s, Price: %.2f)\n",
                   userBookings, transportName, startingPoint, destination, time, transportType, price);
        }
    }

    if (userBookings == 0) {
        printf("No bookings found for your account.\n");
        fclose(bookingFile);
        fclose(tempFile);
        remove("temp_booking.txt");
        return;
    }

    // Ask user which booking to cancel
    printf("\nEnter the number of the booking you want to cancel: ");
    scanf("%d", &bookingToCancel);

    if (bookingToCancel < 1 || bookingToCancel > userBookings) {
        printf("Invalid choice.\n");
        fclose(bookingFile);
        fclose(tempFile);
        remove("temp_booking.txt");
        return;
    }

    rewind(bookingFile); // Reset file pointer to the beginning

    userBookings = 0; // Reset counter to track user bookings during the second pass
    while (fscanf(bookingFile, "%s %s %s %s %s %s %f",
                  username, transportName, startingPoint, destination, time, transportType, &price) == 7) {
        if (strcmp(username, loggedInUser.username) == 0) {
            userBookings++;
            if (userBookings == bookingToCancel) {
                // Skip this booking (do not write it to the temp file)
                continue;
            }
        }

        // Write all other bookings to the temp file
        fprintf(tempFile, "%s %s %s %s %s %s %.2f\n",
                username, transportName, startingPoint, destination, time, transportType, price);
    }

    fclose(bookingFile);
    fclose(tempFile);

    // Replace the original file with the updated file
    remove(BOOKING_FILE);
    rename("temp_booking.txt", BOOKING_FILE);

    printf("Booking cancelled successfully.\n");
}
