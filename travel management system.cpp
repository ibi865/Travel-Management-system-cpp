#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include<conio.h>

//view the output in full screen

using namespace std;

class Customer {
protected:
    string guest_ID;
    string guest_name;
    string guest_address;
    string guest_gender;

public:
    Customer(string ID, string name, string address, string gender)
        : guest_ID(ID), guest_name(name), guest_address(address), guest_gender(gender) {}

    string getID() const {
        return guest_ID;
    }

    string getName() const {
        return guest_name;
    }

    string getAddress() const {
        return guest_address;
    }

    string getGender() const {
        return guest_gender;
    }

    string getDetails() const {
        return "Guest ID: " + guest_ID + "\nName: " + guest_name + "\nAddress: " + guest_address + "\nGender: " + guest_gender;
    }
};

class Booking {
protected:
    string guest_name;

public:
    Booking() {}  // Default constructor

    Booking(string name)
        : guest_name(name) {}

    string getGuestName() const {
        return guest_name;
    }
};

class AirplaneBooking : virtual public Booking {
protected:
    string departure_city;
    string arrival_city;
    double ticket_price;

public:
    AirplaneBooking(string name, string departure, string arrival, double price)
        : Booking(name), departure_city(departure), arrival_city(arrival), ticket_price(price) {}

    string getDepartureCity() const {
        return departure_city;
    }

    string getArrivalCity() const {
        return arrival_city;
    }

    double getTicketPrice() const {
        return ticket_price;
    }
};

class HotelBooking : virtual public Booking {
protected:
    string hotel_name;
    int num_of_nights;
    double room_price;

public:
    HotelBooking(string name, string hotel, int nights, double price)
        : Booking(name), hotel_name(hotel), num_of_nights(nights), room_price(price) {}

    string getHotelName() const {
        return hotel_name;
    }

    int getNumOfNights() const {
        return num_of_nights;
    }

    double getRoomPrice() const {
        return room_price;
    }
};

class TransportBooking :  public Booking {
protected:
    string departure_city;
    string arrival_city;
    string transport_type;
    double ticket_price;

public:
    TransportBooking(string name, string departure, string arrival, string type, double price)
        : Booking(name), departure_city(departure), arrival_city(arrival), transport_type(type), ticket_price(price) {}

    string getDepartureCity() const {
        return departure_city;
    }

    string getArrivalCity() const {
        return arrival_city;
    }

    string getTransportType() const {
        return transport_type;
    }

    double getTicketPrice() const {
        return ticket_price;
    }
};

class FoodBooking : virtual public Booking {
protected:
    string food_item;
    double item_price;

public:
    FoodBooking(string name, string item, double price)
        : Booking(name), food_item(item), item_price(price) {}

    string getFoodItem() const {
        return food_item;
    }

    double getItemPrice() const {
        return item_price;
    }
};

class PaymentMethod : virtual public Booking {
protected:
    string card_holder_name;
    string card_number;
    string expiration_date;
    int cvv_code;

public:
    PaymentMethod(string name, string number, string date, int cvv)
        : Booking(name), card_holder_name(name), card_number(number), expiration_date(date), cvv_code(cvv) {}

    string getCardHolderName() const {
        return card_holder_name;
    }

    string getCardNumber() const {
        return card_number;
    }

    string getExpirationDate() const {
        return expiration_date;
    }

    int getCvvCode() const {
        return cvv_code;
    }
};

class TravelManagementSystem : public Customer, public AirplaneBooking, public HotelBooking, public TransportBooking, public FoodBooking, public PaymentMethod {


public:
    public:
    TravelManagementSystem()
        : Customer("", "", "", ""), Booking(""), AirplaneBooking("", "", "", 0), HotelBooking("", "", 0, 0.0), TransportBooking("", "", "", "", 0), FoodBooking("", "", 0), PaymentMethod("", "", "", 0) {}

