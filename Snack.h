#pragma once

#include <iostream>
#include <string>

//namespace snack
//{
	enum SnackType
	{
		CHOCOLATE = 0,
		COOKIE,
		DRINK	// seems not logical, but let it be
	};

	class Snack
	{
	private:
		SnackType snackType;	// chocolate, cookie or some drink
		std::string name;		// name of the snack
		double price;			// price of the snack
		unsigned short calNum;	// number of calories in the snack
		int slotNum;			// a slot number the snack is belonging 
		int index;				// position on a slot

	public:
		Snack(SnackType, std::string, double, unsigned short);
		Snack(SnackType, std::string, double);
		Snack(SnackType, std::string);
		Snack();
		Snack(const Snack&);

		void setSnackType(SnackType);
		SnackType getSnackType() const;

		void setName(std::string);
		std::string getName() const;

		void setPrice(double);
		double getPrice() const;

		void setCalNum(unsigned short);
		unsigned short getCalNum() const;

		void setSlotNum(int);
		int getSlotNum() const;

		void setIndex(int);
		int getIndex() const;

		friend bool operator==(const Snack&, const Snack&);

		~Snack() = default;
	};
//}


