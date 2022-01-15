#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node
{
	int employeeNumber;
	char firstName[25];
	char lastName[25];
	char dateofbirth[25];
	char gender[25];
	char taxpayerNumber[25];
	char position[25];
	float hoursworked;
    float numberofWeeks;
    float rateperHour;
    float numberofyearsworked;
    float salary;
    
 struct node * next;
} node_t;

node_t* create_staff(node_t*);
node_t* createList(int,char[25],char[25],char[25],char[25], char[25],char[25], float,float,float,float);
node_t* inserttoList(node_t*,int ,char [25],char [25],char [25],char [25], char [25], char [25], float, int,float,float,float);
void displayList();
void print_list(node_t*);
struct node * deleteSpecificItem(struct node* ,int);
struct node * updateNode(struct node*);
void createfile(node_t*);
node_t* readfromfile(node_t*);
int read();
void write(int);
void overwritefile(node_t*);
void search(node_t*,int);
float salaryCalculator(float,float,float,char[20]);

int main() 
{
	
	system("COLOR B1");
	int option=0,employeenumber=0;
	
	node_t *head=NULL;
	
	head=readfromfile(head);
	printf("\n\t\t\t\t********************************************************");
	printf("\n\t\t\t\t**       JAMAICA PREPARATORY SCHOOL                   **");
	printf("\n\t\t\t\t********************************************************");
	printf("\n\t\t\t\t**       1. Search & View Staff                       **");
	printf("\n\t\t\t\t**       2. Create Staff                              **");
	printf("\n\t\t\t\t**       3. Update Staff                              **");
	printf("\n\t\t\t\t**       4. Delete Staff                              **");
	printf("\n\t\t\t\t**       5. End Program                               **");
	printf("\n\t\t\t\t********************************************************\n");
	
	printf("\n\t\t\t\t Option:\t");
	scanf("%d",&option);	
	while(option!=5)
	{		
	  if(option==1)
	  {
		 printf("\n Enter the employee number for the record to be viewed:\t");
		 fflush(stdin);
	     scanf("%d",&employeenumber);
	  	search(head,employeenumber);     	
	    		  
      } 	         
     if(option==2)
     {
        head=create_staff(head);
     }
   
     if(option==3)
     {
       head=updateNode(head);
    
       overwritefile(head);	
     } 
	
     if(option==4)
      {
    	
       printf("\n Enter the Employee Number for the record to be deleted:\t");
       fflush(stdin);
	   scanf("%d",&employeenumber);
    	
 	   head=deleteSpecificItem(head ,employeenumber);
 	 
 	   overwritefile(head);
     }

	  
	  printf("\n\t\t\t\t********************************************************");
	  printf("\n\t\t\t\t**       JAMAICA PREPARATORY SCHOOL                   **");
	  printf("\n\t\t\t\t********************************************************");
	  printf("\n\t\t\t\t**       1. Search & View Staff                       **");
	  printf("\n\t\t\t\t**       2. Create Staff                              **");
	  printf("\n\t\t\t\t**       3. Update Staff                              **");
	  printf("\n\t\t\t\t**       4. Delete Staff                              **");
	  printf("\n\t\t\t\t**       5. End Program                               **");
	  printf("\n\t\t\t\t********************************************************\n");
	  scanf("%d",&option);
	 
  }
	getche();
}
node_t* create_staff(node_t* head) 
{
    //node_t * head = NULL;
    
	char firstName[20] = {"kjhgf"}, lastName[20] = { "kjhgf" }, dateofbirth[20] = { "kjhgf" }, gender[10] = { "kjhgf" }, position[20] = { "kjhgf" },taxpayerNumber[20];

	int employeeNumber=0,counter=0, decision=1;
	float hoursworked=0,numberofWeeks=0,salary=0,numberofyearsworked=0;
	int numberofrecords=0,principalLimit=0, secretaryLimit=0, teacherLimit=0, ancillaryLimit=0;
	 int principaldecision=1, secretarydecision=1, teacherdecision=1, ancillarydecision=1;
	
	numberofrecords=read();  
   do 
  {
	  
	printf("\n Employee Number (1000 - 1999):\t");
	fflush(stdin);
	scanf("%d",&employeeNumber);

	printf("\n Enter staff First Name:\t");
	fflush(stdin);
	scanf("%s",&firstName);

	printf("\n Enter staff Last Name:\t\t");
	fflush(stdin);
	scanf("%s", &lastName);

	printf("\n Enter staff Date of Birth (format MM/DD/YYYY e.g. 12/07/1967):\t");
	fflush(stdin);
	scanf("%s",&dateofbirth);

	printf("\n Enter Gender: (M/F)\t");
	fflush(stdin);
	scanf("%s",&gender);

	printf("\n Enter Social Insurance Number (format 999-999-999 e.g. 105-345-265):\t");
	fflush(stdin);
	scanf("%s",&taxpayerNumber);


	   printf("\n Enter Position (Principal, Teacher, Secretary or Ancillary):\t");
	   fflush(stdin);
	   scanf("%s",&position);

	   printf("\n Enter Weekly Hours Worked:\t");
	   fflush(stdin);
	   scanf("%f",&hoursworked);
    
       printf("\n Enter number of weeks Worked:\t");
	   fflush(stdin);
	   scanf("%f",&numberofWeeks);

       printf("\n Enter number of years Worked:\t");
	   fflush(stdin);
	   scanf("%f",&numberofyearsworked);
	   

     salary=salaryCalculator(hoursworked,numberofWeeks,numberofyearsworked,position);
	
	if(numberofrecords==0)
	{
		head=createList(employeeNumber,firstName,lastName,dateofbirth,gender,taxpayerNumber,position,hoursworked,numberofWeeks,numberofyearsworked,salary);
	    createfile(head);	
	}
	else
	{	
	
	    inserttoList(head,employeeNumber,firstName,lastName,dateofbirth,gender,taxpayerNumber,position,hoursworked,decision,numberofWeeks,numberofyearsworked,salary);
    } 
	
	numberofrecords++;
	
	printf("\n Enter (0) to end the PROGRAM or (1) to continue adding staff \t");
	printf("\n");
	fflush(stdin);
	scanf("%d",&counter);
	
  }
  while(counter!=0); 
  	write(numberofrecords);
	
	return head;
	printf( "   "  );
}
void write(int numberofrecords)
{
	FILE*counting;
	counting=fopen("recordnumber.txt","w");
	fprintf(counting,"%d",numberofrecords);
	fclose(counting);
	
}

