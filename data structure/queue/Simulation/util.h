#ifndef UTIL_H
#define UTIL_H
#include"Customer.h"
#include<queue>

#include<list>

using namespace std;

typedef enum{
    Arrive,
    FirstLeave,
    SecondLeave,
    ThirdLeave,
    FourthLeave,
}EventType;
typedef struct{
    int OccurTime;
    int EventType;
}Event;
queue<Customer> customers[4];
list<Event> EventStream;
Event current;

int TotalTime,CustomerNum;
int cmp(Event,Event);
void OpenForDay();
void CustomerArrived(int,int);
void CustomerDeparture();
void BankSimulation(int CloseTime);


#endif