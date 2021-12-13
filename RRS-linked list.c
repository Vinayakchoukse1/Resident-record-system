#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// variable to keep track of total data entered of residents
int count=1;
// structure for resident data
struct node
{
	struct accommodation
	{		
		char firstname[50];
		char lastname[50];
		char accommodation_type[20];
		int idtype;
		struct idnum
		{	
			char aadhaar[15];
			char passport[15];
			char empcode[15];
		}p;
		char address[100];
	}A;
	struct node *next;
};
// function to create node for the resident list
struct node *create()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = NULL;
	return(ptr);
}
// Function to print ALL the data
void printData(struct node *head)
{
	printf("\n Printing the record\n");
	struct node *ptr = head;
	if(ptr != NULL)
	{
		count=1;
		while(ptr != NULL)
		{
			if(ptr->A.idtype == 0)
			{
				printf("\n data of resident %d \n",count);
				printf("\n\nFirst_name = %s",ptr->A.firstname);
				printf("\nLast_name = %s",ptr->A.lastname);
				printf("\nAccommodation_tpye = %s",ptr->A.accommodation_type);
				printf("\nidtpye = %d\n",ptr->A.idtype);
				printf("Aadhaar and address = %s",ptr->A.p.aadhaar);
			}
			else if(ptr->A.idtype == 1)
			{
				printf("\n data of resident %d \n",count);
				printf("\n\nFirst_name = %s",ptr->A.firstname);
				printf("\nLast_name = %s",ptr->A.lastname);
				printf("\nAccommodation_tpye = %s",ptr->A.accommodation_type);
				printf("\nidtpye = %d\n",ptr->A.idtype);
				printf("Passport and address = %s",ptr->A.p.passport);
			}
			else if(ptr->A.idtype == 2)
			{
				printf("\n data of resident %d \n",count);
				printf("\n\nFirst_name = %s",ptr->A.firstname);
				printf("\nLast_name = %s",ptr->A.lastname);
				printf("\nAccommodation_tpye = %s",ptr->A.accommodation_type);
				printf("\nidtpye = %d\n",ptr->A.idtype);
				printf("Empcode and address= %s",ptr->A.p.empcode);
			}
			printf("\nAddress = %s",ptr->A.address);
			ptr = ptr->next;
			count++;
		}
	}
	else
	{
		printf("\nRecords are empty.\n");
	}
}	

