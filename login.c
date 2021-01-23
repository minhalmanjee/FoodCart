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

struct goods
{
    char name[50];
    char id[5];
    int age; //months of expiry
    char status[10]; //expired or not
    float wage;
} goods;

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
    char date_time[20];
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
    

	printf("Enter Your name :"); 
    scanf("%s", &customers.name); 
   
    
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
    	 if(strcmp(email, customers.email) == 0 && strcmp(pass, customers.pass) == 0)
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
    char id[5];
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
    	printf("\n\n\nChoose an option\n\n 1)Add A New Employee Record\n 2)View list of Employees\n 3)View Employee by name\n 4)View Employees by status(active or inactive)\n 5)Delivery history by area\n 6)Exit\n 7)Go to goods-admin");
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
            scanf("%s", &id);
            rewind(fp);
            while(fread(&employee, empsize, 1, fp))  //unique goods id
            {
				if(strcmp(id, employee.id) != 0)
            	continue;
            	else
            	{
            		printf("Enter unique Employee-id: ");
                    scanf("%s", &id);
                    rewind(fp);
				}
			}
			strcpy(employee.id, id);
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
                	 time_t curtime;
                     time ( &curtime );
                     strcpy(delivery.date_time, ctime (&curtime));
                	 strcpy(delivery.order, "Fries x2");
			         printf("\n\nName:\t %s", delivery.name);
			         printf("\nDate and Time:\t %s", delivery.date_time);
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
        case '7':{
        	admin2();
			break;
		}
			
		}
    }
    return;
}



void admin2()
{
    char emp_id[5], a, name[10], stat[10], view = 'y';
    int empsize = sizeof(struct goods);
    char add_record = 'y';
    char id[5];
    
    
     FILE *fp, *fn;                                 //file for employee rcd
     fp = fopen("goods.txt", "rb+");
	 if(fp == NULL)
     {
        fp = fopen("goods.txt","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
        }
     }
     
    while(1)
    {
    	printf("\n\n\nChoose an option\n\n 1)Add A New good Record\n 2)View list of goods\n 3)View raw goods by name\n 4)View raw goods by status(expired or unexpired)\n 5)Delete goods\n 6)Exit\n");
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
            scanf("%s", &goods.name);
            printf("Goods-ID: ");
            scanf("%s", &id);
            rewind(fp);
            while(fread(&goods, empsize, 1, fp))  //unique goods id
            {
				if(strcmp(id, goods.id) != 0)
            	continue;
    
            	else
            	{
            		printf("Enter unique goods-id: ");
                    scanf("%s", &id);
                    rewind(fp);
				}
			}
			strcpy(goods.id, id);
            printf("Status(expired or not): ");
            scanf("%s", &goods.status);
            printf("Price: ");
            scanf("%f", &goods.wage);
            fwrite(&goods,empsize,1,fp);
            printf("\nWould you like to add another record(y/n):");
            fflush(stdin);
            scanf("%c", &add_record);
			}
			break;
		
		case '2':
			rewind(fp);
			printf("\n\tName \tGoods-ID \tStatus \tPrice");
			while( fread(&goods, empsize, 1, fp))
            {
			printf("\n\n\t %s", goods.name);
			printf("\t%s", goods.id);
			printf("\t%s", goods.status);
            printf("\t%.2f", goods.wage);
            }               	
			break;
		
		case '3':
			view = 'y';
			while(view == 'y' || view == 'Y')
			{
				rewind(fp);
				printf("\nEnter the raw goods name to view details: ");
				fflush(stdin);
                scanf("%s", &name);
                while(fread(&goods, empsize, 1, fp))
                {
                	if(strcmp(name, goods.name) == 0)
                	{
			         printf("\n\nName:\t %s", goods.name);
			         printf("\nEmp-ID:\t %s", goods.id);
                     printf("\nBase Salary:\t %.2f", goods.wage);
                     printf("\nStatus: \t %s", goods.status);		                                    
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
				printf("\nEnter the status to view goods ");
				fflush(stdin);
                scanf("%s", &stat);
                while(fread(&goods, empsize, 1, fp))
                {
                	if(strcmp(stat, goods.status) == 0)
                	{
			         printf("\n\nName:\t %s", goods.name);
			         printf("\nEmp-ID:\t %s", goods.id);
                     printf("\nBase Salary:\t %.2f", goods.wage);
                     printf("\nStatus: \t %s", goods.status);		                                    
					}
				}  
				printf("\n\nWould you like to pass your query again(y/n):");
                fflush(stdin);
                scanf("%c", &view);              
			}
			break;
			
		case '5':
			system("cls");
			FILE * ft;
            char another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of goods to delete: ");
                scanf("%s", &name);
                ft = fopen("Temp.txt","wb");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(fread(&goods,empsize,1,fp) == 1)  /// read all records from file
                {
                    if(strcmp(goods.name,name) != 0)  /// if the entered record match
                    {
                        fwrite(&goods,empsize,1,ft); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("goods.txt"); /// remove the orginal file
                rename("Temp.txt","goods.txt"); /// rename the temp file to original file name
                fp = fopen("goods.txt", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
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
	 FILE * fcd = fopen("customerdetails.txt", "rb");
	int a,q1,q2,q3,q4;
		printf("\n\n\n\tFOOD CART MENU\n\t\tWelcome\n\nPlease select from the menu below\nB = Burger\nF = French Fries\nP = Pizza\nS = Sandwiches\nHow many types of snacks you want to order(Enter a number between 1 and 4):");
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
  
        printf("\n\n1)SIGNUP WITH FOODCART\n"); 
        printf("2)LOGIN TO ORDER\n3)EXIT\n\n"); 
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
        case 3: { 
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
