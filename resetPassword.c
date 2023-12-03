// the ResetPasswordFunction takes input from the user for their username and email
// so that the user can reset their password. The new password should be 8 characters
// in length, with an upper case, lower case along with a number and special character


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if the input email is valid
int emailValidityFunction(const char *email) {
    const char *domains[] = {".com", ".edu", ".net"};
    int domainFlag = 0;

    // checking if the email ends with a valid set of domains
    for (int i = 0; i < sizeof(domains) / sizeof(domains[0]); ++i) {
        size_t lenDomain = strlen(domains[i]);
        if (strlen(email) >= lenDomain && strcmp(email + strlen(email) - lenDomain, domains[i]) == 0) {
            domainFlag = 1;
            break;
        }
    }

    return domainFlag;
}

// function to check if the input password meets the specified requirements
int isPasswordValid(const char *password) {
    int hasUpperCase = 0, hasLowerCase = 0, hasDigit = 0, hasSpecialCharacter = 0;

    for (int i = 0; password[i] != '\0'; ++i) {
        if (isupper(password[i])) {
            hasUpperCase = 1;
        } else if (islower(password[i])) {
            hasLowerCase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecialCharacter = 1;
        }
    }

    return hasUpperCase && hasLowerCase && hasDigit && hasSpecialCharacter && (strlen(password) >= 8);
}

int main() {
    char ipnutUsername[100];
    char inputEmail[100];
    char inputPassword[100];

    printf("Enter your username: ");
    scanf("%s", ipnutUsername);

    // loop to ensure that user inputs a valid email
    do {
        printf("Enter your email: ");
        scanf("%s", inputEmail);

        if (!emailValidityFunction(inputEmail)) {
            printf("\nInvalid email! Please enter an email ending with .com, .edu, or .net\n");
        }

    } while (!emailValidityFunction(inputEmail));

    // loop to ensure that the user inputs a valid password
    do {
        printf("Enter a new password: ");
        scanf("%s", inputPassword);

        if (!isPasswordValid(inputPassword)) {
            printf("\nInvalid password! Please try again.\n");
            printf("Password should be minimum 8 characters, with upper and lower case, number, and special character\n");
        }

    } while (!isPasswordValid(inputPassword));

    printf("\nPassword reset successful!\n");


    return 0;
}
