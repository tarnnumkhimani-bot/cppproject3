#include<iostream>
using namespace std;

class Vehicle
{
private:
    int id;
    string manufacturer, model;
    int year;

public:
    static int total;

    Vehicle()
    {
        id = 0;
        year = 0;
        total++;
    }

    Vehicle(int i, string m, string mo, int y)
    {
        id = i;
        manufacturer = m;
        model = mo;
        year = y;
        total++;
    }

    void setID(int i)
    {
        id = i;
    }

    int getID()
    {
        return id;
    }

    void input()
    {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;
    }

    void show()
    {
        cout << "ID: " << id << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    ~Vehicle()
    {
        total--;
    }
};

int Vehicle::total = 0;

class Car : public Vehicle
{
public:
    string fuel;

    void inputCar()
    {
        input();
        cout << "Enter Fuel Type: ";
        cin >> fuel;
    }

    void showCar()
    {
        show();
        cout << "Fuel Type: " << fuel << endl;
    }
};

class ElectricCar : public Car
{
public:
    int battery;

    void inputElectric()
    {
        inputCar();
        cout << "Enter Battery Capacity: ";
        cin >> battery;
    }

    void showElectric()
    {
        showCar();
        cout << "Battery: " << battery << endl;
    }
};

class Aircraft
{
public:
    int range;

    Aircraft()
    {
        range = 0;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    void inputFlying()
    {
        inputCar();
        cout << "Enter Flight Range: ";
        cin >> range;
    }

    void showFlying()
    {
        showCar();
        cout << "Flight Range: " << range << endl;
    }
};

class SportsCar : public ElectricCar
{
public:
    int speed;

    void inputSports()
    {
        inputElectric();
        cout << "Enter Top Speed: ";
        cin >> speed;
    }

    void showSports()
    {
        showElectric();
        cout << "Top Speed: " << speed << endl;
    }
};

class Sedan : public Car
{
public:
    void showSedan()
    {
        showCar();
        cout << "Type: Sedan" << endl;
    }
};

class SUV : public Car
{
public:
    void showSUV()
    {
        showCar();
        cout << "Type: SUV" << endl;
    }
};

int main()
{
    Car c;
    ElectricCar e;
    SportsCar s;
    FlyingCar f;
    Sedan d;
    SUV u;

    int choice;

    while(true)
    {
        cout << "1.  Car" <<endl;
        cout << "2.  Electric Car"<<endl;
        cout << "3.  Sports Car"<<endl;
        cout << "4.  Flying Car"<<endl;
        cout << "5.  Sedan"<<endl;
        cout << "6.  SUV"<<endl;
        cout << "7. View Vehicles"<<endl;
        cout << "8. Total Vehicles"<<endl;
        cout << "9. Exit"<<endl;

        cout << "Enter Choice: "<<endl;
        cin >> choice;

        if(choice == 1)
        {
            c.inputCar();
            c.showCar();
        }
        else if(choice == 2)
        {
            e.inputElectric();
            e.showElectric();
        }
        else if(choice == 3)
        {
            s.inputSports();
            s.showSports();
        }
        else if(choice == 4)
        {
            f.inputFlying();
            f.showFlying();
        }
        else if(choice == 5)
        {
            d.inputCar();
            d.showSedan();
        }
        else if(choice == 6)
        {
            u.inputCar();
            u.showSUV();
        }
        else if(choice == 7)
        {
            cout << "\nVehicle details are displayed after adding.";
        }
        else if(choice == 8)
        {
            cout << "\nTotal Vehicles: " << Vehicle::total;
        }
        else if(choice == 9)
        {
            cout << "\nThank You!";
            break;
        }
        else
        {
            cout << "\nInvalid Choice!";
        }
    }

    return 0;
}
