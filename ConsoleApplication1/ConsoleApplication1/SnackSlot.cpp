#include "SnackSlot.h"
#include "Snack.h"
#include <iostream>
#include <string>

//namespace slot
//{
	SnackSlot::SnackSlot(unsigned short slotNum_, unsigned short maxNumOfSnacks_, unsigned short numOfSnacks_)
	{
		this->slotNum = slotNum_;
		this->maxNumOfSnacks = maxNumOfSnacks_;
		this->numOfSnacks = numOfSnacks_;
		this->snacks = new Snack[maxNumOfSnacks_];
	}

	SnackSlot::SnackSlot(unsigned short slotNum_, unsigned short maxNumOfSnacks_)
	{
		this->slotNum = slotNum_;
		this->maxNumOfSnacks = maxNumOfSnacks_;
		this->numOfSnacks = 0;
		this->snacks = new Snack[maxNumOfSnacks_];
		for (int i = 0; i < maxNumOfSnacks_; i++)
		{
			this->snacks[i] = *(new Snack());
		}
	}

	SnackSlot::SnackSlot(const SnackSlot& other)
	{
		this->slotNum = other.slotNum;
		this->maxNumOfSnacks = other.maxNumOfSnacks;
		this->numOfSnacks = other.numOfSnacks;
		this->snacks = new Snack[other.maxNumOfSnacks];
	}

	SnackSlot::SnackSlot()
	{
		this->slotNum = 1;
		this->maxNumOfSnacks = 50;
		this->numOfSnacks = 0;
		this->snacks = nullptr;
	}

	void SnackSlot::setSlotNum(unsigned short slotNum_)
	{
		slotNum = slotNum_;
	}

	unsigned short SnackSlot::getSlotNum() const
	{
		return slotNum;
	}


	void SnackSlot::setMaxNumOfSnacks(unsigned short maxNumOfSnacks_)
	{
		maxNumOfSnacks = maxNumOfSnacks_;
	}

	unsigned short SnackSlot::getMaxNumOfSnacks() const
	{
		return maxNumOfSnacks;
	}

	void SnackSlot::setNumOfSnacks(unsigned short numOfSnacks_)
	{
		numOfSnacks = numOfSnacks_;
	}

	unsigned short SnackSlot::getNumOfSnacks() const
	{
		return numOfSnacks;
	}

	SnackSlot& SnackSlot::addSnack(Snack& snack_)
	{
		++numOfSnacks;
		if (numOfSnacks > maxNumOfSnacks)
		{
			std::cout << "The slot number " << slotNum << " is full already!" << std::endl;
			--numOfSnacks;
			return *this;
		}
		snacks[numOfSnacks - 1] = Snack(snack_);
		snacks[numOfSnacks - 1].setSlotNum(slotNum);
		snacks[numOfSnacks - 1].setIndex(numOfSnacks);
		snack_.setSlotNum(slotNum);
		snack_.setIndex(numOfSnacks);
		return *this;
	}

	SnackSlot& SnackSlot::getSnack(Snack& snack_)
	{
		int index = 0;
		bool gotIt = false;
		int initialNumOfSnacks = numOfSnacks;
		for (int i = 0; i < numOfSnacks; i++)
		{
			//if (snacks[i] == snack_)
			if ((snacks[i].getSnackType() == snack_.getSnackType()) &&
				(snacks[i].getName() == snack_.getName()) &&
				(snacks[i].getPrice() == snack_.getPrice()) &&
				(snacks[i].getCalNum() == snack_.getCalNum()) &&
				(snacks[i].getSlotNum() == snack_.getSlotNum()) &&
				(snacks[i].getIndex() == snack_.getIndex()))

			{
				index = i;
				gotIt = true;
				break;
			}
		}
		if (!gotIt)
		{
			std::cout << "The slot " << slotNum << " does not have the snack you are looking for! " << std::endl;
			return *this;
		}
		--numOfSnacks;
		if (numOfSnacks < 1)
		{
			std::cout << "The slot number " << slotNum << " is empty already!" << std::endl;
			++numOfSnacks;
			return *this;
		}
		Snack* tmp = new Snack[numOfSnacks];
		for (int i = 0; i < index; i++)
		{
			tmp[i] = snacks[i];
		}
		for (int i = index + 1; i < initialNumOfSnacks; i++)
		{
			tmp[i - 1] = snacks[i];
		}
		snacks = tmp;
		return *this;
	}

	unsigned short SnackSlot::currNumOfCal()
	{
		unsigned short sumCalNum = 0;
		for (int i = 0; i < numOfSnacks; i++)
		{
			sumCalNum += snacks[i].getCalNum();
		}

		return sumCalNum;
	}

	void SnackSlot::printInfo()
	{
		std::cout << "Slot number  " << slotNum << std::endl;
		std::cout << "Maximum number of snacks: " << maxNumOfSnacks << std::endl;
		std::cout << "Number of snacks at the moment: " << numOfSnacks << std::endl;
		std::cout << "============================" << std::endl;
		std::cout << "List of snacks: " << std::endl;
		std::cout << "============================" << std::endl;
		for (int i = 0; i < numOfSnacks; i++)
		{
			std::cout << "Position #" << i + 1 << ": " << std::endl;
			std::cout << "Name: " << snacks[i].getName() << std::endl;
			std::cout << "Price: " << snacks[i].getPrice() << std::endl;
			std::cout << "Calories: " << snacks[i].getCalNum() << std::endl;
			std::cout << "============================" << std::endl;
		}
		std::cout << "============================" << std::endl;
	}

	std::ostream& operator<<(std::ostream& op, const SnackSlot& slot_)
	{
		op << "Slot number  " << slot_.getSlotNum() << std::endl;
		op << "Maximum number of snacks: " << slot_.getMaxNumOfSnacks() << std::endl;
		op << "Number of snacks at the moment: " << slot_.getNumOfSnacks() << std::endl;
		op << "============================" << std::endl;
		op << "List of snacks: " << std::endl;
		op << "============================" << std::endl;
		for (int i = 0; i < slot_.getNumOfSnacks(); i++)
		{
			op << "Position #" << i + 1 << ": " << std::endl;
			op << "Name: " << slot_.snacks[i].getName() << std::endl;
			op << "Price: " << slot_.snacks[i].getPrice() << std::endl;
			op << "Calories: " << slot_.snacks[i].getCalNum() << std::endl;
			op << "============================" << std::endl;
		}
		op << "============================" << std::endl;

		return op;
	}
//}

