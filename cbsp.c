#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char events[3][50] = {"Romeo and Juliet", "Istana Menanti", "Shrek the Musical"};
int seats[3] = {500, 500, 400};
float ticketPrice[3] = {50.80, 40.50, 60.00};
float totalRevenue = 0;

float bookTickets()
{
}

float calculateDiscounts()
{
}

float displayRevenue()
{
}

void displayEvents()
{
    for (int i = 0; i < 3; i++)
    {
        printf("ID: %d | Available: %d | Price: RM%.2f | Event Name: %s  \n",
               i, seats[i], ticketPrice[i], events[i]);
    }
}

void generateSummary()
{
}

int main()
{

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

            char name[50];
            int id;
            printf("\nEnter the member name (No whitespace): ");
            scanf("%s", name);
            printf("Enter the member ID number (numbers only, 0 if no member ID): ");
            scanf("%d", &id);
            if (id == 0)
            {
                printf("No member ID");
            }
            printf("Name: %s, ID: %d\n\n", name, id);

            int eventIndex = -1;
            int attendees;
            bool validEventID = false;
            displayEvents();
            printf("Enter an Event ID from the list: ");
            scanf("%d", &eventIndex);

            while (!validEventID)
            {
                if (eventIndex >= 0 && eventIndex <= 2)
                {
                    validEventID = true;
                }
                else
                {
                    printf("Enter a valid event ID: ");
                    scanf("%d", &eventIndex);
                }
            }

            break;
        case 2:
            printf("\nEvent Information:\n");
            displayEvents();
            break;
        case 3:
            break;

        default:
            printf("Invalid selection. Please choose a option between 0 to 3.\n");
            break;
        }
    }
    return 0;
}