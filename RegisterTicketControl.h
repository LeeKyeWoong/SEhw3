#pragma once

#include <iostream>
#include <string>
#include "main.h"

class MemberCollection;
class TicketCollection;
class Timer;

class RegisterTicketControl
{
	// Class: RegisterTicketControl
	// Description: Ƽ�ϵ�������� �Է¹ް� ó���ϴ��Լ�
	// Created: 2019/05/31
	// Author: �̰��

private:

	TicketCollection * ticketCollection; 
	MemberCollection * memberCollection; 

public:
	void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *pticketCollection, MemberCollection * pmemberCollection ,Timer * ptimer);  //  TicketCollection�� Ƽ���� �߰��ϴ��Լ�
};

