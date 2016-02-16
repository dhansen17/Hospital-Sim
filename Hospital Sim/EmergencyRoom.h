#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_
#include<string>
#include<queue>
#include<vector>
#include "Doctor.h"
#include "Patient.h"
#include<fstream>
#include <map>

Random newRandom;

using namespace std;

class EmergencyRoom
{
	//Private variables
private:
	int discharge_time;
	int total_wait;
	int num_serverd;
	int maxTime;
	int servTime;
	int arrive;
	//Public variables and functions
public:
	//Queue of patients one for high severity of illness and one for low severity of illness
	priority_queue<Patient *> highPQ;
	priority_queue<Patient *> lowPQ;
	//Vector to access the names from the text file
	vector<string> pNames;

	//Variable for accessing the names from the file
	string names;

	//map for patients name and ID
	//Assign the patients each a number
	int patientnumber;
	map <string, int> storage;

	//No-arg constructor
	EmergencyRoom()
	{
		//Opening file
		fstream object;
		if (object.fail())
		{
			cout << "Can't open file" << endl;
		}

		//While loop for getting the information from the file
		while (!object.eof())
		{
			//Statement used for getting the names
			object >> names;

			//Assign a number to each patient that entered
			patientnumber++;

			if (object.eof())
				break;

			//Pushing names to a priority the vector
			pNames.push_back(names);
			storage.insert(make_pair(names, patientnumber));

		}

		object.close();
	}
	//Updatting Emergency Rooms clock
	void updateER(int clock)
	{
		//Updating the ER clock and adding new patients who come into the Emergency room
		if (newRandom.next_double() < arrive && (pNames.size() != 0))
		{

			string someNames = pNames.back();
			pNames.pop_back();

			//Creation of new patient
			Patient *newPatient = new Patient(names, clock);

			//If and else to check the patients illness level
			if (newPatient->getIllness() < 11 && newPatient->getIllness() > 0)
			{
				lowPQ.push(newPatient);
			}
			else
				highPQ.push(newPatient);
		}
	}



	//Getting the amount of patients served 
	int get_num_served(int var)
	{
		num_serverd = var;
		return num_serverd;
	}

	//Returns the Patients with the highest serverity illness
	Patient *getHighIll()
	{
		return highPQ.top();
	}

	//Returns the Patients with the lowest severity illness
	Patient *getLowIll()
	{
		return lowPQ.top();
	}
	//Returns the highest patient of the priority queue
	int getHighPatients()
	{
		return highPQ.size();
	}

	//Returns the lowest patient of the priority queue
	int getLowPatients()
	{
		return lowPQ.size();
	}

	//Treating low patients
	void TreatedLow()
	{
		lowPQ.pop();
	}


	//Treating high patients
	void TreatedHigh()
	{
		highPQ.pop();
	}


	//Getting total wait of visit
	int get_total_wait(int thisvar)
	{
		total_wait = thisvar;
		return total_wait;
	}

	friend class Patient;
};

#endif

