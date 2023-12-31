/*
    contacts.c - Tiny contacts program!
    September 13, 2023
    Kyriakos, kyke@otenet.gr
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN            40
#define PHONENUMBER_LEN     20
#define CONTACTS_NUM        20


unsigned short counter = 0;

void add_contact(void);
void search_contact(void);
void list_contacts(void);

struct contact
{
    char name[NAME_LEN];
    char phonenumber[PHONENUMBER_LEN];
} contacts[CONTACTS_NUM];

int main(void)
{
    unsigned short option;

    printf("Welcome to Contacts program!\n\n");

    while(1) {
        printf("Please select an option:\n\n" \
            "\t1. Add contact\n" \
            "\t2. Search contact\n" \
            "\t3. List contacts\n" \
            "\t4. Exit\n\n");

        scanf("%hu", &option);

        switch(option) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                list_contacts();
                break;
            case 4:
                printf("Exit\n\n");
                exit(0);
                // break;
            default:
                printf("Invalid option. Please choose a valid option\n\n");
                break;
        }
    }
    return 0;
}

void add_contact(void)
{
    getchar();

    unsigned short null_ch;

    if(counter == CONTACTS_NUM) {
        printf("Phone number list is full. Exiting.");
        exit(1);
    }

    printf("Enter name:\n");

    if(fgets(contacts[counter].name, NAME_LEN - 1, stdin) != NULL) {
        null_ch = strlen(contacts[counter].name);
        contacts[counter].name[null_ch - 1] = '\0';
        printf("Name added!\n\n");
    }

    printf("Enter phone number:\n");

    if(fgets(contacts[counter].phonenumber, PHONENUMBER_LEN - 1, stdin) != NULL) {
        null_ch = strlen(contacts[counter].phonenumber);
        contacts[counter].phonenumber[null_ch - 1] = '\0';
        printf("Phone number added!\n\n");
    }
    counter++;
}

void search_contact(void)
{
    getchar();

    char name[NAME_LEN];
    unsigned short null_ch;
    unsigned short i;

    printf("Enter name to search:\n");

    if(fgets(name, NAME_LEN - 1, stdin) != NULL) {
        null_ch = strlen(name);
        name[null_ch - 1] = '\0';
        for(i = 0; i < counter; i++) {
            if(strstr(contacts[i].name, name)) {
                printf("%s: %s\n", contacts[i].name, contacts[i].phonenumber);
            }
        }
    }
}

void list_contacts(void)
{
    unsigned short i;

    printf("\n");
    for(i = 0; i < CONTACTS_NUM; i++) {
        if(strcmp(contacts[i].name, "") != 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phonenumber);
        }
    }
    printf("\n");
}