node_t* createList(int employeeNumber,char firstName[25],char lastName[25],char dateofbirth[25],char gender[25], char taxpayerNumber[25],char position[25], float hoursworked,float numberofWeeks,float numberofyearsworked,float salary)
{
	node_t * head = NULL;
    
	head = malloc(sizeof(node_t));
    
	 if (head == NULL)
	 {
       printf("\nMemory could not be allocated");
     }

     head->employeeNumber=employeeNumber;
     
     strcpy(head->firstName,firstName);
     
     strcpy(head->lastName,lastName);
     
     strcpy(head->dateofbirth,dateofbirth);
     
     strcpy(head->gender,gender);
     
     strcpy(head->taxpayerNumber,taxpayerNumber);
     
     strcpy(head->position,position);
     
     head->hoursworked=hoursworked;
     
     head->numberofWeeks=numberofWeeks;
     
     head->numberofyearsworked=numberofyearsworked;
     
     head->salary=salary;
     
    head->next = NULL;

	return head;
}


node_t* inserttoList(node_t* head,int employeeNumber,char firstName[25],char lastName[25],char dateofbirth[25],char gender[25], char taxpayerNumber[25],char position[25], float hoursworked, int decision,float numberofWeeks,float numberofyearsworked,float salary)
{
	
	node_t * current = head;
    
	while (current->next != NULL) 
	{
		printf("\n text value found  %d\n", current->employeeNumber);
        current = current->next;
    }
    
    current->next = malloc(sizeof(node_t));
    
    current = current->next;
    
	current->employeeNumber=employeeNumber;
    
    strcpy(current->firstName,firstName);
    
    strcpy(current->lastName,lastName);
    
    strcpy(current->dateofbirth,dateofbirth);
    
    strcpy(current->gender,gender);
    
    strcpy(current->taxpayerNumber,taxpayerNumber);
    
    strcpy(current->position,position);
    
    current->hoursworked=hoursworked;
    
    current->numberofWeeks=numberofWeeks;
    
    current->numberofyearsworked=numberofyearsworked;
     
    current->salary=salary;
    
    current->next = NULL;
    
    
   // printf("\nprimary key: %d \t",current->employeeNumber);
   
   if(decision==1)
   {
   	FILE*file;
	
	file=fopen("staff.txt","a");
	
	fprintf(file,"\n%d %s %s %s %s %s %s %.2f %f %f %f",current->employeeNumber,current->firstName,current->lastName,current->dateofbirth,current->gender,current->taxpayerNumber,current->position, current->hoursworked,current->numberofWeeks,current->numberofyearsworked,current->salary);
	
	fclose(file);
	
   }
   
    return current;
    
}

