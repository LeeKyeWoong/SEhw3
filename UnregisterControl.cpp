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
	// Description: canUnregister의 값을 True로 설정하는 생성자
	// Created: 2019/06/02
	// Author: 이계웅

	this->canUnregister = true;
}

void UnregisterControl::requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	// Function: requestUnregister(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	// Description: 해당 회원을 삭제하는 함수
	// Created: 2019/06/02
	// Author: 이계웅

	if (memberCollection->currentSession() == NULL)
	{
		cout << "> 현재 로그인중인 아이디가 없습니다." << endl << endl;
	}
	else
	{
		if (memberCollection->currentSession()->getMemType().compare("seller") == 0) // 만약에 판매자라면 등록 중인 미판매 티켓이 없을때만, 탈퇴가 가능하다.
		{
			int TicketCount = ticketCollection->getTicketCount(); // 티켓의 총 수를 받아서 
			
			for (int i = 0; i < TicketCount; i++) // 티켓 수만큼 반복문을 돌린다.
			{
				if((memberCollection->currentSession()->getId().compare(ticketCollection->getTicket(i)->getSellerId()) == 0) &&
				   (ticketCollection->getTicket(i)->getIsSold() == false)) // 미판매 티켓이 있다. isSold값이 False이다. 
				{
					this->canUnregister = false; // 판매자가 회원탈퇴를 할 수 없다.
				}
			}

			if(canUnregister) // 판매자가 회원 탈퇴를 할 수 있다면
			{
				this->unregisterId = memberCollection->currentSession()->getId();
				memberCollection->deleteMember(memberCollection->getCurrentSessionIndex());
			}
			else // 판매자가 회원 탈퇴를 할 수 없다면.
			{
				cout << "> 등록된 미판매 티켓이 존재합니다." << endl << endl;
			}
		}
		else if (memberCollection->currentSession()->getmemType().compare("guest") == 0) // 만약에 구매자라면 탈퇴가 가능하다.
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
	// Description: 탈퇴 가능 여부를 반환하는 함수
	// Created: 2019/06/02
	// Author: 이계웅
	
	return this->canUnregister;
}

string UnregisterControl::getUnregisterId()
{
	// Function: getCanUnregister()
	// Description: 탈퇴한 ID를 반환하는 함수
	// Created: 2019/06/02
	// Author: 이계웅

	return this->unregisterId;
}