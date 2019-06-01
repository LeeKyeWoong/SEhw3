#pragma once

#include "SearchTicketUI.h"
#include "SearchTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"

#include "Reservation.h"
#include "ReservationCollection.h"
using namespace std;


SearchTicketControl::SearchTicketControl()
{
	tempCount = 0;
	for (int i = 0; i < MAX; i++)
		temp[i] = NULL;
}

void SearchTicketControl::showBuyerWantTicket(string homeTeam, SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	if (memberCollection->currentSession() == NULL)
	{ }

	else
	{
		if (memberCollection->currentSession()->getMemType().compare("guest") == 0)
		{
			int ticketCount = ticketCollection->getTicketCount();
			for (int i = 0; i < ticketCount; i++)
			{
				if ((ticketCollection->getTicket(i)->getHomeTeam().compare(homeTeam) == 0))
				{
					if (ticketCollection->getTicket(i)->getReservable() == 0)
					{
						temp[tempCount++] = ticketCollection->getTicket(i);
					}
				}
			}

			//날짜 및 시간순으로 정렬

			for (int i = 0; i < tempCount - 1; i++)
			{
				for (int j = 0; j < tempCount - 1 - i; j++)
				{
					if()
				}
			}
		}
	}
}

Ticket* SearchTicketControl::getSortedList(int ticketCount)
{
	return temp[ticketCount];
}

int SearchTicketControl::getTempCount()
{
	return tempCount;
}