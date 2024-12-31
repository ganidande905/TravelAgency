#ifndef TRAVEL_H
#define TRAVEL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_TRANSPORTS 500
#define MAX_BOOKINGS 200
#define TIME_LENGTH 6
#define USER_FILE "data/user1.txt"
#define ADMIN_FILE "data/admin.txt"
#define TRANSPORT_FILE "data/transports.txt"
#define BOOKING_FILE "data/booking.txt"

// Structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    char city[MAX_NAME_LENGTH];
    char state[MAX_NAME_LENGTH];
    char time[TIME_LENGTH];
    char transportType[MAX_NAME_LENGTH];
    float price;
} Transport;

typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} User;

typedef struct {
    Transport transport;
    User user;
} Booking;

// Global Variables
extern Transport transports[MAX_TRANSPORTS];
extern Booking bookings[MAX_BOOKINGS];
extern int transportCount;
extern int bookingCount;

// Function Declarations
void addTransport();
void removeTransport();
void modifyTransportCost();
void viewPackages();
void bookTransport(User loggedInUser);
void cancelBooking(User loggedInUser);
void searchTransportByDestination();
void saveTransportToFile(Transport newTransport);
void loadTransportsFromFile();
void showMenu(User loggedInUser);
int userLogin(User *loggedInUser);
int adminLogin(User *loggedInUser);
int isAdmin(User user);
void userRegistration();

#endif
