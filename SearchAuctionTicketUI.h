#pragma once
#pragma once

#include <iostream>
#include <string>
using namespace std;

class TicketCollection;
class SearchTicketControl;
class MemberCollection;

class SearchAuctionTicketUI
{
	//Class: SearchAuctionTicket
	//Description: SearchAuctionTicket �� boundary class
	//Created: 2019/6/2
	//Author: ȫ����

private:

public:
	void selectHomeTeam(SearchAuctionTicketControl* searchAuctionTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection);
	//Ȩ���� �����Ͽ� ���డ���� Ƽ���� ��ȸ�Ѵ�. (4.1.)
};