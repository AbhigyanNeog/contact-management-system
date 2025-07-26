#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100      // Maximum number of contacts allowed
#define NAME_LENGTH 50        // Maximum length for contact names
#define PHONE_LENGTH 15       // Maximum length for phone numbers

// Structure to represent a contact
typedef struct {
    char name[NAME_LENGTH];  // Name of the contact
    char phone[PHONE_LENGTH]; // Phone number of the contact
} Contact;

// Array to hold contacts and a counter for the number of contacts
Contact contacts[MAX_CONTACTS];
int contact_count = 0; // Current number of contacts

// Function to add a new contact
void add_contact() {
    // Check if the contact list is full
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    // Input contact name and phone number
    printf("Enter name: ");
    scanf("%s", contacts[contact_count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[contact_count].phone);
    
    contact_count++; // Increment the contact count
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void view_contacts() {
    // Check if there are no contacts to display
    if (contact_count == 0) {
        printf("No contacts available.\n");
        return;
    }

    // Display all contacts
    printf("\nContacts:\n");
    int i;
    for ( i = 0; i < contact_count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to delete a contact by its index
void delete_contact() {
    int index;
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);

    // Check if the provided index is valid
    if (index < 1 || index > contact_count) {
        printf("Invalid contact number!\n");
        return;
    }

    // Shift contacts to remove the specified contact
    int i;
	for (i = index - 1; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contact_count--; // Decrement the contact count
    printf("Contact deleted successfully!\n");
}

// Main function to run the contact management system
int main() {
    int choice; // Variable to store user choice

    // Infinite loop to display menu until the user exits
    while (1) {
        // Display menu options
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice); // Get user choice

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_contact(); // Add a new contact
                break;
            case 2:
                view_contacts(); // View all contacts
                break;
            case 3:
                delete_contact(); // Delete a contact
                break;
            case 4:
                printf("Exiting...\n"); // Exit the program
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n"); // Handle invalid choice
        }
    }

    return 0; // Return success status
}

