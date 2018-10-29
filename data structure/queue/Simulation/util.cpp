#include"util.h"
int cmp(Event a,Event b)
{
    if(a.OccurTime>b.OccurTime) return -1;
    else if(a.OccurTime=b.OccurTime) return 0;
    else return 1;
}
void OpenForDay()
{
    TotalTime=0;
    CustomerNum=0;
    current.OccurTime=0;current.EventType=Arrive;
}
void CustomerArrived(){
    ++CustomerNum;
    
}