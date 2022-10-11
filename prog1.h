#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
/*Name: Killian Hasson		Date: 04/05/20
 * For program 1 we were tasked with a few specific tasks, we needed to create a way to manage emails, a to_do_list, and appointments all for a specific user on a computer. For this Program the use of 
 * inheritance could prove useful for us. A user being my base class would have to manage each of these classes or events as they would all pertain to this user. I found it very difficult to understand this 
 * program at first and spent weeks goign down the wrong path. This .h file contains my main data objects as I tihnk of them where as my other .h file contains my data strructures. There is some code in here 
 * in which I choose not to delete it so perhaps the grader would have a better udnerstanding of how I attempted to approach this task at first. 
 * */


class user
{
	public:
		user();
		user(char * Name);
		user(const user & to_copy);
		~user();
		int change_user(char * new_name);
	protected:
		char * name;
};

class date: public user
{
	public:
		date();
		date(char * Name, int Year, int Month, int Day);
		date(const date & to_copy);
		~date();
		void display_date();
	protected:
		int year;
		int month;
		int day;
};

//So I have a class for mail, This class will need a date just like the below listed classes so I had it set as a derived class from date since
//if we send out mail it will need to have the date it was sent. Im not totally sure how this would work yet.

class mail: public date
{
	public:	
		mail();	
		mail(char * temp, int Year, int Month,int Day, char * Recipient, char * Subject, char * Body);
		mail(const mail & to_copy);	
		~mail();
		int display_mail();
	protected:	
		char * recipient;
		char * subject;
		char * body;
};
//Appointments will need the date aswell so I have this class as a derived class of date in order for the user to see if any appoints fall on todays date
//or for setting appointments for future dates, could use the set date function in date class perhaps.
class appointment: public date
{
	public:
		appointment();
		appointment(char * temp, int Year, int Month, int Day, char * Meet_Who, char * App_Info);	
		appointment(const appointment * to_add);	
		~appointment();
		int display_app();
	protected:
		char * meet_who;
		char * app_info;
};

//to do class also will need to utilize the functions in date, specifically to allow the suer to see the todays todo list.
class task: public date
{
	public:
		task();	
		task(char * temp,int Year,int Month,int Day, int Complete, int Pri, char * tempD);	
//		task(const task & to_copy);
		~task();
		int display_task();
		int check_complete();
//		int complete_task(const task & to_find);
	protected:
		int complete;
		int priority;
		char * desc;	
};























//;