    TravelManagementSystem(string ID, string name, string address, string gender,
        string guestName, string departure, string arrival, double price,
        string hotel, int nights, double roomPrice,
        string transportName, string transportDeparture, string transportArrival, string transportType, double transportPrice,
        string foodGuestName, string foodItem, double foodPrice,
        string paymentGuestName, string cardNumber, string expirationDate, int cvvCode)
        : Customer(ID, name, address, gender),
          Booking(guestName),
          AirplaneBooking(guestName, departure, arrival, price),
          HotelBooking(guestName, hotel, nights, roomPrice),
          TransportBooking(transportName, transportDeparture, transportArrival, transportType, transportPrice),
          FoodBooking(foodGuestName, foodItem, foodPrice),
          PaymentMethod(paymentGuestName, cardNumber, expirationDate, cvvCode) {}
   

    void addCustomer(const Customer& customer) {
        Customer::guest_ID = customer.getID();
        Customer::guest_name = customer.getName();
        Customer::guest_address = customer.getAddress();
        Customer::guest_gender = customer.getGender();
    }

    void bookAirplane(const AirplaneBooking& booking) {
        AirplaneBooking::guest_name = booking.getGuestName();
        AirplaneBooking::departure_city = booking.getDepartureCity();
        AirplaneBooking::arrival_city = booking.getArrivalCity();
        AirplaneBooking::ticket_price = booking.getTicketPrice();
    }

    void bookHotel(const HotelBooking& booking) {
        HotelBooking::guest_name = booking.getGuestName();
        HotelBooking::hotel_name = booking.getHotelName();
        HotelBooking::num_of_nights = booking.getNumOfNights();
        HotelBooking::room_price = booking.getRoomPrice();
    }

    void bookTransport(const TransportBooking& booking) {
        TransportBooking::guest_name = booking.getGuestName();
        TransportBooking::departure_city = booking.getDepartureCity();
        TransportBooking::arrival_city = booking.getArrivalCity();
        TransportBooking::transport_type = booking.getTransportType();
        TransportBooking::ticket_price = booking.getTicketPrice();
    }

   void orderFood(const FoodBooking& booking) {
        FoodBooking::food_item = booking.getFoodItem();
        FoodBooking::item_price = booking.getItemPrice();
    }

    void addPaymentMethod(const PaymentMethod& method) {
        PaymentMethod::card_holder_name = method.getCardHolderName();
        PaymentMethod::card_number = method.getCardNumber();
        PaymentMethod::expiration_date = method.getExpirationDate();
        PaymentMethod::cvv_code = method.getCvvCode();
    }

    void displayBookings() {
    cout << "Customer Details:" << endl;
    cout << Customer::getDetails() << endl;
    cout << endl;

    cout << "Airplane Booking:" << endl;
    cout << "Guest Name: " << AirplaneBooking::getGuestName() << endl;
    cout << "Departure City: " << AirplaneBooking::getDepartureCity() << endl;
    cout << "Arrival City: " << AirplaneBooking::getArrivalCity() << endl;
    cout << "Ticket Price: " << AirplaneBooking::getTicketPrice() << endl;
    cout << endl;

    cout << "Hotel Booking:" << endl;
    cout << "Guest Name: " << HotelBooking::getGuestName() << endl;
    cout << "Hotel Name: " << HotelBooking::getHotelName() << endl;
    cout << "Number of Nights: " << HotelBooking::getNumOfNights() << endl;
    cout << "Room Price: " << HotelBooking::getRoomPrice() << endl;
    cout << endl;

    cout << "Transport Booking:" << endl;
    cout << "Passenger Name: " << TransportBooking::getGuestName() << endl;
    cout << "Departure City: " << TransportBooking::getDepartureCity() << endl;
    cout << "Arrival City: " << TransportBooking::getArrivalCity() << endl;
    cout << "Transport Type: " << TransportBooking::getTransportType() << endl;
    cout << "Ticket Price: " << TransportBooking::getTicketPrice() << endl;
    cout << endl;

    cout << "Food Bookings:" << endl;
    cout << "Customer Name: " << FoodBooking::getGuestName() << endl;
    cout << "Food Item: " << FoodBooking::getFoodItem() << endl;
    cout << "Item Price: " << FoodBooking::getItemPrice() << endl;
    cout << endl;

    cout << "Payment Method:" << endl;
    cout << "Customer Name: " << PaymentMethod::getGuestName() << endl;
    cout << "Card Holder Name: " << PaymentMethod::getCardHolderName() << endl;
    cout << "Card Number: " << PaymentMethod::getCardNumber() << endl;
    cout << "Expiration Date: " << PaymentMethod::getExpirationDate() << endl;
    cout << "CVV Code: " << PaymentMethod::getCvvCode() << endl;
}
   

double readDoubleValue(const string& valueStr) {
        istringstream iss(valueStr);
        double value;
        iss >> value;
        return value;
    }



