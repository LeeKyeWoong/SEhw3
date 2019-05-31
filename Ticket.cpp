#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;


Ticket::Ticket()
{
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

}
//-> 타이머에서 1년이 지난 티켓 삭제 하지만 구현은 여기서?

bool Ticket::getReservable()
{
	return isSold;
}

void Ticket::setReservable(bool pSold)
{
	isSold = !pSold;

	//만일 pSold가 true이면 아직 안팔렸다는 뜻이므로 isSold는 false가 된다
	//반대로 pSold가 false이면 팔렸다는 뜻이므로 isSold는 true가 되야한다.
}

string Ticket::getSellerId()
{
	return this->sid;
}

string Ticket::getHomeTeam()
{
	return this->homeTeam;
}

string Ticket::getAwayTeam()
{
	return this->awayTeam;
}

int Ticket::getTicketPrice()
{
	return this->price;
}

string Ticket::getTicketRegisterDate()
{
	return this->registerTicketDate;
}

string Ticket::getTicketSeatNum()
{
	return this->seatNum;
}
