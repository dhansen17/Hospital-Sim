#ifndef PATIENT_H_
#define PATIENT_H_
#include<iostream>
#include <string>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;


//Creation of class patient
class Patient
{

	//Public variables
public:
	string fname;
	int illness;
	int recurrence;
	int setarrival;
	int service_time;
	int dischargable;

	//No-arg constructor
	Patient()
	{
		fname = "";
		illness = 0;
	}

	/*
	1. when he arrives
	2. when he gets seen by doctor or nurse (serviced)
	3. time it takes to be seen
	4. Then the patient needs dischargeed
	*/
	Patient(string name, int clock) : setarrival(clock), service_time(-1), dischargable(-1), fname(name)
	{
		//Giving the patient a random illness
		setIllness();
	}

	//Overloading the less than operator, found this in the book
	bool operator<(const Patient &other) const
	{
		return illness < other.illness;
	}

	//Setting illness for patient
	void setIllness()
	{
		srand((time(NULL)));
		int track;

		track = rand() % 100 + 1;

		//If number is greater than one but less than 70 the illness level is between one and ten
		if (track > 1 && track <= 70)
		{
			illness = rand() % 10 + 1;
		}
		//If number is greater than 70 but less than 90 the illness level is between 10 and 15
		else if (track > 70 && track <= 90)
		{
			illness = 10;
			illness + rand() % 5 + 1;
		}

		//If number is greater than 90 illness level is between 15 and 20
		else
		{
			illness = 15;
			illness + rand() % 5 + 1;
		}
	}

	//Returns illness
	int getIllness()
	{
		return illness;
	}
	//Sets the treatment time for when the patient arrived
	void setHelpTime(int clock)
	{
		service_time = clock;
	}
	//Sets the time for a patient to leave
	void setDischargeTime(int time)
	{
		dischargable = time;
	}

	//Gets the intial time of arrival
	int getArrival()
	{
		return setarrival;
	}

	//Gets the time when the patient left
	int getLeave()
	{
		return dischargable;
	}

};
#endif