// Function to insert the data
void InsertRecord(struct node **head)
{
	printf("\n Enter the data for resident no %d \n",count);
	int i=0;
	struct node *temp,*ptr = create();
	temp = *head;
	if(*head == NULL)
	{
		*head = ptr;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
	// scanning first name
	printf("\nFirst_name = ");
	scanf("%s",ptr->A.firstname);
	// scanning last name
	printf("Last_name = ");
	scanf("%s",ptr->A.lastname);
	// scanning accoommodation type
	printf("Accommodation_tpye = ");
	scanf("%s",ptr->A.accommodation_type);
	// scanning idtype
	printf("idtpye = ");
	scanf("%d",&ptr->A.idtype);
	// scannin aadhar 
	if(ptr->A.idtype == 0)
	{
		printf("Aadhaar and address = ");
		scanf("%s ",ptr->A.p.aadhaar);
	}
	// scanning passport
	if(ptr->A.idtype == 1)
	{
		printf("Passport and address = ");
		scanf("%s ",ptr->A.p.passport);	
	}
	// scanning employcode
	if(ptr->A.idtype == 2)
	{
		printf("Empcode and address= ");
		scanf("%s ",ptr->A.p.empcode);
	}
	// scanning adress
	
	scanf("%[^\n]s ",ptr->A.address);
	count++;
}

// Function to remove duplicates
void removeDuplicates(struct node **head)
{
	struct node *ptr1,*ptr2,*temp,*prev;
	ptr1 = *head;
 	int flag=0;
	// checking if list empty
	if(ptr1 != NULL)
	{
		// traversing the list
		while(ptr1 != NULL)
		{
			prev = ptr1;
			ptr2 = ptr1->next;
			while(ptr2 != NULL)
			{
				flag=0;
				// checking if the first name , last name , accoo type, adresss are same
				if(strcmp(ptr1->A.firstname,ptr2->A.firstname)==0 && strcmp(ptr1->A.lastname,ptr2->A.lastname)==0 && 
				strcmp(ptr1->A.accommodation_type,ptr2->A.accommodation_type)==0 && strcmp(ptr1->A.address,ptr2->A.address)==0) 
				{
					flag=1;
					// checking if the id type is saame
					if(ptr1->A.idtype == ptr2->A.idtype)
					{
						// checking if the id is same 
						if(ptr1->A.idtype == 0 && strcmp(ptr1->A.p.aadhaar,ptr2->A.p.aadhaar) != 0)
						{
							flag=0;
						}
						else if(ptr1->A.idtype == 1 && strcmp(ptr1->A.p.empcode,ptr2->A.p.empcode) == 0)
						{
							flag=0;
						}
						else if(ptr1->A.idtype == 2 && strcmp(ptr1->A.p.passport,ptr2->A.p.passport) != 0)
						{
							flag=0;
						}
					}
				}
				// when found we free the node
				if(flag==1)
				{
					temp = ptr2;
					prev->next = ptr2->next;
					ptr2 = ptr2->next;
					free(temp);
				}
				else
				{
					prev = ptr2;
					ptr2 = ptr2->next;
				}
			}
			ptr1 = ptr1->next;
		}
		printf("\nDuplicate records are deleted sucessfully");
	}
	else
	{
		printf("Records are empty.");
	}
}

// Function to print data in  Aadhaar-> passport-> employcode order
void printRecords(struct node *head)
{
	struct node *ptr;
	int i=0;
	// traversing while three times two gest them printed in order
	while(i<3)
	{
		ptr = head;
		while(ptr != NULL)
		{
			if(ptr->A.idtype == i)
			{
				printf("\n\nFirst_name = %s",ptr->A.firstname);
				printf("\nLast_name = %s",ptr->A.lastname);
				printf("\nAccommodation_tpye = %s",ptr->A.accommodation_type);
				printf("\nidtpye = %d\n",ptr->A.idtype);
		
				if(i == 0)
				{
					printf("Aadhaar and address = %s",ptr->A.p.aadhaar);
				}
				else if(i == 1)
				{
					printf("Passport and address = %s",ptr->A.p.passport);
				}
				else if(i == 2)
				{
					printf("Empcode and address= %s",ptr->A.p.empcode);
				}
				printf("\nAddress = %s",ptr->A.address);
			}
			ptr = ptr->next;
		}
		i++;
	}
}
// structure for index
struct node_with_index
{
	struct accommodation A;
	int index;
	struct node_with_index *next;
}*ihead = NULL;
// a variable to count the lenth of the index list
int LL_count=0;
// Function to create index list node
struct node_with_index *create_inode()
{
	struct node_with_index *ptr = (struct node_with_index*)malloc(sizeof(struct node_with_index));
	ptr->next = NULL;
	ptr->index = -1;
	return(ptr);
}
// Function to print sorted list
void printSortedRecords(struct node *head)
{
	struct node_with_index *iptr,*lptr,*lPrev,*temp;
	int i=0;
	
	if(ihead == NULL)
	{
		// assigning the values to index list
		// creating first node
		iptr = create_inode();
		ihead = iptr;
		iptr->A = head->A;
		head = head->next;
		while(head != NULL)	
		{
			iptr->next = create_inode();
			iptr = iptr->next;
			iptr->A = head->A;
			head = head->next;
			i++;
		}
		LL_count = i+1;
		iptr = ihead;
		//tracking the index for the sorted oreder
		for(i=0;i<LL_count;i++)
		{
			temp = ihead;
			while(temp != NULL && temp->index != -1)
			{
				temp = temp->next;
			}
			
			lptr = temp->next;
			while(lptr != NULL)
			{
				if(lptr->index == -1)
				{
					if(strcmp(temp->A.firstname,lptr->A.firstname) > 0)
					{
						temp = lptr;
					}	
					else if(strcmp(temp->A.firstname,lptr->A.firstname) == 0 && strcmp(temp->A.lastname,lptr->A.lastname) > 0)
					{
						temp = lptr;
					}
				}
				lptr = lptr->next;
			}
			temp->index = i;
		}
	}
	
	i=0;
	iptr = ihead;
	// printing them in sorted order using index list
	while(i != LL_count)
	{
		iptr = ihead;
		while(iptr != NULL && iptr->index != i)
		{
			iptr = iptr->next;
		}
		
		if(iptr->A.idtype == 0)
		{
			printf("\n\nFirst_name = %s",iptr->A.firstname);
			printf("\nLast_name = %s",iptr->A.lastname);
			printf("\nAccommodation_tpye = %s",iptr->A.accommodation_type);
			printf("\nidtpye = %d\n",iptr->A.idtype);
			printf("Aadhaar and address = %s",iptr->A.p.aadhaar);
		}
		else if(iptr->A.idtype == 1)
		{
			printf("\n\nFirst_name = %s",iptr->A.firstname);
			printf("\nLast_name = %s",iptr->A.lastname);
			printf("\nAccommodation_tpye = %s",iptr->A.accommodation_type);
			printf("\nidtpye = %d\n",iptr->A.idtype);
			printf("Passport and address = %s",iptr->A.p.passport);
		}
		else if(iptr->A.idtype == 2)
		{
			printf("\n\nFirst_name = %s",iptr->A.firstname);
			printf("\nLast_name = %s",iptr->A.lastname);
			printf("\nAccommodation_tpye = %s",iptr->A.accommodation_type);
			printf("\nidtpye = %d\n",iptr->A.idtype);
			printf("Empcode and address= %s",iptr->A.p.empcode);
		}
		printf("\nAddress = %s",iptr->A.address);
		i++;
	}
}
// Function to Search for a data
void search(struct node *head,char first_name[],char last_name[])
{
	int flag=0;
	// Traversing the list
	while(head != NULL)
	{
		// if the name matches we simple print the data
		if(strcmp(head->A.firstname,first_name) ==0 && strcmp(head->A.lastname,last_name) == 0)
		{
			flag=1;
			if(head->A.idtype == 0)
			{
				printf("\n\nFirst_name = %s",head->A.firstname);
				printf("\nLast_name = %s",head->A.lastname);
				printf("\nAccommodation_tpye = %s",head->A.accommodation_type);
				printf("\nidtpye = %d\n",head->A.idtype);
				printf("Aadhaar and address = %s",head->A.p.aadhaar);
			}
			else if(head->A.idtype == 1)
			{
				printf("\n\nFirst_name = %s",head->A.firstname);
				printf("\nLast_name = %s",head->A.lastname);
				printf("\nAccommodation_tpye = %s",head->A.accommodation_type);
				printf("\nidtpye = %d\n",head->A.idtype);
				printf("Passport and address = %s",head->A.p.passport);
			}
			else if(head->A.idtype == 2)
			{
				printf("\n\nFirst_name = %s",head->A.firstname);
				printf("\nLast_name = %s",head->A.lastname);
				printf("\nAccommodation_tpye = %s",head->A.accommodation_type);
				printf("\nidtpye = %d\n",head->A.idtype);
				printf("Empcode and address= %s",head->A.p.empcode);
			}
			printf("\nAddress = %s",head->A.address);
			return;
		}
		head = head->next;
	}
	// no record found
	if(flag==0)
	{
		printf("\n No record found\n");
	}
}
// Function to delete record
void deleteRecord(struct node **head,int Id_Type,char id[])
{
	struct node *temp,*ptr,*prev;
	int flag=0,n;
	ptr = *head;
	prev = NULL;
	while(ptr != NULL)
	{
		// Searching for the idtype
		if(Id_Type == ptr->A.idtype)
		{
			if(ptr->A.idtype == 0)
			{
				if(strcmp(ptr->A.p.aadhaar,id) == 0)
				{
					flag=1;
				}
			}
			else if(ptr->A.idtype == 1)
			{
				if(strcmp(ptr->A.p.passport,id) == 0)
				{
					flag=1;
				}
			}
			else if(ptr->A.idtype == 2)
			{
				if(strcmp(ptr->A.p.empcode,id) == 0)
				{
					flag=1;
				}
			}
			// updating the index list and deleting the node
			if(flag==1)
			{
				if(ptr == *head)
				{
					*head = ptr->next;
				}
				else
				{
					prev->next = ptr->next;
				}
				struct node_with_index *iptr,*iprev;
				iptr = ihead;
				iprev = NULL;
				if(iptr != NULL)
				{
					while(strcmp(iptr->A.firstname,ptr->A.firstname) != 0 || strcmp(iptr->A.lastname,ptr->A.lastname) != 0)
					{
						iprev = iptr;
						iptr = iptr->next;	
					}
					n = iptr->index;
					if(iprev != NULL)
					{
						iprev->next = iptr->next;
					}
					else
					{
						ihead = iptr->next;
					}
					struct node_with_index *f = iptr;
					free(f);
					LL_count--;
						
					iptr = ihead;
					
					while(iptr != NULL)
					{
						if(iptr->index > n)
						{
							iptr->index = iptr->index - 1;
						}
						iptr = iptr->next;
					}
					
				}
				free(ptr);
				return;
			}
		}
		prev = ptr;
		ptr = ptr->next;
	}
	printf("no record found to be deleted");
	
}
// Function to update a data
void updateRecord(struct node *head,char first_name[],char last_name[])
{
	int iIndex,flag=1,i=0;
	struct node *ptr;
	struct node_with_index *iptr,*p;
	ptr = head;
	iptr = ihead;
	// Finding the node whith given entry
	while(ptr != NULL && (strcmp(first_name,ptr->A.firstname) != 0 || strcmp(last_name,ptr->A.lastname) != 0))
	{
		ptr = ptr->next;
		iptr = iptr->next;
	}
	if(ptr != NULL)
	{
		int choice=1;
		while(choice!=0)
		{
			printf("\n\nSelect ur choice");
			printf("\n1. Firstname \n2. Lastname \n3. Accomodation Type \n4. Id Type \n5. Address\n");
			printf("choice = ");
			scanf("%d",&choice);
		
		switch(choice)	
		{
			// for updating first name
			case 1:		
				printf("\nEnter new Firstname : ");
				scanf("%s",first_name);
				strcpy(ptr->A.firstname,first_name);
				strcpy(iptr->A.firstname,first_name);
				// Updating the index list
				iIndex = iptr->index;
				p = ihead;
				while(p != NULL)
				{
					if(strcmp(p->A.firstname,iptr->A.firstname) < 0)
					{
						i++;
					}
					if(strcmp(p->A.firstname,iptr->A.firstname) == 0 && strcmp(p->A.lastname,iptr->A.lastname) < 0 )
					{
						i++;
					}
					p = p->next;	
				}
				p = ihead;
				if(iIndex > i)
				{
					while(p != NULL)
					{
						if(p->index >= i && p->index < iIndex)
						{
							p->index = p->index + 1;
						}
						p = p->next;
					}
					iptr->index = i;
				}
				if(iIndex < i)
				{
					while(p != NULL)
					{
						if(p->index <= i && p->index > iIndex)	
						{
							p->index = p->index - 1;
						}
						p = p->next;
						iptr->index = i;
					}
				}
				p = ihead;
				while(p != NULL)
				{
					p=p->next;
				}
				break;
			// updating last name
			case 2:
				printf("\nEnter new Lastname : ");
				scanf("%s",last_name);
				strcpy(ptr->A.lastname,last_name);
				strcpy(iptr->A.lastname,last_name);
				
				iIndex = iptr->index;
				p = ihead;
				while(p != NULL)
				{
					if(strcmp(p->A.firstname,iptr->A.firstname) < 0)
					{
						i++;
					}
					if(strcmp(p->A.firstname,iptr->A.firstname) == 0 && strcmp(p->A.lastname,iptr->A.lastname) < 0 )
					{
						i++;
					}
					p = p->next;	
				}
				p = ihead;
				if(iIndex > i)
				{
					while(p != NULL)
					{
						if(p->index <= i && p->index > iIndex)
						{
							p->index = p->index + 1;
						}
						p = p->next;
					}
					iptr->index = i;
				}
				if(iIndex < i)
				{
					while(p != NULL)
					{
						if(p->index <=i && p->index > iIndex)	
						{
							p->index = p->index - 1;
						}
						iptr->index = i;
					}
				}
				break;
			// updating accommodation type
			case 3:
				printf("\nEnter the new Accomodation type = ");
				scanf("%s",first_name);
				strcpy(ptr->A.accommodation_type,first_name);
				strcpy(iptr->A.accommodation_type,first_name);
				break;
			// updating id type
			case 4:
				printf("\nEnter the Idtype = ");
				scanf("%d",&ptr->A.idtype);
				iptr->A.idtype = ptr->A.idtype;
				if(ptr->A.idtype == 0)
				{
					printf("Enter Aadhaar no. = ");
					scanf("%s",ptr->A.p.aadhaar);
					strcpy(iptr->A.p.aadhaar,ptr->A.p.aadhaar);
				}
				else if(ptr->A.idtype == 1)
				{
					printf("Enter Passport no. = ");
					scanf("%s",ptr->A.p.aadhaar);
					strcpy(iptr->A.p.aadhaar,ptr->A.p.aadhaar);
				}
				else if(ptr->A.idtype == 2)
				{
					printf("Enter Empcode no. = ");
					scanf("%s",ptr->A.p.empcode);
					strcpy(iptr->A.p.empcode,ptr->A.p.empcode);
				}
				else
				{
					printf("\nInvalid ID Type");
				}
				break;
				// updating address
			case 5:
				printf("\nEnter new Address : ");
				scanf("%[^\n]s ",ptr->A.address);
				strcmp(iptr->A.address,iptr->A.address);
		}
		}
		
	}
	else
	{
		printf("no record found");
	}
}
// structure for accommodation type
struct status
{
	int status;
	struct status *next;
}*head1[4] = {NULL};
// Function for creating node for accomodation typr
struct  status *create_acc()
{
	struct status *anode = (struct status*)malloc(sizeof(struct status));
	anode->status = 0;
	anode->next = NULL;
	return(anode);
} 
// function to input  accomodation for block type
void insert_accomodation()
{
	int i,j;
	struct status *anode;
	
	printf("\n\nEnter data in accomodation list");
	printf("\n\nEnter 1 if the block is accomodated and 0 if it is not accommodated.");
	// 4 tupes of accomodation
	for(i=0;i<4;i++)
	{
		printf("\n\nType%d Blocks :",i+1);
		head1[i] = create_acc();
		anode = head1[i];
		printf("\nBLock 0 = ");
		scanf("%d",&anode->status);
		// 10 blocks of each accommodation type
		for(j=1;j<10;j++)
		{
			anode->next = create_acc();
			anode = anode->next;
			printf("BLock %d = ",j);
			scanf("%d",&anode->status);
		}
	}
}

// function for special request accoomodation
void specialRequestAllocation()
{
	insert_accomodation();
	struct status *anode,*prev,*nptr;
	int old,New,index,i=0;
	printf("Enter the Type of the block whose type you want to change. \nold = ");
	scanf("%d",&old);
	printf("Enter the index of the block");
	scanf("%d",&index);
	printf("Enter the new type of the block = ");
	scanf("%d",&New);
	

}

int main()
{
	int i=1,choice;
	char first_name[50],last_name[50],ID[15];
	struct node *head;
	head = NULL;
	
	while(choice != 9)
	{
		printf("\n\nEnter the operation no. that you want to be performed.");
		printf("\n0. Print data");
		printf("\n1. Insert data");
		printf("\n2. Remove duplicates");
		printf("\n3. Print according to Aadhar->Passport->Empcode");
		printf("\n4. Print in sorted way");
		printf("\n5. Search a data");
		printf("\n6. Delete a certain data");
		printf("\n7. Update a data");
		printf("\n8. Special request allocation");
		
		printf("\n9. Exit");
		printf("\nChoice = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printData(head);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 1:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				while(i!=0)
				{	
					InsertRecord(&head);
					printf("\nDo you want to add another entry : ");
					scanf("%d",&i);		
				}
				printf("\n values have been added\n-------------------------------------------------------------------------------\n");
				break;
				
			case 2:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				removeDuplicates(&head);
				printf("\n Duplicates removed\n---------------------------------------------------------------------------------------\n");
				break;
			
			case 3:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nPrinting according to Aadhar->Passport->Empcode\n");
				printRecords(head);	
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 4:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printSortedRecords(head);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
				
			case 5:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nEnter the firstname and lastname of the person whose data you want to print");
				scanf("%s %s",first_name,last_name);
				search(head,first_name,last_name);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			
			case 6:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nEnter the id type and IdNo. of the person whose data you want to delete.");
				printf("\nId Type = ");
				scanf("%d",&i);
				printf("Id no. = ");
				scanf("%s",ID);
				deleteRecord(&head,i,ID);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
				
			case 7:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nEnter the firstname and lastname of the person whose record you want to update.");
				scanf("%s %s",first_name,last_name);
				updateRecord(head,first_name,last_name);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			
			case 8:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				specialRequestAllocation();
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 9:
				exit(0);
				
			default: 
				printf("Invalid Choice");
		}
	}
	return(0);
}
