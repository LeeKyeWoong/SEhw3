#pragma once

#include <iostream>
#include <string>

using namespace std;

class UnregisterControl;
class TicketCollection;
class ReservationCollection;
class MemberCollection;

class UnregisterUI
{
	//Class: UnregisterControl
	//Description: Unregister�� boudnary class
	//Created: 2019/06/02
	//Author: �̰��

private:

public:
	void callUnregister(UnregisterControl* unregisterControl, TicketCollection* ticketCollection, ReservationCollection* reservationCollection,
		MemberCollection* memberCollection);  //ȸ�� Ż�� ��û�� control�� �����ϴ� �Լ�
};

