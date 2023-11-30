#include <stdio.h>
#include <string.h>

// Define a structure to hold account information
typedef struct {
    char Fname[100];
    char email[100];
    char phone[20];
    char Lname[100];
    char paymentMethod[50];
} Account;

// Function to get account information from the user
void getAccountInfo(Account *account) {
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

    printf("Enter your preferred payment method (Visa, Mastercard, ect...): ");
    fgets(account->paymentMethod, 50, stdin);
    account->paymentMethod[strcspn(account->paymentMethod, "\n")] = 0;
}

// Function to display account information (for confirmation)
void displayAccountInfo(Account account) {
    printf("\nAccount Information:\n");
    printf("First Name: %s\nLast Name: %s\n", account.Fname, account.Lname);
    printf("Last Name: %s\n", account.Lname);
    printf("Email: %s\n", account.email);
    printf("Phone: %s\n", account.phone);
    printf("Payment Method: %s\n", account.paymentMethod);
    printf("Registration Complete.\n");
}

int main() {
    Account userAccount;

    printf("Welcome to AutoRider! Please enter your account details to register.\n");
    getAccountInfo(&userAccount);
    displayAccountInfo(userAccount);

    return 0;
}
