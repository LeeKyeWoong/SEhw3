#pragma once

#include<iostream>
#include "RegisterTicketUI.h"

using namespace std;

void RegisterTicketUI::inputRegisterNewTicket(RegisterTicketControl * registerTicketControl, TicketCollection *ticketCollection,  MemberCollection * memberCollection, Timer * timer)
{
	// Function: inputRegisterNewTicket(RegisterTicketControl * registerTicketControl,TicketCollection *ticketCollection,  MemberCollection * memberCollection, Timer * timer)
	// Description: �� Ticket ������ �Է��ϴ� �Լ�
	// Created: 2019/05/31
	// Author: �̰��
	
	this->registerTicketControl = registerTicketControl;
	this->ticketCollection = ticketCollection;
	this->memberCollection = memberCollection;

	string homeTeam; 			//Ȩ��
	string awayTeam; 			//������� 
	int price; 					//Ƽ���� ����
	string gameDatenTime; 		//���� ���۳�¥�� �ð�
	string seatNum; 			//Ƽ���� �¼�
	bool isLimitedTimeAuction;  //Ƽ���� ��ŷ� �ѱ�������� ����
	
	cin >> price >> gameDatenTime >> homeTeam >> awayTeam >> seatNum >> isLimitedTimeAuction;

	this->registerTicketControl->registerNewTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction,ticketCollection,memberCollection,timer);
	
	cout << "3.1 �Ǹ�Ƽ�ϵ��" << endl; // ����Ѵ�.
	cout << ">" << price << " " << gameDatenTime << " " << homeTeam << " " << awayTeam << " " << seatNum << isLimitedTimeAuction << endl; // ����Ѵ�.
	
}

