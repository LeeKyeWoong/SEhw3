#pragma once

#include <iostream>
#include <string>
#include "ParticipateAuctionTicketControl.h"

using namespace std;

class ParticipateAuctionTicketControl;
class ReservationCollection;
class MemberCollection;
class TicketCollection;

class ParticipateAuctionTicketUI {
	// Class: ParticipateAuctionTicketUI
	// Description: 경매참여를 위한 boundary class
	// Created: 2019/06/03
	// Author: 김승연
public:
	void participateAuctionInterface(ParticipateAuctionTicketControl *ctl, 
		ReservationCollection *resCollect, MemberCollection *memCollect, TicketCollection *tkCollect, Timer *timer);
};