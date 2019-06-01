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
	//Description: �Ű������� ���� �ε����� �ش��ϴ� Ƽ���� �����Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����
	// Revsions : 
	// 1. When & Who : 2019/06/02 by ��¿�
	//    What : �߰��� �ִ� Ƽ�� ���� ��, ������ ������ �ʵ��� �ڿ� �ִ� ������ ������ ���ܿ�

	ticketList[deleteTicketIndex]->removeTicket();
	int num = this->ticketCount;
	for (int i = deleteTicketIndex; i < num-1; i++) {
		this->ticketList[i] = this->ticketList[i + 1];
	}
	this->ticketList[num] = NULL;
}

void TicketCollection::addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType) // TicketList�� Ƽ�ϵ���Ѵ�.
{
	int currenTicketCount = this->getTicketCount();
	this->ticketList[currenTicketCount]->addNewTicket(price, gameDatenTime, homeTeam, awayTeam, seatNum, isLimitedTimeAuction,isSold, sid, registerTicketDate, ticketType);
	this->increaseTicketCount();
}

Ticket * TicketCollection::getTicket(int ticketCount)
{
	return ticketList[ticketCount];
}