#pragma once

#include<iostream>
#include "main.h"
using namespace std;

void RegisterTicketControl::registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
{
	//Function: void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
	//Description: Ƽ��������� TicketCollection, MemberCollection, Timer�� ���ڷ� �޾� Ƽ���� �߰��ϴ��Լ�
	// Created: 2019/05/31
	// Author: �̰��

	this->ticketCollection = ticketCollection; 
	this->memberCollection = memberCollection; 
	
	bool isSold;
	string sid;
	string registerTicketDate;
	string ticketType;

	if (this->memberCollection->currentSession() == NULL)  // ����ON�� ����� ����.
	{
		cout << "> ���� SessionOn �� ����� �����ϴ�" << endl;
	}
	else
	{
		if (this->memberCollection->currentSession()->getMemType().compare("host") == 0) // ���� �Ǹ��ڶ��
		{
			isSold = false;													// �Ǹſ��δ� false�� �Ѵ�.
			sid = this->memberCollection->currentSession()->getId(); 		// ���̵� �޴´�.
			registerTicketDate = timer->getCurrentTime();            		// ����ð��� �޴´�.

			if(isLimitedTimeAuction) // ���� ��� Ƽ���̶�� 
			{
				ticketType = "A"; // Ƽ��Ÿ���� �������� �Ѵ�.
			}
			else
			{
				ticketType = "G"; // Ƽ��Ÿ���� �Ϲ�Ƽ������ �Ѵ�.
			}
			this->ticketCollection->addTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction, isSold, sid, registerTicketDate, ticketType);  // TicketList�� Ƽ�ϵ��
		}
		else // ���� �����ڶ�� 
		{	
			cout << "> �����ڴ� Ƽ���� ����� �� �����ϴ�" << endl;
		}
	}

}
