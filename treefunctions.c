#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "treeheader.h"

void NonSearchableTree(struct node **headRef, int data)//evens are searchable and odds just pushed
{
	struct node *newNode = NULL;
	struct node *holder = NULL;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->visited = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	if(*headRef == NULL)
	{
		newNode->parent = NULL;
		*headRef = newNode;
		return;
	}
	else
	{
		holder = *headRef;
	}
	while(*headRef != NULL)
	{
		if((newNode->data) % 2 == 0)
		{
			if(newNode->data <= (*headRef)->data)
			{
				if((*headRef)->left != NULL)
				{
					*headRef = (*headRef)->left;
				}
				else
				{
					newNode->parent = *headRef;
					(*headRef)->left = newNode;
					*headRef = holder;
					return;
				}
			}
			else
			{
				if((*headRef)->right != NULL)
				{
					*headRef = (*headRef)->right;
				}
				else
				{
					newNode->parent = *headRef;
					(*headRef)->right = newNode;
					*headRef = holder;
					return;
				}
			}
		}
		else
		{
			newNode->parent = NULL;
			newNode->right = *headRef;
			(*headRef)->parent = newNode;
			*headRef = newNode;
			return;
		}
	}
}

void Append(struct node **headRef, int data)
{
	struct node *newNode = NULL;
	struct node *holder = NULL;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->visited = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	if(*headRef == NULL)
	{
		newNode->parent = NULL;
		*headRef = newNode;
		return;
	}
	else
	{
		holder = *headRef;
	}
	while(*headRef != NULL)
	{
		if(newNode->data <= (*headRef)->data)
		{
			if((*headRef)->left != NULL)
			{
				*headRef = (*headRef)->left;
			}
			else
			{
				newNode->parent = *headRef;
				(*headRef)->left = newNode;
				*headRef = holder;
				return;
			}
		}
		else
		{
			if((*headRef)->right != NULL)
			{
				*headRef = (*headRef)->right;
			}
			else
			{
				newNode->parent = *headRef;
				(*headRef)->right = newNode;
				*headRef = holder;
				return;
			}
		}
	}
}

/* int Max_Depth(struct node *headRef) *///Less efficient for large lists the the algorithm that follows below
/* { */
/* 	short int OFF; */
/* 	short int ON; */
/* 	int count = 0; */
/* 	int holder = 0; */
/* 	struct node *headHolder = headRef; */
/* 	if(headRef->visited == 0) */
/* 	{ */
/* 		OFF = 0; */
/* 		ON = 1; */
/* 	} */
/* 	else */
/* 	{ */
/* 		OFF = 1; */
/* 		ON = 0; */
/* 	} */
/* 	while(1) */
/* 	{ */
/* 		if(headRef == NULL) */
/* 		{ */
/* 			break; */
/* 		} */
/* 		if(headRef->left != NULL && (headRef->left)->visited == OFF) */
/* 		{ */
/* 			count++; */
/* 			headRef = headRef->left; */
/* 		} */
/* 		else if(headRef->right != NULL && (headRef->right)->visited == OFF) */
/* 		{ */
/* 			count++; */
/* 			headRef = headRef->right; */
/* 		} */
/* 		else if(headRef->visited == OFF) */
/* 		{ */
/* 			count++; */
/* 			if(count > holder) */
/* 			{ */
/* 				holder = count; */
/* 				printf("Holder is %d\n", holder); */
/* 			} */
/* 			headRef->visited = ON; */
/* 			count = 0; */
/* 			headRef = headHolder; */
/* 		} */
/* 		else if(headRef->visited == ON) */
/* 		{ */
/* 			break; */
/* 		} */
/* 		/1* else *1/ */
/* 		/1* { *1/ */
/* 		/1* 	headRef = headRef->parent; *1/ */
/* 		/1* 	count--; *1/ */
/* 		/1* } *1/ */
/* 	} */
/* 	return holder; */
/* } */

int Max_Depth(struct node *headRef)
{
	short int OFF;
	short int ON;
	int count = 0;
	int holder = 0;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	if(headRef != NULL)
	{
		count = 1;
	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF)
		{
			count++;
			headRef = headRef->left;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF)
		{
			count++;
			headRef = headRef->right;
		}
		else if(headRef->visited == OFF)
		{
			if(count > holder)
			{
				holder = count;
				/* printf("Holder is %d\n", holder); */
			}
			headRef->visited = ON;
		}
		else
		{
			headRef = headRef->parent;
			count--;
		}
	}
	return holder;
}

