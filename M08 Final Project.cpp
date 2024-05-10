/*
Program Name: M08 Final Project.cpp
Author: Oladayo David Ayorinde
Date last revised:05/09/2024
Description: The program created several classes for the car dealership system. All of which have distinct private data members, and constructors, getter methods, setter methods, and functions are set where necessary. The main function creates a menu-driven program for the user to interact with the system. Input validation is set for the menu which is created with a switch statement. The program provides a simple interface to manage car inventory, customer orders, and employee transactions. The users are able to perform various tasks such as adding, updating, and removing cars from the inventory, and also placing orders, updating customer profiles, and processing sales.
*/

#include<iostream>
#include<string>
#include<vector>
#include<fstream> // For File I/O
#include<limits>
#include<stdexcept>

using namespace std;

class Car
{
    // Private attributes for the Car Class
    private:
        string make;
        string model;
        int year;
        double price;
        bool available;
    
    // Public attributes for the Car Class
    public:
        // Constructor for the Car Class
        Car(const string& make, const string& model, int year, double price, bool available) :
            make(make), model(model), year(year), price(price), available(available) {}

        // Getter methods for the attributes
        string getMake() const { return make; }
        string getModel() const { return model; }
        int getYear() const { return year; }
        double getPrice() const { return price; }
        bool isAvailable() const { return available; }

        // Setter methods for the attributes
        void setPrice(double newPrice) { price = newPrice; }
        void setAvailability(bool availability) { available = availability; }

        // Display car details
        void displayDetails() const
        {
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Price: $" << price << endl;
            cout << "Availability: " << (available ? "Yes" : "No") << endl;
        }

        // Function to reserve Car
        void reserveCar()
        {
            if (available)
            {
                available = false;
                cout << "Car reserved successfully!\n" << endl;
            }
            else 
            {
                cout << "Car is already reserved!\n" << endl;
            }
        }

        // Function to sell Car
        void sellCar()
        {
            if (available)
            {
                available = false;
                cout << "Car sold successfully!\n" << endl;
            }
            else
            {
                cout << "Car is not available for sale!\n" << endl;
            }
        }
};

class Customer
{
    // Private attributes for the Customer Class
    private:
        string firstName;
        string lastName;
        string email;
        string phoneNumber;
        vector<string> orderHistory; // This stores the order history
    
    // Public attributes for the Customer Class
    public:
        // Constructor for the Customer Class
        Customer(const string& firstName, const string& lastName, const string& email, const string& phoneNumber) : firstName(firstName), lastName(lastName), email(email), phoneNumber(phoneNumber) {}

        // Getter methods for the customer class
        string getFirstName() const { return firstName; }
        string getLastName() const { return lastName; }
        string getEmail() const { return email; }
        string getPhoneNumber() const { return phoneNumber; }

        // Function that allows to place an Order
        void placeOrder(const string& orderDetails)
        {
            orderHistory.push_back(orderDetails);
            cout << "Order placed successfully!\n" << endl;
        }

        // Function that updates the customer profile
        void updateProfile(const string& newEmail, const string& newPhoneNumber)
        {
            email = newEmail;
            phoneNumber = newPhoneNumber;
            cout << "Profile updated successfully!\n" << endl;
        }

        // Function to view order history
        void viewOrderHistory() const
        {
            cout << "Order History:" << endl;
            for (const auto& order : orderHistory)
            {
                cout << "- " << order << endl << endl;
            }
        }
};

class Employee
{
    // Private attributes for the Employee Class
    private:
        string name;
        string role;
    
    // Public attributes for the Employee Class
    public:
        // Constructor for the Employee Class
        Employee(const string& name, const string& role) :
            name(name), role(role) {}
    
    // Other methods (performSale, manageInventory, trackPerformance) as needed

    // Display employee details
    void displayDetails() const
    {
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
    }
};

class Transaction
{
    // Private attributes for the Transaction Class
    private:
        Car car;
        Customer customer;
        string saleDate;
        double transactionAmount;
    
    // Public attributes for the Transaction Class
    public:
        // Constructor for the Transaction Class
        Transaction(const Car& car, const Customer& customer, const string& saleDate, double amount) : car(car), customer(customer), saleDate(saleDate), transactionAmount(amount) {}

        // Getter Methods for the transaction class
        string getSaleDate() const { return saleDate; }
        double getTransactionAmount() const { return transactionAmount; }
    
    // Other methods (generateInvoive, calculateCommision) as needed
};

class InventoryManager
{
    // Private attributes for the InventoryManager Class
    private:
        vector<Car> inventory;
    
    // Public attributes for the InventoryManager Class
    public:
        // Functions that allows to add cars in the inventory
        void addCar(const Car& car)
        {
            inventory.push_back(car);
        }

        // Functions that allows to update cars in the inventory
        void updateCar(const string& make, const string& model, int year, double price)
        {
            for (auto& car : inventory)
            {
                if (car.getMake() == make && car.getModel() == model && car.getYear() == year)
                {
                    car.setPrice(price);
                    cout << "Car details updated successfully!\n" << endl;
                    return;
                }
            }
            cout << "Car not found in inventory!\n" << endl;
        }

        // Functions that allows to remove cars in the inventory
        void removeCar(const string& make, const string& model, int year)
        {
            for (auto it = inventory.begin(); it != inventory.end(); ++it)
            {
                if ((*it).getMake() == make && (*it).getModel() == model && (*it).getYear() == year)
                {
                    inventory.erase(it);
                    cout << "Car removed from inventory successfully!\n" << endl;
                    return;
                }
            }
            cout << "Car not found in inventory!\n" << endl;
        }

