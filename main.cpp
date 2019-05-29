#pragma once
#include "main.h"
#define MAX 50
using namespace std;


int main()
{
	//Function: Main()
	//Description: ���� ���� ���α׷��� main������ �ϴ� �Լ�
	//Created: 2018/05/25
	//Author: ������
	// Revsions : 
	//   1. When & Who : 2018/05/26 by ������
	//      What : switch �� case���� interface �Լ� ���� 
	//   2. When & Who : 2018/05/26 by ������
	//      What : Reservation ��� ���� �Լ� �Է� �� test
	//   3. When & Who : 2018/05/27 by ������
	//      What : Accommodation ��� ���� �Լ� �Է� �� test
	//   4. When & Who : 2018/05/27 by ����ȯ
	//      What : Accommodation ���� ����, ���� ���� �� �Լ� �� Ŭ���� �ݿ�
	//   5. When & Who : 2018/05/28 by ������
	//      What : Meber ��� ���� �Լ� �Է� �� test
	//   6. When & Who : 2018/05/28 by ������
	//      What : Member ���� ����, ���� ���� �� �Լ� �� Ŭ���� �ݿ�
	//   7. When & Who : 2018/05/28 by �ڰǿ�
	//      What : Reservation ���� ����, ���� ���� �� �Լ� �� Ŭ���� �ݿ�, Opaque invnetory ���� �Լ� ������
	//   8. When & Who : 2018/05/28 by ������
	//      What : ����� ������ ������� case�� �Լ� ���� �� test
	//   9. When & Who : 2018/05/29 by ������
	//      What : �ڵ� ���� ��� ���� �� ���ü��� ���� ���ϵ��� ���� �Է� ������ ���� �� ���� test
	//   10. When & Who : 2018/05/30 by ������
	//      What : �߰� �������� �ݿ� �� ��� ��� test, preprocessor �� ���� ���� interface �Լ��� main.h�� �̵�


	Reservation reservation[MAX];
	Accommodation accommodation[MAX];
	MemberInfo memberInfo[MAX];
	Timer timer;

	ReservationCollection reservationCollection(reservation);
	AccommodationCollection accommodationCollection(accommodation);
	MemberInfoCollection memberInfoCollection(memberInfo);


	freopen("input.txt", "r", stdin); // scanf�ÿ� input.txt���� �о��
	freopen("output.txt", "w", stdout); // printf�ÿ� output.txt���� ��

	while (1)
	{
		// �޴� �Ľ��� ���� level ������ ���� ����
		int menulevel_1 = 0, menulevel_2 = 0;

		// �Է����Ͽ��� �޴� ���� 2���� �б�
		cin >> menulevel_1 >> menulevel_2;

		//�޴� ���� �� �ش� ���� ����
		switch (menulevel_1)
		{
		case 1:
		{
			switch (menulevel_2)
			{
			case 1: {	// "1.1. ȸ������" �޴� �κ� 
				signInInterface(&memberInfoCollection);
				break;
			}
			case 2: {	// "1.2. ȸ�� Ż��" �޴� �κ�
				unregisterInterface(&accommodationCollection, &reservationCollection, &memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 2:
		{
			switch (menulevel_2)
			{
			case 1: {	// "2.1. �α���" �޴� �κ� 
				loginInterface(&memberInfoCollection);
				break;
			}
			case 2: {	// "2.2. �α׾ƿ�" �޴� �κ�
				logoutInterface(&memberInfoCollection);
				break;
			}
			}
			break;
		}
		case 3: {
			switch (menulevel_2) {
			case 1: {   // "3.1. ���� ��ϡ� �޴� �κ�
				registerAccommodationInterface(&accommodationCollection, &memberInfoCollection,&timer);
				break;
			}
			case 2: {   // "3.2 ��� ���� ��ȸ" �޴��κ�
				checkAccommodationInterface(&accommodationCollection, &memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 4: {
			switch (menulevel_2) {
			case 1: {   // "4.1 ���� �˻�" �޴��κ�
				searchAccommodationInterface(&accommodationCollection, &memberInfoCollection);
				break;
			}
			case 2: {   //"4.2 ���� ����" �޴��κ�
				reserveGeneralReservationInterface(&reservationCollection, &accommodationCollection, &memberInfoCollection);
				break;
			}
			case 3: {   //"4.3 Opaque inventroy"�޴��κ�
				reserveOpaqueReservationInterface(&reservationCollection, &accommodationCollection, &memberInfoCollection, &timer);
				break;
			}
			case 4: {   // "4.4 �������� ��ȸ"�޴��κ�
				checkReservationInterface(&reservationCollection, &memberInfoCollection);
				break;
			}

			}
			break;
		}
		case 5:
		{
			switch (menulevel_2) {
			case 1: {	 // " 5.1. ����ð� ����
				setCurrentTimeInterface(&timer, &accommodationCollection, &memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 6: {
			switch (menulevel_2) {
			case 1: {	 // " 6.1 Session ����" �޴� �κ�
				changeSession(&memberInfoCollection);
				break;
			}
			case 2: {	// " 6.2. Guest session���� ���� " �޴� �κ�
				guestSession(&memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 7: {
			switch (menulevel_2) {
			case 1: {   // "7.1. ���ᡰ �޴� �κ�
				programExit();	//programExit() �Լ����� �ش� ��� ����
				break;

			}
			}
			break;
		}
		}
		cout << endl;
	}

	return 0;
}

void signInInterface(MemberInfoCollection* memberInfoCollection)  //1.1ȸ������ �������̽�
{
	SignInUI userInterface;
	SignInControl control;
	userInterface.inputInfo(&control, memberInfoCollection);
}

void unregisterInterface(AccommodationCollection* accommodationCollection, ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection) //1.2 ȸ��Ż�� �������̽�
{
	UnregisterUI userInterface;
	UnregisterControl control;
	userInterface.callUnregister(&control, accommodationCollection, reservationCollection, memberInfoCollection);
}

void loginInterface(MemberInfoCollection* memberInfoCollection) //2.1 �α��� �������̽�
{
	LoginUI userInterface;
	LoginControl control;
	userInterface.inputLoginInfo(&control, memberInfoCollection);
}

void logoutInterface(MemberInfoCollection* memberInfoCollection) //2.2 �α׾ƿ� �������̽�
{
	LogoutUI userInterface;
	LogoutControl control;
	userInterface.callLogout(&control, memberInfoCollection);
}


void registerAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection,Timer * timer) //3.1 ���� ��� �������̽�
{

	RegisterAccommodationUI userInterface;
	RegisterAccommodationControl control;
	userInterface.inputRegisterNewAccommodation(&control, accommodationCollection, memberInfoCollection, timer);
}

void checkAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection) //3.2 ���� ��ȸ �������̽�
{
	CheckAccommodationUI userInterface;
	CheckAccommodationControl control;
	control.getHostAccommodation(&userInterface, accommodationCollection, memberInfoCollection);
}

void searchAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection)  //4.1 ���Ұ˻� �������̽�
{
	SearchAccommodationUI userInterface;
	SearchAccommodationControl control;
	userInterface.selectCityAndDate(&control, accommodationCollection, memberInfoCollection);
}
void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection) //4.2 ���ҿ��� �������̽�
{
	ReserveGeneralAccommodationUI userInterface;
	ReserveGeneralAccommodationControl control;
	userInterface.reserveGeneralAccommodation(&control, reservationCollection, accommodationCollection, memberInfoCollection);
}
void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection, Timer* timer) //4.3 opaque inventory ���� �������̽�
{
	ReserveOpaqueInventoryUI userInterface;
	ReserveOpaqueInventoryControl control;
	userInterface.reserveOpaqueInventory(&control, reservationCollection, accommodationCollection, memberInfoCollection, timer);
}
void checkReservationInterface(ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection)  //4.4 �������� ��ȸ �������̽�
{
	CheckReservationInformationUI userInterface;
	CheckReservationInformationControl control;
	userInterface.showReservationInformation(&control, reservationCollection, memberInfoCollection);
}
void setCurrentTimeInterface(Timer* timer, AccommodationCollection * accommodationCollection, MemberInfoCollection* memberInfoCollection) //5.1 ����ð�����
{
	SetCurrentTimeUI userInterface;
	SetCurrentTimeControl control;
	userInterface.startInterface(&control, timer, memberInfoCollection, accommodationCollection);
}

void changeSession(MemberInfoCollection* p_membercollection)//6.1 Session����
{
	// Function : changeSession(MemberInfoCollection* p_membercollection)
	// Description: �Է¹��� ID�� Session Change�� �õ��ϴ� �Լ�
	// Created: 2018/5/27
	// Author: ������


	string ID;
	cin >> ID;
	bool sameID = false;
	int membercount = p_membercollection->getMemberInfoCount();

	// �ش� ��� ����
	for (int i = 0; i < membercount; i++)
	{
		if (p_membercollection->getMemberInfo(i)->getID().compare(ID) == 0)
		{
			sameID = true;
			break;
		}
	}

	if (sameID)
	{
		for (int i = 0; i < membercount; i++)
		{
			if (p_membercollection->getMemberInfo(i)->getID().compare(ID) == 0)
			{
				p_membercollection->getMemberInfo(i)->setsessionOn(true);
			}
			else
			{
				p_membercollection->getMemberInfo(i)->setsessionOn(false);
			}
		}
		cout << "6.1 Session ����" << endl;
		cout << ">" << ID << endl;
	}

}

void guestSession(MemberInfoCollection* p_memberInfoCollection)  //6.2. gusetSession���� ����
{
	// Function :guestSession(MemberInfoCollection* membercollection)
	// Description: ���α׷��� memType�� guest�� ����
	// Created: 2018/5/27
	// Author: ������

	// �ش� ��� ����

	if (p_memberInfoCollection->currentSession() == NULL)
	{
		cout << "6.2 Guest Session���� ����" << endl;
	}
	else
	{
		p_memberInfoCollection->currentSession()->setsessionOn(false);
		cout << "6.2 Guest Session���� ����" << endl;
	}

}



void programExit() {  //7.1 ���� �������̽�

	// Function :programExit()
	// Description: ���α׷� ����
	// Created: 2018/05/25
	// Author: ����ȯ

	printf("7.1 ����\n");
	exit(0);
}
