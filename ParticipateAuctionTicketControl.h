#pragma once
#include <iostream>
#include <string>
#include "Reservation.h"
#include "ReservationCollection.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"
using namespace std;

class ParticipateAuctionTicketControl {
	// Class: ParticipateAuctionTicketControl
	// Description: 경매참여를 위한 control class
	// Created: 2019/06/03
	// Author: 김승연

public:
	void participateAuction(string date, string awayTeam, string seatNum, int bidPrice,
		ReservationCollection *resCollect, MemberCollection *memCollect, TicketCollection *tkCollect, Timer *Tmr);
};