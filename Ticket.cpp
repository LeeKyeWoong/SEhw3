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
	//��� �������ٰ��ΰ�.
	this->sid = sid;	
	this->registerTicketDate = registerTicketDate;
	this->isSold = false;
	this->ticketType = ticketType;

	//�Ʒ��� ���� �Է� ������
	this->price = price;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->gameDatenTime = gameDatenTime;
	this->seatNum = seatNum;
	this->isLimitedTimeAuction = isLimitedTimeAuction;
}

//void Ticket::removeTicket()  ->�ʿ��Ѱ�
//-> Ÿ�̸ӿ��� 1���� ���� Ƽ�� ���� ������ ������ ���⼭?

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

