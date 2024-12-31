#include "../header/travel.h"

void viewPackages() {
    if (transportCount == 0) {
        printf("No transport packages available at the moment.\n");
        return;
    }

    printf("\nAvailable Transport Packages:\n");
    for (int i = 0; i < transportCount; i++) {
        printf("%d. %s\n", i + 1, transports[i].name);
        printf("   Destination: %s, %s\n", transports[i].city, transports[i].state);
        printf("   Time: %s\n", transports[i].time);
        printf("   Type: %s\n", transports[i].transportType);
        printf("   Price: %.2f\n\n", transports[i].price);
    }
}
