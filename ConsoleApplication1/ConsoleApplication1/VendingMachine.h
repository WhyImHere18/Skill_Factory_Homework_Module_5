#pragma once

#include <iostream>
#include <string>
#include "SnackSlot.h"

//namespace machine
//{
	class VendingMachine
	{
	private:
		unsigned short machineNum;		// machine number
		std::string address;					// address where the machine is installed
		unsigned short maxNumOfSlots;	// maximum number of slots in the machine
		unsigned short numOfSlots;		// number of slots in the machine at the moment
		SnackSlot* slots;				// massive of slots

	public:
		VendingMachine(unsigned short, std::string, unsigned short, unsigned short);
		VendingMachine(unsigned short, std::string, unsigned short);
		VendingMachine(const VendingMachine&);
		VendingMachine();

		void setMachineNum(unsigned short);
		unsigned short getMachineNum() const;

		void setAddress(std::string);
		std::string getAddress() const;

		void setMaxNumOfSlots(unsigned short);
		unsigned short getMaxNumOfSlots() const;

		void setNumOfSlots(unsigned short);
		unsigned short getNumOfSlots() const;

		VendingMachine& addSlot(SnackSlot&);			// put the slot into the machine
		//VendingMachine& getSlot(slot::SnackSlot&) const;		// remove the slot from the machine 

		unsigned short getEmptySlotsNumber();

		void printInfo();

		friend std::ostream& operator<<(std::ostream&, const VendingMachine&);


		~VendingMachine() = default;
	};
//}

