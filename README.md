OOP Food Cart Management System
Introduction
Welcome to the OOP Food Cart Management System project! This project demonstrates an object-oriented approach to managing a simple food cart operation. It allows users to sign up, log in, place orders, and provides an admin panel for managing employees, goods, and deliveries.

Features
User Registration and Login:

Users can create an account with validation for email, password, and contact details.
Users can log in using their email and password.
Admin Panel:

Employee Management:
Add, view, search, and manage employee records.
Goods Management:
Add, view, search, and manage inventory, including status checks (e.g., expired goods).
Delivery Management:
Track delivery history by area.
Order Management:

Users can order food items like burgers, fries, pizza, and sandwiches.
The system calculates and displays the total price based on the quantity ordered.
Project Structure
The project contains several structures and functions to handle the operations:

Structures
Address:

Stores address details such as house number, street number, area, and city.
Customers:

Stores customer details like name, email, password, contact number, and address.
Goods:

Manages inventory items, tracking name, ID, expiry status, and price.
Employee:

Handles employee records, including name, ID, age, delivery area, status, and salary.
Delivery:

Manages delivery details such as name, date/time, price, and order details.
Key Functions
Passvalid(char *pass): Validates password strength, ensuring it contains uppercase, lowercase, numbers, and special characters.
signup(): Handles user registration, including validation and saving data to a file.
login(): Manages user login and redirects based on user type (admin or customer).
admin(): The main admin panel for managing employees and deliveries.
admin2(): A secondary admin panel for managing goods.
orderfood(): Allows users to place food orders and calculates the total cost.
Getting Started
Prerequisites
Compiler: You will need a C compiler (e.g., GCC) to compile and run the project.
Operating System: This project is developed for Windows. It utilizes conio.h and windows.h, which are specific to Windows environments.
Running the Project
Clone the Repository:

bash
Copy code
git clone https://github.com/minhalmanjee/FoodCart.git
cd OOP-Food-Cart-Management
Compile the Code:

bash
Copy code
gcc -o foodcart main.c
Run the Executable:

bash
Copy code
./foodcart
Follow the On-Screen Instructions: The system will guide you through user registration, login, and food ordering.

Contribution
Feel free to fork the repository, create feature branches, and submit pull requests. All contributions are welcome!

License
This project is licensed under the MIT License - see the LICENSE file for details.

Contact
For any inquiries or further information, please reach out to the project maintainer at your minhal.manjee@gmail.com

