#include "../header/travel.h"

void modifyTransportCost() {
    char transportName[MAX_NAME_LENGTH];
    int found = 0;

    printf("\nEnter transport name to modify cost: ");
    getchar();
    fgets(transportName, MAX_NAME_LENGTH, stdin);
    transportName[strcspn(transportName, "\n")] = '\0';

    for (int i = 0; i < transportCount; i++) {
        if (strcmp(transports[i].name, transportName) == 0) {
            found = 1;

            printf("Current price: %.2f\n", transports[i].price);
            printf("Enter new price: ");
            scanf("%f", &transports[i].price);

            FILE *transportFile = fopen(TRANSPORT_FILE, "w");
            for (int j = 0; j < transportCount; j++) {
                fprintf(transportFile, "%s %s %s %s %s %.2f\n", transports[j].name, transports[j].city,
                        transports[j].state, transports[j].time, transports[j].transportType, transports[j].price);
            }
            fclose(transportFile);

            printf("Transport cost modified successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("Transport not found.\n");
    }
}
