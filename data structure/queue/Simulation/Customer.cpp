#include"customer.h"
#include<stdlib.h>
Customer::Customer()
{
    Durations=rand()%60;
    ArrivalTime=rand()%20;
}
int Customer::GetArrvalTime(){
    return ArrivalTime;
}
int Customer::GetDuration()
{
    return Durations;
}


