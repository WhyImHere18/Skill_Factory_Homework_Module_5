#include "Snack.h"
#include <iostream>
#include <string>

Snack::Snack(SnackType Type_, std::string Name_, double Price_, unsigned short CalNum_)
{
	this->snackType = Type_;
	this->name = Name_;
	this->price = Price_;
	this->calNum = CalNum_;
	this->slotNum = 0;
	this->index = 0;
}

Snack::Snack(SnackType Type_, std::string Name_, double Price_)
{
	this->snackType = Type_;
	this->name = Name_;
	this->price = Price_;
	this->calNum = 0;
	this->slotNum = 0;
	this->index = 0;
}

Snack::Snack(SnackType Type_, std::string Name_)
{
	this->snackType = Type_;
	this->name = Name_;
	this->price = 0.0;
	this->calNum = 0;
	this->slotNum = 0;
	this->index = 0;

}

Snack::Snack(const Snack& other)
{
	this->snackType = other.snackType;
	this->name = other.name;
	this->price = other.price;
	this->calNum = other.calNum;
	this->slotNum = other.slotNum;
	this->index = other.index;
}

Snack::Snack()
{
	this->snackType = CHOCOLATE;
	this->name = "chocolate";
	this->price = 1.0;
	this->calNum = 0;
	this->slotNum = 0;
	this->index = 0;
}

void Snack::setSnackType(SnackType type_)
{
	snackType = type_;
}

SnackType Snack::getSnackType() const
{
	return snackType;
}

void Snack::setName(std::string name_)
{
	name = name_;
}

std::string Snack::getName() const
{
	return name;
}

void Snack::setPrice(double price_)
{
	price = price_;
}

double Snack::getPrice() const
{
	return price;
}

void Snack::setCalNum(unsigned short calNum_)
{
	calNum = calNum_;
}

unsigned short Snack::getCalNum() const
{
	return calNum;
}

void Snack::setSlotNum(int slotNum_)
{
	slotNum = slotNum_;
}

int Snack::getSlotNum() const
{
	return slotNum;
}

void Snack::setIndex(int index_)
{
	index = index_;
}

int Snack::getIndex() const
{
	return index;
}

bool operator==(Snack& snack1, Snack& snack2)
{
	if (snack1.getSnackType() == snack2.getSnackType() &&
		snack1.getName() == snack2.getName() &&
		snack1.getPrice() == snack2.getPrice() &&
		snack1.getCalNum() == snack2.getCalNum() &&
		snack1.getSlotNum() == snack2.getSlotNum() &&
		snack1.getIndex() == snack2.getIndex())
	{
		return true;
	}
	else
	{
		return false;
	}
}

