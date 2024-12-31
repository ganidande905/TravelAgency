#include "../header/travel.h"

void saveTransportToFile(Transport newTransport) {
    FILE *transportFile = fopen(TRANSPORT_FILE, "a");
    if (!transportFile) {
        printf("Error opening transport file.\n");
        return;
    }

    fprintf(transportFile, "%s %s %s %s %s %.2f\n", newTransport.name, newTransport.city, newTransport.state,
            newTransport.time, newTransport.transportType, newTransport.price);
    fclose(transportFile);
}

void loadTransportsFromFile() {
    FILE *transportFile = fopen(TRANSPORT_FILE, "r");
    if (!transportFile) {
        return;
    }

    while (fscanf(transportFile, "%s %s %s %s %s %f", transports[transportCount].name, transports[transportCount].city,
                  transports[transportCount].state, transports[transportCount].time,
                  transports[transportCount].transportType, &transports[transportCount].price) != EOF) {
        transportCount++;
    }

    fclose(transportFile);
}
