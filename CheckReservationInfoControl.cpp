#pragma once

#include "CheckReservationInfoUI.h"
#include "CheckReservationInfoControl.h"
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Member.h"
#include "MemberCollection"

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
		memberCollection->currentSession()->getmemType().compare("guest") == 0)
	}
}