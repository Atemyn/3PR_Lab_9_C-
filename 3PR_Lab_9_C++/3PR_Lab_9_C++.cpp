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

	firstStaticB.addToBuilding(&secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* ������ � ������������� ������������ ������. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB = new Building;

	cout << "������������ ����������: " << endl << endl;

	firstDynamicB->inputBuilding();

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
	cout << "�������� ������� � �������������� this � ������� addToBuilding:" << endl << endl;
	Building* buildd = new Building;
	buildd->inputBuilding();
	buildd->addToBuilding(buildd);
	/*.................................................................*/

	/* ������������� ������������ ������. */
	cout << "������������� ������������ ������:" << endl;
	cout << "����� ����� �����-���� ����������� ���� ��������� ������: " << Building::getCountOfBuildings() << endl << endl;
	/*....................................*/

	/* ����� ������������� ������������ � ������������� ���������, ������������� �������. */
	cout << "����� ������������� ������������ ���������:" << endl << endl;
	char adr[] = "�������, 11";
	Building statB1, statB2(3), statB3((string)"������� ������", adr,  5, 1, 2, 3, 5, 3);
	statB1.getBuilding();
	statB2.getBuilding();
	statB3.getBuilding();
	cout << "����� ������������� ������������� ���������:" << endl << endl;
	Building* dynB1 = new Building;
	Building* dynB2 = new Building(3);
	Building* dynB3 = new Building((string)"������� ������", adr, 5, 1, 2, 3, 5, 3);
	dynB1->getBuilding();
	dynB2->getBuilding();
	dynB3->getBuilding();
	cin.get();
	cout << "������������� ������� ������������� � ����� ����������:" << endl << endl;
	Building masB[3] = { 3, 5, 7 };
	masB[0].getBuilding();
	masB[1].getBuilding();
	masB[2].getBuilding();
	/*.............................................*/

	/* �������� �����������. */
	cout << "�������� �����������:" << endl << endl;
	Building build1((string)"������� ������", adr, 5, 1, 2, 3, 5, 3);
	Building build2 = build1;

	build1.inputBuilding();
	build2.getBuilding();
	/*....................*/

	/* ���������� ��������� ������������. */
	cout << "���������� ��������� ������������:" << endl << endl;
	Building* b_1 = new Building((string)"������� ������", adr, 5, 1, 2, 3, 5, 3);
	Building* b_2 = new Building((string)"������������� ������", adr, 5, 1, 3, 5, 5, 5);
	
	*b_2 = *b_1;
	b_1->inputBuilding();

	b_2->getBuilding();
	return 0;
}