   double calculateTotalCost() {
    double totalCost = 0.0;

    totalCost += TransportBooking::getTicketPrice();
    totalCost += getRoomPrice() * getNumOfNights();
    totalCost += TransportBooking::getTicketPrice();

    
    totalCost += getItemPrice();

    
    string receiptFilename = "receipt.txt";
    printReceiptToFile(receiptFilename, totalCost);

    return totalCost;
}

    

  void saveDataToFile(const string& filename) {
    ofstream file(filename.c_str(),ios::app);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    // Save customer details
    file <<"CustomerBooking :"<<endl<< "ID: " << Customer::getID() << endl << "Name: " << Customer::getName() << endl << "Address: " << Customer::getAddress() << endl << "Gender: " << Customer::getGender() << endl;

    // Save airplane booking details
    file << "AirplaneBooking:" << endl  << AirplaneBooking::getGuestName() << endl << AirplaneBooking::getDepartureCity() << endl
         << AirplaneBooking::getArrivalCity() << endl<< fixed << setprecision(2) << AirplaneBooking::getTicketPrice() << endl;

    // Save hotel booking details
    file <<"HotelBooking :" <<endl  << HotelBooking::getGuestName() << endl  << HotelBooking::getHotelName() << endl
    << HotelBooking::getNumOfNights() << endl  << fixed << setprecision(2) << HotelBooking::getRoomPrice() << endl;

    // Save transport booking details
    file << "TransportBooking:" << endl  << TransportBooking::getGuestName() << endl  << TransportBooking::getDepartureCity() << endl
         << TransportBooking::getArrivalCity() << endl << TransportBooking::getTransportType() << endl
        << fixed << setprecision(2) << TransportBooking::getTicketPrice() << endl;

    // Save food bookings
    file << "FoodBooking:" << endl <<FoodBooking:: getGuestName() << endl << FoodBooking::getFoodItem() << endl
        << fixed << setprecision(2) << FoodBooking::getItemPrice() << endl;

    file.close();
    cout << "Data saved to file." << endl;
}




   void loadDataFromFile(const string& filename) {
    ifstream file(filename.c_str(),ios::app);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

   
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        ss >> type;

        if (type == "Customer:") {
            string ID, name, address, gender;
            getline(file, ID);
            getline(file, name);
            getline(file, address);
            getline(file, gender);

      
           
            Customer::guest_ID = ID;
            Customer::guest_name = name;
            Customer::guest_address = address;
            Customer::guest_gender = gender;
        } else if (type == "AirplaneBooking:") {
            string name, departure, arrival, priceStr;
            double price;
            ss >> name;
            getline(file, name); 
            getline(file, departure);
            getline(file, arrival);
            getline(file, priceStr);
            price = readDoubleValue(priceStr); 

            bookAirplane(AirplaneBooking(name, departure, arrival, price));
        } else if (type == "HotelBooking:") {
            string name, hotel, nightsStr, priceStr;
            int nights;
            double price;
            ss >> name;
            getline(file, name); 
            getline(file, hotel);
            getline(file, nightsStr);
            nights = atoi(nightsStr.c_str());
            getline(file, priceStr);
            price = readDoubleValue(priceStr);

            bookHotel(HotelBooking(name, hotel, nights, price));
        } else if (type == "TransportBooking:") {
            string name, departure, arrival, transportType, priceStr;
            double price;
            ss >> name;
            getline(file, name); 
            getline(file, departure);
            getline(file, arrival);
            getline(file, transportType);
            getline(file, priceStr);
            price = readDoubleValue(priceStr); 
            bookTransport(TransportBooking(name, departure, arrival, transportType, price));
        } else if (type == "FoodBooking:") {
            string customerName, foodItem, priceStr;
            double price;
            ss >> customerName;
            getline(file, customerName); 
            getline(file, foodItem);
            getline(file, priceStr);
            price = readDoubleValue(priceStr); 

            orderFood(FoodBooking(customerName, foodItem, price));
        }
        

    }

