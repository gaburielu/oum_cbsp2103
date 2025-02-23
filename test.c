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

void readEventsSummary(struct Event events[], int totalEvent)
{

    for (int i = 0; i < totalEvent; i++)
    {
        printf("ID: %d | Name: %s | Available: %d/%d | Price: RM%.2f | Sales(Before Discounts): RM %.2f\n",
               events[i].eventID, events[i].eventName, events[i].availableSeats, events[i].totalSeats, events[i].price, events[i].totalRevenue);
    }
}

void displayConfirmation(struct Event events[], int totalEvent, char name[], char id[])
{
}

void displayTotalRevenue(struct Event events[], int totalEvent)
{
    float total = 0;
    for (int i = 0; i < totalEvent; i++)
    {
        total += events[i].totalRevenue;
    }
    printf("\nCurrent total sales(before discounts) for all events: RM%.2f\n", total);
}

void bookEvent(struct Event events[], int totalEvent)
{
    // Need to add data validation for this part
    char name[50];
    int id;
    printf("Enter the member name: ");
    scanf("%s", name);
    printf("Enter the member ID number (numbers only, 0 for no member ID): ");
    scanf("%d", &id);
    if (id == 0)
    {
        printf("No member ID");
    }
    //
    printf("Name: %s, ID: %d\n", name, id);

    readEventsSummary(events, totalEvent);

    int eventIndex;
    int attendees;
    int index;
    bool validId = false;
    printf("\nEnter an Event ID: ");
    scanf("%d", &eventIndex);

    while (!validId)
    {
        for (int i = 0; i < totalEvent; i++)
        {
            if (eventIndex == events[i].eventID)
            {
                validId = true;
                index = i;
            }
        }
        if (!validId)
        {
            printf("Enter a valid event ID: ");
            scanf("%d", &eventIndex);
        }
    }

    printf("Enter number of attendees: ");
    scanf("%d", &attendees);

    while (attendees > events[index].availableSeats)
    {
        printf("Not enough seats available!\n");
        printf("Enter number of attendees or -1 to cancel booking: ");
        scanf("%d", &attendees);
        if (attendees == -1)
        {
            return;
        }
    }
    events[index].availableSeats -= attendees;

    readEventsSummary(events, totalEvent);
}

int main()
{
    int totalEvent = 3;
    struct Event events[totalEvent];
    createEvents(events);

    bool app = true;
    int choice;

    while (app)
    {
        printf("\nChoose an option: \n0. Exit The Program\n1. Make A Booking");
        printf("\n2. Show Event Information\n3. Show Total Sales\n-> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting program");
            app = false;
            break;
        case 1:
            printf("You selected Option 1. make a booking\n");
            break;
        case 2:
            printf("\nEvent Information:\n");
            break;
        case 3:
            break;

        default:
            printf("Invalid selection. Please choose a number between 1 and 3.\n");
            break;
        }
    }
    return 0;
}