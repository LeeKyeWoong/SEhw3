#pragma once
#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void SearchAuctionTicketUI::selectHomeTeam(SearchAuctionTicketControl* searchAuctionTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	//Function: selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: �����ڰ� Ȩ���� �����ϴ� UI�� �����ϰ� �� Ȩ���� ���� ��� ���� Ƽ���� �����ش�.
	//Created: 2019/6/2
	//Author: ȫ����

	string homeTeam; //Ȩ��
	cin >> homeTeam;

	searchAuctionTicket->showBuyerWantAuctionTicket(homeTeam, ticketCollection, memberCollection);

	int ticketCount = searchAuctionTicket->getTempCount(); //�ӽ� Ƽ�� ������ ���� 

	if (ticketCount == 0)//������ ���Ұ� ���ٸ�
	{
		cout << "4.3. ��� ���� Ƽ�� �˻�" << endl;
		cout << ">" << endl;
	}

	else
	{
		cout << "4.3. ��� ���� Ƽ�� �˻�" << endl;
		for (int i = 0; i < ticketCount; i++)
		{
			cout << searchAuctionTicket->getSortedList(i)->getGameDateNTime() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getHomeTeam() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getAwayTeam() << " ";
			cout << searchAuctionTicket->getSortedList(i)->getTicketSeatNum() << " ";
			//�������� ���� �ð� ���
			cout  << endl;
		}
	}
}