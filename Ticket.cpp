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

void Ticket::addNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction)
{
	//어떻게 지정해줄것인가.
	this->sid = sid;	
	this->registerTicketDate = registerTicketDate;
	this->isSold = false;
	this->ticketType = ticketType;

	//아래는 실제 입력 데이터
	this->price = price;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->gameDatenTime = gameDatenTime;
	this->seatNum = seatNum;
	this->isLimitedTimeAuction = isLimitedTimeAuction;
}

//void Ticket::removeTicket()  ->필요한가
//-> 타이머에서 1년이 지난 티켓 삭제 하지만 구현은 여기서?

bool Ticket::getReservable()
{
	return isSold;
}

void Ticket::setReservable(bool isSold)
{
	
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

