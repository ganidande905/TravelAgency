#include "../header/travel.h"

int userLogin(User *loggedInUser) {
    FILE *userFile = fopen(USER_FILE, "r");
    char line[256]; // Buffer to hold each line
    char fileUsername[MAX_NAME_LENGTH], filePassword[MAX_NAME_LENGTH];
    char fileName[MAX_NAME_LENGTH], filePhone[MAX_NAME_LENGTH], fileEmail[MAX_NAME_LENGTH];

    if (!userFile) {
        printf("No user file found. Please register.\n");
        return 0;
    }

    printf("\nEnter username: ");
    getchar();
    fgets(loggedInUser->username, MAX_NAME_LENGTH, stdin);
    loggedInUser->username[strcspn(loggedInUser->username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(loggedInUser->password, MAX_NAME_LENGTH, stdin);
    loggedInUser->password[strcspn(loggedInUser->password, "\n")] = '\0';

    while (fgets(line, sizeof(line), userFile)) {
        // Parse each line into the respective fields
        if (sscanf(line, "%s %s %s %s %s", fileUsername, filePassword, fileName, filePhone, fileEmail) == 5) {
            if (strcmp(fileUsername, loggedInUser->username) == 0 &&
                strcmp(filePassword, loggedInUser->password) == 0) {
                // If match is found, populate the loggedInUser struct
                strcpy(loggedInUser->name, fileName);
                strcpy(loggedInUser->phone, filePhone);
                strcpy(loggedInUser->email, fileEmail);
                fclose(userFile);
                printf("Login successful! Welcome, %s.\n", loggedInUser->name);
                return 1; // Login successful
            }
        }
    }

    fclose(userFile);
    printf("Invalid username or password!\n");
    return 0;
}

int adminLogin(User *loggedInUser) {
    printf("\nEnter admin username: ");
    getchar();
    fgets(loggedInUser->username, MAX_NAME_LENGTH, stdin);
    loggedInUser->username[strcspn(loggedInUser->username, "\n")] = '\0';

    printf("Enter admin password: ");
    fgets(loggedInUser->password, MAX_NAME_LENGTH, stdin);
    loggedInUser->password[strcspn(loggedInUser->password, "\n")] = '\0';

    return strcmp(loggedInUser->username, "admin") == 0 && strcmp(loggedInUser->password, "admin123") == 0;
}

int isAdmin(User user) {
    return strcmp(user.username, "admin") == 0 && strcmp(user.password, "admin123") == 0;
}
