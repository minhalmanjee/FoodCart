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

  //successfully logged in 
    printf("\n\n\n**********you are successfully logged in*********** ");
	orderfood();               
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

