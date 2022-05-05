#include "../std_lib_facilities.h"
//1:int year month day
struct Date 
{
    int y; // year
    int m; // month
    int d; // day 
};

void init_day(Date& dd, int y, int m, int d)
{
 // 2:check that (y,m,d) is a valid date
 //   if it is, use it to initialize dd
    if (y > 0)
        dd.y = y;
    else
        error("Invalid year");
    
    if (m > 0 && m < 13)
        dd.m = m;
    else 
        error("Invalid month");
    
    if (d > 0 && d < 32)
        dd.d = d;
    else 
        error("Invalid day");
}

void add_day(Date& date, int n)
{
//3: increase dd by n days
    date.d += n;
	if (date.d > 31) 
	{
		date.m++;
		date.d -= 31;
		if (date.m > 12)
		{
			date.y++;
			date.m -= 12;
		}
	}
}
       
int main()
try
{
//4: Date variable ( named object)
    Date today;
    Date tomorrow;
//5: set today to 1978.6.25
//  copy today to tomorrow
//  add 1 day to tomorrow
    init_day(today, 1978, 6, 25);  
    tomorrow = today;
    add_day(tomorrow, 1);
    
    cout << "today: " << today.y << "." << today.m << "." << today.d << "."<< endl;  
    cout << "tomorrow: " << tomorrow.y << "." << tomorrow.m << "." << tomorrow.d << "."<< endl;  
    
//6: invalid date to check
    Date x;
    init_day(x, -2, 13, 32);
    cout << x.y << "." << x.m << "." << x.d << endl;
     
    return 0;
}
catch (exception& e)
{
    cout << "Error: " << e.what() << endl;
    return 1;
}
