#include "../header/travel.h"


void loadBookingsFromFIle(){
    FILE *bookingFile = fopen(BOOKING_FILE,"r");
    if(!bookingFile){
        printf("No bookings found.\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), bookingFile)){
        if (sscanf(line, "%s %s %s %s %s %f",
                bookings[bookingCount].name,
                bookings[bookingCount].starting_point,
                bookings[bookingCount].city,
                bookings[bookingCount].time,
                bookings[bookingCount].transportType,
                &bookings[bookingCount].price) == 6){
            bookingCount++;
        } else{
            printf("DEBUG: Failed to parse line: %s\n", line);
        }
    }
}
void viewBookings(User loggedInUser) {
     if (bookingCount == 0) {
        printf("No Bookings available.\n");
        return;
    }

    printf("\nYour booking(s):\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("%d. %s\n", i + 1, bookings[i].name);
        printf("   Destination: %s\n", bookings[i].city);
        printf("   Starting Point: %s\n", bookings[i].starting_point);
        printf("   Time: %s\n", bookings[i].time);
        printf("   Type: %s\n", bookings[i].transportType);
        printf("   Price: %.2f\n\n", bookings[i].price);
    }
}
