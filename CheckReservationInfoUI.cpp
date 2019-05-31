#pragma once

#include "CheckReservationInfoUI.h"
#include "CheckReservationInfoControl.h"
#include "Reservation.h"
#include "reservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void CheckReservationInfoUI::showReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	//Function: showReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	//Description: 회원의 예약정보를 보여줌
	//Created: 2019/05/31
	//Author: 홍지은


	_CheckReservationInfo->getReservationInfo(_CheckReservationInfo, reservationCollection, memberCollection);

	int reservationCount = _CheckReservationInfo->getTempCount();

	if (reservationCount == 0)
	{
		cout << "4.5. 예약정보 조회" << endl;
		cout << ">" << endl;
	}

	else
	{
		cout << "4.5.예약정보조회" << endl;
		for (int i = 0; i < reservationCount << i++)
		{
			cout << ">" << _CheckReservationInfo->getReservationInfo(i)->getReservePrice() << " ";
			cout << _CheckReservationInfo->getReservationInfo(i)->//여기에 날짜시간 들어가야함!!
			cout << _CheckReservationInfo->getReservationInfo(i)->getHomeTeam() << " ";
			cout << _CheckReservationInfo->getReservationInfo(i)->getAwayTeam() << " ";
			cout << _CheckReservationInfo->getReservationInfo(i)->getSeatNumber() << endl;
		}
	}
}