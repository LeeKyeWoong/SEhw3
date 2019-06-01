#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;


Ticket::Ticket()
{

	//Function: Ticket()
	//Description:Ticket의 생성자 및 초기화
	//Created: 2019/5/28
	//Author: 홍지은


	this->sid = "";
	this->homeTeam = "";
	this->awayTeam = "";
	this->price = 0;
	this->gameDatenTime = "";
	this->registerTicketDate = "";
	this->seatNum = "";
	this->isSold = false;
	this->ticketType = "";
	this->isLimitedTimeAuction = false;
}

void Ticket::addNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType )
{
	//Function: addNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType )
	//Description: 새로운 티켓을 추가한다.
	//Created: 2019/5/28
	//Author: 홍지은

	this->price = price;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->gameDatenTime = gameDatenTime;
	this->seatNum = seatNum;
	this->isLimitedTimeAuction = isLimitedTimeAuction;
	this->isSold = false; //새로 들어온 티켓은 아직 팔리지 않은상태!
	this->sid = sid;	
	this->registerTicketDate = registerTicketDate;
	this->ticketType = ticketType;
}

void Ticket::removeTicket()
{
	//Function: removeTicket()
	//Description: 티켓을 삭제한다.
	//Created: 2019/6/1
	//Author: 홍지은

	this->price = 0;
	this->homeTeam = "";
	this->awayTeam = "";
	this->gameDatenTime = "";
	this->seatNum = "";
	this->isLimitedTimeAuction = false;
	this->isSold = false;
	this->sid = "";
	this->registerTicketDate = "";
	this->ticketType = "";
}

bool Ticket::getReservable()
{

	//Function: getReservable()
	//Description: 예약가능한지에 대한 여부를 반환한다. getReservable이 트루이면 예약이 가능하다는 뜻이고 isSold는 false이다.
	//Created: 2019/5/28
	//Author: 홍지은

	return !isSold;
}

void Ticket::setReservable(bool pSold)
{
	//Function: setReservable(bool pSold)
	//Description: setReservable이 true면 티켓이 다시 예약가능한 상태가 되도록 한다.
	//Created: 2019/5/28
	//Author: 홍지은

	isSold = !pSold;

	//만일 pSold가 true이면 아직 안팔렸다는 뜻이므로 isSold는 false가 된다
	//반대로 pSold가 false이면 팔렸다는 뜻이므로 isSold는 true가 되야한다.
}

string Ticket::getSellerId()
{
	//Function: getSellerId()
	//Description: seller의 id를 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->sid;
}

string Ticket::getHomeTeam()
{
	//Function: getHomeTeam()
	//Description: 홈팀을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->homeTeam;
}

string Ticket::getAwayTeam()
{
	//Function: getAwayTeam()
	//Description: 어웨이팀을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->awayTeam;
}

int Ticket::getTicketPrice()
{
	//Function: getTicketPrice()
	//Description: 티켓의 가격을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->price;
}

string Ticket::getTicketRegisterDate()
{
	//Function: getTicketRegisterDate()
	//Description: 티켓의 등록날짜를 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->registerTicketDate;
}

string Ticket::getTicketSeatNum()
{
	//Function: getTicketSeatNum()
	//Description: 좌석을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->seatNum;
}
