#include "Building.h"

int main()
{

	// ����������� �������� ����������� �����.
	SetConsoleCP(1251);
	// ����������� �������� ����������� ������.
	SetConsoleOutputCP(1251);

	/* ������ �� ������������ ������������ ������. */
	Building firstStaticB, secondStaticB;

	cout << "��������� �� �������� ������." << endl << "��� ��������� ������ �������� � ������." << endl;
	cout << "����������� ����������: " << endl << endl;

	firstStaticB.inputBuilding();
	initBuilding(secondStaticB);

	firstStaticB.addToBuilding(&secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* ������ � ������������� ������������ ������. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB = new Building;

	cout << "������������ ����������: " << endl << endl;

	firstDynamicB->inputBuilding();
	initBuilding(*secondDynamicB);

	firstDynamicB->addToBuilding(secondDynamicB);

	firstDynamicB->addFloors();
	firstDynamicB->removeFloors();
	// ������� ������.
	delete firstDynamicB;
	delete secondDynamicB;
	/*............................................*/

	/* ������������ ������ ��������. */
	int amount = 2;
	Building* firstDynamicArray = new Building[amount];

	cout << "������������ ������ ��������: " << endl << endl;

	firstDynamicArray->inputBuilding();
	initBuilding(*(firstDynamicArray + 1));

	firstDynamicArray->addToBuilding((firstDynamicArray + 1));
	// ������� ������.
	delete[] firstDynamicArray;
	/*...............................*/

	/* ������ ������������ ��������. */
	Building* firstArrayOfDyn[2];
	for (int i = 0; i < 2; i++)
	{
		// ��������� ������.
		firstArrayOfDyn[i] = new Building;
	}

	cout << "������ ������������ ��������: " << endl << endl;

	firstArrayOfDyn[0]->inputBuilding();
	initBuilding(*firstArrayOfDyn[1]);

	firstArrayOfDyn[0]->addToBuilding(firstArrayOfDyn[1]);

	for (int i = 0; i < 2; i++)
	{
		// ������� ������.
		delete firstArrayOfDyn[i];
	}
	/*..............................*/

	/* ����� ������� ����������. */
	Building staticB;
	cout << "����� ������� ����������: " << endl;

	staticB.inputBuilding();

	staticB.openWindowsOnFacade();
	staticB.closeWindowsOnFacade();
	/*..........................*/

	/* ����������� �������� �� ������� ����� ��������� � ����� ������. */
	Building b1, b2;
	cout << "����������� �������� �� ������� ����� ��������� � ����� ������: " << endl;

	b1.inputBuilding();
	initBuilding(b2);
	// ����� ������� ������ ����� ���������.
	b1.exchangeWindowsOnBuildings(&b2);

	cout << "������ ������ ����� ������� ������:" << endl;
	b1.getBuilding();

	cout << "������ ������ ����� ������� ������:" << endl;
	b2.getBuilding();
	// ����� ������� ������ ����� ������.
	b1.exchangeWindowsOnBuildings(b2);

	cout << "������ ������ ����� ������� ������:" << endl;
	b1.getBuilding();

	cout << "������ ������ ����� ������� ������:" << endl;
	b2.getBuilding();
	/*................................................................*/

	/* �������� ������� � �������������� this � ������� addToBuilding. */
	cout << "�������� ������� � �������������� this � ������� addToBuilding:" << endl;
	b1.inputBuilding();
	b1.addToBuilding(&b1);
	/*.................................................................*/

	/* ������������� ������������� ������ Building ������� initBuilding. */
	cout << "������������� ������������� ������ Building ������� Init:" << endl;
	initBuilding(b1);
	b1.getBuilding();
	/*...................................................................*/

	/* �������� ���������������� ����������. */
	cout << "�������� ���������������� ����������:" << endl;
	Building b3;

	b1.inputBuilding();
	initBuilding(b2);

	b3 = b1 + b2;

	b3.getBuilding();

	b1 = b3++;
	b2 = ++b3;

	b1.getBuilding();
	b2.getBuilding();
	/*......................................*/

	/* ������������� ������������ ������. */
	cout << "������������� ������������ ������:" << endl;
	cout << "����� ����� �����-���� ����������� ���� ��������� ������: " << Building::getCountOfBuildings() << endl;
	/*....................................*/
	cin.get();
	return 0;
}