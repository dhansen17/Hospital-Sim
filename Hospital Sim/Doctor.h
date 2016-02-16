#ifndef DOCTOR_H_
#define DOCTOR_H_
#include<iostream>
#include<ctime>
#include"Patient.h"
#include"Random.h"
#include"EmergencyRoom.h"
#include"Hospital.h"
#include"Simulator.h"

using namespace std;
Random my_rand;
class Doctor
{
	//Public variables
public:
	bool helpingPatient;
	int treatTime = 0;
	Hospital *hospital;
	EmergencyRoom *room;
	Patient *thisPatient;

	//Constructor, takes in two pointers and sets helping patient to false because there are no patients in the hospital
	Doctor(EmergencyRoom* object, Hospital* object1) : treatTime(0), helpingPatient(false), hospital(), room()
	{}


	//Clock for the doctors
	void track(int clock)
	{
		//If the doctor is not helping a patient then get a high patient and check their illness level, if they fit then take care of them and set the timers and change variables accordingly
		if (helpingPatient == false)
			if (room->getHighPatients() != 0)
			{
				//Get the patients high Illness
				thisPatient = room->getHighIll();

				//Set this patients start time
				thisPatient->setHelpTime(clock + treatTime);

				//The doctor is now helping the patient
				helpingPatient = true;

				//The total treatment time of the patient is now set
				treatTime = my_rand.next_int(20) + 1;

				//Pop the the top of the Priority Queue because we helped a patient with a high prioirity illness
				room->TreatedHigh();

			}

		//If the doctor is not helping a patient then get a low patient and check their illness level, if they fit then take care of them and set the timers and change variables accordingly
			else if (room->getLowPatients() != 0)
			{
				helpingPatient = true;

				helpingPatient = room->getHighIll();

				treatTime = my_rand.next_int(10) + 1;

				thisPatient->setHelpTime(clock + treatTime);

				room->TreatedLow();
			}

		//If the patient is all done with treatment then adjust variables accordingly and set the helping patient varible to false because the patient has left
			else if (thisPatient->getLeave() < clock)
			{

				thisPatient->setDischargeTime(clock);


				hospital->setServePatients(thisPatient);


				helpingPatient = false;
			}
	}


};

#endif