void print_list(node_t * head) 
{
    node_t * current = head;

    while (current != NULL) 
	{
        printf("\n%d %s %s %s %s %s %s %.2f %f %f %f",current->employeeNumber,current->firstName,current->lastName,current->dateofbirth,current->gender,current->taxpayerNumber,current->position, current->hoursworked,current->numberofWeeks,current->numberofyearsworked,current->salary);
        
        current = current->next;
    }
}
struct node *deleteSpecificItem(struct node* head ,int employeeNumber)
{ 
    node_t *temp, *current_pointer, *prev_pointer, *p;
    
    int found=0,size=0;//Not found
    
    prev_pointer=NULL;//store the value of first node.
    
	
	if(head==NULL)// Test if list is empty.
	{
	   printf("List is empty");
		
	} 
	else
	{
		p=head;//store the value of head node.
		if(p->employeeNumber ==employeeNumber) //Check if head node has the value.
        {
             head=p->next;//head node is now next node.
             found=1;
             free(p);
	    }	
		p=head;
		
		while(found==0 && p!=NULL)//Search list for requested record.
		{
		
		   if(p->employeeNumber==employeeNumber)//test if node have the requested value
            {
               printf("\ntext value found  %d\n", prev_pointer->employeeNumber);
               prev_pointer->next = p->next;
			   found=1;
			   free(p);  
	        }
	        
	        prev_pointer=p; // assign the address of p to the previous node variable.
			p=p->next;//step to the next node.
	    }
	    
	    size=read();
	    
	    size--;
	    
	    write(size);
		
	}
	
   return head;
}
struct node * updateNode(struct node* head)
{
    node_t *temp, *current_pointer, *prev_pointer, *p;
    
    char firstName[20] = {"kjhgf"}, lastName[20] = { "kjhgf" }, dateofbirth[20] = { "kjhgf" }, gender[10] = { "kjhgf" }, position[20] = { "kjhgf" },taxpayerNumber[20];
    
    int employeeNumber=0,size=0,numberofWeeks=0,salary=0,numberofyearsworked=0;
    
	float hoursworked=0;
    
    int found=0;//Not found    
    prev_pointer=NULL;//store the value of first node.
    
    printf("\nEmployee Number (1000 - 1999):\t");
	fflush(stdin);
	scanf("%d",&employeeNumber);
	
	printf("\nEnter staff First Name:\t");
	fflush(stdin);
	scanf("%s",&firstName);

	printf("Enter staff Last Name:\t");
	fflush(stdin);
	scanf("%s", &lastName);

	printf("Enter staff Date of Birth (format MM/DD/YYYY e.g. 12/07/1967):\t");
	fflush(stdin);
	scanf("%s",&dateofbirth);

