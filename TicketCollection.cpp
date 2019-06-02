#pragma once

#include <iostream>
#include <string>
#include "TicketCollection.h"

TicketCollection::TicketCollection(Ticket ticketList[MAX])
{
	this->ticketCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		this->ticketList[i] = &ticketList[i];
	}
}

void TicketCollection::increaseTicketCount()
{
	this->ticketCount++;
}

int TicketCollection::getTicketCount()
{
	return this->ticketCount;
}

void TicketCollection::deleteTicket(int deleteTicketIndex)
{	//Function: deleteTicket()
	//Description: 매개변수로 받은 인덱스에 해당하는 티켓을 삭제한다.
	//Created: 2019/6/1
	//Author: 홍지은
	// Revsions : 
	// 1. When & Who : 2019/06/02 by 김승연
	//    What : 중간에 있는 티켓 삭제 시, 공백이 생기지 않도록 뒤에 있는 정보들 앞으로 땡겨옴

	ticketList[deleteTicketIndex]->removeTicket();
	int num = this->ticketCount;
	for (int i = deleteTicketIndex; i < num-1; i++) {
		this->ticketList[i] = this->ticketList[i + 1];
	}
	this->ticketList[num] = NULL;
}

void TicketCollection::addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType) // TicketList에 티켓등록한다.
{
	int currenTicketCount = this->getTicketCount();
	this->ticketList[currenTicketCount]->addNewTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction,isSold, sid, registerTicketDate, ticketType);
	this->increaseTicketCount();
}

Ticket * TicketCollection::getTicket(int ticketCount)
{
	return ticketList[ticketCount];
}