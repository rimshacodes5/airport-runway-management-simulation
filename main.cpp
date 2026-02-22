#include <iostream>
using namespace std;
struct Plane
{
	int Planeid;
	int Fuel; //fuel is only for emergency/landing planes
};
int main() {
	//declared the three queues with size of 10
	Plane emergency[10];
	Plane landing[10];
	Plane takeoff[10];

	//Each Queue has two pointers, declared and initialised below
	int emergency_front = 0, emergency_rear = -1;
	int landing_front = 0, landing_rear = -1;
	int takeoff_front = 0, takeoff_rear = -1;

	cout << "Rimsha Faisal\n";
	cout << "2025F-BCS-156\n" << endl;
	cout << "===== Airport Runway Management =====" << endl;

	int choice;
	do {
		cout << "\n1. Add Emergency Landing" << endl;
		cout << "2. Add Landing Request" << endl;
		cout << "3. Add Takeoff Request" << endl;
		cout << "4. Serve Runway" << endl;
		cout << "5. Display Queues" << endl;
		cout << "6. Exit" << endl;

		cout << "\nEnter your choice: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (emergency_rear == 9)
			{
				cout << "Emergency Queue is full" << endl;
			}
			else
			{
				emergency_rear += 1;

				cout << "Enter Plane ID: ";
				cin >> emergency[emergency_rear].Planeid;
				cout << "Enter Fuel level: ";
				cin >> emergency[emergency_rear].Fuel;
				cout << "Emergency landing request added successfully." << endl;
			}
			break;

		case 2:
			if (landing_rear == 9)
			{
				cout << "Landing Queue is full" << endl;
			}
			else
			{
				landing_rear += 1;

				cout << "Enter Plane ID: ";
				cin >> landing[landing_rear].Planeid;
				cout << "Enter Fuel level: ";
				cin >> landing[landing_rear].Fuel;
				cout << "Landing request added successfully." << endl;
			}
			break;

		case 3:
			if (takeoff_rear == 9)
			{
				cout << "Take Off Queue is full" << endl;
			}
			else
			{
				takeoff_rear += 1;

				cout << "Enter Plane ID: ";
				cin >> takeoff[takeoff_rear].Planeid;
				cout << "Takeoff request added successfully." << endl;
			}
			break;

		case 4:
			if (emergency_front <= emergency_rear)
			{
				cout << emergency[emergency_front].Planeid << endl;
				cout << "Emergency Plane Served." << endl;
				emergency_front += 1;
			}
			else if (landing_front <= landing_rear)
			{
				cout << landing[landing_front].Planeid << endl;
				cout << "Landing Plane Served." << endl;
				landing_front += 1;
			}
			else if (takeoff_front <= takeoff_rear)
			{
				cout << takeoff[takeoff_front].Planeid << endl;
				cout << "Take Off Plane Served." << endl;
				takeoff_front += 1;
			}
			else
			{
				cout << "Runway is empty. No planes are waiting!" << endl;
			}
			break;

		case 5:
			cout << "--- Emergency Queue ---" << endl;
			if (emergency_front > emergency_rear)
			{
				cout << "No emergency planes." << endl;
			}
			else
			{
				for (int i = emergency_front; i <= emergency_rear; i++)
				{
					cout << "Plane ID: " << emergency[i].Planeid;
					cout << "   Fuel: " << emergency[i].Fuel << endl;
				}
			}

			cout << "--- Landing Queue ---" << endl;
			if (landing_front > landing_rear)
			{
				cout << "No landing planes." << endl;
			}
			else
			{
				for (int i = landing_front; i <= landing_rear; i++)
				{
					cout << "Plane ID: " << landing[i].Planeid;
					cout << "   Fuel: " << landing[i].Fuel << endl;
				}
			}

			cout << "--- Take Off Queue ---" << endl;
			if (takeoff_front > takeoff_rear)
			{
				cout << "No take off planes." << endl;
			}
			else
			{
				for (int i = takeoff_front; i <= takeoff_rear; i++)
				{
					cout << "Plane ID: " << takeoff[i].Planeid << endl;
				}
			}
			break;

		case 6:
			cout << "Program exits as per your choice!" << endl;
			break;

		default:
			cout << "Invalid choice. Try again!" << endl;
		}
	} while (choice != 6);
	return 0;
}

