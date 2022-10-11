#include "prog1.h"
//Constructor for user class
user::user()
{
	name = NULL;
}

//Constructor for a user, takes in a array of char as an argument
user::user(char * Name)
{
  //copies in the argument into the name of the user
  name = new char[strlen(Name)+1];
  strcpy(name, Name);
}

//Copy constructor for if I want to copy a user object
user::user(const user & to_copy)
{
	name = new char[strlen(to_copy.name)+1];
	strcpy(name,to_copy.name);
}
//destructor
user::~user()
{
	//if name exists we need to ensure its deleted
	if(name)
	{
		delete [] name;
		name = NULL;
	}
}

//Constructor for date
date::date()
{
	year = 0;
	month = 0;
	day = 0;
}

//Constructor for date, since date is derived of user also intilizes user name to the Name passed in
date::date(char * Name, int Year, int Month, int Day): user(Name)
{
	year = Year;
	month = Month;
	day = Day;
}

//Copy constructor for date
date::date(const date & to_copy): user(to_copy)
{
	year = to_copy.year;
	month = to_copy.month;
	day = to_copy.day;
}

//Destructor for date, check if the ints have values 
date::~date()
{
	if(year)
	{
		year = 0;
	}
	if(month)
	{
		month = 0;
	}
	if(day)
	{
		day =0;
	}
}

//Display date fucntion, this will be able to be called in main if the user wants to know the date
void date::display_date()
{
	cout << "Todays date is: " << year << "/" << month << "/" << day << endl;// Basic read out to the user
}

//Task constructor
task::task()
{
	complete = 0;
	priority = 0;
	desc = NULL;
}

//Task constructor that takes in arguments for the date constructor as well as values for the task data
task::task(char * temp,int Year,int Month, int Day, int Complete, int Pri, char * tempD): date(temp,Year,Month,Day)
{
	complete = Complete;

	priority = Pri;

	//Have to dynamically allocate the memory of the desc task
	desc = new char[strlen(tempD)+1];
	strcpy(desc, temp);
}

//Destructor for tasks, ensure data is deleted
task::~task()
{
	complete = 0;

	priority = 0;

	desc = NULL;
}

//Realized I needed a way to check if a task is complete when removing completed tasks from the to do list
int task::check_complete()
{
	//Basic conditional checks if the tasks complete int = 1
	if(complete == 1)
	{
		return 1;//return 1 if task is compplete
	}
	else
	{
		return 0;//return 0 if the task isnt complete
	}
}

//Basic fucntion called in the to do list function to directly display the data of a task in an organized fashion
int task::display_task()
{
	cout << "\nTask Desc: " << desc;
	cout << "\nTask Complete?(0 = Not Complete 1 = Complete): " << complete;
	cout << "\nTask Priority: " << priority;
	cout << "\n";
	return 1;
}

//Constructor for mail
mail::mail()
{
	recipient = NULL;
	subject = NULL;
	body = NULL;
}

//Destructor for mail
mail::~mail()
{
	recipient = NULL;

	subject = NULL;

	body = NULL;
}

//Constructor for mail, takes in arguments to pass to the date constructor as well as to properly fill in data for a mail object
mail::mail(char * temp, int Year, int Month, int Day, char * Recipient, char * Subject, char * Body): date(temp,Year,Month,Day)
{
	//All three data types in the mail object are dynamically allocated arrays and need to be handled as such
	recipient = new char[strlen(Recipient)+1];
	strcpy(recipient, Recipient);

	subject = new char[strlen(Subject)+1];
	strcpy(subject, Subject);

	body = new char[strlen(Body)+1];
	strcpy(body, Body);

}
/*
mail::mail(const mail& to_copy)
{}
*/

//Basic Dispaly function for mail in order to have data read out for a eNode
int mail::display_mail()
{
	cout << "\nRecipient: " << recipient;
	cout << "\nSubject: " << subject;
	cout << "\nBody: " << body;
	cout << "\n";
	return 1;
}

//Appointment constructor
appointment::appointment()
{
	meet_who = NULL;

	app_info = NULL;
}

//Appointment copy constructor
appointment::appointment(const appointment * to_add)
{
	meet_who = new char[strlen(to_add->meet_who)+1];
	strcpy(meet_who, to_add->meet_who);

	app_info = new char[strlen(to_add->app_info)+1];
	strcpy(app_info, to_add->app_info);
}

//Appointment constrcutor with arguments for the base classes
appointment::appointment(char * temp, int Year, int Month, int Day, char * Meet_Who, char * App_Info): date(temp,Year,Month,Day)
{
	meet_who = new char[strlen(Meet_Who)+1];
	strcpy(meet_who, Meet_Who);

	app_info = new char[strlen(App_Info)+1];
	strcpy(app_info, App_Info);
}

//Destructor
appointment::~appointment()
{
	meet_who = NULL;

	app_info = NULL;
}

//Basic display appointemnt function which will be called in the app_CLL data structure
int appointment::display_app()
{
	cout << "\nMeeting with: " << meet_who;
	cout << "\nYour appointment info: " << app_info;
	cout << "\n";
}
































//}
