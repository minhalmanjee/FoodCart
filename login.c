 #include<stdio.h>
#include<string.h>
#include<conio.h>
#include <windows.h>

struct address
{
	char house_no[10] , street_no[10] ;
	char area[15] , city[10];
}add;

struct customers 
{
	char name[20] , email[20] , pass[20] ;
	char number[13];
	struct address add;
};

struct employee
{
    char name[50];
    char area[50];
    char id[5];
    int age;
    char status[10];
    float wage;
} employee;

struct delivery
{
    char name[50];
    char date[10];
    char time[10];
    float price;
    char order[20];
} delivery;
//PASSWORD VALIDATION//
void Passvalid(char *pass)
{
 char ch;
 int i,number,special,capital,small;
 number=0;
 special=0;
 capital=0;
 small=0;
  puts("Your Password must contain\n an uppercase\n a lowercase\n a number\n a special char \n");
   	puts("Enter Password");
 while(number==0 || special==0 || capital==0 || small==0 || strlen(pass)<8) 
 {
	gets(pass);

 	 for(i=0;pass[i]!='\0';i++)
 {
  if(pass[i]>='0' && pass[i]<='9')
   number=1;
  if(pass[i]>='a' && pass[i]<='z')
   small=1;
  if(pass[i]>='A' && pass[i]<='Z')
   capital=1;
  if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='*')
   special=1;
 }
  
}
}

//***********************SIGN UP************************
void signup() 
{
	system("cls");
	// initilizers
	char name[20], email[25], pass1[20], pass2[20] , mobile[11];
	int x , i , j , k , error =0 ,count = 0;
	char proceed;
	struct customers customers ;
	printf("\tFOR SIGNING UP PLEASE FILL THE FORM BELOW\n");
    
//	// for name and validation
//	do
//	{
	printf("Enter Your name :"); 
    scanf("%s", &customers.name); 
//    for (i = 0; name[i] = '\0'; i++) 
//	{ 
//        if (((name[i] < 'a' && name[i] > 'z') || (name[i] < 'A' && name[i] > 'Z'))); 
//        {
//        	error++;
//		}
//    }
//    } while(error == 0);
//    strcpy(customers.name , name);
    
    
    //email and validation
    do
    {
    printf("\nEnter Your Email :"); 
    scanf("%s", &email);  
        for (j = 0; email[j] != '\0'; j++) 
		{ 
            if (email[j] == '@'|| email[j] == '.') 
                count++; 
        } 
    }while (count < 2 );
    strcpy(customers.email , email);
   
   
   //password and validation
   int flag=1;
    Passvalid(&pass1);
   do
   { 
	printf("\nConfirm Password :"); 
    scanf("%s", &pass2);
	if(strcmp(pass1, pass2)==0) 
    flag = 0;
    }while (flag != 0);
   printf("\nThe Passwords match");
   strcpy(customers.pass, pass2);
   
  
   
   //number and its validation
     
    	printf("\nEnter Your Mobile Number :"); 
        scanf("%s", &mobile);
        do
	 {
	 	count=0;
	 	printf("enter mobile number : ");
	 	scanf("%s" , &mobile);
	 	if(strlen(mobile)!=11)
	 	{
	 		count++;
	 		printf("Enter correct 11 digit contact number \n");
		}
	 	for(k=0 ; k<11 ; k++)
	 	{
	 		if(mobile[k]<'0' && mobile[k]>'9')
	 		{
	 			count++;
	 			printf("invalid number\n");
	 			break;
			}
		}
	 	
	 }while(count>0);
      strcpy(customers.number, mobile);
    
	
	//address 
	printf("For your complete Address\n");
    printf("\nhouse number :");
    scanf("%s" , &customers.add.house_no);
    
    
    printf("\nstreet number :");
    scanf("%s" , &customers.add.street_no);
    

    printf("\narea name :");
    scanf("%s" , &customers.add.area);

    
    printf("\ncity name :");
    scanf("%s" , &customers.add.city);
    
   
    
    // account successfully created 
    printf("\n\n\n******************Your account has been successfully created***************** ");
    
    //writing record to file
    FILE * fcd = fopen("customerdetails.txt", "ab+");
    if(fcd == NULL)
    {
    	exit(1);
	}
	fwrite(&customers, sizeof(struct customers), 1, fcd);
	fclose(fcd);
  
//    //for proceeding 
//    printf("\n\nWould you like to proceed and place an order");
//    printf("\nTo login and view menu press 1 \n To exit press 2\n\nYour Choice: ");
//    while(1)
//    {
//    	scanf("%c" , &proceed);
//    	switch (proceed)
//    {
//    	case '1':
//    		login();
//    		break;
//    	case '2':
//    		printf("\nThankyou for signing up, have a nice day");
//		    exit(1);
//		    break;
//		default:
//			printf("\nPlease Enter a valid choice: ");
//			break;
//	}
//	return;	
//	}
    
    
    	
} 

