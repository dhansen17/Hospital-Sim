#ifndef SIMULATOR_H_
#define SIMULATOR_H_
#include"Patient.h"
#include"Hospital.h"
#include"Random.h"
#include"Doctor.h"
#include"Emergency.h"

Random newmy_random;


class Simulator
{
	//Private variables
private:
	//Int variables
	int totalTime;
	int clock;

	//Pointers
	EmergencyRoom* roomobject;
	Hospital* hospitalobject;
	DocRoom* pointer;

	//Fuunction
	int checkP(const std::string &prompt, int low, int high)
	{
		//This can not happen
		if (low >= high)
			throw std::invalid_argument("Your low is greater than your high");

		std::cin.exceptions(std::ios_base::failbit);

		//While loop for obtaining input
		int track = 0;
		while (true)
		{
			try {
				while (true)
				{
					cout << prompt;
					cin >> track;
					if (track >= low && track <= high)
					{
						return track;
					}
				}
			}
			//Catching any errors
			catch (std::ios_base::failure)
			{
				cout << "Invalid string, please try again\n";
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}

	//Public variables
public:
	//No-arg construct
	Simulator()
	{
		//New hospital
		roomobject = new EmergencyRoom();
		//Weeks worth of time
		totalTime = 10080;
		//A hospital has an emergency room
		hospitalobject = new Hospital(roomobject);

	}

	//Users get to ent in the data for the hospital
	void enterPdata()
	{
		std::cout << "Hello and welcome to our Hospital Simulator.\n";

		//Allowing for user to input number of doctors, then creating an array of doctors
		cout << "How many doctors are working now? Please only enter between 1 and 2" << endl;
		int doctrack = checkP("", 1, 2);

		int hourPatientRate = checkP("Please enter the amount of patients in the hospital: ", 1, 59);
		hospitalobject->setpArrive(hourPatientRate);

		pointer = new DocRoom(doctrack, roomobject, hospitalobject);
	}

	void runPSim()
	{
		//For loop to run patient simulation
		for (clock = 0; clock < totalTime; ++clock)
		{
			roomobject->updateER(clock);
			pointer->docClock(clock);
		}
	}

	//Displaying the results
	void showSim()
	{
		cout << "Total time for patient spent waiting : " << hospitalobject->getTotalwait() << endl;

		int choice = 0;
		Simulator sim;
		cout << "Please enter in a choice" << endl;
		cout << "1. Show Simulation" << endl;
		cout << "2. Show the list of all patients" << endl;
		cout << "3. Find a patient" << endl;
		cout << "4. End session" << endl;
		cin >> choice;

		//Switch statement for the choice of which the user can do
		switch (choice)
		{
		case 1: cout << "Show simulation" << endl;
			sim.enterPdata();
			sim.runPSim();

		case 2: cout << "Show record of patients" << endl;
			hospitalobject->display();

		case 3: cout << "Find a person who may have entered into the hospital" << endl;
			hospitalobject->reCurrence();

		case 4: cout << "End session" << endl;
			break;
		default:
			cout << "Please enter in an option between 1 and 4" << endl;
		}


	}


};

#endif
