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
	else // 세션ON 인 멤버가 있다.
	{ 
		if (this->memberCollection->currentSession()->getMemType().compare("host") == 0) // 만약 판매자라면
		{	
			int ticketNumber = this->ticketCollection->getTicketCount();// 전체티켓수를 받는다.
			bool checkRegister = true; 									// 등록여부(중복여부)를 알려준다.
			 								
			for(int i = 0 ; i < ticketNumber; i ++) // 티켓수만큼 반복한다.
			{
				if(  (homeTeam.compare(this->ticketCollection[i]->getHomeTeam()==0))&&
				     (awayTeam.compare(this->ticketCollection[i]->getAwayTeam()==0))&&
				     (gameDatenTime.compare(this->ticketCollection[i]->getTicketRegisterDate()==0))&&
				     (seatNum.comapre(this->ticketCollection[i]->getTicketSeatNum()==0)) )
				{
					checkRegister = false; // 티켓을 등록할 수 없다. (중복티켓 )
				}

			}

			if(!checkRegister) // 등록할 수 없다면 
			{
				cout << "> 동일한 티켓은 등록할 수 없습니다." << endl;
			}
			else // 날짜,홈팀, 어웨이팀,날짜시간 모두 겹치는 것이 없다.
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
			
		}
		else // 만약 구매자라면 
		{	
			cout << "> 구매자는 티켓을 등록할 수 없습니다" << endl;
		}
	}

}
