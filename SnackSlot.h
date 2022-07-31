#pragma once

#include <iostream>
#include <string>
#include "Snack.h"

class SnackSlot
{
private:
	unsigned short slotNum;				// the slot number in the machine
	unsigned short maxNumOfSnacks;		// maximum number of snacks in the slot
	unsigned short numOfSnacks;			// number of snacks in the slot at the moment

	Snack* snacks;						// massive of snacks

public:
	SnackSlot(unsigned short slotNum_, unsigned short maxNumOfSnacks_, unsigned short currNumOfSnacks_);
	SnackSlot(unsigned short slotNum_, unsigned short maxNumOfSnacks);
	SnackSlot();

	SnackSlot(const SnackSlot&);

	~SnackSlot() = default;

	void setSlotNum(unsigned short);
	unsigned short getSlotNum() const;

	void setMaxNumOfSnacks(unsigned short);
	unsigned short getMaxNumOfSnacks() const;

	void setNumOfSnacks(unsigned short);
	unsigned short getNumOfSnacks() const;

	SnackSlot& addSnack(Snack&);			// put the snack in the slot
	SnackSlot& getSnack(Snack&);			// remove the snack from the slot

	void printInfo();

	friend std::ostream& operator<<(std::ostream&, const SnackSlot&);

	unsigned short currNumOfCal();			// calculates the number of calories in the slot

};

