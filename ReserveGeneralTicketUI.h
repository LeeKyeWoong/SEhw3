#pragma once

#include <iostream>
#include <string>

using namespace std;

class ReservationCollection;
class TicketCollection;
class MemberCollection;
class ReserveGeneralTicketControl;

class ReserveGeneralTicketUI
{
	//Class: ReserveGeneralTicketUI
	//Description: ReserveGeneralTicket�� boundary class
	//Created: 2019/6/2
	//Author: ȫ����


private:


public:
	void reserveGeneralTicket(ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
		TicketCollection* ticketCollection, MemberCollection* memberCollection); //��¥�ð�, �������, �¼���ġ�� �Է��ؼ� Ƽ�� ����

};