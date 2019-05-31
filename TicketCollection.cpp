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
{
	if (deleteTicketIndex == 0)
	{
		ticketList[deleteTicketIndex]->removeTicket();
		ticketList[deleteTicketIndex] = NULL;
	}
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