	printf("Enter Gender (M/F):\t");
	fflush(stdin);
	scanf("%s",&gender);

	printf("Enter Social Insurance Number  (format 999-999-999 e.g. 105-345-265):\t");
	fflush(stdin);
	scanf("%s",&taxpayerNumber);

	printf("Enter Position (Principal, Teacher, Secretary or Ancillary):\t");
	fflush(stdin);
	scanf("%s",&position);

	printf("Enter Weekly Hours Worked :\t");
	fflush(stdin);
	scanf("%f",&hoursworked);
	
	printf("\n Enter number of weeks Worked:\t");
	fflush(stdin);
	scanf("%f",&numberofWeeks);

    printf("\n Enter number of years Worked:\t");
	fflush(stdin);
	scanf("%f",&numberofyearsworked);
	
	if(head==NULL)// Test if list is empty.
	{
	   printf("List is empty");
		
	} 
	else
	{
		p=head;//store the value of head node.
		
		if(p->employeeNumber==employeeNumber) //Check if head node has the value.
        {        	
             //head=p->next;//head node is now next node.
          strcpy(p->firstName,firstName);
          
		  strcpy(p->lastName,lastName);
    
          strcpy(p->dateofbirth,dateofbirth);
    
          strcpy(p->gender,gender);
    
          strcpy(p->taxpayerNumber,taxpayerNumber);
    
          strcpy(p->position,position);
    
          p->hoursworked=hoursworked;
          
          p->numberofWeeks=numberofWeeks;
          
          p->numberofyearsworked=numberofyearsworked;
     
          p->salary=salary;
          
          //overwritefile(p);
             
		  found=1;
	    }
	
		p=head;
		
		while(found==0&& p!=NULL)//Search list for requested record.
		{
		   //found==0
		   if(p->employeeNumber==employeeNumber)//test if node have the requested value
            {
               
               strcpy(p->firstName,firstName);
               
               strcpy(p->lastName,lastName);
    
               strcpy(p->dateofbirth,dateofbirth);
    
               strcpy(p->gender,gender);
    
               strcpy(p->taxpayerNumber,taxpayerNumber);
    
               strcpy(p->position,position);
    
               p->hoursworked=hoursworked;
               
               p->numberofWeeks=numberofWeeks;
               
               p->numberofyearsworked=numberofyearsworked;
     
               p->salary=salary;
               
               
			   found=1;
	        }     
	       	         //overwritefile(p);
	        
	        prev_pointer=p; // assign the address of p to the previous node variable.
			p=p->next;//step to the next node.*/
	    }   		
	}
	
	size=read();	
	 //overwritefile(p);	
   return head;
}

void createfile(node_t* head)
{	
	node_t * current = head;	
	FILE*file;	
	file=fopen("staff.txt","a");	
	fprintf(file,"\n%d %s %s %s %s %s %s %.2f %f %f %f",current->employeeNumber,current->firstName,current->lastName,current->dateofbirth,current->gender,current->taxpayerNumber,current->position, current->hoursworked,current->numberofWeeks,current->numberofyearsworked,current->salary);
	fclose(file); 
}

node_t* readfromfile(node_t* head)
{
	
	node_t * current = head;
	
	int decision=0;
	
	char firstName[20], lastName[20], dateofbirth[20], gender[10], position[20],taxpayerNumber[20];
	
	int numberofrecords=0,count=0,employeeNumber=0;
	
	float hoursworked=0,salary=0,numberofWeeks=0,numberofyearsworked=0;
	
	numberofrecords=read();
	
	FILE*read;
	//read from file
	read=fopen("staff.txt","r");	
	while(count<numberofrecords)    {
    	  
	    fscanf(read,"\n%d %s %s %s %s %s %s %f %f %f %f",&employeeNumber,&firstName,&lastName,&dateofbirth,&gender,&taxpayerNumber,&position,&hoursworked,&numberofWeeks,&numberofyearsworked,&salary);
        if(count==0)
        {   
            head=createList(employeeNumber,firstName,lastName,dateofbirth,gender,taxpayerNumber,position,hoursworked,numberofWeeks,numberofyearsworked,salary);   
       }
    	else
	   {
	        inserttoList(head,employeeNumber,firstName,lastName,dateofbirth,gender,taxpayerNumber,position,hoursworked,decision,numberofWeeks,numberofyearsworked,salary);
	        
       }
	       count++;   
	}
   // close file after reading
   fclose(read);
   
   return head;

}

