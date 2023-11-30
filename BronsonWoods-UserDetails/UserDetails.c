#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define a structure to hold account information
typedef struct 
{
    char username[50];
    char password[50];
    char Fname[100];
    char Lname[100];
    char email[100];
    char phone[20];
    char paymentMethod[50];
} Account;

// Function to get account information from the user
void getAccountInfo(Account *account) 
{

    // Letting User "Login"
    printf("Enter your Username: ");
    fgets(account->username, 50, stdin);
    account->username[strcspn(account->username, "\n")] = 0;

    printf("Enter your Password: ");
    fgets(account->password, 50, stdin);
    account->password[strcspn(account->password, "\n")] = 0;


    // Getting user to add details to their account 
    printf("Enter your First Name: ");
    fgets(account->Fname, 100, stdin);
    account->Fname[strcspn(account->Fname, "\n")] = 0;

    printf("Enter your Last Name: ");
    fgets(account->Lname, 100, stdin);
    account->Lname[strcspn(account->Lname, "\n")] = 0;

    printf("Enter your email: ");
    fgets(account->email, 100, stdin);
    account->email[strcspn(account->email, "\n")] = 0;

    printf("Enter your phone number: ");
    fgets(account->phone, 20, stdin);
    account->phone[strcspn(account->phone, "\n")] = 0;

    printf("Enter your preferred payment method (Visa, Mastercard, etc...): ");
    fgets(account->paymentMethod, 50, stdin);
    account->paymentMethod[strcspn(account->paymentMethod, "\n")] = 0;
}

// Function to display account information (for confirmation)
void displayAccountInfo(Account account) 
{
    printf("\nAccount Information:\n");

    printf("Username: %s\n", account.username);
    printf("Password: %s\n", account.password);

    printf("First Name: %s\n", account.Fname);
    printf("Last Name: %s\n", account.Lname);
    printf("Email: %s\n", account.email);
    printf("Phone: %s\n", account.phone);
    printf("Payment Method: %s\n", account.paymentMethod);
    printf("Details Added.\n");
}

int main() {
    Account userAccount;
    bool gettingDetails = true;

    // Adding buffer
    char exitOption[10];

    while(gettingDetails) 
    {
        printf("Welcome to AutoRider! Please Login to add details to your account.\n");
        getAccountInfo(&userAccount);
        displayAccountInfo(userAccount);

        printf("\nPress 'e' and Enter to exit, or any other key and Enter to continue: \n");
        fgets(exitOption, 10, stdin);

        if(exitOption[0] == 'e') 
        {
            gettingDetails = false;
        }
    }

    return 0;
}