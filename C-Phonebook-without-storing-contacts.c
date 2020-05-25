/* Levi Hazelwood
CES 130
Lab 8
10/17/2019
The purpose of this program is to create an editable phonebook using structures and memory functions*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct phonum
{
	char fname[50];
	char lname[50];
	char phone[50];
};

int main()
{
	struct phonum p;
	
	char ffname[50];
	char flname[50];
	char fphone[50];
	
	
	int counter = 1;
	struct phonum *arrayofnumbers = malloc(counter *sizeof(struct phonum));
	
	FILE* phonefile = fopen("phone.txt", "r");
	int x, numlines, i = 0; 

	
	while (!feof (phonefile))
	{
		
		if(fscanf(phonefile, "%s %s %s\n", ffname, flname, fphone)==-1){
		break;}
		
		arrayofnumbers = realloc(arrayofnumbers, counter *sizeof(struct phonum));
		
		strcpy(arrayofnumbers[x].fname, ffname);
		strcpy(arrayofnumbers[x].lname, flname);
		strcpy(arrayofnumbers[x].phone, fphone);
		
		x++;
		counter++;
	}
	
	int choice = 1;
	while (choice != 0)
	{
		
		printf("\n1) Add a phone number\n2) Delete a number\n3) Show phone book\n4) Sort names\n5) Find a number\n6) Randomly select number\n7) Delete all contacts\n0) Exit");
		printf("\n\nWhat would you like to do? ");
		scanf("%d", &choice);

		
		if (choice == 1)
		{
			arrayofnumbers = realloc(arrayofnumbers,counter * sizeof(struct phonum));
			
			
			
			printf("\nEnter the first name: ");
			scanf("%s", &p.fname);
			
			printf("\nEnter the last name: ");
			scanf("%s", &p.lname);
			
			printf("\nEnter the phone number: ");
			scanf("%s", &p.phone);
			
			
			strcpy(arrayofnumbers[counter-1].fname, p.fname);
			strcpy(arrayofnumbers[counter-1].lname, p.lname);
			strcpy(arrayofnumbers[counter-1].phone, p.phone);
			
			counter++;
			
		}
		if (choice ==2)
		{
			char fname[25];
			char lname[25];
			printf("\nEnter first name to delete: ");
			scanf("%s", fname);
			
			printf("\nEnter last name to delete: ");
			scanf("%s", lname);
			
			int d;
			int t;
			int checkcout = counter;
			for(d=0; d<counter-1; d++)
			{
					if (strcmp(fname, arrayofnumbers[d].fname)==0 && strcmp(lname, arrayofnumbers[d].lname)==0)
					{
						 strcpy(arrayofnumbers[d].fname, arrayofnumbers[counter-2].fname);
						 strcpy(arrayofnumbers[d].lname, arrayofnumbers[counter-2].lname);
						 strcpy(arrayofnumbers[d].phone, arrayofnumbers[counter-2].phone);
						 
						 counter--;
						 arrayofnumbers = realloc(arrayofnumbers,counter * sizeof(struct phonum));	
					}
			}
			if (counter == checkcout)
			{
				printf("\nFailure, please try again\n");
			}
			else
			{
				printf("\nSuccess\n");
			}
		}
		if (choice == 3)
		{
			int i;
			for(i = 0; i < counter-1; i++)
			{
				printf("\nFirst Name: %s\n", arrayofnumbers[i].fname);
				printf("Last Name: %s\n", arrayofnumbers[i].lname);
				printf("Phone Number: %s\n", arrayofnumbers[i].phone);
				
			}
		
			
		}
		if (choice == 4)
		{
			char arr[50] ;
			int d;
			int t;
			
			for (d=0; d<counter-1; d++)
			{
				for (t=d+1; t<counter-1; t++)
				{
					if(strcmp(arrayofnumbers[t].lname, arrayofnumbers[d].lname)<0)
					{
					strcpy(arr,arrayofnumbers[t].lname);
					strcpy(arrayofnumbers[t].lname,arrayofnumbers[d].lname);
					strcpy(arrayofnumbers[d].lname,arr);
					
					strcpy(arr,arrayofnumbers[t].fname);
					strcpy(arrayofnumbers[t].fname,arrayofnumbers[d].fname);
					strcpy(arrayofnumbers[d].fname,arr);
					
					strcpy(arr,arrayofnumbers[t].phone);
					strcpy(arrayofnumbers[t].phone,arrayofnumbers[d].phone);
					strcpy(arrayofnumbers[d].phone,arr);
					
					}
				}
			}
		}
	
		if (choice == 5)
		{
			char fname[25];
			char lname[25];
			printf("\nEnter first name: ");
			scanf("%s", fname);
			
			printf("\nEnter last name: ");
			scanf("%s", lname);
			
			int d;
			int t;
			for(d=0; d<counter-1; d++)
			{
					if (strcmp(fname, arrayofnumbers[d].fname)==0 && strcmp(lname, arrayofnumbers[d].lname)==0)
					{
						printf("\nFirst Name: %s\n", arrayofnumbers[d].fname);
						printf("Last Name: %s\n", arrayofnumbers[d].lname);
						printf("Phone Number: %s\n", arrayofnumbers[d].phone);
					}
			}
		}
		if(choice == 6)
		{
			srand(time(NULL));
			int random = (rand()%(counter-1));
			
			printf("\nFirst Name: %s\n", arrayofnumbers[random].fname);
			printf("Last Name: %s\n", arrayofnumbers[random].lname);
			printf("Phone Number: %s\n", arrayofnumbers[random].phone);
		}
		if (choice == 7)
		{
			arrayofnumbers = realloc(arrayofnumbers,0 * sizeof(struct phonum));
			counter = 1;
		}
	}	
	if (choice == 0 )
	{
		printf("Goodbye");
	}
	close(phonefile);
	
	FILE* phonefile2 = fopen("phone.txt", "w");
	
	int i2;
	
	for(i = 0; i < counter-1; i++)
		{
			fprintf(phonefile2, "%s %s %s\n", arrayofnumbers[i].fname, arrayofnumbers[i].lname, arrayofnumbers[i].phone);
			
		}
	close(phonefile2);
	return 0;
}
