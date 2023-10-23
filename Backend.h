#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

struct Car
{
    vector<Car> CarShop;

    string CarModel;
    string CarBodyStyle;
    int CarModelYear;
    double CarVolume;
    int price;

    void PushNewCar(const Car& newCar)
    {
        CarShop.push_back(newCar);
    }

    void SetCar() {
        Car newCar;

        cout << "Enter car model: ";
        cin >> newCar.CarModel;

        cout << "Enter car body style: ";
        cin >> newCar.CarBodyStyle;

        cout << "Enter car model year: ";
        cin >> newCar.CarModelYear;

        cout << "Enter car engine volume: ";
        cin >> newCar.CarVolume;

        cout << "Enter car price: ";
        cin >> newCar.price;

        CarShop.push_back(newCar);
    }

    void GetCar()
    {
        for (int i = 0; i < CarShop.size(); i++)
        {
            cout << "////////////////////////////////////////////////////////" << endl << endl;
            cout << "Car N" << i + 1 << endl;
            cout << "Car model: " << CarShop[i].CarModel << endl;
            cout << "Car body style: " << CarShop[i].CarBodyStyle << endl;
            cout << "Car model year: " << CarShop[i].CarModelYear << endl;
            cout << "Car engine volume: " << CarShop[i].CarVolume << endl;
            cout << "Car price: " << CarShop[i].price << endl;
            cout << endl;
            cout << "////////////////////////////////////////////////////////" << endl << endl;

        }
    }
    void GetCarSingle()
    {
        cout << "////////////////////////////////////////////////////////" << endl << endl;
        cout << "Car model: " << CarModel << endl;
        cout << "Car body style: " << CarBodyStyle << endl;
        cout << "Car model year: " << CarModelYear << endl;
        cout << "Car engine volume: " << CarVolume << endl;
        cout << "Car price: " << price << endl;
        cout << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;
    }
    void SaveToFile(const string& filename)
    {
        ofstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (const Car& car : CarShop)
        {
            file << car.CarModel << "\n";
            file << car.CarBodyStyle << "\n";
            file << car.CarModelYear << "\n";
            file << car.CarVolume << "\n";
            file << car.price << "\n";
        }

        file.close();
    }

    void SaveToFileOwerWite(const string& filename)
    {
        ofstream file(filename, ios::trunc);
        if (!file.is_open())
        {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (const Car& car : CarShop)
        {
            file << car.CarModel << "\n";
            file << car.CarBodyStyle << "\n";
            file << car.CarModelYear << "\n";
            file << car.CarVolume << "\n";
            file << car.price << "\n";
        }

        file.close();
    }

    void LoadFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        CarShop.clear();

        while (!file.eof())
        {
            Car newCar;
            file >> newCar.CarModel;
            file >> newCar.CarBodyStyle;
            file >> newCar.CarModelYear;
            file >> newCar.CarVolume;
            file >> newCar.price;

            if (!file.eof())
            {
                CarShop.push_back(newCar);
            }
        }

        file.close();
    }

};


struct Manager
{
    vector<Manager> ManagerList;

    string ManagerName;
    string ManagerSecondName;
    string ManagerSurname;
    int ManagerBornDate;
    int ManagerBornMonth;
    int ManagerBornYear;
    double ManagerWorkExperience;
    string ManagerPhoneNumber;

    void PushNewManager(const Manager& newManager)
    {
        ManagerList.push_back(newManager);
    }

    void SetManager()
    {
        Manager newManager;
        cout << "Enter manager's first name: ";
        cin >> newManager.ManagerName;

        cout << "Enter manager's second name: ";
        cin >> newManager.ManagerSecondName;

        cout << "Enter manager's surname: ";
        cin >> newManager.ManagerSurname;

        cout << "Enter manager's date of birth (day month year): ";
        cin >> newManager.ManagerBornDate >> newManager.ManagerBornMonth >> newManager.ManagerBornYear;

        cout << "Enter manager's work experience (in years): ";
        cin >> newManager.ManagerWorkExperience;

        cout << "Enter manager's phone number: ";
        cin >> newManager.ManagerPhoneNumber;

        PushNewManager(newManager);
    }

    void GetManager()
    {
        for (int i = 0; i < ManagerList.size(); i++)
        {
            cout << "////////////////////////////////////////////////////////" << endl << endl;
            cout << "Manager N" << i + 1 << endl;
            cout << "Manager's first name: " << ManagerList[i].ManagerName << endl;
            cout << "Manager's second name: " << ManagerList[i].ManagerSecondName << endl;
            cout << "Manager's surname: " << ManagerList[i].ManagerSurname << endl;
            cout << "Manager's date of birth: " << ManagerList[i].ManagerBornDate << "/"
                << ManagerList[i].ManagerBornMonth << "/" << ManagerList[i].ManagerBornYear << endl;
            cout << "Manager's work experience: " << ManagerList[i].ManagerWorkExperience << " years" << endl;
            cout << "Manager's phone number: " << ManagerList[i].ManagerPhoneNumber << endl;
            cout << endl;
            cout << "////////////////////////////////////////////////////////" << endl << endl;
        }
    }
    void SaveToFile(const string& filename)
    {
        ofstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (const Manager& manager : ManagerList)
        {
            file << manager.ManagerName << "\n";
            file << manager.ManagerSecondName << "\n";
            file << manager.ManagerSurname << "\n";
            file << manager.ManagerBornDate << "\n";
            file << manager.ManagerBornMonth << "\n";
            file << manager.ManagerBornYear << "\n";
            file << manager.ManagerWorkExperience << "\n";
            file << manager.ManagerPhoneNumber << "\n";
        }

        file.close();
    }

