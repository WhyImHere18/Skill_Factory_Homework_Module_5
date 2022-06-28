// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

int main()
{
	Snack* bounty = new Snack(CHOCOLATE, "Bounty", 60.0, 355);
	Snack* snickers = new Snack(CHOCOLATE, "Snickers", 60.0, 350);
	Snack* cola = new Snack(DRINK, "Coca-Cola", 50.0, 300);
	Snack* kvas = new Snack(DRINK, "Kvas", 53.0, 312);
	Snack* oreo = new Snack(COOKIE, "Oreo", 70.0, 467);
	Snack* water = new Snack(DRINK, "Akva", 40.0, 0);

	SnackSlot* slot1 = new SnackSlot(1, 2);

	slot1->addSnack(*bounty);	// add bounty
	slot1->addSnack(*cola);		// add cola
	slot1->addSnack(*oreo);		// trying add oreo, but slot is alreafy full (maximum 2 snacks are defined in the slot)
	slot1->printInfo();			// print
	slot1->getSnack(*cola);		// get cola --> only bounty remains in the slot
	slot1->printInfo();			// print
	

	SnackSlot* slot2 = new SnackSlot(2, 4);

	slot2->addSnack(*snickers);	// add skickers
	slot2->addSnack(*kvas);		// add kvas
	slot2->addSnack(*water);	// add water
	slot2->printInfo();			// print
	slot2->getSnack(*snickers);	// get snickers --> remains kvas and water
	slot2->printInfo();			// print

	VendingMachine* machine = new VendingMachine(1, "N. Novgorod city, Gagarina st, 23", 4);
	machine->addSlot(*slot1);
	machine->addSlot(*slot2);
	machine->printInfo();

	delete machine;
	delete slot2;
	delete slot1;
	delete kvas;
	delete cola;
	delete snickers;
	delete bounty;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
