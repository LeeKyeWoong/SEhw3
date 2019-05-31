#pragma once

#include<iostream>
#include <string>
#include "RegisterTicketControl.h"
#include "TicketCollection.h"
#include "MemberCollection.h"

class RegisterTicketUI {
	
	// Class: RegisterTicketUI
	// Description: Ƽ�ϵ���� ���� ������ �Է¹ް� RegisterControl::registerNewTicket�Լ����� �Ѱ��ش�
	// Created: 2019/05/31
	// Author: �̰��

private:

	RegisterTicketControl *registerTicketControl;  
	TicketCollection *ticketCollection;     
	MemberCollection *memberCollection;
	
public:
	void inputRegisterNewTicket(RegisterTicketControl * registerTicketControl, TicketCollection *ticketCollection, MemberCollection * memberCollection, Timer * timer);  //�Ű������� �޾� �� Ticket���� �����ϴ� �Լ�	
};