    file.close();
    cout << "Data loaded from file." << endl;
}



    
    void printReceiptToFile(const string& filename, double totalCost) {
    ofstream file(filename.c_str(), ios::app);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

            file << "--------Keep Smiling Travel Agency--------" << endl;
            file << "-------------Receipt-------------" << endl;
            file << "_________________________________" << endl;

            file << "Customer ID: " << Customer::guest_ID << endl << endl;
            file << "Description\t\t Total" << endl;
            file << "Hotel cost:\t\t " << fixed << setprecision(2) <<  getRoomPrice() << endl;
            file << "Transport:\t\t " << fixed << setprecision(2) <<TransportBooking::getTicketPrice() << endl;
            file << "Others:\t\t" <<fixed << setprecision(2) <<totalCost- getRoomPrice()-TransportBooking::getTicketPrice()<<endl;
            

            file << "_________________________________" << endl;
            file << "Total Charge:\t\t " << fixed << setprecision(2) << totalCost << endl;
            file << "_________________________________" << endl;
            file << "------------THANK YOU------------" << endl;
    file.close();
    cout << "Receipt saved to file." << endl;
}


};
int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  KEEP SMILING TRAVEL AGENCY \n\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) { 
        if (ch == 8) { 
            if (!pass.empty()) {
                pass.erase(pass.size() - 1);
                cout << "\b \b"; 
            }
        } else {
            pass.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }

    if (pass == "pass") {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
        system("PAUSE");
        system("CLS");
        login();
    }
    return 0;
}


