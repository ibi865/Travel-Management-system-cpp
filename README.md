# Travel Management System - Keep Smiling Travel Agency

## Overview
This C++ program is a comprehensive travel management system for "Keep Smiling Travel Agency". It allows customers to book various travel services including flights, hotels, transportation, and food orders. The system also handles customer details and payment methods, with functionality to save and load data to/from files.

## Features

### 1. Customer Management
- Add and store customer details including:
  - Guest ID
  - Name
  - Address
  - Gender

### 2. Booking Services
- **Airplane Booking**:
  - Choose departure and arrival cities (Lahore, Islamabad, Karachi)
  - Select ticket type (Economy, Business, First Class) with fixed prices
- **Hotel Booking**:
  - Choose from 3 hotels with different room prices
  - Specify number of nights
- **Transport Booking**:
  - Book trains, buses, or taxis between cities
  - Fixed prices for each transport type
- **Food Ordering**:
  - Choose from a menu of meal options (Quarter, Half, Full) with set prices

### 3. Payment System
- Add payment methods with:
  - Cardholder name
  - Card number
  - Expiration date
  - CVV code

### 4. Data Management
- Save all bookings and customer data to a file
- Load previously saved data from a file
- Generate receipts with total costs

### 5. Security
- Password-protected login system (default password: "pass")

## Technical Details

### Classes
The system uses multiple classes with inheritance:
- **Customer**: Base class for customer information
- **Booking**: Base booking class
- Specialized booking classes:
  - `AirplaneBooking`
  - `HotelBooking`
  - `TransportBooking`
  - `FoodBooking`
- **PaymentMethod**: Handles payment information
- **TravelManagementSystem**: Main class that inherits from all others and provides the interface

### File Handling
- Data is saved in a structured text format
- Receipts are generated as separate text files

## How to Use

1. **Login**: Enter the password "pass" at the login screen
2. **Main Menu**: Choose from the following options:
   - 0: Add customer details
   - 1: Book airplane tickets
   - 2: Book hotels
   - 3: Book transportation
   - 4: Order food
   - 5: Add payment method
   - 6: Display all bookings
   - 7: Calculate total cost
   - 8: Save/Load data
   - 9: Exit

3. **Navigation**: Follow the on-screen prompts to complete bookings
4. **Data Persistence**: Save your bookings to a file before exiting

## Requirements
- C++ compiler (tested with Windows)
- Standard C++ libraries:
  - iostream
  - string
  - fstream
  - sstream
  - windows.h (for Windows-specific functions)
  - iomanip
  - limits
  - conio.h (for password input)

## Notes
- The program uses Windows-specific functions for color and screen clearing
- All prices are in Pakistani Rupees (PKR)
- The system is designed for single-user operation

## Future Enhancements
- Add more cities and travel options
- Implement a database backend instead of file storage
- Add user registration with multiple accounts
- Include more payment options
- Add cancellation and modification features

Enjoy using the Keep Smiling Travel Agency management system!
