#include "nodes.h"
//Below are the tNode classes to help create a LLL of tasks
//This class is the basic constructor for a tNode it does a task object and assigns that to data
tNode::tNode(task * the_task) 
{
	data = the_task;//data is a pointer to a task 
}

//Destructor for a tNode in order to check if the deleted node still has data
tNode::~tNode()
{
	//Check if data exists
	if(data)
	{
		//delete the data
		delete data;
		data = NULL;
	}
}

//Takes in a tNode as an argument, ensures that the tNodes are properly connected via the next pointer
tNode * tNode::set_next(tNode * new_next)
{
	next = new_next;//sets this tNodes next to the tNode passed in as an argument
}

//Returns the tNode next, since tNode * next isnt accessible 
tNode * tNode::get_next()
{
	return next;//returns that next tNode
}

//Checks if the task is complete
int tNode::is_comp()
{
	int num;//Temp int to hold the value returned from the check_complete()
	num = data->check_complete();//calls a task function to see what value is set for int complete
	//If 1 is returned above the task is complete
	if(num == 1)
	{
		return 1;//if the task is complete return 1 to where this function was called
	}
	if(num != 1)
	{
		return 0;//just return any number other than 1 this task isnt done yet
	}
}

//Returns the task of a node, will help with display
task * tNode::get_data()
{
	return data;
}
//Below are the nodes for creating an array of LLLs of mail
//Basic constructor takes in a mail object and assigns it to the data of a eNode
eNode::eNode(mail * the_mail)
{
	data = the_mail;//data is a pointer to mail
}

//Destructor to delete data in a node if the node is being deleted
eNode::~eNode()
{
	//check if data is in node before deleteing node
	if(data)
	{
		delete data;
		data = NULL;
	}
}

//assists in linking the eNode taken as an argument to another eNode
eNode * eNode::set_next(eNode * new_next)
{
	next = new_next;
}

//returns the next eNode
eNode * eNode::get_next()
{
	return next;
}

//Returns the data which is a pointer to mail to where it was called (probably mainly for displaying)
mail * eNode::get_data()
{
	return data;
}
//Below are the aNode classes to help create a CLL of appointments
//Basic constructor for aNode
aNode::aNode()
{
	data = new appointment[size];//Intializes an array of a set size of appointments to data
	top_index = 0;//top index so we dont try to add more than the allowed number of appointments for a day
}

//Destructor to help with the deleting of data in aNode
aNode::~aNode()
{
	//check if data exists
	if(data)
	{
		delete [] data;//since were deleting an array of pointers set up is a little different
		data = NULL;
	}
}

//Needed a set data function since we couldnt exactly access the data indexs directly very easily
int aNode::set_data(appointment * to_add)
{
	//Checks to make sure the top index of the aNode isnt max size yet
	if(top_index < size)
	{
		data[top_index] = new appointment(to_add);//If its not we call the copy constructor for a appointment and pass in the appointment to pass it into the index
		++top_index;//keep track of the top_index so we know how many appoints we have booked for a day
		return 1;//return 1 for success
	}
	//If that day is booked dont rewrite an index instead let the user know
	if(top_index == size)
	{
		return -1;//return -1 for booked day
	}
	return 0;//base return of 0 for checking for errors
}	

//We need a for loop for displaying data in an array, I tried to do this recursively but time is running out
void aNode::display_data()
{
	for(int i = 0; i < top_index; i++)
	{
		data[i].display_app();//call the display function for a appointment object for each index
		return;//base return
	}
}

//Ensures we can properly link together the aNodes
aNode * aNode::set_next(aNode * new_next)
{
	next = new_next;//set arguments node next
}

//return the aNode that a aNode points to
aNode * aNode::get_next()
{
	return next;
}

//return the data of an appointment
appointment * aNode::get_data()
{
	return data;
}
//Below are the classes for the LLL of tasks ie the To_do_list
//For a LLL we will need to ensure in the constructor head is NULL to start
to_do_list::to_do_list()
{
	head = NULL;
}

//Basic destructor for a LLL, check head if it exists delete
to_do_list::~to_do_list()
{
	if(head)
	{
		delete head;
		head = NULL;
	}
}

//Add a task to the to do list, one of the first data structure I did I forgot everything is recursive now...
int to_do_list::add_task(task* to_add)
{
	tNode * new_node = new tNode(to_add);//this task data is copied into a tNode
	
	//If the list is empty, set this new node to head
	if(!head)
	{
		head = new_node;
		return 1;
	}
	//List isnt empty
	else
	{
		tNode * temp = head;//Use a temp node for traversing
		//traverse the list until we get to the last node
		while(temp->get_next() != NULL)
		{
			temp = temp->get_next();
		}
		//set the last nodes next to the new node, adding to the end
		temp->set_next(new_node);
	}
	return 0;
}

