#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
//#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
queue<string> q1;
queue<int> q2;
queue<string> q3;
queue<int> q4;
queue<int> q5;
queue<int> q6;
using namespace std;

void menu();

class ManageMenu
{
protected:
    string userName; // hide admin name

public:
    ManageMenu()
    {
        system("color 9F"); // change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu(); // call to main function to load after executing the constructr
    }

    ~ManageMenu() {} // de
};

class Customer
{
public:
    // char name[100];
    string name, gender, address, uid, mobileNo;
    int age, menuBack, f = 0;
    static int cusID;
    char all[999];

    void getDetails()
    {
        // static float lastCabCost = 0.0;
        // static float hotelCost = 0.0;
        f = 0;
        ofstream fout("cusid.txt", ios::app); // open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
        }
        // fout << cusID << endl;
        uid = to_string(cusID);
        fout.close();
        ifstream fin("cusid.txt");
        {
            if (!fin)
            {
                cout << "File Error!" << endl;
            }
            while (!(fin.eof()))
            {
                fin.getline(all, 999);
                if (all == uid)
                {
                    f = 1;
                    break;
                }
                f = 0;
            }
            if (f == 1)
            {
                cout << "Not Unique Id .... Re-enter details : " << endl;
                getDetails();
            }
            fin.close();
        }
        ofstream gout("cusid.txt", ios::app); // open file using append mode to write customer details
        gout << cusID << endl;
        gout.close();
        ofstream out("old-customers.txt", ios::app); // open file using append mode to write customer details
        {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            do
            {
                cout << "Enter valid Mobile Number: ";
                cin >> mobileNo;
            } while (mobileNo.length() != 10);
            // cout << "Enter Mobile Number: ";
            // cin >> mobileNo;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nPlease wait while we save your record!!\n"
             << endl;
        Sleep(1100);
        cout << "Saved!!" << endl;
        Sleep(1100);
        menu();
    }
    void showDetails() // function to show old customer records
    {
        ifstream in("old-customers.txt");
        {
            if (!in)
            {
                cout << "File Error!" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------ABC Cabs-----------\n"
             << endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;

        int hireCab;

        if (cabChoice == 1)
        {
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        for (int a = 0; a < 3; a++)
        {
            cout << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently we collaborated with above hotels!" << endl;

        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> choiceHotel;

        system("CLS");

        if (choiceHotel == 1)
        {
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n"
                 << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n"
                 << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 2)
        {
            cout << "-------WELCOME TO HOTEL CHOICEYOU-------\n"
                 << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by ChoiceYou:\n"
                 << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 3)
        {
            cout << "-------WELCOME TO HOTEL ELEPHANTBAY-------\n"
                 << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked ElephantBay Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }
};

float Booking::hotelCost;

class flight
{
public:
    char name[20], food[10];
    int ticket, mob, noc, fid, pid, dep, arr, time;
    static int s;
    static float bil;

    flight()
    {
        cout << "\n\t\t\t---- WELCOME TO ABC AIRWAYS ----   \n\n";
    }

    void list()
    {
        cout << "     ** FLIGHT DEPARTURE AND ARRIVAL TABLE **\n\n";
        cout << "Sno | Pack Id  |  Flight Id |  Departure  |   Landing   | Price |\n\n";
        cout << " 1  |   1001   |  FE-1235   |  Chennai    | Mumbai      | 4650* \n";
        cout << " 2  |   1002   |  FE-1250   |  Chennai    | Delhi       | 7650* \n";
        cout << " 3  |   1003   |  FE-3243   |  Chennai    | Singapore   | 21650* \n";
        cout << " 4  |   1004   |  FE-2786   |  Chennai    | Sydney      | 31999* \n";
        cout << " 5  |   1005   |  FE-3350   |  Chennai    | Auckland    | 30030* \n";
        cout << " *GST included\n\n";
    }

    flight book()
    {
    a:
        cout << "\t\t\t** ! BOOKING ! **\n\n";
        cout << "TICKETS REMAINING: ";
        cout << s << endl
             << endl;
        if (s > 0)
        {
            cout << "Enter the package id : ";
            cin >> pid;
            q6.push(pid);
            if (pid >= 1001 && pid <= 1005)
                cout << "\nPack is available !\n\n";
            else
            {
                cout << "Invalid pack !\n\n";
                goto a;
            }
            cout << "Name      : ";
            cin >> name;
            q1.push(name);
            cout << "Seats     : ";
            cin >> noc;
            q2.push(noc);
            cout << "Food      : ";
            cin >> food;
            q3.push(food);
            cout << "Departure : ";
            cin >> dep;
            q4.push(dep);
            cout << "Arrival   : ";
            cin >> arr;
            q5.push(arr);
            time = arr - dep;
            if (time < 0)
                cout << "Error ! Enter valid dates !\n\n";
            else
            {
                s -= noc;
                cout << endl;
                cout << "Congrats ! Your ticket has been booked ! Have a safe journey !\n";
                cout << endl;
            }
        }
    }

    flight bill()
    {
        if (pid == 1001)
            bil += 4650 * noc;
        else if (pid == 1002)
            bil += 7650 * noc;
        else if (pid == 1003)
            bil += 21650 * noc;
        else if (pid == 1004)
            bil += 31999 * noc;
        else if (pid == 1005)
            bil += 30030 * noc;
        else
            cout << "The pack isnt available now !\n";
    }

    flight details()
    {
        bill();
        cout << "\t\t\t** TRAVEL DETAILS **\n\n";
        cout << "Name     : " << q1.front() << endl;
        cout << "Seats    : " << q2.front() << endl;
        cout << "Dep date : " << q4.front() << endl;
        cout << "Arr date : " << q5.front() << endl;
        // cout<<"Journey  : "<<time<<" days "<<endl;
        cout << "Food     : " << q3.front() << endl;
        cout << "Bill     : Rs. " << bil << endl
             << endl;
    }
};

float flight::bil = 0.0;
int flight::s = 500;

class Chargers : public Booking, Cabs, Customer, flight // Multiple Inheritance of some other classes to Chargers
{

public:
    void printBill()
    {
        ofstream outf("receipt.txt"); // receipt for bought items
        {
            outf << "--------ABC Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl
                 << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outf << "Travel (flight) cost:\t " << fixed << setprecision(2) << flight::bil << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost + flight::bil << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        // cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu() // menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * ABC Travels *\n"
         << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    // cout << "\t|\tAgency System Management -> 0" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tHotel Booking Management -> 3\t|" << endl;
    cout << "\t|\tFlight Booking Management-> 4\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 5\t|" << endl;
    cout << "\t|\tExit                -> 6\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; // creating objects
    Cabs a3;
    Booking a4;
    Chargers a5;
    flight f;

    /*if(mainChoice == 0){

    }*/
    if (mainChoice == 1)
    {
        cout << "------Customers------\n"
             << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            a3.lastCabCost = 0.0;
            a4.hotelCost = 0.0;
            f.bil = 0.0;
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "--> Book a Luxury Hotel using the System <--\n"
             << endl;
        a4.hotels();
    }
    else if (mainChoice == 4)
    {
        // flight f;
        int ch;
        cout << "**1. Available Flights ** ** 2. Booking ** ** 3. Details ** ** 4. Go to main menu ** \n\n";
        cin >> ch;
        while (1)
        {
            switch (ch)
            {
            case 1:
                f.list();
                break;
            case 2:
                f.book();
                break;
            case 3:
                f.details();
                break;
            case 4:
                menu();
            }
            cout << "**1. Available Flights ** ** 2. Booking ** ** 3. Details ** ** 4. Go to main menu ** \n\n";
            cin >> ch;
        }
        cout << "Enter a key to go back to main menu: ";
        cin >> ch;
        menu();
    }
    else if (mainChoice == 5)
    {
        cout << "-->Get your receipt<--\n"
             << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n"
             << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 6)
    {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    system("CLS");
    ManageMenu startObj;
    return 0;
}