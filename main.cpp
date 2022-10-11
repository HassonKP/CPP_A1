#include "nodes.h"
//Main 
int main()
{
	//Temp data for copying to objects
	int resp = 0;
	int resp1 = 0;
	char temp1[100];
	char temp[100];
	char tempD[100];
	char tempB[100];
	int Complete =0;
	int Pri = 0;
	int Year = 0;
	int Month = 0;
	int Day = 0;
	//Get the Base info name and date
	cout << "Please enter in your name: ";
	cin.get(temp, 100, '\n');
	cin.ignore(101, '\n');

	cout << "Enter in the year(Four digit ex: 1994): ";
	cin >> Year;
	cout << "Enter in the month(Two digit ex: 05): ";
	cin >> Month;
	cout << "Enter in the day(Two digit ex: 08): ";
	cin >> Day;
	//Create the date object to test
	date * newObj = new date(temp, Year, Month, Day);
	//Datastructure objects
	to_do_list LLLobj;
	emails eObj;	
	app_CLL aObj;
	do
	{
		//Decided what the user wants to do
	  cout << "What would you like to do?"; 
	  cout << "\nEnter 0 to exit. \nEnter 1 to view the date. \nEnter 2 to focus on to do list.";
	  cout << "\nEnter 3 to manage emails.\nEnter 4 to manage appointments.\n";
	  cin >> resp;
	    if(resp == 1)
	    {
		    newObj->display_date();
	    }
	    if(resp == 2)
	    {
			cout << "What would you like to do with your task list? \nEnter 1 to add to the to do list. \nEnter 2 to display the list.";
			cout << "\nEnter 3 to remove complete tasks from your list.";
			cin >> resp1;
			cin.ignore();
			if(resp1 == 1)
			{
				cout << "Enter in a new task description: ";
				cin.get(tempD, 100, '\n');
				cin.ignore(101, '\n');

				cout << "Enter in a 1 if the task is complete or a 0 if it is not complete: ";
				cin >> Complete;

				cout << "Enter in the priority from 1-5 (5 being extremely important 1 being not important): ";
				cin >> Pri;
				
				task * to_add = new task(temp, Year, Month, Day, Complete, Pri, tempD);//Create a new task object
				LLLobj.add_task(to_add);//pass that new task object to the LLL of tasks
				
			}	
			if(resp1 == 2)
			{
				LLLobj.display_all();//Display the LLL of tasks
			}
			if(resp1 == 3)
			{
				LLLobj.remove_task();//Remove complete tasks
			}
	    }
	    if(resp == 3)
	    {
		cout << "What would you like to do with your email. \nPress 1 to draft a new email. \nPress 2 to display an email index. ";
		cin >> resp1;
		cin.ignore();
		if(resp1 == 1)
		{
			cout << "Enter in the recipient of the email first: ";
			cin.get(temp1, 100, '\n');
			cin.ignore(101, '\n');

			cout << "Enter the subject of the email: ";
			cin.get(tempD, 100, '\n');
			cin.ignore(101, '\n');

			cout << "Enter in the body of the email: ";
			cin.get(tempB, 100, '\n');
			cin.ignore(101, '\n');

			mail * to_add = new mail(temp, Year, Month, Day, temp1, tempD, tempB);//Create a new mail object
	    		eObj.add_email(to_add);//Pass the mail object to the array of LLLs for managing mail

		}
		if(resp1 == 2)
		{
			eObj.display();//Display emails
		}

	    }
	    if(resp == 4)
	    {
	    	cout << "What would you like to do with your appointments? Enter 1 to add an appointment. Enter 2 to display appointments for this week.";
		cin >> resp1;
		cin.ignore();
		if(resp1 == 1)
		{
			cout << "Please enter who this meeting is with: ";
			cin.get(temp1, 100, '\n');
			cin.ignore(101,'\n');

			cout << "Enter the information about this appointment: ";
			cin.get(tempD, 100, '\n');
			cin.ignore(101, '\n');

			appointment * to_add = new appointment(temp, Year, Month, Day, temp1, tempD);//Create a appointment object
			aObj.add_app(to_add);//Pass the appointment object to the app_CLL data structure
		}
		if(resp1 == 2)
		{
			aObj.display();//Display appointments
		}

	    }


	}while (resp != 0);//Loop until the user wants to exit
























}