//wrapper function for removing complete tasks from the list
int to_do_list::remove_task()
{
	tNode * temp = head;
	head = remove_task(temp);
}

//Traversal to find the next non complete task node
tNode * to_do_list::remove_task(tNode * temp)
{
	//base conditional
	if(!temp)
	{
		return NULL;
	}
	//traverse
	if(temp->get_next())
	{
		temp->set_next(remove_task(temp->get_next()));
	}
	//if complete return
	if(temp->is_comp() == 1)
	{
		return temp->get_next();
	}
	return temp;
}

//My first attemp at removing from the LLL, I was going to remove it but i figured maybe useful for understanding how i was interpretting this problem
/*
int to_do_list::remove_task()
{
	tNode * temp = head;

	if(!head)
	{
		cout << "List is empty!";
		return 0;
	}
	if(head->is_comp() == 1)
	{
		head = head->get_next();
	        delete temp;
		temp = head;
	}
	
	tNode * prev = head;

	remove_task();
	temp = head->get_next();
	remove_task(temp,prev);
}

int to_do_list::remove_task(tNode * temp, tNode * prev)
{
	if(temp->is_comp() == 1)
	{
	  tNode * to_del = temp;
	  temp = temp->get_next();
	  prev->set_next(temp);
	  delete to_del;
	 }

}	
*/

//Wrapper function to display the list
void to_do_list::display_all()
{
	//base conditional see if list is empty
	if(!head)
	{
		cout << "List is empty!";
		return;
	}
	//recursive call passing in the front of the list
	display_all(head);
}

//recursive call to go through the list and display the tasks
void to_do_list::display_all(tNode * temp)
{
	//conditional to see if the list is now empty or were at the end
	if(!temp)
	{
		return;
	}
	//Temp task so we can use it to call the display function, I would learn another way to do this utilizing the tNode functions later
	task * read = temp->get_data();
	//Call the task display function with the data from the tNode
	read->display_task();
	//recursively call this function, traversing temp to its next tNode
	display_all(temp->get_next());

}
//Below are the classes for the array of LLLs for managing the emails

//Constructor for the emails class which is an array of head pointers
emails::emails()
{

 	array = new eNode*[size];//set eNode ** array to a new array of size 'size' eNode pointers

	//for loop to intitialize each index to NULL
	for(int i = 0; i < size; i++)
	{
	  array[i] = NULL;
	}

}

//destructor
emails::~emails()
{
//Didnt finish didnt get to removing 
}

//Add an email to the array of LLLs
int emails::add_email(mail * to_add)
{
	int num = 0;//This int will be used to ask the user what category the email falls into
	eNode * new_mail = new eNode(to_add);//create a new eNode copying in the mail object for data

	cout << "Please select the index to add this email. \n1 for School, 2 for Work, 3 for Casual, 4 for Draft, 5 for Inbox.";
	cin >> num;
	num = num - 1;//make sure its set right for dealing with an array of size 5, so starts at 0 not 1
	
	//Check if that index is empty already
	if(array[num] == NULL)
	{
		array[num] = new_mail;//We can set that index to the new mail if its first
		return 1;//return 1 for suuccess
	}
		//if the list isnt empty we will need to traverse and do so recursively
		eNode * temp = array[num];//temp for traverse
		add_email(new_mail, temp, num);//call the recursive function passing in the eNode were adding, the eNode temp for traversing, and num

}

//Recursive call for the function to find the end of a List in a index of an array 
int emails::add_email(eNode * new_mail,eNode * temp, int num)
{	
	//Conditional for if we are at the last node
	if(temp->get_next() == NULL)
	{
		temp->set_next(new_mail);//Set the last nodes next to point to the new node
		return 1;//return 1 for success
	}
	else
		temp = temp->get_next();//if we arent at the end traverse temp

	add_email(new_mail,temp,num);//Call the function recursively 
	return 0;//return 0 for error checks 
}

//Function to display an array of LLLs
int emails::display()
{
	int num;
	//lets ask what index to read out or if they want to display all indexs
	cout << "Please select the index to display.";
        cout <<	"\n1 for School emails, 2 for Work emails, 3 for Casual emails, 4 for the Drafts, 5 for Outbox emails, 6 to display all emails.";
	cin >> num;
	//Conditional for if the user wants to display 1 index or category of mail
	if(num < 6 && num > 0)
	{
		num = num - 1;//correct the entry to match an array indices
		display_index(num);//call the display 1 index function
		return 1;//return 1 for success
	}
	//Conditional for if the user wants to display all emails
	if(num == 6)
	{
		//Only way I could imagine doing this was with a for loop
		for(int i = 0; i < 5; i++)
		{
			display_index(i);//call the display 1 index function but with i which will increase with the for loop
			return 1;//return 1 for success, mainly just for original design planning and testing
		}
	}
	return 0;//return 0 for error
}

