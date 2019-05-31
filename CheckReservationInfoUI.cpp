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
	//Description: ȸ���� ���������� ������
	//Created: 2019/05/31
	//Author: ȫ����


	_CheckReservationInfo->getReservationInfo(_CheckReservationInfo, reservationCollection, memberCollection);

	int reservationCount = _CheckReservationInfo->getTempCount();

	if (reservationCount == 0)
	{
		cout << "4.5. �������� ��ȸ" << endl;
		cout << ">" << endl;
	}

	else
	{
		cout << "4.5.����������ȸ" << endl;
		for (int i = 0; i < reservationCount << i++)
		{
			cout << ">" << _CheckReservationInfo->getReservationInfo(i)->getReservePrice() << " ";
			cout << _CheckReservationInfo->getReservationInfo(i)->//���⿡ ��¥�ð� ������!!
			cout << _CheckReservationInfo->getReservationInfo(i)->getHomeTeam() << " ";
			cout << _CheckReservationInfo->getReservationInfo(i)->getAwayTeam() << " ";
			cout << _CheckReservationInfo->getReservationInfo(i)->getSeatNumber() << endl;
		}
	}
}