int Min_Value(struct node *headRef)
{
	struct node *current = headRef;

	while(current->left != NULL)
	{
		current = current->left;
	}
	return (current->data);
}

void Print_Tree(struct node *headRef)//Print tree element data in sorted order
{
	short int OFF;
	short int ON;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	while(1)
	{
		//These next two take care of the case when headRef is NULL or only one element. Eventually, in this loop, a non NULL headRef will will become NULL to break out of function
		if(headRef == NULL)
		{
			return;
		}
		if(headRef->parent == NULL && headRef->left == NULL && headRef->right == NULL)
		{
			printf("The value is %d\n", headRef->data);
			return;
		}
		//This case is when the left side including the headRef (top of the tree) have been parsed. We can move to the the right side
		if(headRef->parent == NULL && headRef->visited == ON)
		{
			if(headRef->right != NULL && (headRef->right)->visited == OFF)
			{
				headRef = headRef->right;
			}
			else if(headRef->right != NULL && (headRef->right)->visited == ON)
			{
				headRef = headRef->parent;
			}
			else if(headRef->right == NULL)
			{
				headRef = headRef->parent;
			}
		}
		//This is used to parse up the tree and get the value of elements that were before passed over for smaller valued elements
		else if(headRef->left != NULL)
		{
			if((headRef->left)->visited == ON && headRef->visited == OFF)
			{
				headRef->visited = ON;
				printf("The value is %d\n", headRef->data);
			}
			else if((headRef->left)->visited == ON && headRef->visited == ON && headRef->right != NULL)
			{
				headRef = headRef->right;
			}
			else
			{
				headRef = headRef->left;
			}
		}	
		//this is used when we reach the min
		else if(headRef->left == NULL)
		{
			if(headRef->visited == OFF)
			{
				headRef->visited = ON;
				printf("The value is %d\n", headRef->data);
			}
			else if(headRef->right != NULL)
			{
				headRef = headRef->right;
			}
			else if(headRef->right == NULL)
			{
				while(headRef->visited == ON)
				{
					if(headRef->parent == NULL)
					{
						break;
					}
					headRef = headRef->parent;
				}
			}
		}
	}
}

void Print_Post_Order(struct node *headRef, int length, int depth)
{
	short int OFF;
	short int ON;
	int count = 0;
	int i;
	int j;
	int arraydepth[depth];
	int arrayvalue[depth][(length/2)+1];//length/2 - 1 represents the maximum number of nodes that could be at the lowest level of the tree and therefore covers all cases in excess (overkill but convenient.)
	memset(arraydepth, 0, sizeof arraydepth);//initialize arraydepth to 0
	memset(arrayvalue, 0, sizeof arrayvalue);//initialize arrayvalue to 0
	/* for(i = 0; i < depth; i++)//other way to initialize arraydepth to 0 */
	/* { */
	/* 	arraydepth[i] = 0; */
	/* } */
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	if(headRef != NULL)
	{
		count++;
		j = arraydepth[count - 1];
		arrayvalue[count -1][j] = headRef->data;
		j++;
		arraydepth[count - 1] = j;
		headRef->visited = ON;

	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF)
		{
			count++;
			headRef = headRef->left;
			j = arraydepth[count - 1];
			arrayvalue[count -1][j] = headRef->data;
			j++;
			arraydepth[count - 1] = j;
			headRef->visited = ON;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF)
		{
			count++;
			headRef = headRef->right;
			j = arraydepth[count - 1];
			arrayvalue[count -1][j] = headRef->data;
			j++;
			arraydepth[count - 1] = j;
			headRef->visited = ON;
		}
		else if(headRef->visited == OFF)
		{
			j = arraydepth[count - 1];
			arrayvalue[count -1][j] = headRef->data;
			j++;
			arraydepth[count - 1] = j;
			headRef->visited = ON;
		}
		else
		{
			headRef = headRef->parent;
			count--;
		}
	}
	for(i = depth - 1; i >= 0; i--)
	{
		int k;
		int m;
		m = arraydepth[i];
		for(k = 0; k < m; k++)
		{
			printf("%d\n", arrayvalue[i][k]);
		}
	}


	return;
}

