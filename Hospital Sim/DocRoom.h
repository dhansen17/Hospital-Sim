#ifndef DOCROOM_H_
#define DOCROOM_H_
#include <vector>
#include "EmergencyRoom.h"
#include "Doctor.h"
#include "Hospital.h"

class DocRoom
{
public:

	vector<Doctor*> docvec;

	DocRoom(int num, EmergencyRoom* object, Hospital* hospital)
	{
		for (int i = 0; i < num; i++)
			docvec.push_back(new Doctor(object, hospital));
	}

	void docClock(int timer)
	{
		for (int i = 0; i < docvec.size(); i++)
			docvec[i]->treatTime(timer);
	}
};
#endif