#include <stdio.h>
#include <string.h>
#include <stdbool.h>

float bookTickets(int eventIndex, int numTickets, int seats[], float ticketPrice[])
{
    seats[eventIndex] -= numTickets;
    float totalCost = (float)numTickets * ticketPrice[eventIndex];
    return totalCost;
}

float calculateDiscounts(float totalCost, int NumTickets, int ID)
{
    float costAfterDiscount = totalCost;
    if (NumTickets > 5)
    {
        costAfterDiscount = totalCost * 0.9;
    }
    if (ID != 0)
    {
        costAfterDiscount = costAfterDiscount * 0.95;
    }
    return costAfterDiscount;
}

void displayEvents(char events[][50], int seats[], float ticketPrice[], int numberOfEvent)
{
    for (int i = 0; i < numberOfEvent; i++)
    {
        printf("ID: %d | Available: %d | Price: RM%.2f | Event Name: %s  \n",
               i, seats[i], ticketPrice[i], events[i]);
    }
}

void generateSummary(char events[][50], int seats[], float sales[], float totalSales, int numberOfEvent)
{
    printf("\n");
    for (int i = 0; i < numberOfEvent; i++)
    {
        printf("ID: %d | Event: %s | Available Seats: %d | Event Sales: %.2f \n",
               i, events[i], seats[i], sales[i]);
    }
    printf("Total sales for all event: %.2f \n", totalSales);
}

void generateConfirmation(char events[][50], char name[], int id, int seats[], int index, float price, int numTickets)
{
    char confirmationString[200];
    printf("\nBooking successful! The ticket confirmation is as follows:\n");
    snprintf(confirmationString, sizeof(confirmationString),
             "Name: %s\nEvent: %s\nMember ID: %d\nNumber of Tickets: %d\nTotal Cost: %.2f",
             name, events[index], id, numTickets, price);

    printf("%s\n", confirmationString);
}

void inputName(char name[])
{
    printf("Enter the member name (No whitespace): ");
    scanf("%s", name);
}

int inputID()
{
    int id;
    printf("Enter the member ID number (numbers only, 0 for non member): ");
    scanf("%d", &id);
    if (id == 0)
    {
        printf("No member ID\n");
    }
    return id;
}

int inputEventId()
{
    bool validEventID = false;
    int eventID;
    printf("Enter an Event ID from the list: ");
    scanf("%d", &eventID);

    while (!validEventID)
    {
        if (eventID >= 0 && eventID <= 2)
        {
            validEventID = true;
        }
        else
        {
            printf("Enter a valid event ID: ");
            scanf("%d", &eventID);
        }
    }
    return eventID;
}

char getConfirmation()
{
    char choice;
    while (1)
    {
        printf("Enter 'Y' to confirm purchase or 'N' to cancel (Y/N): ");
        scanf(" %c", &choice);
        if ((choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'))
        {
            return choice;
        }
        else
        {
            printf("Invalid input.\n");
        }
    }
}

int main()
{
    int numberOfEvents = 3;
    char events[3][50] = {"Romeo and Juliet", "Istana Menanti", "Shrek the Musical"};
    int seats[3] = {500, 500, 400};
    float ticketPrice[3] = {50.80, 40.50, 60.00};
    float eventSales[3] = {0.00, 0.00, 0.00};
    float totalRevenue = 0.00;
    char name[50];
    int id = -1;

    bool app = true;
    int choice = -1;

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

            int eventIndex = -1;
            int numTickets = 0;

            id = inputID();
            inputName(name);
            printf("Name: %s, ID: %d\n\n", name, id);

            displayEvents(events, seats, ticketPrice, numberOfEvents);
            eventIndex = inputEventId();

            printf("Enter number of tickets required: ");
            scanf("%d", &numTickets);

            while (numTickets > seats[eventIndex] || numTickets < 0)
            {
                printf("Not enough seats available/Invalid number!\n");
                printf("Enter number of number of attendees or 0 to cancel booking: ");
                scanf("%d", &numTickets);
            }
            float totalCost = bookTickets(eventIndex, numTickets, seats, ticketPrice);
            if (totalCost == 0.00)
            {
                printf("Booking cancelled.\n");
                break;
            }
            float costAfterDiscount = calculateDiscounts(totalCost, numTickets, id);
            printf("Total cost: RM%.2f \n", totalCost);
            printf("Total cost(After Discount): RM%.2f \n", costAfterDiscount);

            char confirmBooking = getConfirmation();

            if (confirmBooking == 'Y' || confirmBooking == 'y')
            {
                eventSales[eventIndex] += costAfterDiscount;
                totalRevenue += costAfterDiscount;
                generateConfirmation(events, name, id, seats, eventIndex, costAfterDiscount, numTickets);
                generateSummary(events, seats, eventSales, totalRevenue, numberOfEvents);
            }

            break;
        case 2:
            printf("\nEvent Information:\n");
            displayEvents(events, seats, ticketPrice, numberOfEvents);
            break;
        case 3:
            generateSummary(events, seats, eventSales, totalRevenue, numberOfEvents);
            break;
        default:
            printf("Invalid selection. Please choose a option between 0 to 3.\n");
            break;
        }
    }
    return 0;
}