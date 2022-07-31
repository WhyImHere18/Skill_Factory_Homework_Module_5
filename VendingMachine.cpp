#include "VendingMachine.h"
#include "SnackSlot.h"
#include "Snack.h"
#include <iostream>
#include <string>

VendingMachine::VendingMachine(unsigned short machineNum_, std::string address_, unsigned short maxNumOfSlots_, unsigned short numOfSlots_)
{
	this->machineNum = machineNum_;
	this->address = address_;
	this->maxNumOfSlots = maxNumOfSlots_;
	this->numOfSlots = numOfSlots_;
	this->slots = new SnackSlot[maxNumOfSlots_];
}

VendingMachine::VendingMachine(unsigned short machineNum_, std::string address_, unsigned short maxNumOfSlots_)
{
	this->machineNum = machineNum_;
	this->address = address_;
	this->maxNumOfSlots = maxNumOfSlots_;
	this->numOfSlots = 0;
	this->slots = new SnackSlot[maxNumOfSlots_];
}


VendingMachine::VendingMachine(const VendingMachine& other)
{
	this->machineNum = other.machineNum;
	this->address = other.address;
	this->maxNumOfSlots = other.maxNumOfSlots;
	this->numOfSlots = other.numOfSlots;
	this->slots = new SnackSlot[other.maxNumOfSlots];
}

VendingMachine::VendingMachine()
{
	this->machineNum = 0;
	this->address = "random address";
	this->maxNumOfSlots = 5;
	this->numOfSlots = 0;
	this->slots = nullptr;
}

void VendingMachine::setMachineNum(unsigned short machineNum_)
{
	machineNum = machineNum_;
}

unsigned short VendingMachine::getMachineNum() const
{
	return machineNum;
}

void VendingMachine::setAddress(std::string address_)
{
	address = address_;
}

std::string VendingMachine::getAddress() const
{
	return address;
}

void VendingMachine::setMaxNumOfSlots(unsigned short maxNumOfSlots_)
{
	maxNumOfSlots = maxNumOfSlots_;
}

unsigned short VendingMachine::getMaxNumOfSlots() const
{
	return maxNumOfSlots;
}

void VendingMachine::setNumOfSlots(unsigned short numOfSlots_)
{
	numOfSlots = numOfSlots_;
}

unsigned short VendingMachine::getNumOfSlots() const
{
	return numOfSlots;
}

VendingMachine& VendingMachine::addSlot(SnackSlot& slot_)
{
	++numOfSlots;
	if (numOfSlots > maxNumOfSlots)
	{
		std::cout << "The machine number " << machineNum << " is full already!" << std::endl;
		--numOfSlots;
		return *this;
	}
	slots[numOfSlots - 1] = SnackSlot::SnackSlot(slot_);
	return *this;
}

unsigned short VendingMachine::getEmptySlotsNumber()
{
	return maxNumOfSlots - numOfSlots;
}

void VendingMachine::printInfo()
{
	std::cout << "Vending machine number " << machineNum << std::endl;
	std::cout << "Address  " << address << std::endl;
	std::cout << "Maximum number of slots: " << maxNumOfSlots << std::endl;
	std::cout << "Number of empty slots: " << getEmptySlotsNumber() << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "List of slots: " << std::endl;
	std::cout << "============================" << std::endl;
	for (int i = 0; i < numOfSlots; i++)
	{
		std::cout << "Slot #" << i + 1 << ": " << std::endl;
		std::cout << "Maximum number of snacks: " << slots[i].getMaxNumOfSnacks() << std::endl;
		std::cout << "Number of snacks at the moment: " << slots[i].getNumOfSnacks() << std::endl;
		std::cout << "============================" << std::endl;
	}
	std::cout << "============================" << std::endl;
}

std::ostream& operator<<(std::ostream& op, const VendingMachine& machine_)
{
	std::cout << "Vending machine number " << machine_.getMachineNum() << std::endl;
	std::cout << "Address  " << machine_.getAddress() << std::endl;
	std::cout << "Maximum number of slots: " << machine_.getMaxNumOfSlots() << std::endl;
	std::cout << "Number of empty slots: " << machine_.getMaxNumOfSlots() - machine_.getNumOfSlots() << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "List of slots: " << std::endl;
	std::cout << "============================" << std::endl;
	for (int i = 0; i < machine_.numOfSlots; i++)
	{
		std::cout << "Slot #" << i + 1 << ": " << std::endl;
		std::cout << "Maximum number of snacks: " << machine_.slots[i].getMaxNumOfSnacks() << std::endl;
		std::cout << "Number of snacks at the moment: " << machine_.slots[i].getNumOfSnacks() << std::endl;
		std::cout << "============================" << std::endl;
	}
	std::cout << "============================" << std::endl;

	return op;
}


