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
	// Description: 티켓등록정보를 입력받고 처리하는함수
	// Created: 2019/05/31
	// Author: 이계웅

private:

	TicketCollection * ticketCollection; 
	MemberCollection * memberCollection; 

public:
	void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *pticketCollection, MemberCollection * pmemberCollection ,Timer * ptimer);  //  TicketCollection에 티켓을 추가하는함수
};

