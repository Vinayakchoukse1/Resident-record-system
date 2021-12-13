/*
	Topic      : DSPD-2-HW-ASSIGNMENT-2
	Name       : VINAYAK CHOUKSE
	Roll No    : BT19CSE120
	Date       : 10-04-21 18:04
	Description: AVL TREE IS BEEN USED
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<stdbool.h>

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
};

void acc_to_acc(struct accommodation *A,struct accommodation *B)
{
	strcpy(A->firstname,B->firstname);
	strcpy(A->lastname,B->lastname);
	strcpy(A->accommodation_type,B->accommodation_type);
	A->idtype = B->idtype;
	if(B->idtype == 0)
	{
		strcpy(A->p.aadhaar,B->p.aadhaar);
	}
	else if(B->idtype == 1)
	{
		strcpy(A->p.passport,B->p.passport);
	}
	else if(B->idtype == 2)
	{
		strcpy(A->p.empcode,B->p.empcode);
	}
	strcpy(A->address,B->address);
}

struct accommodation_status initialize_acc();
struct accommodation_status
{
	int *A,*B,*C,*D;
	int size[4];
}acc_status;

struct accommodation_status initialize_acc()
{
	struct accommodation_status acc;
	int i;
	
	acc_status.A = (int*)malloc(10*sizeof(int));
	acc_status.B = (int*)malloc(10*sizeof(int));
	acc_status.C = (int*)malloc(10*sizeof(int));
	acc_status.D = (int*)malloc(10*sizeof(int));
	
	for(i=0;i<4;i++)
	{
		acc_status.size[i] = 10;
	}
	for(i=0;i<10;i++)
	{
		acc_status.A[i] = 0;
		acc_status.B[i] = 0;
		acc_status.C[i] = 0;
		acc_status.D[i] = 0;
	}
	return(acc);
}

void print_accommoadtion_status()
{
	int i,j;
	for(j=0;j<4;j++)
	{
		switch(j)
		{
			case 0:
				printf("\nType-A Blocks\n\n");
				for(i=0;i<acc_status.size[j];i++)
				{
					printf("A%d = %d\n",i+1,acc_status.A[i]);
				}
				break;
			case 1:
				printf("\nType-B Blocks\n\n");
				for(i=0;i<acc_status.size[j];i++)
				{
					printf("B%d = %d\n",i+1,acc_status.B[i]);
				}
				break;
			case 2:	
				printf("\nType-C Blocks\n\n");
				for(i=0;i<acc_status.size[j];i++)
				{
					printf("C%d = %d\n",i+1,acc_status.C[i]);
				}
				break;
			case 3:	
				printf("\nType-D Blocks\n\n");
				for(i=0;i<acc_status.size[j];i++)
				{
					printf("D%d = %d\n",i+1,acc_status.D[i]);
				}
				break;		
		}
	}
	
}

int charToInt(char s[])
{
	int i=1,val=0;
	while(s[i] != '\0')
	{
		val = val*10 + s[i] - 48;
		i++;
	}
	return(val);
}

int allocateBlock(char s[])
{
	int flag=0;
	int index;
	
	if(s[0] < 65 || s[0] > 68 || s[1] < 49 || s[1] > 57 || s[2] != '\0')  
	{
		if(s[1] == '1' && s[2] == '0' && s[3] == '\0')
		{
			flag=0;
		}
		else
		{
			return(-1);
		}
	}
	
	index = charToInt(s)-1;
	printf("Index = %d",index);
	switch(s[0])	
	{
		case 'A':
			printf("InA");
			if(acc_status.A[index] == 0) 
			{
				printf("In A");
				acc_status.A[index] = 1;
				flag=1;
			}
			break;
			
		case 'B':
			if(acc_status.B[index] == 0) 
			{
				acc_status.B[index] = 1;
				flag=1;
			}	
			break;
		case 'C':
			if(acc_status.C[index] == 0) 
			{
				acc_status.C[index] = 1;
				flag=1;
			}
			break;
			
		case 'D':
			if(acc_status.D[index] == 0) 
			{
				acc_status.D[index] = 1;
				flag=1;
			}
			break;
			
		default:
			return(-1);
	}
	return(flag);
}
	 
void deallocateBlock(char s[])
{
	int index = charToInt(s);
	
	printf("In deallocate");
	switch(s[0])	
	{
		case 'A':
			printf("Astatus = 0");
			acc_status.A[index] = 0;
			printf("stat = %d",acc_status.A[index]);
			break;
			
		case 'B':
			printf("Bstatus = 0");
			acc_status.B[index] = 0;
			break;
			
		case 'C':
			printf("Cstatus = 0");
			acc_status.C[index] = 0;
			break;
			
		case 'D':
			printf("Dstatus = 0");
			acc_status.D[index] = 0;
			break;
		default:
			printf("The person whose record we are deleting was not accommodated any block");;
			return;
	}	
}

struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
	int height;
	struct accommodation A;
};

int max(int a, int b);
int height(struct tree *N)
{
	if (N == NULL)
		return 0;
	return (N->height);
}

int max(int a, int b)
{
	if(a>b)
	{
		return(a);
	}
	else
	{
		return(b);
	}
}

struct tree* newtree(int key)
{
	struct tree* tree = (struct tree*)
						malloc(sizeof(struct tree));
	tree->key = key;
	tree->left = NULL;
	tree->right = NULL;
	tree->height = 1; 
	return(tree);
}

struct tree *rightRotate(struct tree *y)
{
	struct tree *x = y->left;
	struct tree *T2 = x->right;

	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

struct tree *leftRotate(struct tree *x)
{
	struct tree *y = x->right;
	struct tree *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

int getBalance(struct tree *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct tree* InsertRecords(struct tree *tree,int key)
{	
	if (tree == NULL)
	{
		struct tree *tree = newtree(key);
		
		printf("\nFirst_name = ");
		scanf("%s",tree->A.firstname);
		
		printf("Last_name = ");
		scanf("%s",tree->A.lastname);
		
		printf("Accommodation_tpye = ");
		scanf("%s",tree->A.accommodation_type);
		
		int flag = allocateBlock(tree->A.accommodation_type);
		
		while(flag != 1)
		{
			if(flag == -1)
			{
				printf("\nInvalid Format");
			}
			else
			{
				printf("\nThe block is already accommodated");
			}
			printf("\nPlease Reenter the acccommodation type");
			printf("Accommodation_tpye = ");
			scanf("%s",tree->A.accommodation_type);
			flag = allocateBlock(tree->A.accommodation_type);
		}
		
		tree->A.idtype = key;
		
		if(tree->A.idtype == 0)
		{
			strcpy(tree->A.p.passport,"\0");
			strcpy(tree->A.p.empcode,"\0");
			printf("Aadhaar and address = ");
			scanf("%s ",tree->A.p.aadhaar);
			
		}
		else if(tree->A.idtype == 1)
		{
			strcpy(tree->A.p.aadhaar,"\0");
			strcpy(tree->A.p.empcode,"\0");
			printf("Passport and address = ");
			scanf("%s ",tree->A.p.passport);	
		}
		else if(tree->A.idtype == 2)
		{
			strcpy(tree->A.p.aadhaar,"\0");
			strcpy(tree->A.p.passport,"\0");
			printf("Empcode and address= ");
			scanf("%s ",tree->A.p.empcode);
		}
		scanf("%[^\n]s ",tree->A.address);
		return(tree);
	}
	if (key <= tree->key)
	{
		tree->left = InsertRecords(tree->left, key);
	}	
	else if (key > tree->key)
	{
		tree->right = InsertRecords(tree->right, key);
	}	
	else 
		return tree;


	tree->height = 1 + max(height(tree->left),
						height(tree->right));
						
	int balance = getBalance(tree);
	if (balance > 1 && key < tree->left->key)
		return rightRotate(tree);

	if (balance < -1 && key > tree->right->key)
		return leftRotate(tree);

	if (balance > 1 && key > tree->left->key)
	{
		tree->left = leftRotate(tree->left);
		return rightRotate(tree);
	}

	if (balance < -1 && key < tree->right->key)
	{
		tree->right = rightRotate(tree->right);
		return leftRotate(tree);
	}

	return tree;
}

void print_A(struct accommodation A)
{
	printf("\nFirst_name = %s",A.firstname);	
	printf("\nLast_name = %s",A.lastname);
	printf("\nAccommodation_tpye = %s",A.accommodation_type);
	printf("\nidtpye = %d\n",A.idtype);
	
	if(A.idtype == 0)
	{
		printf("Aadhaar and address = %s ",A.p.aadhaar);
	}
	else if(A.idtype == 1)
	{
		printf("Passport and address = %s ",A.p.passport);	
	}
	else if(A.idtype == 2)
	{
		printf("Empcode = %s ",A.p.empcode);
	}
	printf("\nAddress = %s\n\n",A.address);
}

struct queue
{
	struct tree *tr;
	struct queue *next;
};

void enqueue(struct tree *q,struct queue **head)
{
	struct queue *trav,*ptr = (struct queue*)malloc(sizeof(struct queue));
	ptr->tr = q;
	ptr->next = NULL;
	
	trav = *head;
	if(*head == NULL)
	{
		*head = ptr;
	}
	else
	{
		while(trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = ptr;
	}
}

struct tree* dequeue(struct queue **head)
{
	struct queue *temp;
	struct tree *q;
	q = NULL;
	temp = *head;
	if(*head != NULL)
	{
		q = temp->tr;
		*head = temp->next;
		free(temp);
	}
	else
	{
		*head = NULL;
		free(temp);
	}
	return(q);
}

void printRecords(struct tree *root)
{
	struct queue *head;
	struct tree *ptr;
	int i;
	
	for(i=0;i<3;i++)
	{
		printf("In for for %d",i);
		head = NULL;
		ptr = root;
		enqueue(ptr,&head);
		
		if(ptr != NULL)
		{
			printf("In if");
			while(head != NULL)
			{
				printf("In while");
				ptr = dequeue(&head);
				if(ptr != NULL)
				{
					if(ptr->A.idtype == i)
					{
						printf("#A#\n");
						print_A(ptr->A);
					}
					enqueue(ptr->left,&head);
					enqueue(ptr->right,&head);
				}
			}
		}
		else
		{
			printf("Tree is empty");
			return;
		}
	}
}

void preOrder(struct tree *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

bool compare_acc(struct accommodation A,struct accommodation B)
{
	bool check = false;
	
	if(strcmp(A.firstname,B.firstname)==0 && strcmp(A.lastname,B.lastname)==0 && strcmp(A.accommodation_type,B.accommodation_type)==0 && strcmp(A.address,B.address)==0) 
	{
		check = true;
		if(A.idtype == B.idtype)
		{
			if(A.idtype == 0 && strcmp(A.p.aadhaar,B.p.aadhaar) != 0)
			{
				check = false;
			}
			else if(A.idtype == 1 && strcmp(A.p.passport,B.p.passport) != 0)
			{
				check = false;
			}
			else if(A.idtype == 2 && strcmp(A.p.empcode,B.p.empcode) != 0)
			{
				check = false;
			}
		}
	}
	if(check == true)
	{
		printf("Yes equal$#");
	}
	else
	{
		printf("NOt equal$#");
	}
	return(check);
}

void Insert(struct tree *tr,struct tree **root)
{	
	printf("%s",tr->A.firstname);
	printf("\n320");
	if(tr != NULL)
	{	
		tr->left = NULL;
		tr->right = NULL;
		printf("Line 325");
	}
	else
	{	
		printf("tr == NULL");	
		return;
	}
	
	struct queue *head = NULL;
	struct tree *ptr = *root;
	struct tree *temp;
	if(*root == NULL)
	{
		*root = tr;
		printf("root was NULL");
	}
	else
	{
		printf("In if");
		if(ptr->A.idtype >= tr->A.idtype)
		{
			tr->left = *root;
			*root = tr;
		}
		else
		{	
			enqueue(ptr,&head);
			while(head != NULL)
			{
				ptr = dequeue(&head);
				if(ptr != NULL)
				{
					if(ptr->left != NULL)
					{
						enqueue(ptr->left,&head);
					}
					if(ptr->right != NULL)
					{
						enqueue(ptr->right,&head);		
					}
				}	
				printf("In while");
				if(ptr->right != NULL)
				{
					printf("In if");
					if(ptr->right->A.idtype > tr->A.idtype)
					{
						if(ptr->left->A.idtype > tr->A.idtype)
						{
							printf("case 1.1");
							tr->left = ptr->left->left;
							tr->right = ptr->left->right;
							
							ptr->left->left = ptr->right->left;
							ptr->left->right = ptr->right->left;
							
							temp = ptr->left;
							ptr->left = tr;
							tr = ptr->right;
							ptr->right = temp;
							
							tr->left = NULL;
							tr->right = NULL;
						}
						else
						{
							printf("case 1.2");
							tr->left = ptr->right->left;
							tr->right = ptr->right->right;
							
							temp = ptr->right;
							ptr->right = tr;
							tr = temp;
							
							tr->left = NULL;
							tr->right = NULL;
						}
					}
				}
				else if(ptr->left == NULL)
				{
					printf("case 2");
					ptr->left = tr;
					return;
				}
				else if(ptr->left->A.idtype > tr->A.idtype)
				{
					printf("case 3");
					tr->left = ptr->left->left;
					tr->right = ptr->left->right;
					
					ptr->right = ptr->left;
					ptr->left = tr;
					
					ptr->right->left = NULL;
					ptr->right->right = NULL;
					printf("ENd");
					return;
				}	
				else
				{
					printf("case 4");
					if(ptr->left->A.idtype == tr->A.idtype)
					{
						ptr->right = tr;
						return;
					}
				}
			}
		}
	}
}

void removeDuplicates(struct tree **root)
{
	struct queue *head,*h[3],*q,*fr=NULL;
	struct tree *ptr,*nroot;
	bool ex;
	int i;
	for(i=0;i<3;i++)
	{
		h[i] = NULL;
	}
	head = NULL;
	ptr = *root;
	enqueue(ptr,&head);
	
	printf("In Rd");
	while(head != NULL)
	{
		printf("In while");
		ptr = dequeue(&head);
		if(ptr != NULL)
		{
			if(ptr->left != NULL)
			{
				enqueue(ptr->left,&head);
			}
			if(ptr->right != NULL)
			{
				enqueue(ptr->right,&head);	
			}	
			ex = false;
			for(i=0;i<3 && ex == false;i++)
			{	
				if(h[i] != NULL)
				{
					q = h[i];
					while(q != NULL && ex == false)
					{
						printf("\ncomplaring ptr = %s %s and tr = %s %s\n",ptr->A.firstname,ptr->A.lastname,q->tr->A.firstname,q->tr->A.lastname);
						if(compare_acc(ptr->A,q->tr->A) == true)
						{
							ex = true;
							printf("MAtch found for %s %s\n",ptr->A.firstname,ptr->A.lastname);
						}
						q = q->next;
					}
				}
			}
			
			if(ex == false)
			{
				printf("enqueuing");
				enqueue(ptr,&h[ptr->A.idtype]);
				printf("\nname = %s\n",ptr->A.firstname);
			}
			else
			{
				enqueue(ptr,&fr);
			}
		}
	}
	
	while(fr != NULL)
	{
		ptr = dequeue(&fr);
		free(ptr);
	}
	
	*root = NULL;
	if(*root == NULL)
	{
		printf("Yes");
	}
	
	for(i=0;i<3;i++)
	{
		printf("Enqueuing new data");
	
		while(h[i] != NULL)
		{
			Insert(h[i]->tr,&(*root));
			dequeue(&h[i]);
			printf("out of dequeue");
		}
	}
}

struct index_tree
{
	struct accommodation A;
	struct index_tree *left;
	struct index_tree *right;
	int index;
};

struct index_tree* create_itree()
{
	struct index_tree *iptr = (struct index_tree*)malloc(sizeof(struct index_tree));
	iptr->left = NULL;
	iptr->right = NULL;
	iptr->index = 0;
	return(iptr);
}

void printSortedRecords(struct tree *root,struct index_tree **iroot)
{
	int i=0,j;
	struct queue *head = NULL,*temp;
	struct index_tree *iptr;
	
	printf("\n\nSorted Records : ");
	enqueue(root,&head);
	temp = head;
	int size = 0;
	printf("\nsize measurement\n");
	while(temp != NULL)
	{
		if(temp->tr != NULL)
		{
			enqueue(temp->tr->left,&head);
			enqueue(temp->tr->right,&head);
		}
		size++;
		temp = temp->next;
	}
	
	temp = head;
	for(i=0;i<size;i++)
	{
		if(temp->tr != NULL)
		{
			printf("%s %s\n",temp->tr->A.firstname,temp->tr->A.lastname);
		}
		else
		{
			printf("\nNULL");
		}
		temp = temp->next;
	}	
	
	struct index_tree *ihead[size];
	i=0;
	temp = head;
	printf("\nihead insert\n");
	while(i != size && temp != NULL)
	{
		if(temp->tr != NULL)
		{
			ihead[i] = temp->tr;
			ihead[i]->index = 0;
			printf("line 1");
			acc_to_acc(&(ihead[i])->A,&temp->tr->A);
			printf("%s %s\n",(ihead[i])->A.firstname,(ihead[i])->A.lastname);
			printf("line 2");
		}
		else
		{
			ihead[i] = NULL;
			printf("NULL\n");
		}
		temp = temp->next;
		i++;
	}
	
	printf("index = %d",(ihead[0])->index);
	printf("size = %d\n\n",size);
	for(i=0;i<size;i++)
	{
		if(ihead[i] != NULL)
		{
			printf("%s %s\n",(ihead[i])->A.firstname,(ihead[i])->A.lastname);
			printf("#$");
		}
	}
	
	printf("Indexing");
	
	for(i=0;i<size-1;i++)
	{
		if(ihead[i] != NULL)
		{
			for(j=i+1;j<size;j++)
			{
				if(ihead[j] != NULL)
				{
					if(strcmp(ihead[i]->A.firstname,ihead[j]->A.firstname) < 0)
					{
						ihead[j]->index = ihead[j]->index+1;
					}
					else if(strcmp(ihead[i]->A.firstname,ihead[j]->A.firstname) > 0)
					{
						ihead[i]->index = ihead[i]->index+1;
					}
					else if(strcmp(ihead[i]->A.firstname,ihead[j]->A.firstname) == 0)
					{
						if((strcmp(ihead[i]->A.lastname,ihead[j]->A.lastname) <= 0))
						{
							ihead[j]->index = ihead[j]->index+1;
						}
						else if((strcmp(ihead[i]->A.lastname,ihead[j]->A.lastname) > 0))
						{
							ihead[i]->index = ihead[i]->index+1;
						}
					}
				}		
			}
		}
	}
	i=0;
	j=1;
	temp = head;
	*iroot = create_itree();
	(*iroot)->A = head->tr->A;
	iptr = *iroot;
	printf("\nconverting to tree\n");
	
	while(i != size)
	{
		iptr = ihead[i];
		if(iptr != NULL)
		{
			iptr->left = ihead[j];
			iptr->right = ihead[j+1];
			j = j+2;
		}
		i++;
	}
	
	int flag=1;
	for(i=0;i<size;i++)
	{
		flag=1;
		for(j=0;j<size && flag==1;j++)
		{
			if(ihead[j] != NULL && i == ihead[j]->index)
			{
				print_A(ihead[j]->A);
				flag=0;
			}
		}
	}
}

void search(char fn[],char ln[],struct tree *root)
{
	struct queue *head = NULL;
	struct tree *ptr = root;
	
	printf("\n\nRecords with name %s %s : \n",fn,ln);
	enqueue(ptr,&head);
	
	while(head != NULL)
	{
		ptr = dequeue(&head);
		if(ptr != NULL)
		{
			if(ptr->left != NULL)
			{
				enqueue(ptr->left,&head);
			}
			if(ptr->right != NULL)
			{
				enqueue(ptr->right,&head);
			}
		}
		
		if(strcmp(ptr->A.firstname,fn) == 0 && strcmp(ptr->A.lastname,ln) == 0)
		{
			print_A(ptr->A);
		}
	}
}

void deleteRecord(struct tree **root,struct index_tree **iroot,char fn[],char ln[])
{
	struct tree *ptr,*new_root,*t;
	struct queue *head = NULL;
	
	new_root = NULL;
	ptr = *root;
	*iroot = NULL;
	enqueue(ptr,&head);
	
	while(head != NULL)
	{
		printf("In while");
		ptr = dequeue(&head);
		if(ptr != NULL)
		{
			if(ptr->left != NULL)
			{
				enqueue(ptr->left,&head);
			}
			if(ptr->right != NULL)
			{
				enqueue(ptr->right,&head);
			}
			
			printf("In if");
			if(strcmp(ptr->A.firstname,fn) != 0 || strcmp(ptr->A.lastname,ln) != 0)
			{
				printf("in insert");
				printf("%s\n",ptr->A.firstname);
				Insert(ptr,&new_root);
			}
			else
			{
				printf("Deleting");
				t = ptr;
				deallocateBlock(ptr->A.accommodation_type);
				free(t);
			}
		}
	}
	printf("After having newroot : ");
	
	printf("Out of while");
	*root = new_root;
	printf("before calling printSortedRecords");
	printSortedRecords(new_root,iroot);
	printf("Orginal : ");
	printRecords(*root);
}

void updateRecord(char fn[],char ln[],struct node *root,struct index_tree **iroot)
{
	struct queue *head = NULL;
	struct tree *ptr;
	char f[50],l[50];
	int i=1;

	ptr = root;
	enqueue(ptr,&head);
	while(head != NULL)
	{
		ptr = dequeue(&head);
		if(ptr != NULL)
		{
			if(strcmp(ptr->A.firstname,fn) == 0 && strcmp(ptr->A.lastname,ln) == 0)
			{
				printf("\nEnter the new name for %d match : ",i);
				scanf("%s%s",f,l);
				i++;
				strcpy(ptr->A.firstname,f);
				strcpy(ptr->A.lastname,l);
			}
			if(ptr->left != NULL)
			{
				enqueue(ptr->left,&head);
			}
			if(ptr->right != NULL)
			{
				enqueue(ptr->right,&head);
			}
		}
	}
	printSortedRecords(root,iroot);
}


int main()
{
	struct tree *root = NULL;
	struct index_tree *iroot = NULL;	
	initialize_acc();

	
	char first_name[50],last_name[50];
	

	
	int i=1,choice;
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
				printRecords(root);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 1:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				while(i!=0)
				{	
					InsertRecords(root,0);
					printf("\nDo you want to add another entry : ");
					scanf("%d",&i);		
				}
				printf("\n values have been added\n-------------------------------------------------------------------------------\n");
				break;
				
			case 2:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				removeDuplicates(&root);
				printf("\n Duplicates removed\n---------------------------------------------------------------------------------------\n");
				break;
			
			case 3:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nPrinting according to Aadhar->Passport->Empcode\n");
				printRecords(root);	
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 4:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printSortedRecords(root,&iroot);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
				
			case 5:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nEnter the firstname and lastname of the person whose data you want to print");
				scanf("%s %s",first_name,last_name);
				search(first_name,last_name,root);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			
			case 6:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nEnter the name whose record you want to delete : ");
				scanf("%s %s",first_name,last_name);
				deleteRecord(&root,&iroot,first_name,last_name);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
				
			case 7:
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				printf("\nEnter the firstname and lastname of the person whose record you want to update.");
				scanf("%s %s",first_name,last_name);
				updateRecord(first_name,last_name,root,&iroot);
				printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			
			case 8:
			//	printf("\n---------------------------------------------------------------------------------------------------------------\n");
			//	specialRequestAllocation();
			//	printf("\n---------------------------------------------------------------------------------------------------------------\n");
				break;
			case 9:
				exit(0);
				
			default: 
				printf("Invalid Choice");
		}	
	}
	
	
	return 0;
}