void GrabElem(struct node *headRef, int length, int depth, int *ptr)
{
	short int OFF;
	short int ON;
	int count = 0;
	int i;
	int j;
	int n = 0;
	int arraydepth[depth];
	int arrayvalue[depth][(length/2)+1];//length/2 - 1 represents the maximum number of nodes that could be at the lowest level of the tree and therefore covers all cases in excess (overkill but convenient.)
	memset(arraydepth, 0, sizeof arraydepth);//initialize arraydepth to 0
	memset(arrayvalue, 0, sizeof arrayvalue);//initialize arrayvalue to 0
	/* for(i = 0; i < depth; i++)//other way to initialize arraydepth to 0 */
	/* { */
	/* 	arraydepth[i] = 0; */
	/* } */
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	if(headRef != NULL)
	{
		count++;
		j = arraydepth[count - 1];
		arrayvalue[count -1][j] = headRef->data;
		j++;
		arraydepth[count - 1] = j;
		headRef->visited = ON;

	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF)
		{
			count++;
			headRef = headRef->left;
			j = arraydepth[count - 1];
			arrayvalue[count -1][j] = headRef->data;
			j++;
			arraydepth[count - 1] = j;
			headRef->visited = ON;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF)
		{
			count++;
			headRef = headRef->right;
			j = arraydepth[count - 1];
			arrayvalue[count -1][j] = headRef->data;
			j++;
			arraydepth[count - 1] = j;
			headRef->visited = ON;
		}
		else if(headRef->visited == OFF)
		{
			j = arraydepth[count - 1];
			arrayvalue[count -1][j] = headRef->data;
			j++;
			arraydepth[count - 1] = j;
			headRef->visited = ON;
		}
		else
		{
			headRef = headRef->parent;
			count--;
		}
	}
	for(i = depth - 1; i >= 0; i--)
	{
		int k;
		int m;
		m = arraydepth[i];
		for(k = 0; k < m; k++)
		{
			ptr[n] = arrayvalue[i][k];
			n++;
		}
	}


	return;
}

void Print_Paths(struct node *headRef, int depth)
{
	short int OFF;
	short int ON;
	int count = 0;
	int i = 0;
	int j;
	int switchsignal = 1;
	int arrayholder[depth];
	memset(arrayholder, 0, sizeof(arrayholder));
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	if(headRef != NULL)
	{
		count = 1;
	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF && switchsignal == 1)
		{
			headRef = headRef->left;
			count++;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF && switchsignal == 1)
		{
			headRef = headRef->right;
			count++;
		}
		else if(headRef->visited == OFF && headRef->left == NULL && headRef->right == NULL)
		{
			int m = 1;
			headRef->visited = ON;
			i = count;
			arrayholder[count - 1] = headRef->data;
			while(headRef->parent != NULL)
			{
				headRef = headRef->parent;
				count--;
				arrayholder[count - 1] = headRef->data;
				if(headRef->left != NULL && headRef->right != NULL)
				{
					if((headRef->left)->visited == OFF || (headRef->right)->visited == OFF)
					{
						m = 0;
					}
					else if(m == 1)
					{
						headRef->visited = ON;
					}
				}
				else if(m == 1)
				{
					headRef->visited = ON;
				}
			}
			for(j = 0; j < i; j++)
			{
				printf("%d  ", arrayholder[j]);
			}
			printf("\n");
		}
		else
		{
			switchsignal = 0;
			headRef = headRef->parent;
			count--;
		}
	}
}

