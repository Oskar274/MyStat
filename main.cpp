
#include"Backend.h";
#include <cstdio>
#include <fstream>
Car NewCar;
Manager NewManager;
Buyer NewBuyer;
vector<int> BuyerRequests = {};
void LoadFromFile(const string& filename);
void SaveToFileOwerWrite(const string& filename);
int main()
{
	NewCar.LoadFromFile("CarList.bin");                 
	NewManager.LoadFromFile("ManagerList.bin");			//загрузка в массив после перезапуска
	NewBuyer.LoadFromFile("BuyerLIst.bin");				
	LoadFromFile("BuyersRequests.bin");					
	system("cls");										


	while (true)
	{
		short ManageOrBuyerOrBoss;
		cout << "Welcome to our car shop!" << endl;
		cout << "U are manager or buyer or boss?" << endl;
		cout << "If u are buyer press 1" << endl;
		cout << "If u are manager press 2" << endl;
		cout << "If u are Boss press 3" << endl;
		cout << "if u wanna exit press 4" << endl;
		cout << "Enter Number: ";
		cin >> ManageOrBuyerOrBoss;
		system("cls");
		if (cin.fail())
		{
			cout << "Invalid input. Please enter a valid number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			if (ManageOrBuyerOrBoss == 1)
			{
				cout << "to sell we have" << endl;
				NewCar.GetCar();
				system("pause");
				cout << endl << endl;
				short BuyerAns;
				cout << "what we wanna do?" << endl;
				cout << "if u wanna buy car press 1:" << endl;
				cout << "exit - (0)";
				cin >> BuyerAns;
				system("cls");
				if (cin.fail())
				{
					cout << "Invalid input. Please enter a valid number." << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					if (BuyerAns == 1)
					{
						cout << "please register" << endl;
						NewBuyer.SetBuyer();
						NewBuyer.SaveToFile("BuyerLIst.bin");
						cout << "saved!" << endl;
						system("pause");
						system("cls");
						int BuyerRequest;
						cout << "what auto u want?" << endl;
						cout << "to sell we have:" << endl;
						NewCar.GetCar();
						cout << "enter number of auto u want ";
						for (int i = 0; i < NewCar.CarShop.size(); i++)
						{
							if (i == NewCar.CarShop.size() - 1)
							{
								cout << i + 1 << " ";
								break;
							}
							cout << i + 1 << ", ";
						}
						cout << "?";
						cout << endl;
						cout << "enter number of auto: ";
						cin >> BuyerRequest;
						if (cin.fail())
						{
							cout << "Invalid input. Please enter a valid number." << endl << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else
						{
							BuyerRequests.push_back(BuyerRequest);
							cout << "Thank u for request wait for a call" << endl;
							system("pause");
							system("cls");
						}

						ofstream file("BuyersRequests.bin");
						if (!file.is_open())
						{
							cout << "Error opening file for writing!" << endl;
							exit(-1);
						}
						for (int i = 0; i < BuyerRequests.size(); i++)
						{
							file << BuyerRequest << "\n";
						}
						file.close();
					}
					else if (BuyerAns == 0)
					{

					}
					else
					{
						cout << "something wrong try again" << endl << endl;
					}
				}

			}
			else if (ManageOrBuyerOrBoss == 2)
			{
				short ManagerAns;
				cout << "what we wanna do?" << endl;
				cout << "if u wanna add new car press 1:" << endl;
				cout << "if u wanna delete car press 2:" << endl;
				cout << "if u wanna get list of cars press 3:" << endl;
				cout << "If u wanna check requests press 4:" << endl;
				cout << "Enter number: ";
				cin >> ManagerAns;
				system("cls");
				if (cin.fail())
				{
					cout << "Invalid input. Please enter a valid number." << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					if (ManagerAns == 1)
					{
						NewCar.SetCar();
						NewCar.SaveToFile("CarList.bin");
						system("cls");
					}
					else if (ManagerAns == 2)
					{
						short CarToDelete;
						NewCar.GetCar();
						cout << "what car u wanna delete?" << endl;
						cout << "exit - (0)" << endl;
						cin >> CarToDelete;
						for (int i = 0; i < NewCar.CarShop.size(); i++)
						{
							if (i + 1 == CarToDelete)
							{
								NewCar.CarShop.erase(NewCar.CarShop.begin() + i);
								NewCar.SaveToFileOwerWite("CarList.bin");
								cout << "deleted!" << endl;
							}
						}
						system("pause");
						system("cls");
						if (CarToDelete == 0)
						{

						}
					}
					else if (ManagerAns == 3)
					{
						NewCar.GetCar();
						system("pause");
						system("cls");
					}
					else if (ManagerAns == 4)
					{
						int AcceptOrNot;
						int NextOrPrev;
						for (int i = 0; i < NewBuyer.BuyerList.size();)
						{
							NewBuyer.BuyerList[i].GetSingleBuyer();
							cout << "wanna buy car N";
							cout << BuyerRequests[i];
							cout << endl;
							cout << "accept of Not?" << endl;
							cout << "If you accept the request, you will need to call the buyer within 20 minutes" << endl;
							cout << "accept - (1) reject - (2) next - (3)" << endl;
							cin >> AcceptOrNot;
							system("cls");
							if (AcceptOrNot == 1)
							{
								cout << "request accepted and will be deleted" << endl;
								NewBuyer.BuyerList.erase(NewBuyer.BuyerList.begin() + i);
								BuyerRequests.erase(BuyerRequests.begin() + i);
								NewBuyer.SaveToFileOwerWrite("BuyerLIst.bin");
								SaveToFileOwerWrite("BuyersRequests.bin");

							}
							else if (AcceptOrNot == 2)
							{
								cout << "request rejected and will be deleted" << endl;
								NewBuyer.BuyerList.erase(NewBuyer.BuyerList.begin() + i);
								BuyerRequests.erase(BuyerRequests.begin() + i);
								NewBuyer.SaveToFileOwerWrite("BuyerLIst.bin");
								SaveToFileOwerWrite("BuyersRequests.bin");
							}
							else if (AcceptOrNot == 3)
							{

							}
							else
							{
								cout << "smth went wrong try again" << endl;
							}
							cout << "exit(0)" << endl;
							if (i < NewBuyer.BuyerList.size() - 1)
							{
								cout << "Check nex request (1):" << endl;
							}
							if (i > 0)
							{
								cout << "Check prev request (2):" << endl;
							}
							cout << "enter number: ";
							cin >> NextOrPrev;
							if (NextOrPrev == 1)
							{
								i++;
							}
							if (NextOrPrev == 2)
							{
								i--;
							}
							if (NextOrPrev == 0)
							{
								break;
							}
							system("cls");
						}
					}
					else
					{
						cout << "something wrong try again" << endl << endl;
					}
				}
			}
			else if (ManageOrBuyerOrBoss == 3)
			{
				short BossAns;
				cout << "what we wanna do?" << endl;
				cout << "if u wanna add new Manager press 1:" << endl;
				cout << "if u wanna see of all managers press 2:" << endl;
				cout << "Enter number: ";
				cin >> BossAns;
				system("cls");
				if (cin.fail())
				{
					cout << "Invalid input. Please enter a valid number." << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					if (BossAns == 1)
					{
						NewManager.SetManager();
						NewManager.SaveToFile("ManagerList.bin");
						cout << "saved!" << endl;
						system("pause");
						system("cls");
					}
					if (BossAns == 2)
					{
						NewManager.GetManager();
						system("pause");
						system("cls");
					}
					else
					{
						cout << "something wrong try again" << endl << endl;
					}
				}
			}
			else if (ManageOrBuyerOrBoss == 4) exit(0);
			else
			{
				cout << "something wrong try again" << endl << endl;
			}
		}
	}

	return 0;

}

void LoadFromFile(const string& filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Error opening file for reading!" << endl;
		return;
	}

	BuyerRequests.clear();

	int BuyerRequest;
	while (file >> BuyerRequest)
	{
		BuyerRequests.push_back(BuyerRequest);
	}

	file.close();
}
void SaveToFileOwerWrite(const string& filename)
{
	ofstream file(filename, ios::trunc);
	if (!file.is_open())
	{
		cout << "Error opening file for writing!" << endl;
		return;
	}

	for (const int& BuyerRequest : BuyerRequests)
	{
		file << BuyerRequest << " ";
	}

	file.close();
}