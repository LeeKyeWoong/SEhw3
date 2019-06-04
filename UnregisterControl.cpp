#pragma once
#include "UnregisterUI.h"
#include "UnregisterControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

UnregisterControl::UnregisterControl()
{
	// Function: UnregisterControl()
	// Description: canUnregister�� ���� True�� �����ϴ� ������
	// Created: 2019/06/02
	// Author: �̰��

	this->canUnregister = true;
}

void UnregisterControl::requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	// Function: requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	// Description: �ش� ȸ���� �����ϴ� �Լ�
	// Created: 2019/06/02
	// Author: �̰��

	if (memberCollection->currentSession() == NULL)
	{
		cout << "> ���� �α������� ���̵� �����ϴ�." << endl << endl;
	}
	else
	{
		if (memberCollection->currentSession()->getMemType().compare("seller") == 0) // ���࿡ �Ǹ��ڶ�� ��� ���� ���Ǹ� Ƽ���� ��������, Ż�� �����ϴ�.
		{
			int TicketCount = ticketCollection->getTicketCount(); // Ƽ���� �� ���� �޾Ƽ� 
			
			for (int i = 0; i < TicketCount; i++) // Ƽ�� ����ŭ �ݺ����� ������.
			{
				if((memberCollection->currentSession()->getId().compare(ticketCollection->getTicket(i)->getSellerId()) == 0) &&
				   (ticketCollection->getTicket(i)->getIsSold() == false)) // ���Ǹ� Ƽ���� �ִ�. isSold���� False�̴�. 
				{
					this->canUnregister = false; // �Ǹ��ڰ� ȸ��Ż�� �� �� ����.
				}
			}

			if(canUnregister) // �Ǹ��ڰ� ȸ�� Ż�� �� �� �ִٸ�
			{
				this->unregisterId = memberCollection->currentSession()->getId();
				memberCollection->deleteMember(memberCollection->getCurrentSessionIndex());
			}
			else // �Ǹ��ڰ� ȸ�� Ż�� �� �� ���ٸ�.
			{
				cout << "> ��ϵ� ���Ǹ� Ƽ���� �����մϴ�." << endl << endl;
			}
		}
		else if (memberCollection->currentSession()->getmemType().compare("guest") == 0) // ���࿡ �����ڶ�� Ż�� �����ϴ�.
		{
			int reservationCount = reservationCollection->getReservationCount();
			
			for (int i = 0; i < reservationCount; i++)
			{
				if (memberCollection->currentSession()->getId().compare(reservationCollection->getReservation(i)->getGuestId()) == 0)
				{
					canUnregister = false;
				}
			}

			if (canUnregister)
			{
				unregisterId = memberCollection->currentSession()->getId();
				memberCollection->deleteMember(memberCollection->getCurrentSessionIndex());
			}
			else
			{

			}
		}
	}
}

bool UnregisterControl::getCanUnregister()
{
	// Function: getCanUnregister()
	// Description: Ż�� ���� ���θ� ��ȯ�ϴ� �Լ�
	// Created: 2019/06/02
	// Author: �̰��
	
	return this->canUnregister;
}

string UnregisterControl::getUnregisterId()
{
	// Function: getCanUnregister()
	// Description: Ż���� ID�� ��ȯ�ϴ� �Լ�
	// Created: 2019/06/02
	// Author: �̰��

	return this->unregisterId;
}