void Double_Tree(struct node *headRef)
{
	short int OFF;
	short int ON;
	int switchsignal = 1;
	struct node *holder = NULL;
	struct node *newNode = NULL;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF && switchsignal == 1)
		{
			headRef = headRef->left;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF && switchsignal == 1)
		{
			headRef = headRef->right;
		}
		else if(headRef->visited == OFF && headRef->left == NULL && headRef->right == NULL)
		{
			int m = 1;
			MakeNode(&newNode, headRef->data);
			headRef->left = newNode;
			(headRef->left)->visited = ON;
			(headRef->left)->parent = headRef;
			newNode = NULL;
			headRef->visited = ON;
			while(headRef->parent != NULL)
			{
				headRef = headRef->parent;
				if(headRef->left != NULL && headRef->right != NULL)
				{
					if((headRef->left)->visited == OFF || (headRef->right)->visited == OFF)
					{
						m = 0;
					}
					else if(m == 1)
					{
						MakeNode(&newNode, headRef->data);
						holder = headRef->left;
						holder->parent = newNode;
						headRef->left = newNode;
						(headRef->left)->visited = ON;
						(headRef->left)->parent = headRef;
						(headRef->left)->left = holder;
						newNode = NULL;
						headRef->visited = ON;
					}
				}
				else if(m == 1 && headRef->left == NULL)
				{
					MakeNode(&newNode, headRef->data);
					headRef->left = newNode;
					(headRef->left)->visited = ON;
					(headRef->left)->parent = headRef;
					newNode = NULL;
					headRef->visited = ON;
				}
				else if(m == 1)
				{
					MakeNode(&newNode, headRef->data);
					holder = headRef->left;
					holder->parent = newNode;
					headRef->left = newNode;
					(headRef->left)->visited = ON;
					(headRef->left)->parent = headRef;
					(headRef->left)->left = holder;
					newNode = NULL;
					headRef->visited = ON;
				}
			}
		}
		else
		{
			switchsignal = 0;
			headRef = headRef->parent;
		}
	}
}
	
void Mirror_Tree(struct node *headRef)
{
	short int OFF;
	short int ON;
	int switchsignal = 1;
	struct node *holder = NULL;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF && switchsignal == 1)
		{
			headRef = headRef->left;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF && switchsignal == 1)
		{
			headRef = headRef->right;
		}
		else if(headRef->visited == OFF && headRef->left == NULL && headRef->right == NULL)
		{
			int m = 1;
			headRef->visited = ON;
			while(headRef->parent != NULL)
			{
				headRef = headRef->parent;
				if(headRef->left != NULL && headRef->right != NULL)
				{
					if((headRef->left)->visited == OFF || (headRef->right)->visited == OFF)
					{
						m = 0;
					}
					else if(m == 1)
					{
						holder = headRef->left;
						headRef->left = headRef->right;
						headRef->right = holder;
						headRef->visited = ON;
					}
				}
				else if(m == 1)
				{
					headRef->visited = ON;
				}
			}
		}
		else
		{
			switchsignal = 0;
			headRef = headRef->parent;
		}
	}
}

int Same_Tree(struct node *head1, struct node *head2, int length, int length2, int depth, int depth2)
{
	int i;
	int array1[length];
	int array2[length2];
	int *ptr1 = &array1[0];
	int *ptr2 = &array2[0];
	memset(array1, 0, sizeof array1);
	memset(array2, 0, sizeof array2);
	GrabElem(head1, length, depth, ptr1);
	GrabElem(head2, length2, depth2, ptr2);
	if(length != length2)
	{
		return 0;
	}
	for(i = 0; i < length; i++)
	{
		if(array1[i] != array2[i])
		{
			return 0;
		}
	}
	return 1;
}
	
void ISBSTTESTER(struct node *headRef, int HIHOLDER, int LOHOLDER)
{
	int switchsignal = 1;
	int HI;
	int LO;
	short int ON;
	short int OFF;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	HI = HIHOLDER;
	LO = LOHOLDER;
	while(1)
	{
		/* printf("The current node is %d\n", headRef->data); */
		if(headRef->parent == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF && switchsignal == 1)
		{
			if(headRef == (headRef->parent)->left)
			{
				headRef = headRef->left;
				if(headRef->data <= LO && headRef->data <= HI)
				{
					HI = (headRef->parent)->data;
					LO = headRef->data;
				}
				else
				{
					printf("The binary tree is not searchable");
				}
			}
			else if(headRef == (headRef->parent)->right)
			{
				headRef = headRef->left;
				if(headRef->data <= LO && headRef->data > HI)
				{
					HI = (headRef->parent)->data;
					LO = headRef->data;
				}
				else
				{
					printf("The binary tree is not searchable");
				}
			}
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF && switchsignal == 1)
		{
			if(headRef == (headRef->parent)->left)
			{
				headRef = headRef->right;
				if(headRef->data > LO && headRef->data <= HI)
				{
					HI = (headRef->parent)->data;
					LO = headRef->data;
				}
				else
				{
					printf("The binary tree is not searchable");
				}
			}
			else if(headRef == (headRef->parent)->right)
			{
				headRef = headRef->right;
				if(headRef->data > LO && headRef->data > HI)
				{
					HI = (headRef->parent)->data;
					LO = headRef->data;
				}
				else
				{
					printf("The binary tree is not searchable");
				}
			}
		}
		else if(headRef->visited == OFF && headRef->left == NULL && headRef->right == NULL)
		{
			int m = 1;
			headRef->visited = ON;
			while((headRef->parent)->parent != NULL)
			{
				HI = (headRef->parent)->parent->data;
				LO = (headRef->parent)->data;
				headRef = headRef->parent;
				if(headRef->left != NULL && headRef->right != NULL)
				{
					if((headRef->left)->visited == OFF || (headRef->right)->visited == OFF)
					{
						m = 0;
					}
					else if(m == 1)
					{
						headRef->visited = ON;
					}
				}
				else if(m == 1)
				{
					headRef->visited = ON;
				}
			}
		}
		else
		{
			switchsignal = 0;
			headRef = headRef->parent;
		}
	}
	return;
}
	
