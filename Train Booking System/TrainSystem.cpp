#include "TrainLL.h"
#include "Passenger.h"
#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
	TrainList test;
	Passenger* temp;
	test.readDatabase();

	int choice;
	bool run = true;

	while (run) {
		cout << "*********************************************************************************************************** " << endl;
		cout << "*                                                                                                         * " << endl;
		cout << "*                                                                                                         * " << endl;
		cout << "*                                       HANGZHOU TRAIN BOOKING SYSTEM                                     * " << endl;
		cout << "*                                                                                                         * " << endl;
		cout << "*                                                                                                         * " << endl;
		cout << "*********************************************************************************************************** " << endl;

		Date date;

		cout << "===========================================================================================================" << endl << endl;
		cout << "=                                                MAIN MENU                                                =" << endl << endl;
		cout << "===========================================================================================================" << endl;
		cout << "=                                                                                                         =" << endl << endl;
		cout << "=                                         1. Book a train.                                                =" << endl << endl;
		cout << "=                                         2. Cancel booking.                                              =" << endl << endl;
		cout << "=                                         3. Show my reservation.                                         =" << endl << endl;
		cout << "=                                         4. Admin menu.                                                  =" << endl << endl;
		cout << "=                                         5. Quit.                                                        =" << endl << endl;
		cout << "=                                                                                                         =" << endl << endl;
		cout << "===========================================================================================================" << endl;
		cin >> choice;
		while ((choice < 1) || (choice > 5)) {
			cout << "Invalid command!!! Retry: ";
			cin >> choice;
		}
		if (choice == 1) {
			system("cls");
			bool run1 = true;
			int choice1;
			while (run1) {
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "+                                               BOOKING MENU                                              +" << endl;
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "+                                                                                                         +" << endl << endl;
				cout << "+                                         1. Show trains.                                                 +" << endl << endl;
				cout << "+                                         2. Search for a train.                                          +" << endl << endl;
				cout << "+                                         3. Main menu.                                                   +" << endl << endl;
				cout << "+                                                                                                         +" << endl << endl;
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cin >> choice1;
				while ((choice1 < 1) || (choice1 > 3)) {
					cout << "*****************************" << endl;
					cout << "*  Invalid command!!! Retry: ";
					cin >> choice1;
					cout << "*****************************" << endl;
				}
				if (choice1 == 1) {
					system("cls");
					test.showTrain();
					cout << "**************************************************************************************************" << endl;
					cout << "                         Press any key to go back to the BOOKING MENU.                            " << endl << endl;
					cin.get();
					cin.get();
					system("cls");
				}
				if (choice1 == 2) {
					system("cls");
					bool runsub = true;
					string decision;
					while (runsub) {
						string dplace, aplace;
						cout << "                                  Input depature: ";
						cin >> dplace;
						cout << "                                  Input arrival: ";
						cin >> aplace;
						cout << endl;
						for (int i = 0; i < dplace.length(); i++) {
							dplace[i] = toupper(dplace[i]);
						}
						for (int i = 0; i < aplace.length(); i++) {
							aplace[i] = toupper(aplace[i]);
						}
						runsub = test.searchTrain(dplace, aplace);
						if (runsub == false) {
							cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
							cout << "^   No train found!!! Retry your search (Y/N): ";
							cin >> decision;
							cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
							if (decision == "Y") runsub = true;
						}
						else {
							runsub = false;
							string name, passno, trainNo, gender, departureDate;
							cout << endl;
							cout << "=================================================================" << endl << endl;
							cout << "=                        BOOKING                                =" << endl << endl;
							cout << "=================================================================" << endl << endl;
							cout << "Input a train number: ";
							cin >> trainNo;
							cout << endl << endl;
							cout << "Input a passport number:";
							cin >> passno;
							cout << endl << endl;
							cin.ignore();
							cout << "Input a name: ";
							getline(cin, name);
							cout << endl << endl;
							cout << "Input Gender: ";
							cin >> gender;
							cout << endl << endl;
							cout << "Input the depature date: ";
							departureDate = date.enterDate();
							cout << "===============================================================" << endl << endl;
							temp = new Passenger(passno, name, gender, departureDate);
							test.insertPassenger(trainNo, *temp);
						}
					}
					cout << "Press any key to go back to the BOOKING MENU." << endl;
					cin.get();
					cin.get();
					system("cls");
				}
				if (choice1 == 3) {
					system("cls");
					run1 = false;
				}
			}
		}
		else if (choice == 2) {
			system("cls");
			string passno, choice2;
			bool run2 = true;
			while (run2) {
				cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
				cout << "w                                                        " << endl;
				cout << "w   Press M if you want to go back to the main menu      " << endl;
				cout << "w                                                        " << endl;
				cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl << endl;
				cout << "w                                                       " << endl;
				cout << "w   Input a passport number to cancel booking: ";
				cin >> passno;
				cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
				if (passno == "M") {
					system("cls");
					run2 = false;
				}
				else {
					if (test.removePassenger(passno)) {
						cout << "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss" << endl;
						cout << "s                                                                                        s" << endl;
						cout << "s   The passenger with a passport number of " << passno << " has canceled his booking.   s" << endl;
						cout << "s                                                                                        s" << endl;
						cout << "s   Press any key to go back to the main menu.                                           s" << endl;
						cout << "s                                                                                        s" << endl;
						cout << "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss" << endl;
						run2 = false;
						cin.get();
						cin.get();
						system("cls");
					}
					else {
						cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
						cout << "x                                                            x" << endl;
						cout << "x  The passenger with this passport number is not found!!!   x" << endl;
						cout << "x                                                            x" << endl;
						cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
						cout << "x                                                            x" << endl;
						cout << "x        Do you want to search again?(Y/N): ";
						cin >> choice2;
						cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
						if (choice2 == "Y") {}
						else {
							run2 = false;
							system("cls");
						}
					}
				}
			}
		}
		else if (choice == 3) {
			system("cls");
			string passno;
			cout << "****************************" << endl;
			cout << "*    Input passport number: ";
			cin >> passno;
			cout << "****************************" << endl;
			if (!test.showBoardingPass(passno)) {
				cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
				cout << "x                                                x" << endl;
				cout << "x        The reservation is not found!           x" << endl;
				cout << "x                                                x" << endl;
				cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl << endl;
			}
			cout << "Press any key to go back to the main menu." << endl;
			cin.get();
			cin.get();
			system("cls");
		}
		else if (choice == 4) {
			system("cls");
			bool run4 = true;
			int choice4;
			while (run4) {
				cout << "*********************************************************************************************************** " << endl;
				cout << "*                                                   ADMIN MENU                                            * " << endl;
				cout << "*********************************************************************************************************** " << endl;
				cout << "*                                         1. Remove a train.                                              * " << endl << endl;
				cout << "*                                         2. Insert a train.                                              * " << endl << endl;
				cout << "*                                         3. See the number of available seats in a particular train.     * " << endl << endl;
				cout << "*                                         4. Show all reservations                                        * " << endl << endl;
				cout << "*                                         5. Show the gender statistics for a particular train.           * " << endl << endl;
				cout << "*                                         6. Main menu.                                                   * " << endl << endl;
				cout << "*********************************************************************************************************** " << endl << endl;
				cin >> choice4;
				while ((choice4 < 1) || (choice4 > 7)) {
					cout << "*****************************" << endl;
					cout << "*  Invalid command!!! Retry: ";
					cin >> choice4;
					cout << "*****************************" << endl;
				}
				if (choice4 == 1) {
					system("cls");
					string removetrain, removedtrain;
					cout << "_______________________________________________" << endl;
					cout << "Input the number of a train to remove: ";
					cin >> removetrain;
					cout << "_______________________________________________" << endl;

					removedtrain = test.remove(removetrain);
					if (removedtrain == "NA") {
						cout << "*************************************************" << endl;
						cout << "*        The train is not found                 *" << endl;
						cout << "*                                               *" << endl;
						cout << "*  Press any key to go back to the admin menu.  *" << endl;
						cout << "*                                               *" << endl;
						cout << "*************************************************" << endl;
						cin.get();
						cin.get();
						system("cls");
					}
					else if (removedtrain == "EMPTY") {
						cout << "###############################################" << endl;
						cout << "#        The list of train is empty.          #" << endl;
						cout << "###############################################" << endl << endl;
						
						cout << "Press any key to go back to the admin menu." << endl;
						cin.get();
						cin.get();
						system("cls");
					}
					else {
						cout << "__________________________________________________________________" << endl;
						cout << "The train with a number of " << removetrain << " has been removed." << endl;
						cout << "__________________________________________________________________" << endl << endl;
						
						cout << "Press any key to go back to the admin menu." << endl;
						cin.get();
						cin.get();
						system("cls");
					}
				}
				else if (choice4 == 2) {
					system("cls");
					string dplace, aplace, dtime, atime, trainNo, fare;
					cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "+    Input a train number:  ";
					cin >> trainNo;
					cout << "+    Input a depature city: ";
					cin >> dplace;
					cout << "+    Input an arrival city: ";
					cin >> aplace;
					cout << "+    Input a depature time: ";
					cin >> dtime;
					cout << "+    Input an arrival time: ";
					cin >> atime;
					cout << "+    Input fare: ";
					cin >> fare;
					test.append(trainNo, dtime, atime, dplace, aplace, fare);
					cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "The train is saved in the database!" << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "Press any key to go back to the admin menu." << endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if (choice4 == 3) {
					system("cls");
					int num;
					string trainNo;
					cout << "********************" << endl;
					cout << "*  Train number:    ";
					cin >> trainNo;
					cout << "********************" << endl;
					num = test.seatsAvailable(trainNo);
					if (num == -1) {
						cout << "*******************************************" << endl;
						cout << "*         The train is not found.         *" << endl;
						cout << "*******************************************" << endl << endl;
						cout << "Press any key to go back to the admin menu." << endl;
						cin.get();
						cin.get();
						system("cls");
					}
					else {
						cout << "----------------------------------------------------" << endl;
						cout << "The number of available seats in this train: " << num << endl;
						cout << "----------------------------------------------------" << endl << endl;
						
						cout << "Press any key to go back to the admin menu." << endl;
						cin.get();
						cin.get();
						system("cls");
					}
				}

				else if (choice4 == 4) {
					system("cls");
					test.showReservations();
					cout << "**************************************************************************************************" << endl;
					cout << "                         Press any key to go back to the BOOKING MENU.                            " << endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if (choice4 == 5) {
					system("cls");
					string trainNo;
					cout << "*************************************************" << endl;
					cout << "Input a train number to see gender statistics: ";
					cin >> trainNo;
					test.genderStatistics(trainNo);
					cout << "*************************************************" << endl;
					cout << "Press any key to go back to the admin menu." << endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if (choice4 == 6) {
					run4 = false;
					system("cls");
				}
			}
		}
		else if (choice == 5) {
			run = false;
		}
	}
	return 0;
}

