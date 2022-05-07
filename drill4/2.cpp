   
#include "../std_lib_facilities.h"

struct Date
{
    int year, month, day;
    Date(int y, int m, int d);     
    void add_day(int n);        // increase the Date by n days

};

Date::Date(int y, int m, int d)
{
    if (y > 0)
        year = y;
    else
        error("Invalid year");
    if (m > 0 && m < 13)
        month = m;
    else 
        error("Invalid month");
    if (d > 0 && d < 32)
        day = d;
    else 
        error("Invalid day");
}

void Date::add_day(int n)
{
    day += n;
	if (day > 31) 
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -= 12;
		}
	}
}
       

int main()
try
{   
    Date today {1978, 6, 25};
    cout << "today: " << today.year << "." << today.month << "." << today.day << endl;
	
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "tomorrow: " << tomorrow.year << "." << tomorrow.month << "." << tomorrow.day << endl;
	
    //invalid date to check
    Date x {-2, 13, 32};
    cout << x.year << "." << x.month << "." << x.day << endl;
     
    return 0;
}
catch (exception& e)
{
    cout << "Error: " << e.what() << endl;
    return 1;
}
