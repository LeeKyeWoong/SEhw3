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
	//Description: output �� ����� �ӽ� ���Ҹ� �ʱ�ȭ�Ѵ�
	//Created: 2019/05/31
	//Author: ȫ����

	tempCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp[i] = NULL;
		//�ӽ� ���� �ʱ�ȭ
	}
}


void CheckReservationInfoControl::getReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{

	//Function: getReservationInfo(CheckReservationInfoControl* _CheckReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	//Description: ������ ������ �����´�
	//Created: 2019/05/31
	//Author: ȫ����


	if(memberCollection->currentSession() == NULL)
	{ }

	else
	{
		if (memberCollection->currentSession()->getMemType().compare("guest") == 0)
		{
			//�ش� id�� ���ҿ����� Ȯ��
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
	//Description: n��° ������ ������ �����Ѵ�.
	//Created: 2019/05/31
	//Author: ȫ����


	return temp[n];
}

int CheckReservationInfoControl::getTempCount()
{

	//Function: getTempCount()
	//Description: �ӽü����� ������ �����Ѵ�
	//Created: 2019/05/31
	//Author: ȫ����


	return tempCount;
}