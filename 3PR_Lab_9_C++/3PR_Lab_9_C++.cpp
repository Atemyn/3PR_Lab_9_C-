#include "Building.h"

int main()
{

	// Подключение русского консольного ввода.
	SetConsoleCP(1251);
	// Подключение русского консольного вывода.
	SetConsoleOutputCP(1251);

	/* Работа со статическими экземплярами класса. */
	Building firstStaticB, secondStaticB;

	cout << "Программа по созданию зданий." << endl << "Все размерные данные вводятся в метрах." << endl;
	cout << "Статические экземпляры: " << endl << endl;

	firstStaticB.inputBuilding();

	firstStaticB.addToBuilding(&secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* Работа с динамическими экземплярами класса. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB = new Building;

	cout << "Динамические экземпляры: " << endl << endl;

	firstDynamicB->inputBuilding();

	firstDynamicB->addToBuilding(secondDynamicB);

	firstDynamicB->addFloors();
	firstDynamicB->removeFloors();
	// Очистка памяти.
	delete firstDynamicB;
	delete secondDynamicB;
	/*............................................*/

	/* Динамический массив объектов. */
	int amount = 2;
	Building* firstDynamicArray = new Building[amount];

	cout << "Динамический массив объектов: " << endl << endl;

	firstDynamicArray->inputBuilding();

	firstDynamicArray->addToBuilding((firstDynamicArray + 1));
	// Очистка памяти.
	delete[] firstDynamicArray;
	/*...............................*/

	/* Массив динамических объектов. */
	Building* firstArrayOfDyn[2];
	for (int i = 0; i < 2; i++)
	{
		// Выделение памяти.
		firstArrayOfDyn[i] = new Building;
	}

	cout << "Массив динамических объектов: " << endl << endl;

	firstArrayOfDyn[0]->inputBuilding();

	firstArrayOfDyn[0]->addToBuilding(firstArrayOfDyn[1]);

	for (int i = 0; i < 2; i++)
	{
		// Очистка памяти.
		delete firstArrayOfDyn[i];
	}
	/*..............................*/

	/* Новые функции Ассоциации. */
	Building staticB;
	cout << "Новые функции Ассоциации: " << endl;

	staticB.inputBuilding();

	staticB.openWindowsOnFacade();
	staticB.closeWindowsOnFacade();
	/*..........................*/

	/* Возвращение значения из функции через указатель и через ссылку. */
	Building b1, b2;
	cout << "Возвращение значения из функции через указатель и через ссылку: " << endl;

	b1.inputBuilding();
	// Вызов первого метода через указатель.
	b1.exchangeWindowsOnBuildings(&b2);

	cout << "Первое здание после первого обмена:" << endl;
	b1.getBuilding();

	cout << "Второе здание после первого обмена:" << endl;
	b2.getBuilding();
	// Вызов второго метода через ссылку.
	b1.exchangeWindowsOnBuildings(b2);

	cout << "Первое здание после второго обмена:" << endl;
	b1.getBuilding();

	cout << "Второе здание после второго обмена:" << endl;
	b2.getBuilding();
	/*................................................................*/

	/* Проверка условия с использованием this в функции addToBuilding. */
	cout << "Проверка условия с использованием this в функции addToBuilding:" << endl;
	Building* buildd = new Building;
	buildd->inputBuilding();
	buildd->addToBuilding(buildd);
	/*.................................................................*/

	/* Проверка переопределенных операторов. */
	cout << "Проверка переопределенных операторов:" << endl;
	Building bRes, bFirst, bSecond;

	b1.inputBuilding();

	bRes = bFirst + bSecond;

	bRes.getBuilding();

	bFirst = bRes++;
	bSecond = ++bRes;

	bFirst.getBuilding();
	bSecond.getBuilding();
	/*......................................*/

	/* Использование статического метода. */
	cout << "Использование статического метода:" << endl;
	cout << "Общее число когда-либо построенных этой компанией зданий: " << Building::getCountOfBuildings() << endl;
	/*....................................*/

	cin.get();
	return 0;
}