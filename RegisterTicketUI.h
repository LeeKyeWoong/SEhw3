#pragma once

#include<iostream>
#include <string>
#include "RegisterTicketControl.h"
#include "TicketCollection.h"
#include "MemberCollection.h"

class RegisterTicketUI {
	
	// Class: RegisterTicketUI
	// Description: 티켓등록을 위한 정보를 입력받고 RegisterControl::registerNewTicket함수에게 넘겨준다
	// Created: 2019/05/31
	// Author: 이계웅

private:

	RegisterTicketControl *registerTicketControl;  
	TicketCollection *ticketCollection;     
	MemberCollection *memberCollection;
	
public:
	void inputRegisterNewTicket(RegisterTicketControl * registerTicketControl, TicketCollection *ticketCollection, MemberCollection * memberCollection, Timer * timer);  //매개변수를 받아 새 Ticket으로 저장하는 함수	
};
