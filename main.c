#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "treeheader.h"

static void BuildCount()//PROBLEM 1 and 2
{
	int boolean = 1;
	int content;
	int length = 0;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	length = getLength(head);
	printf("The lenght of the tree is %d.\n", length);
	boolean = 1; //reset boolean to default to prepare for next while loop

	while(boolean)
	{
		int count = 0;
		if(yesno("Do you want to search for the total number of entries for a value (Y/N)?"))
		{
			read_int("Please enter your value to search for: ", &content);
			length = getLength(head);
			printf("The lenght of the tree is %d.\n", length);
			ElementSearch(head, content, &count);
			printf("The total number of entries for %d is %d.\n", content, count);
		}
		else
		{
			boolean = 0;
		}
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 1 and 2

static void MaxDepth()//PROBLEM 3
{
	int boolean = 1;
	int content;
	int depth = 0;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	depth = Max_Depth(head);
	printf("The depth of the tree is %d.\n", depth);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 4

static void MinValue()//PROBLEM 4
{
	int boolean = 1;
	int content;
	int minvalue = 0;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	minvalue = Min_Value(head);
	printf("The depth of the tree is %d.\n", minvalue);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 4

static void PrintTree()//PROBLEM 5
{
	int boolean = 1;
	int content;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}

	Print_Tree(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 5

static void PrintPostOrder()//PROBLEM 6
{
	int boolean = 1;
	int content;
	int length;
	int depth;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The tree is empty.\n");
		return;
	}
	length = getLength(head);
	depth = Max_Depth(head);
	Print_Post_Order(head, length, depth);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 6

static void PrintPaths()//PROBLEM 8 -- This is an extension of Problem 7.
{
	int boolean = 1;
	int content;
	int depth;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The tree is empty.\n");
		return;
	}
	depth = Max_Depth(head);
	Print_Paths(head, depth);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 8 -- This is an extension of Problem 7

static void Mirror()//PROBLEM 9
{
	int boolean = 1;
	int content;
	int depth;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The tree is empty.\n");
		return;
	}
	depth = Max_Depth(head);
	Print_Paths(head, depth);
	Mirror_Tree(head);
	Print_Paths(head, depth);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 9

static void DoubleTree()//PROBLEM 10
{
	int boolean = 1;
	int content;
	int depth;
	struct node *head = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The tree is empty.\n");
		return;
	}
	depth = Max_Depth(head);
	Print_Paths(head, depth);
	Double_Tree(head);
	Print_Paths(head, depth);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 10

static void SameTree()//PROBLEM 11
{
	int boolean = 1;
	int content;
	int length;
	int length2;
	int depth;
	int depth2;
	struct node *head = NULL;
	struct node *head2 = NULL;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head2, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The head tree is empty.\n");
		if(head2 != NULL)
		{
			freeElements(&head2);//free up the allocated memory
		}
		return;
	}
	if(head2 == NULL)
	{
		printf("The head2 tree is empty.\n");
		if(head != NULL)
		{
			freeElements(&head);//free up the allocated memory
		}
		return;
	}
	depth = Max_Depth(head);
	length = getLength(head);
	depth2 = Max_Depth(head2);
	length2 = getLength(head2);
	boolean = Same_Tree(head, head2, length, length2, depth, depth2);
	if(boolean == 1)
	{
		printf("The two trees are indentical.\n");
	}
	else
	{
		printf("The two trees are different.\n");
	}
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	freeElements(&head2);//free up the allocated memory
	if(head == NULL)
	{
		printf("Head2 node was set to NULL.\n");
	}
}//END PROBLEM 11

static void ISBST()//PROBLEM 13 and 14
{
	int boolean = 1;
	struct node *head = NULL;
	int content;

	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			Append(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The tree is empty.\n");
		return;
	}
	Is_Search_Tree(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
	//Now enter the same nodes and make a non searchable tree
	boolean = 1;
	while(boolean)
	{
		if(yesno("Would you like to enter a value (Y/N)?"))
		{
			read_int("Please enter your value: ", &content);
			NonSearchableTree(&head, content);
		}
		else
		{
			boolean = 0;
		}
	}
	if(head == NULL)
	{
		printf("The tree is empty.\n");
		return;
	}
	Is_Search_Tree(head);
	freeElements(&head);//free up the allocated memory
	if(head == NULL)
	{
		printf("The head node was set to NULL.\n");
	}
}//END PROBLEM 13 and 14

static void quit()
{
	exit(0);
}

static struct
{
	char *string; //declaring this as a string is helpful when we use Nelts later
	//in other words, since it is a pointer it will have a standard size
	//as opposed to an array which will have a size dependent on the 
	//the size of the string in the array
	void (*func)(void);
}
menu_opts[] =
{
	{"Build and Count", BuildCount},
	{"Max Depth", MaxDepth},
	{"Min Value", MinValue},
	{"Print Tree", PrintTree},
	{"Print Post Order", PrintPostOrder},
	{"Print Paths", PrintPaths},
	{"Mirror", Mirror},
	{"Double Tree", DoubleTree},
	{"Same Tree", SameTree},
	{"Is BST", ISBST},
	{"Exit Program", quit}
};

/*
 *  display_menu()
 *
 *  Display the full menu screen ONCE, then prompt for a choice and call
 *  the appropriate function
 */
static void display_menu()
{
	int     choice;
	int     i;


	/*
	 *  display the menu
	 */
	puts("Please choose an option:");
	for (i = 0; i < Nelts(menu_opts); i++)
		printf("%2d.  %s\n", i+1, menu_opts[i].string);

	/*
	 *  loop until they enter a valid choice
	 */
	for (;;)
	{
		read_int("Please enter your choice: ", &choice);
		if (choice > 0 && choice <= Nelts(menu_opts))
			break;
		puts("Invalid Selection");
	}

	/*
	 *  call the function (via the function pointer
	 */
	menu_opts[choice-1].func();
	enter("\nPress ENTER to continue: ");
}

/*
 *  goodbye()
 *
 *  Exit the program gracefully (used with atexit())
 */

static void goodbye()
{
	enter("\nPress ENTER to exit the program: ");
}


int main(void)
{

	atexit(goodbye);        /* ensure we say goodbye nicely */

	puts("Welcome to the solutions for Nick Parlante's Linked List Problems.");

	/*
	 *  just keep displaying the menu - the QUIT option will break the loop
	 */
	for (;;)
		display_menu();

}
