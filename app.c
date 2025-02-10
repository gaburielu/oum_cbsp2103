#include <stdio.h>

struct Event
{
    char eventName[50];
    int eventID;
    int numTickets;
    int seats;
    float price;
    int totalRevenue;
};

int main()
{
    struct Event shakespear;

    strcpy(shakespear.eventName, "Romeo and Juliet");
    shakespear.eventID = 20;

    printf("%s\n", shakespear.eventName);
    printf("%d\n", shakespear.eventID);

    return 0;
}