#include "../header/travel.h"

void removeTransport() {
    char transportName[MAX_NAME_LENGTH];
    int found = 0;

    printf("\nEnter transport name to remove: ");
    getchar();
    fgets(transportName, MAX_NAME_LENGTH, stdin);
    transportName[strcspn(transportName, "\n")] = '\0';

    for (int i = 0; i < transportCount; i++) {
        if (strcmp(transports[i].name, transportName) == 0) {
            found = 1;
            for (int j = i; j < transportCount - 1; j++) {
                transports[j] = transports[j + 1];
            }
            transportCount--;

            FILE *transportFile = fopen(TRANSPORT_FILE, "w");
            for (int j = 0; j < transportCount; j++) {
                fprintf(transportFile, "%s %s %s %s %s %.2f\n", transports[j].name, transports[j].city,
                        transports[j].state, transports[j].time, transports[j].transportType, transports[j].price);
            }
            fclose(transportFile);

            printf("Transport removed successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("Transport not found.\n");
    }
}
