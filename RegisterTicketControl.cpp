#pragma once

#include<iostream>
#include "main.h"
using namespace std;

void RegisterTicketControl::registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
{
	//Function: void registerNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, TicketCollection *ticketCollection, MemberCollection * memberCollection ,Timer * timer)
	//Description: 티켓정보들과 TicketCollection, MemberCollection, Timer을 인자로 받아 티켓을 추가하는함수
	// Created: 2019/05/31
	// Author: 이계웅

	this->ticketCollection = ticketCollection; 
	this->memberCollection = memberCollection; 
	
	bool isSold;
	string sid;
	string registerTicketDate;
	string ticketType;

	if (this->memberCollection->currentSession() == NULL)  // 세션ON인 멤버가 없다.
	{
		cout << "> 현재 SessionOn 인 멤버가 없습니다" << endl;
	}
	else
	{
		if (this->memberCollection->currentSession()->getMemType().compare("host") == 0) // 만약 판매자라면
		{
			isSold = false;													// 판매여부는 false로 한다.
			sid = this->memberCollection->currentSession()->getId(); 		// 아이디를 받는다.
			registerTicketDate = timer->getCurrentTime();            		// 현재시간을 받는다.

			if(isLimitedTimeAuction) // 만약 경매 티켓이라면 
			{
				ticketType = "A"; // 티켓타입을 옥션으로 한다.
			}
			else
			{
				ticketType = "G"; // 티켓타입을 일반티켓으로 한다.
			}
			this->ticketCollection->addTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction, isSold, sid, registerTicketDate, ticketType);  // TicketList에 티켓등록
		}
		else // 만약 구매자라면 
		{	
			cout << "> 구매자는 티켓을 등록할 수 없습니다" << endl;
		}
	}

}
