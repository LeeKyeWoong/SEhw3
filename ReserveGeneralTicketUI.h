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
	//Description: ReserveGeneralTicket의 boundary class
	//Created: 2019/6/2
	//Author: 홍지은


private:


public:
	void reserveGeneralTicket(ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
		TicketCollection* ticketCollection, MemberCollection* memberCollection); //날짜시간, 어웨이팀, 좌석위치를 입력해서 티켓 예약

};