void Is_Search_Tree(struct node *headRef)
{
	short int OFF;
	short int ON;
	int HIHOLDER;
	int LOHOLDER;
	struct node *holder = headRef;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	if(headRef == NULL)
	{
		printf("The tree is NULL.\n");
		return;
	}
	if(headRef != NULL)
	{
		if(headRef->left != NULL && headRef->data < (headRef->left)->data)
		{
			printf("The binary tree is not searchable");
			return;
		}
		if(headRef->right != NULL && headRef->data >= (headRef->right)->data)
		{
			printf("The binary tree is not searchable");
			return;
		}
		headRef->visited = ON;//This is needed since we will bypass the true headRef in the loop. If we were to run this tree again without exiting the calling function, all visited signal would have to be the same.
		HIHOLDER = headRef->data;
	}
	if(headRef->left != NULL)
	{
		headRef = headRef->left;
		LOHOLDER = headRef->data;
		ISBSTTESTER(headRef, HIHOLDER, LOHOLDER);
	}
	headRef = holder;
	if(headRef->right != NULL)
	{
		headRef = headRef->right;
		LOHOLDER = headRef->data;
		ISBSTTESTER(headRef, HIHOLDER, LOHOLDER);
	}
	printf("The tree is searchable.\n");
	return;
}
	

int getLength(struct node *headRef)
{
	short int OFF;
	short int ON;
	int count = 0;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF)
		{
			headRef = headRef->left;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF)
		{
			headRef = headRef->right;
		}
		else if(headRef->visited == OFF)
		{
			headRef->visited = ON;
			count++;
		}
		else
		{
			headRef = headRef->parent;
		}
	}
	return count;
}

void ElementSearch(struct node *headRef, int content, int *count)
{
	short int OFF;
	short int ON;
	if(headRef->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	while(1)
	{
		if(headRef == NULL)
		{
			break;
		}
		if(headRef->left != NULL && (headRef->left)->visited == OFF)
		{
			headRef = headRef->left;
		}
		else if(headRef->right != NULL && (headRef->right)->visited == OFF)
		{
			headRef = headRef->right;
		}
		else if(headRef->visited == OFF)
		{
			if(headRef->data == content)
			{
				(*count)++;
			}
			headRef->visited = ON;
		}
		else
		{
			headRef = headRef->parent;
		}
	}
}

void MakeNode(struct node **headRef, int data)
{
	struct node *newNode = NULL;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->visited = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	*headRef = newNode;
	return;
}

void freeElements(struct node **headRef)
{
	struct node *holder = *headRef;
	short int OFF;
	short int ON;
	if((*headRef)->visited == 0)
	{
		OFF = 0;
		ON = 1;
	}
	else
	{
		OFF = 1;
		ON = 0;
	}
	while(1)
	{
		if(*headRef == NULL)
		{
			break;
		}
		if((*headRef)->left != NULL && ((*headRef)->left)->visited == OFF)
		{
			*headRef = (*headRef)->left;
		}
		else if((*headRef)->right != NULL && ((*headRef)->right)->visited == OFF)
		{
			*headRef = (*headRef)->right;
		}
		else if((*headRef)->visited == OFF)
		{
			(*headRef)->visited = ON;
			holder = *headRef;
		}
		else
		{
			*headRef = (*headRef)->parent;
			free(holder);
		}
	}
}
