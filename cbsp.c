#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Event
{
    char eventName[50];
    int eventID;
    int totalSeats;
    int availableSeats;
    float price;
    float totalRevenue;
};

void createEvents(struct Event events[])
{
    strcpy(events[0].eventName, "Romeo and Juliet");
    events[0].eventID = 101;
    events[0].totalSeats = 500;
    events[0].availableSeats = 100;
    events[0].price = 60.0;
    events[0].totalRevenue = (events[0].totalSeats - events[0].availableSeats) * events[0].price;

    strcpy(events[1].eventName, "Istana Menanti");
    events[1].eventID = 102;
    events[1].totalSeats = 500;
    events[1].availableSeats = 185;
    events[1].price = 40.50;
    events[1].totalRevenue = (events[1].totalSeats - events[1].availableSeats) * events[1].price;

    strcpy(events[2].eventName, "Pride and Prejudice");
    events[2].eventID = 103;
    events[2].totalSeats = 500;
    events[2].availableSeats = 452;
    events[2].price = 50.80;
    events[2].totalRevenue = (events[2].totalSeats - events[2].availableSeats) * events[2].price;
}

void readEvents(struct Event events[], int size)
{
    {
        printf("\nEvent Information:\n");
        for (int i = 0; i < size; i++)
        {
            printf("ID: %d | Name: %s | Available: %d/%d | Price: RM%.2f | Sales: RM%.2f\n",
                   events[i].eventID, events[i].eventName, events[i].availableSeats, events[i].totalSeats, events[i].price, events[i].totalRevenue);
        }
    }
}

int main()
{

    struct Event events[3];
    createEvents(events);

    bool app = true;
    int choice;

    char name[50];
    char id[10];

    printf("\nEnter your name: ");
    scanf(" %s", name);
    printf("Enter your ID: ");
    scanf("%s", id);

    while (app)
    {
        printf("\nChoose an option: \n0. Exit The Program\n1. Make a booking\n2. Change member\n3. Show Event information\n-> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting program");
            app = false;
            break;
        case 1:
            printf("You selected Option 1.\n");
            break;
        case 2:
            printf("You selected Option 2.\n");
            break;
        case 3:
            readEvents(events, 3);
            break;

        default:
            printf("Invalid selection. Please choose a number between 1 and 3.\n");
            break;
        }
    }
    return 0;
}