int read()
{
	int count=0;
	FILE *readcount;	
	readcount=fopen("recordnumber.txt","r");
	fscanf(readcount,"%d",&count);
	fclose(readcount);

    return count;

}

void overwritefile(node_t* head)
{
	
	node_t * current = head;
	
	FILE*overwrite;
	
	overwrite=fopen("staff.txt","w");

    while (current != NULL) 
	{
		printf("\n%d %s %s %s %s %s %s %f %f %f %f",current->employeeNumber,current->firstName,current->lastName,current->dateofbirth,current->gender,current->taxpayerNumber,current->position, current->hoursworked,current->numberofWeeks,current->numberofyearsworked,current->salary);
        fprintf(overwrite,"\n%d %s %s %s %s %s %s %f %f %f %f",current->employeeNumber,current->firstName,current->lastName,current->dateofbirth,current->gender,current->taxpayerNumber,current->position, current->hoursworked,current->numberofWeeks,current->numberofyearsworked,current->salary);
        
        current = current->next;
    }
	
	fclose(overwrite);
}

void search(node_t * head,int employeeNumber)
{
    node_t * current = head;

    while (current != NULL) 
	{
	  if(current->employeeNumber==employeeNumber)
	  {
        printf("\n%d %s %s %s %s %s %s %.2f %f %f %f",current->employeeNumber,current->firstName,current->lastName,current->dateofbirth,current->gender,current->taxpayerNumber,current->position, current->hoursworked,current->numberofWeeks,current->numberofyearsworked,current->salary);
      }
        current = current->next;
    }
		
}

float salaryCalculator(float hoursworked,float numberofWeeks, float numberofyearsworked, char position[20])
{
	float principalRate=300, teacherRate=150,  secretaryRate=100, ancillaryRate=50, salary=0,noBonus=1, bonus=1.05;
	
	int principaldecision=1, secretarydecision=1, teacherdecision=1, ancillarydecision=1;
	
	principaldecision=strcmp(position,"principal");
	
	secretarydecision=strcmp(position,"secretary");
	
	teacherdecision=strcmp(position,"teacher");
	
	ancillarydecision=strcmp(position,"ancillary");
	
	
	if(numberofyearsworked>5)
	{
	    if(principaldecision==0)
		{
		 salary=bonus*(numberofWeeks*hoursworked*principalRate);
   	    }
   	   
   	    if(secretarydecision==0)
   	    {
   	    	
		   salary=bonus*(numberofWeeks*hoursworked*teacherRate);
		}
   	   
   	     if(teacherdecision==0)
   	     {
			salary=bonus*(numberofWeeks*hoursworked*secretaryRate);
		 }
		
		  if(ancillarydecision==0)
		  {
		  	salary=bonus*(numberofWeeks*hoursworked*ancillaryRate);
		  }
		
	}
	else
	{
		 if(principaldecision==0)
		{
		 salary=noBonus*(numberofWeeks*hoursworked*principalRate);
   	    }
   	   
   	    if(secretarydecision==0)
   	    {
   	    	
		   salary=noBonus*(numberofWeeks*hoursworked*teacherRate);
		}
   	   
   	     if(teacherdecision==0)
   	     {
			salary=noBonus*(numberofWeeks*hoursworked*secretaryRate);
		 }
		
		  if(ancillarydecision==0)
		  {
		  	salary=noBonus*(numberofWeeks*hoursworked*ancillaryRate);
		  }		
	}	
	return salary;
}


