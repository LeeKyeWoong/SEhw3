#pragma once

#include "CheckReservationInfoUI.h"
#include "CheckReservationInfoControl.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

CheckReservationInfoControl::CheckReservationInfoControl()
{
	//Function: CheckReservationInfoControl()
	//Description: output 에 출력할 임시 숙소를 초기화한다
	//Created: 2019/05/31
	//Author: 홍지은

	tempCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp[i] = NULL;
		//임시 숙소 초기화
	}
}


void CheckReservationInfoControl::getReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{

	//Function: getReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	//Description: 예약한 정보를 가져온다
	//Created: 2019/05/31
	//Author: 홍지은


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

	//Function: getReservationInfo(int n) 
	//Description: n번째 숙소의 정보를 리턴한다.
	//Created: 2019/05/31
	//Author: 홍지은


	return temp[n];
}

int CheckReservationInfoControl::getTempCount()
{

	//Function: getTempCount()
	//Description: 임시숙소의 개수를 리턴한다
	//Created: 2019/05/31
	//Author: 홍지은


	return tempCount;
}