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

//Ƽ�� ������ ����غ���.
//void TicketCollection::deleteTicket(int deleteTicketIndex)
{
	if (deleteTicketIndex == 0)
	{
		ticketList[deleteTicketIndex]->removeTicket();
		ticketList[deleteTicketIndex] = NULL;
	}
}

void TicketCollection::addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction)
{
	int currenTicketCount = this->getTicketCount();
	this->ticketList[currenTicketCount]->addNewTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction);
	this->increaseTicketCount();
}

Ticket * TicketCollection::getTicket(int ticketCount)
{
	return ticketList[ticketCount];
}