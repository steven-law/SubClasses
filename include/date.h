#include <Arduino.h>

class Date
{
private:
    int Day;
    int Month;
    int Year;

public:
    int get_day() const { return Day; }
    int get_month() const { return Month; }
    int get_year() const { return Year; }
    Date(int d, int m, int y)
    {
        Day = d;
        Month = m;
        Year = y;
    }
};
