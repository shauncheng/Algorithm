#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
  public:
    Customer(const Customer &);
    virtual ~Customer();
    Customer();
    int GetDuration();
    int GetArrvalTime();

  private:
    int Durations;
    int ArrivalTime;
};
#endif