        // Functions that allows to search cars in the inventory
        vector<Car> searchCars(const string& make, const string& model, int year) const
        {
            vector<Car> searchResults;
            for (const auto& car : inventory)
            {
                if (car.getMake() == make && car.getModel() == model && car.getYear() == year)
                {
                    searchResults.push_back(car);
                }
            }
            cout << "\nResult for search details:" << endl;
            return searchResults;
        }

        // allows to filter cars by the price range
        vector<Car> filterCarsByPriceRange(double minPrice, double maxPrice) const
        {
            vector<Car> filteredCars;
            for (const auto& car : inventory)
            {
                if (car.getPrice() >= minPrice && car.getPrice() <= maxPrice)
                {
                    filteredCars.push_back(car);
                }
            }
            return filteredCars;
        }

        vector<Car> getInventory() const
        {
        return inventory;
        }
};

// Function to display inventory
void displayInventory(const vector<Car>& inventory)
{
    cout << "Inventory: " << endl;
    for (const auto& car : inventory)
    {
        car.displayDetails();
        cout << endl;
    }
}



int main ()
{
    cout << "Welcome to DAVE's CAR DEALERSHIP\nHow can we be of help today?" << endl;

    // Example usage
    InventoryManager manager;
    manager.addCar(Car("Toyota", "Camry", 2022, 25000.0, true));
    manager.addCar(Car("Honda", "Civic", 2021, 22000.0, true));

    // Declaration and initialization of customer object
    Customer customer("John", "Doe", "john@example.com", "123-456-7890");

    // Declaration of Transaction object
    Transaction transaction(manager.getInventory()[0], customer, "05/09/2024", 25000.0);

    
    // List of menu that the user can pick from
    int choice;
    do
    {
        cout << "Menu:\n1. Add Car\n2. Update Car\n3. Remove Car\n4. Search Car\n5. Filter Cars by Price Range\n6. Display Inventory\n7. Place Order\n8. Update Customer Profile\n9. View Customer Order History\n10. Process Sale\n0. Exit\n";
        cin >> choice;

        // This validates the user input
        if (cin.fail() || choice < 0 || choice > 10)
        {
            cout << "Invalid choice! Please enter a number between 0 and 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }


        switch (choice)
        {
            case 1:
            {
                string make, model;
                int year;
                double price;
                cout << "Enter car details:\nMake: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Year: ";
                cin >> year;
                cout << "Price: ";
                cin >> price;
                manager.addCar(Car(make, model, year, price, true));
                cout << "Car added successfully!\n" << endl;
                break;
            }
            case 2:
            {
                string make, model;
                int year;
                double price;
                cout << "Enter car details to update:\nMake: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Year: ";
                cin >> year;
                cout << "Enter new price: ";
                cin >> price;
                manager.updateCar(make, model, year, price);
                break;
            }
            case 3:
            {
                string make, model;
                int year;
                cout << "Enter car details to remove:\nMake: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Year: ";
                cin >> year;
                manager.removeCar(make, model, year);
                break;
            }
            case 4:
            {
                string make, model;
                int year;
                cout << "Enter car details to search:\nMake: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Year: ";
                cin >> year;
                vector<Car> searchResults = manager.searchCars(make, model, year);
                displayInventory(searchResults);
                break;
            }
            case 5:
            {
                double minPrice, maxPrice;
                cout << "Enter minimum price: ";
                cin >> minPrice;
                cout << "Enter maximum price: ";
                cin >> maxPrice;
                vector<Car> filteredCars = manager.filterCarsByPriceRange(minPrice, maxPrice);
                displayInventory(filteredCars);
                break;
            }
            case 6:
                displayInventory(manager.getInventory());
                break;
            case 7:
            {
                string firstName, lastName, email, phoneNumber, orderDetails;
                cout << "Enter customer details:\nFirst Name: ";
                cin >> firstName;
                cout << "Last Name: ";
                cin >> lastName;
                cout << "Email: ";
                cin >> email;
                cout << "Phone Number: ";
                cin >> phoneNumber;
                cout << "Enter order details: ";
                cin >> orderDetails;
                customer.placeOrder(orderDetails);
                break;
            }
            case 8:
            {
                string email, phoneNumber;
                cout << "Enter new email: ";
                cin >> email;
                cout << "Enter new phone number: ";
                cin >> phoneNumber;
                customer.updateProfile(email, phoneNumber);
                break;
            }
            case 9:
                customer.viewOrderHistory();
                break;
            case 10:
            {
                // Process sale functionality
                cout << "Processing sale..." << endl;
                // Example: Updating car availability
                manager.getInventory()[0].sellCar(); // Assuming the first car in inventory is sold

                // Create an employee object
                Employee employee("Alice", "Salesperson");

                // Example: Displaying transaction details
                cout << "Transaction details:" << endl;
                cout << "Car: " << manager.getInventory()[0].getMake() << " " << manager.getInventory()[0].getModel() << endl;
                cout << "Customer: " << customer.getFirstName() << " " << customer.getLastName() << endl;
                cout << "Contact Information:\n Email Address: " << customer.getEmail() << endl << "Phone Number: " << customer.getPhoneNumber() << endl;
                cout << "Sale Date: " << transaction.getSaleDate() << endl;
                cout << "Transaction Amount: $" << transaction.getTransactionAmount() << endl;
                break;
            }
            case 0:
            {
                cout << "Exiting program..." << endl;
                cin.get();
                break;
            }                
            default:
                cout <<  "Invalid choice! Please try again." << endl;
        }
    }
    while (choice != 0);

    cin.get();
    return 0;
}