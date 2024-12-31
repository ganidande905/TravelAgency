#include "../header/travel.h"

void saveTransportToFile(Transport newTransport) {
    FILE *transportFile = fopen(TRANSPORT_FILE, "a");
    if (!transportFile) {
        printf("Error opening transport file.\n");
        return;
    }

    fprintf(transportFile, "%s %s %s %s %s %.2f\n", 
            newTransport.name, 
            newTransport.starting_point, 
            newTransport.city, 
            newTransport.time, 
            newTransport.transportType, 
            newTransport.price);

    fclose(transportFile);
}

void loadTransportsFromFile() {
    FILE *transportFile = fopen(TRANSPORT_FILE, "r");
    if (!transportFile) {
        printf("No transport data found.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), transportFile)) {

        if (sscanf(line, "%s %s %s %s %s %f", 
                   transports[transportCount].name, 
                   transports[transportCount].starting_point, 
                   transports[transportCount].city, 
                   transports[transportCount].time, 
                   transports[transportCount].transportType, 
                   &transports[transportCount].price) == 6) {
            transportCount++;
        } else {
            printf("DEBUG: Failed to parse line: %s\n", line);
        }
    }

    fclose(transportFile);
}
