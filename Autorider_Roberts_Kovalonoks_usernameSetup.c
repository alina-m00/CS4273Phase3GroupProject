/*
============================================================================
Name        : Autorider_Roberts_Kovalonoks_usernameSetup.c
Author      : Roberts Kovalonoks
Version     : 1.0
Copyright   : Your copyright notice
Description : Hello World in C, Ansi-style
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user information
struct User {
   char firstName[50];
   char lastName[50];
   char username[50];
};

// Function to set up the username
void setupUsername(struct User *user) {
   
   // Combine the first name and last name to form the username
   snprintf(user->username, sizeof(user->username), "%s%s", user->firstName, user->lastName);
   
   // Convert the username to lowercase (optional, for consistency)
   for (int i = 0; user->username[i]; i++) {
       user->username[i] = tolower(user->username[i]);
   }
   // Print the generated username
   printf("Username set up successfully: %s\n", user->username);
}

int main() {
   // new user Struct
   struct User newUser;
   
   // Input user details
   printf("Enter first name: ");
   fflush(stdout);
   scanf("%s", newUser.firstName);
   printf("Enter last name: ");
   fflush(stdout);
   scanf("%s", newUser.lastName);
   
   // Call the function to set up the username
   setupUsername(&newUser);
   return 0;
}