    void LoadFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        ManagerList.clear();

        while (!file.eof())
        {
            Manager newManager;
            file >> newManager.ManagerName;
            file >> newManager.ManagerSecondName;
            file >> newManager.ManagerSurname;
            file >> newManager.ManagerBornDate;
            file >> newManager.ManagerBornMonth;
            file >> newManager.ManagerBornYear;
            file >> newManager.ManagerWorkExperience;
            file >> newManager.ManagerPhoneNumber;

            if (!file.eof())
            {
                ManagerList.push_back(newManager);
            }
        }

        file.close();
    }
};

struct Buyer
{
    vector<Buyer> BuyerList;

    string BuyerName;
    string BuyerSecondName;
    string BuyerSurname;
    string BuyerPhoneNumber;
    string BuyerAddress;
    int BuyerID;

    void PushNewBuyer(const Buyer& newBuyer)
    {
        BuyerList.push_back(newBuyer);
    }

    void SetBuyer()
    {
        Buyer newBuyer;
        cout << "Enter buyer's first name: ";
        cin >> newBuyer.BuyerName;

        cout << "Enter buyer's second name: ";
        cin >> newBuyer.BuyerSecondName;

        cout << "Enter buyer's surname: ";
        cin >> newBuyer.BuyerSurname;

        cout << "Enter buyer's phone number: ";
        cin >> newBuyer.BuyerPhoneNumber;

        cout << "Enter buyer's address: ";
        cin >> newBuyer.BuyerAddress;

        newBuyer.BuyerID = rand() % 16000;

        PushNewBuyer(newBuyer);
    }

    void GetBuyer()
    {
        for (int i = 0; i < BuyerList.size(); i++)
        {
            cout << "////////////////////////////////////////////////////////" << endl << endl;
            cout << "Buyer N" << i + 1 << endl;
            cout << "Buyer's first name: " << BuyerList[i].BuyerName << endl;
            cout << "Buyer's second name: " << BuyerList[i].BuyerSecondName << endl;
            cout << "Buyer's surname: " << BuyerList[i].BuyerSurname << endl;
            cout << "Buyer's phone number: " << BuyerList[i].BuyerPhoneNumber << endl;
            cout << "Buyer's address: " << BuyerList[i].BuyerAddress << endl;
            cout << "Buyer's ID: " << BuyerList[i].BuyerID << endl;
            cout << endl;
            cout << "////////////////////////////////////////////////////////" << endl << endl;
        }
    }
    void GetSingleBuyer()
    {
        cout << "////////////////////////////////////////////////////////" << endl << endl;
        cout << "Buyer's first name: " << BuyerName << endl;
        cout << "Buyer's second name: " << BuyerSecondName << endl;
        cout << "Buyer's surname: " << BuyerSurname << endl;
        cout << "Buyer's phone number: " << BuyerPhoneNumber << endl;
        cout << "Buyer's address: " << BuyerAddress << endl;
        cout << "Buyer's ID: " << BuyerID << endl;
        cout << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;
    }
    void SaveToFileOwerWrite(const string& filename)
    {
        ofstream file(filename, ios::trunc);
        if (!file.is_open())
        {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (const Buyer& buyer : BuyerList)
        {
            file << buyer.BuyerName << "\n";
            file << buyer.BuyerSecondName << "\n";
            file << buyer.BuyerSurname << "\n";
            file << buyer.BuyerPhoneNumber << "\n";
            file << buyer.BuyerAddress << "\n";
            file << buyer.BuyerID << "\n";
        }

        file.close();
    }
    void SaveToFile(const string& filename)
    {
        ofstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (const Buyer& buyer : BuyerList)
        {
            file << buyer.BuyerName << "\n";
            file << buyer.BuyerSecondName << "\n";
            file << buyer.BuyerSurname << "\n";
            file << buyer.BuyerPhoneNumber << "\n";
            file << buyer.BuyerAddress << "\n";
            file << buyer.BuyerID << "\n";
        }

        file.close();
    }

    void LoadFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        BuyerList.clear();

        while (!file.eof())
        {
            Buyer newBuyer;
            file >> newBuyer.BuyerName;
            file >> newBuyer.BuyerSecondName;
            file >> newBuyer.BuyerSurname;
            file >> newBuyer.BuyerPhoneNumber;
            file >> newBuyer.BuyerAddress;
            file >> newBuyer.BuyerID;

            if (!file.eof())
            {
                BuyerList.push_back(newBuyer);
            }
        }

        file.close();
    }
};

