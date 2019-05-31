#pragma once

#include "CheckReservationInfoUI.h"
#include "CheckReservationInfoControl.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

CheckReservationInfoControl::CheckReservationInfoControl()
{
	tempCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp[i] = NULL;
		//임시 숙소 초기화
	}
}


void CheckReservationInfoControl::getReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	if(memberCollection->currentSession() == NULL)
	{ }

	else
	{
		if (memberCollection->currentSession()->getMemType().compare("guest") == 0)
		{
			//해당 id의 숙소예약을 확인
			int reservationCount = reservationCollection->getReservationCount();

			if(reservationCount ==0)
			{ }

			else
			{
				for (int i = 0; i < reservationCount; i++)
				{
					if (reservationCollection->getReservation(i)->getBuyerID().compare(memberCollection->currentSession()->getId()) == 0)
					{
						temp[tempCount++] = reservationCollection->getReservation(i);
					}
				}
			}
		}
	}
}

Reservation* CheckReservationInfoControl::getReservationInfo(int n)
{
	return temp[n];
}

int CheckReservationInfoControl::getTempCount()
{
	return tempCount;
}