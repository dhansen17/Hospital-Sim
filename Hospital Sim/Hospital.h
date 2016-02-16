#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include<string>
#include<map>
#include<queue>
#include"Doctor.h"
#include"Patient.h"
#include"DocRoom.h"
#include"Random.h"
#include"EmergencyRoom.h"

using namespace std;

Random myRand;

class Hospital
{
public:
	//Variables
	queue<Patient*> served;
	double patientArrivalRate;
	int numOfPatients;
	int totalWait;
	map<string, int> newNames;
	map<string, int>::iterator it;
	string check;

	EmergencyRoom *user;

	Hospital()
	{
		patientArrivalRate = 0;
		numOfPatients = 0;
	}
	//Constructor for Hospital taking in an emergency room object because a hospital has an emergency room
	Hospital(EmergencyRoom* object)
	{
		user = object;
		patientArrivalRate = 0;
		numOfPatients = 0;

	}
	//Setting patient arrival
	void setpArrive(double rate)
	{
		this->patientArrivalRate = rate;
		totalWait += totalWait;
	}

	//Returning the total wait for the patient
	int getTotalwait()
	{
		return totalWait;
	}

	//Returning people helped
	int getNumpeopleHelped()
	{
		return numOfPatients;
	}

	//Serving the patiens and adding to the queue who were served
	void setServePatients(Patient* object)
	{
		served.push(object);
	}
	//Displaying patient name and illness from the map that was created
	void display()
	{
		for (it = newNames.begin(); it != newNames.end(); it++)
		{
			cout << "Patient Name: " << it->first << endl;
			cout << '\n' << endl;
			cout << "Patient Illness: " << it->second << endl;
		}
	}
	//Checking to see how many times a patient has been to the hospital using the map created
	void reCurrence()
	{
		cout << "Who would you like to look for? " << endl;
		cin >> check;

		int tracker;
		tracker = 0;

		for (it = newNames.begin(); it != newNames.end(); it++)
		{
			if (it->first == check)
			{
				tracker++;
				cout << "The patient you are looking for is: " << it->first << " they had an illness level of: " << it->second << endl;
			}

			else
				cout << "No record of this patient in our hospital" << endl;

		}
	}


	friend class EmergencyRoom;
};

#endif