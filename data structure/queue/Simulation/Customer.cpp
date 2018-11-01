#include"customer.h"
#include<stdlib.h>
Customer::Customer(int currentTime)
{
    Durations=rand()%60;
    ArrivalTime=rand()%20+currentTime;
}
int Customer::GetArrvalTime(){
    return ArrivalTime;
}
int Customer::GetDuration()
{
    return Durations;
}


