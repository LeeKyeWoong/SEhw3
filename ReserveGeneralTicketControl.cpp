#pragma once
#include "ReserveGeneralTicketUI.h"
#include "ReserveGeneralTicketControl.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"

ReserveGeneralTicketControl::ReserveGeneralTicketControl()
{
	//Function: ReserveGeneralTicketControl()
	//Description: �ӽ� Ƽ�� ��ü�� tempTicket�� �ʱ�ȭ �Ѵ�.
	//Created: 2019/6/2
	//Author: ȫ����

	tempTicket = NULL;
}

void ReserveGeneralTicketControl::makeGeneralReservation(string gameDateTime, string awayTeam, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
	TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
{
	//Function: makeGeneralReservation(string gameDateTime, string awayTeam, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: ���ӳ�¥ �� �ð�, �������, �¼���ġ�� �����ϴ� Ƽ���� �����Ѵ�.
	//Created: 2019/6/2
	//Author: ȫ����

	// ���� ���� Ȯ��
	if (memberCollection->currentSession() == NULL) {}

	else
	{
		// ���������� Ȯ��
		if (memberCollection->currentSession()->getMemType().compare("buyer") == 0)
		{
			int ticketCount = ticketCollection->getTicketCount(); //Ƽ�� ���� Ȯ��

			bool existTicket = false; //Ƽ���� �����ϴ��� Ȯ���� ����

			for (int i = 0; i < ticketCount;  i++)
			{
				if (ticketCollection->getTicket(i)->getTicketType() == "G") {
					if ((ticketCollection->getTicket(i)->getGameDateNTime().compare(gameDateTime) == 0) &&
						(ticketCollection->getTicket(i)->getAwayTeam().compare(awayTeam) == 0) &&
						(ticketCollection->getTicket(i)->getTicketSeatNum().compare(seatNum) == 0))
					{
						if (ticketCollection->getTicket(i)->getReservable() == false)
						{
							tempTicket = ticketCollection->getTicket(i);
							existTicket = true; //���� ��¥�� �ð�, �������, �¼���ġ�� �ش��ϴ� Ƽ���� ����.
							break;
						}
					}
				}
				
			}

			// �׷� Ƽ���� ������ ���Ҹ� ����
			if (existTicket)
			{
				tempTicket->setReservable(false);

				reservationCollection->addReservation(tempTicket->getSellerId(), memberCollection->currentSession()->getId(),
					tempTicket->getTicketPrice(), t->getCurrentTime(), tempTicket->getGameDateNTime(),
					tempTicket->getHomeTeam(), tempTicket->getAwayTeam(), tempTicket->getTicketSeatNum());
			}
			else 
			{
			}
		}
	}
}

Ticket* ReserveGeneralTicketControl::getReservedTicket()
{
	//Function: getReservedTicket()
	//Description: Ƽ�� ���� �� , �������� ��ȯ�ϴ� �Լ�
	//Created: 2019/6/2
	//Author: ȫ����

	return tempTicket;
}