int main() {

    system("color 7D");
    TravelManagementSystem tms;
    int choice;
    string ID,name, departure, arrival, hotel, type, item, address, gender, filename;
    double price, totalCost;
    int nights;
    int cvv;

   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                          KEEP SMILING TRAVEL AGENCY                                   |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                -By:     Ayesha                        |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
    system("color 0A");
int i;
int login();
login();
    do {
    	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  KEEP SMILING TRAVEL AGENCY \n\n";
        cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             0  >> Customer Details                              |\n";
        cout<<"\t\t\t\t\t\t|             1  >> Book Airplane                                 |\n";
        cout<<"\t\t\t\t\t\t|             2  >> Book a Hotel                                  |\n";
        cout<<"\t\t\t\t\t\t|             3  >> Book Transport                                |\n";
        cout<<"\t\t\t\t\t\t|             4  >> Order Food                                    |\n";
        cout<<"\t\t\t\t\t\t|             5  >> Add a Payment Method                          |\n";
        cout<<"\t\t\t\t\t\t|             6  >> Display ALL Bookings                          |\n";
        cout<<"\t\t\t\t\t\t|             7  >> Calculate Total Cost                          |\n";
        cout<<"\t\t\t\t\t\t|             8  >> Save and Load Data                            |\n";
        cout<<"\t\t\t\t\t\t|             9  >> Exit                                          |\n";
        cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
       
 a: cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;

    if (cin.fail()) {
        // Handle invalid input
        cout << "Invalid input. Please enter a valid choice." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto a;
    }

    if (choice > 9 || choice < 0) {
        cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
        cout << "\t\t\t\t\t\tTry again...........\n\n";
        goto a;
    }
         
        system("CLS");

        switch (choice) {
            case 0:
                cout << "Enter Guest ID: ";
                cin.ignore();
                getline(cin, ID);
                cout << "Enter Guest Name: ";
                getline(cin, name);
                cout << "Enter Guest Address: ";
                getline(cin, address);
                cout << "Enter Guest Gender: ";
                getline(cin, gender);
                tms.addCustomer(Customer(ID, name, address, gender));

                cout << "Customer details added." << endl;
                break;

        case 1:
{
    cout << "Enter Passenger Name: ";
    cin.ignore();
    getline(cin, name);


    string departureCity;
    string arrivalCity;

    // Display city options for departure
    cout << "Choose Departure City:" << endl;
    cout << "1. Lahore" << endl;
    cout << "2. Islamabad" << endl;
    cout << "3. Karachi" << endl;
    int departureChoice;
    cin >> departureChoice;

    // Assign departure city based on the choice
    switch (departureChoice) {
        case 1:
            departureCity = "Lahore";
            break;
        case 2:
            departureCity = "Islamabad";
            break;
        case 3:
            departureCity = "Karachi";
            break;
        default:
            cout << "Invalid choice. Departure city not set." << endl;
            continue;
    }

    // Display city options for arrival
    cout << "Choose Arrival City:" << endl;
    cout << "1. Lahore" << endl;
    cout << "2. Islamabad" << endl;
    cout << "3. Karachi" << endl;
    int arrivalChoice;
    cin >> arrivalChoice;

    // Assign arrival city based on the choice
    switch (arrivalChoice) {
        case 1:
            arrivalCity = "Lahore";
            break;
        case 2:
            arrivalCity = "Islamabad";
            break;
        case 3:
            arrivalCity = "Karachi";
            break;
        default:
            cout << "Invalid choice. Arrival city not set." << endl;
            continue;
    }

    // Fixed price choices for airplane ticket
    cout << "Choose Ticket Type:" << endl;
    cout << "1. Economy - Price: 10000.99" << endl;
    cout << "2. Business - Price: 15000.99" << endl;
    cout << "3. First Class - Price: 20000.99" << endl;
    int ticketChoice;
    cin >> ticketChoice;

    double ticketPrice;
    switch (ticketChoice) {
        case 1:
            ticketPrice = 10000.99;
            break;
        case 2:
            ticketPrice = 15000.99;
            break;
        case 3:
            ticketPrice = 20000.99;
            break;
        default:
            cout << "Invalid ticket choice. Airplane not booked." << endl;
            continue;
    }

   tms.bookAirplane(AirplaneBooking(name, departureCity, arrivalCity, ticketPrice));

    cout << "Airplane booked." << endl;
}
break;

            case 2:
             {
    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, name);

    // Display hotel options
    cout << "Choose Hotel:" << endl;
    cout << "1. Hotel Avendra" << endl;
    cout << "2. Hotel Lakeview" << endl;
    cout << "3. Hotel Rex" << endl;
    int hotelChoice;
    cin >> hotelChoice;

   
    string hotel;
    double roomPrice;
    switch (hotelChoice) {
        case 1:
            hotel = "Hotel Avendra";
            roomPrice = 1500.0;
            break;
        case 2:
            hotel = "Hotel Lakeview";
            roomPrice = 2000.0;
            break;
        case 3:
            hotel = "Hotel Rex";
            roomPrice = 2500.0;
            break;
        default:
            cout << "Invalid hotel choice. Hotel not booked." << endl;
            continue;
    }

    cout << "Enter Number of Nights: ";
    cin >> nights;

    tms.bookHotel(HotelBooking(name, hotel, nights, roomPrice));

    cout << "Hotel booked." << endl;
}
break;

            case 3:
{
    

    cout << "Enter Passenger Name: ";
    cin.ignore();
    getline(cin, name);

    string transportDepartureCity;
    string transportArrivalCity;

   
    cout << "Choose Departure city for Transport:" << endl;
    cout << "1. Lahore" << endl;
    cout << "2. Islamabad" << endl;
    cout << "3. Karachi" << endl;
    int transportDepartureChoice;
    cin >> transportDepartureChoice;

  
    switch (transportDepartureChoice) {
        case 1:
            transportDepartureCity = "Lahore";
            break;
        case 2:
            transportDepartureCity = "Islamabad";
            break;
        case 3:
            transportDepartureCity = "Karachi";
            break;
        default:
            cout << "Invalid choice. Departure city for transport not set." << endl;
            continue;
    }

    // Display city options for arrival
    cout << "Choose Arrival City for Transport:" << endl;
    cout << "1. Lahore" << endl;
    cout << "2. Islamabad" << endl;
    cout << "3. Karachi" << endl;
    int transportArrivalChoice;
    cin >> transportArrivalChoice;

    // Assign arrival city based on the choice
    switch (transportArrivalChoice) {
        case 1:
            transportArrivalCity = "Lahore";
            break;
        case 2:
            transportArrivalCity = "Islamabad";
            break;
        case 3:
            transportArrivalCity = "Karachi";
            break;
        default:
            cout << "Invalid choice. Arrival city for transport not set." << endl;
            continue;
    }

   
    cout << "Choose Transport Type:" << endl;
    cout << "1. Train - Price: 6000.99" << endl;
    cout << "2. Bus - Price: 3500.99" << endl;
    cout << "3. Taxi - Price: 10000.99" << endl;
    int transportTypeChoice;
    cin >> transportTypeChoice;

    string type;
    double ticketPrice;
    switch (transportTypeChoice) {
        case 1:
            type = "Train";
            ticketPrice = 1550.99;
            break;
        case 2:
            type = "Bus";
            ticketPrice = 1800.99;
            break;
        case 3:
            type = "Taxi";
            ticketPrice = 2000.99;
            break;
        default:
            cout << "Invalid choice. Transport type not set." << endl;
            continue;
    }

    tms.bookTransport(TransportBooking(name, transportDepartureCity, transportArrivalCity, type, ticketPrice));

    cout << "Transport booked." << endl;
}
break;

            case 4:
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, name);

                // Display food menu
                cout << "Food Menu:" << endl;
                cout << "1. Quarter Meal" << endl;
                cout << "2. Half Meal" << endl;
                cout << "3. Full Meal" << endl;
                cout << "Enter your choice: ";
                int foodChoice;
                cin >> foodChoice;

                switch (foodChoice) {
                    case 1:
                        item = "Quarter Meal";
                        price = 1000.99;
                        break;
                    case 2:
                        item = "Half Meal";
                        price = 1500.99;
                        break;
                    case 3:
                        item = "Full Meal";
                        price = 2000.99;
                        break;
                    default:
                        cout << "Invalid food choice. Food not ordered." << endl;
                        continue;
                }

                tms.orderFood(FoodBooking(name, item, price));
                cout << "Food ordered." << endl;
                break;

            case 5:
                cout << "Enter Card Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Card Number: ";
                getline(cin, departure);
                cout << "Enter Expiration Date: ";
                getline(cin, arrival);
                cout << "Enter CVV Code: ";
                cin >> cvv;
                tms.addPaymentMethod(PaymentMethod(name, departure, arrival, cvv));

                cout << "Payment method added." << endl;
                break;

            case 6:
                tms.displayBookings();
                break;

            case 7:
                 totalCost = tms.calculateTotalCost();
            cout << "Total Cost: " << totalCost << endl;
            break;

            case 8:
                int saveLoadChoice;
                cout << "Choose an option:" << endl;
                cout << "1. Save data to file" << endl;
                cout << "2. Load data from file" << endl;
                cout << "Enter your choice: ";
                cin >> saveLoadChoice;

                if (saveLoadChoice == 1) {
                    cout << "Enter filename to save data: ";
                    cin >> filename;
                    tms.saveDataToFile(filename);
                }
                else if (saveLoadChoice == 2) {
                    cout << "Enter filename to load data from: ";
                    cin >> filename;
                    tms.loadDataFromFile(filename);
                }
                else {
                    cout << "Invalid choice." << endl;
                }
                break;

            case 9:
               system("color 7D");
               tms.saveDataToFile(filename);
               cout << "Exiting the program..." << endl;
               cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                            KEEP SMILING TRAVEL AGENCY                                 |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
               
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
        
        system("pause");
        system("CLS");
    } while (choice != 9);return 0;}
