#include "../header/travel.h"

void userRegistration() {
    User newUser;
    FILE *userFile = fopen(USER_FILE, "a");

    if (!userFile) {
        printf("Error opening user file.\n");
        return;
    }

    printf("\nEnter username: ");
    getchar();
    fgets(newUser.username, MAX_NAME_LENGTH, stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(newUser.password, MAX_NAME_LENGTH, stdin);
    newUser.password[strcspn(newUser.password, "\n")] = '\0';

    printf("Enter your name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';

    printf("Enter your phone number: ");
    fgets(newUser.phone, MAX_NAME_LENGTH, stdin);
    newUser.phone[strcspn(newUser.phone, "\n")] = '\0';

    printf("Enter your email: ");
    fgets(newUser.email, MAX_NAME_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0';

    fprintf(userFile, "%s %s %s %s %s\n", newUser.username, newUser.password, newUser.name, newUser.phone, newUser.email);
    fclose(userFile);
    printf("Registration successful!\n");
}
