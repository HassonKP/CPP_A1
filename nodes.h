#include "prog1.h"
/*Name: Killian Hasson			Date: 04/21/2021
 *
 *For this pprogram I mainly covered the purpose and such on prog1.h file, But here I will discuss briefly How I attempted to handle the data structures.
 I foudn it very difficult to navigate between lets say a list and its nodes, I know we were told to avoid getters and setters but I really couldnt figure
 out another way to handle this. I also had a terrible time with designing a CLL of a specific size where each node is an array opf appointments. The
 overall program wasnt terrible but many times I found myself taken aback by the amount of work doing simple things could take, which I know is a sign
 that my use of inheritance and OOP wasnt great but I tried.
 *
 */
//Below is the class for a node that holds a task data
class tNode
{
	public:
		tNode(task * the_task);//Constructor
		~tNode();//Destructor
		tNode * set_next(tNode * new_next);//Setter
		tNode * get_next();//Getter
		task * get_data();//Getter
		int is_comp();//Check if the task is complete for the task
	protected:
		task * data;//Data is a pointer to a task
		tNode * next;//Next is a pointer to a tNode
};

//Below is the data structure that will utilize the above listed tNode, it is a LLL of tNodes
class to_do_list
{
	public:
		to_do_list();//Constructor
		~to_do_list();//Destructor
		int add_task(task* to_add);//Add to the LLL
		int remove_task();//Remove from the LLL
		tNode * remove_task(tNode * temp);//Assist in traversing/linking while removing
		void display_all();//Wrapper function to display
		void display_all(tNode * head);//Recursive call for displaying a LLL
	protected:
		tNode * head;//Each LLL will have atleast a head pointer
};

//Below is a node that holds mail as data
class eNode
{
	public:
		eNode(mail * the_mail);//Constructor that takes in a mail object as argument
		~eNode();//destructor
		eNode * set_next(eNode * new_next);//Setter
		eNode * get_next();//Getter
		mail * get_data();//Getter
	protected:
		mail * data;//Data helps with managing a mail object
		eNode * next;//Next is a pointer to a eNode
};

//Below is the class for a array of LLLs, the LLLs consist of 'eNode' nodes
class emails
{
	public:
		emails();//Constructor
		~emails();//Destructor
		int add_email(mail * to_add);//Wrapper function to add 
		int add_email(eNode * new_mail,eNode * temp,int num);//Recursively traversive to add to the correct part in the LLL of an Index
		int display();//Display function
		void display_index(int num);//wrapper fucntion to display a particular index in the array of LLLs
		void display_index(eNode * temp);//Recursively display the entire index
	protected:
		eNode **array;//Array of LLLs set up just like in 163 program 2
		int size = 5;//Allow 5 categories of email
};

//Manage an aNode that will act as a node for appointments
class aNode
{
	public:
		aNode();//Constructor
		~aNode();//Destructor
		aNode * set_next(aNode * new_next);//Setter
		aNode * get_next();//Getter
		int set_data(appointment * to_add);//Setter
		void display_data();//Display a aNode function
		appointment * get_data();//Getter for data
	protected:
		appointment * data;//Data helps with managing a appointment object
		aNode * next;//Next points to a aNode
		int top_index;//Helps with seeing how many appointments are already on that day
		int size = 5;//Allow 5 appointments per day
};

//Class for creating a CLL of arrays
class app_CLL
{
	public:
		app_CLL();//Constructor
		~app_CLL();//Destructor
		int add_app(appointment * to_add);//Wrapper fucntion to add to the CLL
		int add_app(aNode * temp, appointment * to_add,int num);//Recursively add to the CLL
		void display();//Wrapper function for displaying the CLL
		void display(aNode * temp, int num);//Recursively display the CLL
	protected:
		aNode * rear;//Each CLL will have atleast a rear pointer
};