//********************* LOG IN*****************************************
void login() 
{
system("cls");
struct customers customers;
printf("\n\n\tTO LOG IN TO YOUR FOODCART ACCOUNT PLEASE ENTER YOUR \n");
char email[25] , pass[20];
int i;
//email and validaion 
    FILE * fcd = fopen("customerdetails.txt", "rb");
    printf("\nEmail :"); 
    scanf("%s", &email);
    printf("\nPassword : "); 
    scanf("%s", &pass);
    while(fread(&customers, sizeof(customers), 1, fcd))
    {
    	 if(strcmp(email, customers.email) == 0 || strcmp(pass, customers.pass))
    	 {
    	 	break;
		 }
	}
	
	printf("\n\n\n**********you are successfully logged in*********** ");
	
	if(strcmp(customers.pass, "AdminPanel786!") == 0)
	{
		system("cls");
		admin(); //if password is admin, will redirect to admin panel.
	}
	else
	{
		system("cls");
		orderfood();
	}
    
    
    
}


void admin()
{
	char emp_id[5], a, name[10], stat[10], view = 'y';
    int empsize = sizeof(struct employee);
    char add_record = 'y';
    char place[50] = "pechs";
    
    
     FILE *fp, *fn;                                 //file for employee rcd
     fp = fopen("employee.txt", "rb+");
	 if(fp == NULL)
     {
        fp = fopen("employee.txt","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
        }
     }
     
    while(1)
    {
    	printf("\n\n\nChoose an option\n\n 1)Add A New Employee Record\n 2)View list of Employees\n 3)View Employee by name\n 4)View Employees by status(active or inactive)\n 5)Delivery history by area\n 6)Exit\n");
    	fflush(stdin);
        scanf("\n%c", &a);
		switch(a)
    	{
    	case '1':
    		add_record = 'y';
    		while(add_record == 'y' || add_record == 'Y')
    		{
    		fseek(fp,0,SEEK_END);
	        printf("\nName: ");
            scanf("%s", &employee.name);
            printf("Employee-ID: ");
            scanf("%s", &employee.id);
            printf("Age: ");
            scanf("%d", &employee.age);
	        printf("Area of Delivery: ");
            scanf("%s", &employee.area);
            printf("Status: ");
            scanf("%s", &employee.status);
            printf("Base Salary: ");
            scanf("%f", &employee.wage);
            fwrite(&employee,empsize,1,fp);
            printf("\nWould you like to add another record(y/n):");
            fflush(stdin);
            scanf("%c", &add_record);
			}
			break;
		
		case '2':
			rewind(fp);
			printf("\n\tName \tEmp-ID \tAge \tBase-Salary \tArea \tStatus");
			while( fread(&employee, empsize, 1, fp))
            {
			printf("\n\n\t %s", employee.name);
			printf("\t%s", employee.id);
            printf("\t%d", employee.age);
            printf("\t%.2f", employee.wage);
            printf("\t%s", employee.area);
            printf("\t%s", employee.status);
            }               	
			break;
		
		case '3':
			view = 'y';
			while(view == 'y' || view == 'Y')
			{
				rewind(fp);
				printf("\nEnter the employee name to view details: ");
				fflush(stdin);
                scanf("%s", &name);
                while(fread(&employee, empsize, 1, fp))
                {
                	if(strcmp(name, employee.name) == 0)
                	{
			         printf("\n\nName:\t %s", employee.name);
			         printf("\nEmp-ID:\t %s", employee.id);
                     printf("\nAge:\t %d", employee.age);
                     printf("\nBase Salary:\t %.2f", employee.wage);
                     printf("\nDelivery Area:\t %s", employee.area);
                     printf("\nStatus: \t %s", employee.status);		                                    
					}
				}  
				printf("\n\nWould you like to view another record(y/n):");
                fflush(stdin);
                scanf("%c", &view);              
			}
			break;
		case '4':
			view = 'y';
			while(view == 'y' || view == 'Y')
			{
				rewind(fp);
				printf("\nEnter the status to view employees ");
				fflush(stdin);
                scanf("%s", &stat);
                while(fread(&employee, empsize, 1, fp))
                {
                	if(strcmp(stat, employee.status) == 0)
                	{
			         printf("\n\nName:\t %s", employee.name);
			         printf("\nEmp-ID:\t %s", employee.id);
                     printf("\nAge:\t %d", employee.age);
                     printf("\nBase Salary:\t %.2f", employee.wage);
                     printf("\nDelivery Area:\t %s", employee.area);
                     printf("\nStatus: \t %s", employee.status);		                                    
					}
				}  
				printf("\n\nWould you like to pass your query again(y/n):");
                fflush(stdin);
                scanf("%c", &view);              
			}
			break;
			
		case '5':
			view = 'y';
			while(view == 'y' || view == 'Y')
			{
				rewind(fp);
				printf("\nEnter the area to view deliveries: ");
				fflush(stdin);
                scanf("%s", &place);
                while(fread(&employee, empsize, 1, fp))
                {
                	if(strcmp(place, employee.area) == 0)
                	{
                	 strcpy(delivery.name, employee.name);
                	 delivery.price = 1000;
                	 strcpy(delivery.date,"21/01/2020");
                	 strcpy(delivery.time, "10:34:25");
                	 strcpy(delivery.order, "Fries x2");
			         printf("\n\nName:\t %s", delivery.name);
			         printf("\nTime:\t %s", delivery.date);
                     printf("\nDate:\t %s", delivery.time);
                     printf("\nAmount:\t %.2f", delivery.price);
                     printf("\nDelivery Area:\t %s", employee.area);
                     printf("\nOrder: \t %s", delivery.order);		                                    
					}
				}  
				printf("\n\nWould you like to pass your query again(y/n):");
                fflush(stdin);
                scanf("%c", &view);              
			}
			break;
		case '6':
			fclose(fp);
            exit(0);
			
		}
    }
    return;
}



