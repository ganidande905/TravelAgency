#include "../header/travel.h"

void searchTransportByDestination() {
    char destination[MAX_NAME_LENGTH];
    printf("\nEnter destination to search for transport: ");
    getchar();
    fgets(destination, MAX_NAME_LENGTH, stdin);
    destination[strcspn(destination, "\n")] = '\0';

    printf("\nSearch results for transports going to %s:\n", destination);
    for (int i = 0; i < transportCount; i++) {
        if (strstr(transports[i].city, destination) || strstr(transports[i].state, destination)) {
            printf("%d. %s\n", i + 1, transports[i].name);
        }
    }
}