//display a specific index in an array of LLLs
void emails::display_index(int num)
{
	//Check to make sure the index isnt empty
	if(array[num] == NULL)
	{
		return;//if that index is empty just return
	}
	eNode * temp = array[num];//set a temp eNode to point to the first node in that index
	
	display_index(temp);//call the display index function for recursive traversal
}

//Recursively display an entire LLL in a array of LLLs
void emails::display_index(eNode * temp)
{
	//Conditional for if were at the end of the LLL
	if(!temp)
		return;
	//Create a temp mail object and assign the data from the node to it
	mail * read = temp->get_data();
	//if theres no data in there its empty and didnt get copied correctly
	if(!read)
	{
		return;//return for fail
	}
	read->display_mail();//call the dispaly function for that temp mail and read out to the user its contents
	display_index(temp->get_next());//traverse temp and call this function again
}
//Below are the classes for managing a CLL of appointments
//Constructor for creating a CLL that will be restricted to a set size, Let it be known if youre reading this I didnt like the idea of any list being a specific size but this seemed like the overwhelmingly popular interpretation of the sentence describing this data structure
app_CLL::app_CLL()
{
	
	rear = NULL;
	//For loop to go through and create 7 aNodes, each will hold data and a next pointer
	for(int i = 0; i < 7; i++)
	{
		//if rear doesnt exist
		if(!rear)
		{
			rear = new aNode();//rear is a new node
			rear->set_next(rear);//link rear with itself making a CLL
		}
		//If the CLL isnt empty
		if(rear)
		{
			aNode * temp = new aNode();//create a new empty aNode
			temp->set_next(rear->get_next());//set this aNodes next to the front of the CLL
			rear->set_next(temp);//connect rear to the new aNode
			rear = temp;//set rear to temp since we added temp to the end of the list
		}
	}
}

//Destructor to delete the CLL
app_CLL::~app_CLL()
{
	if(rear)
	{
		delete rear;
		rear = NULL;	
	}
}

//An attempt at a function to properly add an appointment to a specific node in a CLL
int app_CLL::add_app(appointment * to_add)
{
	int num;
	//I will need to find a way to attempt to set a specific node to a specific day, since we didnt use an array here I need to count as I traverse
	cout << "What day this week is this appointment?(1 for Monday,2 for Tuesday,3 for Wednesday,4 for Thursday,5 for Friday,6 for Saturday,0 for Sunday): ";
	cin >> num;
	aNode * temp = rear;//set a temp aNode to rear

	add_app(temp,to_add,num);//pass temp, the appointment to copy, and the number that represents the day into the recursive function

}

//The recursive function for adding an appointment to a specific node in a CLL
int app_CLL::add_app(aNode * temp, appointment * to_add, int num)
{
	int check = 0;//Using a temp int to check is that days already full of appointments

	//if num == 0 were on the correct day, if no traverse if done that means were adding to sunday
	if(num == 0)
	{
		//Attemp to call the set data function in aNode class, this will check the array of appointments and see if we can add to it
		check = temp->set_data(to_add);
		if(check == -1)//if -1 is returned from the set_data function we have the max number of appointments on that day already
		{
			cout << "This day has too many appointments already!\n";
		}
		if(check == 1)//If 1 is returned we successfully added the appointment to that day
		{
			cout << "Your appointment is booked!\n";
		}
	return 0;
	}
	else//if we arent at the day we want to add to yet
	{
		temp = temp->get_next();//traverse temp
		--num;//subtract 1 from num until were at 0 which should put us at the correct day we want to add to
	}
	add_app(temp,to_add,num);//recursively call the fucntion passing in the traversed temp and the updated num
}

//The display functions will operate similarly to the add functions in terms of traversal 
void app_CLL::display()
{
	int num;//temp int for keeping track of how far weve traversed
	if(!rear)//if rear doesnt exist the week wasnt properly intialized 
	{
		cout << "Week is empty.";//error statement 
	}
	
	cout << "What day would you like to display the appointments for?(1 for Monday,2 for Tuesday,3 for Wednesday,4 for Thursday,";
	cout << "5 for Friday,6 for Saturday, 0 for Sunday): ";
	cin >> num;	
	aNode * temp = rear;//temp for traversing

	display(temp,num);//recursive function call passing in temp and num
}	

//Recursive function for getting to the correct array in the CLL
void app_CLL::display(aNode * temp, int num)
{
	//Conditional where if our num == were at correct aNode
	if(num == 0)
	{
		temp->display_data();//call display data function
		return;//return
	}
	else
	{
	 	temp = temp->get_next();//traverse temp
	       	--num;//keep track of how many 'days' weve traversed through
	}

	display(temp,num);//recursive call of the function

}	


