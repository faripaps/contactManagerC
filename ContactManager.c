/*
    Contact Manager
    Programmer: George Papaya
    Date: 31 July 2023
    Level: Beginner Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold contact details
struct Contact {
    char name[50];
    char surname[50];
    char phoneNumber[15];
};

// Function to create a new contact
struct Contact createContact() {
    struct Contact c;
    printf("Enter name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove trailing newline
    
    printf("Enter surname: ");
    fgets(c.surname, sizeof(c.surname), stdin);
    c.surname[strcspn(c.surname, "\n")] = '\0'; // Remove trailing newline
    
    printf("Enter phone number: ");
    fgets(c.phoneNumber, sizeof(c.phoneNumber), stdin);
    c.phoneNumber[strcspn(c.phoneNumber, "\n")] = '\0'; // Remove trailing newline
    
    return c;
}

// Function to save a contact to a file
void saveContact(struct Contact c) {
    FILE *file = fopen("contacts.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s,%s,%s\n", c.name, c.surname, c.phoneNumber);
    fclose(file);
    printf("Contact saved successfully!\n");
}

// Function to edit a specific contact
void editContact() {
    char searchName[50];
    printf("Enter the name of the contact you want to edit: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline
    
    struct Contact c;
    FILE *file = fopen("contacts.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    int found = 0;
    
    while (fscanf(file, "%[^,],%[^,],%s\n", c.name, c.surname, c.phoneNumber) != EOF) {
        if (strcmp(c.name, searchName) == 0) {
            found = 1;
            printf("Enter new details for the contact:\n");
            c = createContact();
        }
        fprintf(tempFile, "%s,%s,%s\n", c.name, c.surname, c.phoneNumber);
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    
    if (found) {
        printf("Contact edited successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

// Function to search for a contact based on name
void searchContact() {
    char searchName[50];
    printf("Enter the name of the contact you want to search for: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline
    
    struct Contact c;
    FILE *file = fopen("contacts.txt", "r");
    int found = 0;
    
    while (fscanf(file, "%[^,],%[^,],%s\n", c.name, c.surname, c.phoneNumber) != EOF) {
        if (strcmp(c.name, searchName) == 0) {
            found = 1;
            printf("Contact details:\n");
            printf("Name: %s %s\n", c.name, c.surname);
            printf("Phone Number: %s\n", c.phoneNumber);
            break;
        }
    }
    
    fclose(file);
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

int main() {
    int choice;
    
    // Menu loop
    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Create a contact\n");
        printf("2. Edit a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Capture newline character
        
        switch (choice) {
            case 1:
                printf("\n--- Create a New Contact ---\n");
                struct Contact newContact = createContact();
                saveContact(newContact);
                break;
            case 2:
                printf("\n--- Edit a Contact ---\n");
                editContact();
                break;
            case 3:
                printf("\n--- Search for a Contact ---\n");
                searchContact();
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-4).\n");
        }
    } while (choice != 4);
    
    return 0;
}
