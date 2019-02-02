//Mahdiul Chowdhury email: mahdiulc@bu.edu 
//Code will read input from a file and write to a file...

//uint	0 to 4,294,967,295	Unsigned 32-bit integer
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "bits.h"

//void sort_function( struct node_t **current_HEAD);
typedef struct Node 
{
	unsigned int data;
	char* string;  
	unsigned int count;
	struct Node *next; 

} node_t; 

int main(int argc, char *argv[]) 
{
	
	unsigned int* array =  (unsigned int*)malloc(100*sizeof(unsigned int));
	node_t *HEAD = NULL; 
	node_t *temp = NULL;
	node_t *temp_two = NULL;
	node_t *n = NULL;  
	
	int i = 0;
	int j = 0;
	int number; 
	FILE *fptr; //file pointer
	FILE *fptr_close;//File pointer 
	fptr = fopen(argv[1], "r"); //reading from file 
	fptr_close = fopen(argv[2], "w");//wrtting to file

	if ((!fptr) || (!fptr_close)) //error checking
	{
		printf("Can't open the file\n");
	}
	//This while loop will read from the file, send the data to Binary Mirror and sequeence count. Both of this function 
	//will return binary mirror and count. Usign return value, I am creating a linked list. 
	while (fscanf(fptr,"%d", &number) != EOF) //read untill the end of the file
	{
		temp = (node_t*)malloc(sizeof(node_t)); 
		//printf("%d\n", number);
		temp->data=BinaryMirror(number);
		temp->count = SequenceCount(number);
		temp->string= (char*)malloc(11*sizeof(char)); 
		sprintf(temp->string,"%u",temp->data);
		temp->next = NULL; 
		if (HEAD == NULL) 
		{

			HEAD = temp; 
			n=temp; 
			temp = NULL;
		}
		else 
		{
			n->next = temp; 
			n = temp; 
		}
			
	}
	temp_two = (node_t*)malloc(sizeof(node_t));
	//temp_three = (node_t*)malloc(sizeof(node_t));
	//sort_function(&HEAD); 
	node_t* tempHead = HEAD;

	char *string_temp;
	node_t* HeadPtr = tempHead;
	node_t* insertionPtr = HeadPtr;
	
	tempHead = tempHead->next;
	//In this while loop, using insertion sort I am sorting the linked list using string comparator, at the same time I am swapping the count and data attribute of the struct. 
	while (tempHead != NULL)
	{
		insertionPtr = HeadPtr;
		while (insertionPtr->next != tempHead)
		{	
			int return_value = strcmp(insertionPtr->string, tempHead->string);
					if (return_value>0) 
						{
						 	string_temp = tempHead->string; 
							unsigned int temp = tempHead->data; 
							unsigned int temp_count = tempHead->count;

							tempHead->string = insertionPtr->string;
							tempHead->data =  insertionPtr->data; 
							tempHead->count = insertionPtr->count;

							insertionPtr->string = string_temp;
							insertionPtr->data = temp;
							insertionPtr->count = temp_count;  
							//printf("inser:%s\n",insertionPtr->string);
						}
					else
					{
						insertionPtr = insertionPtr->next;
					}
		} 
		tempHead = tempHead->next;
		
	}
	 
	temp_two = HEAD;
	fprintf(fptr_close,"%s\t\t","Mirror");
	fprintf(fptr_close,"%s\n","Count");
	//in this while loop I am writing to the file. 
	while (temp_two != NULL)
	{
		//printf("%u\t",temp_two->data);
		//printf("%s\n",temp_two->string);
		fprintf(fptr_close,"%u\t",temp_two->data);
		fprintf(fptr_close,"%u\n",temp_two->count);
		temp_two = temp_two->next; 

	}
	 
	//closing the file
	fclose(fptr);
	fclose(fptr_close);
}


/*void sort_function( struct Node **current_HEAD)
{
	node_t* head = current_HEAD;
	node_t* insertionPointer = head; 
	current_HEAD = current_HEAD->next; 
	
	while (current_HEAD != NULL) 
	{
		insertionPointer = current_HEAD;
			while(insertionPointer !=  current_HEAD) 
				{
					unsigned int return_value = strcpy(insertionPointer->data, current_HEAD->data);
					if (return_value>0) 
						{
						 	int temp = current->data; 
							current->data = insertionPointer->data; 
							insertionPointer->data = temp; 

						}
					else 
						{
							insertionPointer = insertionPointer->next; 
						}
					
				}
	}
	//return current_HEAD;
}*/