//******************order food*************************
int orderfood()	
	{
	char s,s1,s2,s3;
	int pizza,fries,burger,sand,price;
	int price1 = 0;
	int price2=0;
	int price3 =0;
	
	int a,q1,q2,q3,q4;
		printf("\n\n\n\tABC online restaurant order\n\t\tWelcome\n\nPlease select from the menu below\nB = Burger\nF = French Fries\nP = Pizza\nS = Sandwiches\nHow many types of snacks you want to order(Enter a number between 1 and 4):");
	scanf("%d", & a);
    switch (a)
	{
		case 1:
    		printf("Enter snack you want to order:"); 
			scanf(" %c", &s);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q1);
			switch (s)
			{
				case 'p':
				case 'P':
				pizza = pizza + q1;
				price = q1 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q1;
				price = q1 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q1;
				price = q1 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q1;
				price = q1 * 150;
				break;						
			}
			switch (s)
			{
				case 'p':
				case 'P':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Pizza (s) value %d PKR",q1,price);
					break;
				case 'f':
				case 'F':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d French Fries (s) value %d PKR",q1,price);
					break;
				case 'b':
				case 'B':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Burger (s) value %d PKR",q1,price);
					break;
				case 's':
				case 'S':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Sandwich (es) value %d PKR",q1,price);
					break;		
			}
			printf("\nTotal: %d", price);
			printf("\nThankyou for your order... have a nice day!");
			break;
		case 2:
			printf("Enter first snack you want to order:"); scanf(" %c", &s);
			printf("Please provide Quantity:"); scanf(" %d", &q1);
			switch (s)
			{
				case 'p':
				case 'P':
				pizza = pizza + q1;
				price = q1 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q1;
				price = q1 * 50;
				break;
				case 'b':			
				case 'B':
				burger = burger + q1;
				price = q1 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q1;
				price = q1 * 150;
				break;						
			}
			printf("Enter second snack you want to order:"); scanf(" %c", &s1);
			printf("Please provide Quantity:"); scanf(" %d", &q2);
			switch (s1)
			{
				case 'p':
				case 'P':
				pizza = pizza + q2;
				price1 = q2 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q2;
				price1 = q2 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q2;
				price1 = q2 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q2;
				price1 = q2 * 150;
				break;						
			}
			switch (s)
			{
				case 'p':
				case 'P':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Pizza (s) value %d PKR",q1,price);
					break;
				case 'f':
				case 'F':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d French Fries (s) value %d PKR",q1,price);
					break;
				case 'b':
				case 'B':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Burger (s) value %d PKR",q1,price);
					break;
				case 's':
				case 'S':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Sandwich (es) value %d PKR",q1,price);
					break;		
			}
			switch (s1)
			{
				case 'p':
				case 'P':
				printf("\n%d Pizza (s) value %d PKR",q2,price1);
					break;
				case 'f':
				case 'F':
				printf("\n%d French Fries (s) value %d PKR",q2,price1);
					break;
				case 'b':
				case 'B':
				printf("\n%d Burger (s) value %d PKR",q2,price1);
					break;
				case 's':			
				case 'S':
				printf("\n%d Sandwich (es) value %d PKR",q2,price1);
					break;		
			}
			printf("\nTotal: %d", price+price1);
			printf("\nThankyou for your order... have a nice day!");
			break;
		case 3:
			printf("Enter first snack you want to order:"); 
			scanf(" %c", &s);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q1);
			switch (s)
			{
				case 'p':
				case 'P':
				pizza = pizza + q1;
				price = q1 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q1;
				price = q1 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q1;
				price = q1 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q1;
				price = q1 * 150;
				break;						
			}
			printf("Enter second snack you want to order:"); 
			scanf(" %c", &s1);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q2);
			switch (s1)
			{
				case 'p':
				case 'P':
				pizza = pizza + q2;
				price1 = q2 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q2;
				price1 = q2 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q2;
				price1 = q2 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q2;
				price1 = q2 * 150;
				break;						
			}
			printf("Enter second snack you want to order:"); 
			scanf(" %c", &s2);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q3);
			switch (s2)
			{
				case 'p':
				case 'P':
				pizza = pizza + q3;
				price2 = q3 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q3;
				price2 = q3 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q3;
				price2 = q3 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q3;
				price2 = q3 * 150;
				break;						
			}
			switch (s)
			{
				case 'p':
				case 'P':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Pizza (s) value %d PKR",q1,price);
					break;
				case 'f':
				case 'F':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d French Fries (s) value %d PKR",q1,price);
					break;
				case 'b':
				case 'B':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Burger (s) value %d PKR",q1,price);
					break;
				case 's':
				case 'S':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Sandwich (es) value %d PKR",q1,price);
					break;		
			}
			switch (s1)
			{
				case 'p':
				case 'P':
				printf("\n%d Pizza (s) value %d PKR",q2,price1);
					break;
				case 'f':
				case 'F':
				printf("\n%d French Fries (s) value %d PKR",q2,price1);
					break;
				case 'b':
				case 'B':
				printf("\n%d Burger (s) value %d PKR",q2,price1);
					break;
				case 's':
				case 'S':
				printf("\n%d Sandwich (es) value %d PKR",q2,price1);
					break;		
			}
			switch (s2)
			{
				case 'p':
				case 'P':
				printf("\n%d Pizza (s) value %d PKR",q3,price2);
					break;
				case 'f':
				case 'F':
				printf("\n%d French Fries (s) value %d PKR",q3,price2);
					break;
				case 'b':
				case 'B':
				printf("\n%d Burger (s) value %d PKR",q3,price2);
					break;
				case 's':
				case 'S':
				printf("\n%d Sandwich (es) value %d PKR",q3,price2);
					break;		
			}
			printf("\nTotal: %d", price+price1+price2);
			printf("\nThankyou for your order... have a nice day!");
			break;	
		case 4:
			printf("Enter first snack you want to order:"); scanf(" %c", &s);
			printf("Please provide Quantity:"); scanf(" %d", &q1);
			switch (s)
			{
				case 'p':
				case 'P':
				pizza = pizza + q1;
				price = q1 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q1;
				price = q1 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q1;
				price = q1 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q1;
				price = q1 * 150;
				break;						
			}
			printf("Enter second snack you want to order:"); 
			scanf(" %c", &s1);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q2);
			switch (s1)
			{
				case 'p':
				case 'P':
				pizza = pizza + q2;
				price1 = q2 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q2;
				price1 = q2 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q2;
				price1 = q2 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q2;
				price1 = q2 * 150;
				break;						
			}
			printf("Enter second snack you want to order:"); 
			scanf(" %c", &s2);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q3);
			switch (s2)
			{
				case 'p':
				case 'P':
				pizza = pizza + q3;
				price2 = q3 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q3;
				price2 = q3 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q3;
				price2 = q3 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q3;
				price2 = q3 * 150;
				break;						
			}
			printf("Enter fourth snack you want to order:"); 
			scanf(" %c", &s3);
			printf("Please provide Quantity:"); 
			scanf(" %d", &q4);
			switch (s3)
			{
				case 'p':
				case 'P':
				pizza = pizza + q4;
				price3 = q4 * 500;
				break;
				case 'f':
				case 'F':
				fries = fries + q4;
				price3 = q4 * 50;
				break;
				case 'b':
				case 'B':
				burger = burger + q4;
				price3 = q4 * 200;
				break;
				case 's':
				case 'S':
				sand = sand + q4;
				price3 = q4 * 150;
				break;						
			}
			switch (s)
			{
				case 'p':
				case 'P':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Pizza (s) value %d PKR",q1,price);
					break;
				case 'f':
				case 'F':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d French Fries (s) value %d PKR",q1,price);
					break;
				case 'b':
				case 'B':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Burger (s) value %d PKR",q1,price);
					break;
				case 's':
				case 'S':
					printf("\n___________________________________________ \n\nYou have ordered!\n");
					printf("%d Sandwich (es) value %d PKR",q1,price);
					break;		
			}
			switch (s1)
			{
				case 'p':
				case 'P':
				printf("\n%d Pizza (s) value %d PKR",q2,price1);
					break;
				case 'f':
				case 'F':
				printf("\n%d French Fries (s) value %d PKR",q2,price1);
					break;
				case 'b':
				case 'B':
				printf("\n%d Burger (s) value %d PKR",q2,price1);
					break;
				case 's':
				case 'S':
				printf("\n%d Sandwich (es) value %d PKR",q2,price1);
					break;		
			}
			switch (s2)
			{
				case 'p':
				case 'P':
				printf("\n%d Pizza (s) value %d PKR",q3,price2);
					break;
				case 'f':
				case 'F':
				printf("\n%d French Fries (s) value %d PKR",q3,price2);
					break;
				case 'b':
				case 'B':
				printf("\n%d Burger (s) value %d PKR",q3,price2);
					break;
				case 's':
				case 'S':
				printf("\n%d Sandwich (es) value %d PKR",q3,price2);
					break;		
			}
			switch (s3)
			{
				case 'p':
				case 'P':
				printf("\n%d Pizza (s) value %d PKR",q4,price3);
					break;
				case 'f':
				case 'F':
				printf("\n%d French Fries (s) value %d PKR",q4,price3);
					break;
				case 'b':
				case 'B':
				printf("\n%d Burger (s) value %d PKR",q4,price3);
					break;
				case 's':
				case 'S':
				printf("\n%d Sandwich (es) value %d PKR",q4,price3);
					break;		
			}
			printf("\nTotal: %d", price+price1+price2+price3);
			printf("\nThankyou for your order... have a nice day!");
			break;	
	}
}





int main() 
{
	
	int choice;
	while(1)
	{
		printf("\tWelcome to FOODCART "); 
  
        printf("\n\n1)SIGNUP\n"); 
        printf("2)LOGIN\n3)ORDER FOOD\n\n"); 
        printf("Enter your choice\t"); 
        scanf("%d", &choice); 
  
        // Switch Cases 
        switch (choice) { 
  
        // For Signup Function 
        case 1: { 
            signup(); 
            break; 
        } 
  
      // For Login Function 
        case 2: {
            login(); 
            break; 
        } 
  //   for ordering food   
        case 3: { 
            orderfood();
			break; 
        } 
        case 4: { 
                printf("Thankyou for visiting FOODCART");
				exit(1);
        }
		default:{
			printf("\nEnter a valid choice\n\n");
			break;
		} 
        }
		 
	}
	return;
        
} 
