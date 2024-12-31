#include "../header/travel.h"

void addTransport() {
    if (transportCount >= MAX_TRANSPORTS) {
        printf("Transport list is full.\n");
        return;
    }

    Transport newTransport;
    printf("\nEnter transport name: ");
    getchar();
    fgets(newTransport.name, MAX_NAME_LENGTH, stdin);
    newTransport.name[strcspn(newTransport.name, "\n")] = '\0';

    printf("Enter city: ");
    fgets(newTransport.city, MAX_NAME_LENGTH, stdin);
    newTransport.city[strcspn(newTransport.city, "\n")] = '\0';

    printf("Enter state: ");
    fgets(newTransport.state, MAX_NAME_LENGTH, stdin);
    newTransport.state[strcspn(newTransport.state, "\n")] = '\0';

    printf("Enter transport time: ");
    fgets(newTransport.time, TIME_LENGTH, stdin);
    newTransport.time[strcspn(newTransport.time, "\n")] = '\0';

    printf("Enter transport type: ");
    fgets(newTransport.transportType, MAX_NAME_LENGTH, stdin);
    newTransport.transportType[strcspn(newTransport.transportType, "\n")] = '\0';

    printf("Enter price: ");
    scanf("%f", &newTransport.price);

    transports[transportCount++] = newTransport;
    saveTransportToFile(newTransport);
    printf("Transport added successfully!\n");
}
