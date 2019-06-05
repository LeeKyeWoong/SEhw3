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
	// Description: °æ¸ÅÂü¿©¸¦ À§ÇÑ boundary class
<<<<<<< HEAD
	// Created: 2019/06/30
	// Author: ±è½Â¿¬

=======
	// Created: 2019/06/03
	// Author: ±è½Â¿¬
>>>>>>> 63ab847e92eb84fa0ca4f1b169f7bb417bcd8ee6
public:
	void participateAuctionInterface(ParticipateAuctionTicketControl *ctl, 
		ReservationCollection *resCollect, MemberCollection *memCollect, TicketCollection *tkCollect, Timer *timer);
};