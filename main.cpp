#pragma once
#include "main.h"
#define MAX 50
using namespace std;


int main()
{
	// Function: Main()
	// Description: Ƽ�� ���� ���α׷� main�Լ�
	// Created: 2019/05/29
	// Author: �̰��
	// Revsions : 
	// 1. When & Who : 20--/--/-- by ___
	//    What : switch �� case���� interface �Լ� ���� 

	Member member[MAX];             // ��� ��ü ���� 
	Timer timer;					// Ÿ�̸� ��ü ���� 
	Reservation reservation[MAX];	// ���� ��ü ����
	Ticket ticket[MAX];				// Ƽ�� ��ü ����

	ReservationCollection reservationCollection(reservation);  // ���� ����
	TicketCollection ticketCollection(ticket);                 // Ƽ�� ����
	MemberCollection memberCollection(member);				   // ��� ����

	freopen("input.txt", "r", stdin);   // scanf�ÿ� input.txt���� read�Ѵ�.
	freopen("output.txt", "w", stdout); // printf�ÿ� output.txt���� write�Ѵ�.

	while (1)
	{
		// �� ���� �޴��� ���� ���� 
		int menu_1 = 0;
		int menu_2 = 0;

		// �Է����Ͽ��� �޴� ���� 2���� �б�
		cin >> menu_1 >> menu_2;

		// �޴� ���� �� �ش� ���� ����
		switch(menu_1)
		{
			case 1: 
			{
				switch(menu_2)
				{
					case 1: {	// 1.1. ȸ������ 
						signupInterface(&memberCollection);
						break;
					}
					case 2: {	// 1.2. ȸ��Ż�� 
						//unregisterInterface(&TicketCollection, &reservationCollection, &MemberCollection);
						break;
					}
				}
				break;
			}
			case 2:
			{
				switch(menu_2)
				{
					case 1: {	// 2.1. �α���
						//loginInterface(&MemberCollection);
						break;
					}
					case 2: {	// 2.2. �α׾ƿ�
						//logoutInterface(&MemberCollection);
						break;
					}
				}
				break;
			}
			case 3: 
			{
				switch(menu_2) 
				{
					case 1: {   // 3.1. �Ǹ�Ƽ�� ���
						//registerTicketInterface(&TicketCollection, &MemberCollection,&timer);
						break;
					}
					case 2: {   // 3.2. ���Ƽ�� ��ȸ
						//checkTicketInterface(&TicketCollection, &MemberCollection);
						break;
					}
				}
				break;
			}
			case 4: 
			{
				switch(menu_2) 
				{
					case 1: {   // 4.1. Ƽ�� �˻�
						//searchTicketInterface(&TicketCollection, &MemberCollection);
						break;
					}
					case 2: {   // 4.2. Ƽ�� ����
						//reserveGeneralReservationInterface(&reservationCollection, &TicketCollection, &MemberCollection);
						break;
					}
					case 3: {   // 4.3. ��� ���� Ƽ�� �˻�
						//reserveOpaqueReservationInterface(&reservationCollection, &TicketCollection, &MemberCollection, &timer);
						break;
					}
					case 4: {   // 4.4. ��� ����
						//checkReservationInterface(&reservationCollection, &MemberCollection);
						break;
					}
					case 5: {   // 4.5. ���� ���� ��ȸ
						//checkReservationInterface(&reservationCollection, &MemberCollection);
						break;
					}
				}
				break;
			}
			case 5:
			{
				switch(menu_2) 
				{
					case 1: {	 // 5.1. ����ð� ����
						//setCurrentTimeInterface(&timer, &TicketCollection, &MemberCollection);
						break;
					}
				}	
				break;
			}
			case 6: 
			{
				switch(menu_2) 
				{
					case 1: {	 // 6.1. session ����
						//changeSession(&MemberCollection);
						break;
					}
					case 2: {	// 6.2. guest session���� ����
						//guestSession(&MemberCollection);
						break;
					}
				}
				break;
			}
			case 7: {
				switch(menu_2) 
				{
					case 1: {   // 7.1. ����
						//programExit();	//programExit() �Լ����� �ش� ��� ����
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

void signupInterface(MemberCollection* memberCollection)  // 1.1 ȸ������ �������̽�
{
	SignUpUI userInterface;
	SignUpControl control;
	userInterface.inputInfo(&control, memberCollection);
}
/*
void unregisterInterface(TicketCollection* TicketCollection, ReservationCollection* reservationCollection, MemberCollection* MemberCollection) //1.2 ȸ��Ż�� �������̽�
{
	UnregisterUI userInterface;
	UnregisterControl control;
	userInterface.callUnregister(&control, TicketCollection, reservationCollection, MemberCollection);
}

void loginInterface(MemberCollection* MemberCollection) //2.1 �α��� �������̽�
{
	LoginUI userInterface;
	LoginControl control;
	userInterface.inputLoginInfo(&control, MemberCollection);
}

void logoutInterface(MemberCollection* MemberCollection) //2.2 �α׾ƿ� �������̽�
{
	LogoutUI userInterface;
	LogoutControl control;
	userInterface.callLogout(&control, MemberCollection);
}

void registerTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer * timer) // 3.1 �Ǹ�Ƽ�� ��� �������̽�
{
	RegisterTicketUI userInterface;
	RegisterTicketControl control;
	userInterface.inputRegisterNewTicket(&control, TicketCollection, MemberCollection, timer);
}

void checkTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection) // 3.2. ���Ƽ�� ��ȸ �������̽�
{
	CheckTicketUI userInterface;
	CheckTicketControl control;
	control.getHostTicket(&userInterface, TicketCollection, MemberCollection);

void searchGeneralTickeInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection)  // 4.1. Ƽ�� �˻� �������̽�
{
	SearchTicketUI userInterface;
	SearchTicketControl control;
	userInterface.selectCityAndDate(&control, TicketCollection, MemberCollection);
}

void reserveGeneralTicketInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection) // 4.2. Ƽ�� ���� �������̽�
{
	ReserveGeneralTicketUI userInterface;
	ReserveGeneralTicketControl control;
	userInterface.reserveGeneralTicket(&control, reservationCollection, TicketCollection, MemberCollection);
}

void searchAuctionTicketInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer* timer) // 4.3. ��� ���� Ƽ�� �˻� �������̽� 
{
	ReserveOpaqueInventoryUI userInterface;
	ReserveOpaqueInventoryControl control;
	userInterface.reserveOpaqueInventory(&control, reservationCollection, TicketCollection, MemberCollection, timer);
}

void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection)  // 4.4. ���� ���� ��ȸ
{
	CheckReservationInformationUI userInterface;
	CheckReservationInformationControl control;
	userInterface.showReservationInformation(&control, reservationCollection, MemberCollection);
}

void participateAuctionTicketInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection) // 4.5. ��� ���� �������̽�
{
	CheckReservationInformationUI userInterface;
	CheckReservationInformationControl control;
	userInterface.showReservationInformation(&control, reservationCollection, MemberCollection);
}

void setCurrentTimeInterface(Timer* timer, TicketCollection * TicketCollection, MemberCollection* MemberCollection) // 5.1 ����ð����� �������̽�
{
	SetCurrentTimeUI userInterface;
	SetCurrentTimeControl control;
	userInterface.startInterface(&control, timer, MemberCollection, TicketCollection);
}

void changeSession(MemberCollection* p_membercollection) // 6.1 Session����
{
	// Function : changeSession(MemberCollection* p_membercollection)
	// Description: �Է¹��� ID�� Session Change�� �õ��ϴ� �Լ�
	// Created: 2018/5/27
	// Author: ������
	string ID;
	cin >> ID;
	bool sameID = false;
	int membercount = p_membercollection->getMemberCount();

	// �ش� ��� ����
	for (int i = 0; i < membercount; i++)
	{
		if (p_membercollection->getMember(i)->getID().compare(ID) == 0)
		{
			sameID = true;
			break;
		}
	}

	if (sameID)
	{
		for (int i = 0; i < membercount; i++)
		{
			if (p_membercollection->getMember(i)->getID().compare(ID) == 0)
			{
				p_membercollection->getMember(i)->setsessionOn(true);
			}
			else
			{
				p_membercollection->getMember(i)->setsessionOn(false);
			}
		}
		cout << "6.1 Session ����" << endl;
		cout << ">" << ID << endl;
	}

}

void guestSession(MemberCollection* p_MemberCollection)  // 6.2. guest session���� ����
{
	// Function :guestSession(MemberCollection* membercollection)
	// Description: ���α׷��� memType�� guest�� ����
	// Created: 2018/5/27
	// Author: ������

	// �ش� ��� ����

	if (p_MemberCollection->currentSession() == NULL)
	{
		cout << "6.2 Guest Session���� ����" << endl;
	}
	else
	{
		p_MemberCollection->currentSession()->setsessionOn(false);
		cout << "6.2 Guest Session���� ����" << endl;
	}

}

void exitProgram() {  // 7.1 ���� �������̽�

	// Function :programExit()
	// Description: ���α׷� ����
	// Created: 2018/05/25
	// Author: ����ȯ

	printf("7.1 ����\n");
	exit(0);
}
*/