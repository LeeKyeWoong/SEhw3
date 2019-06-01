#pragma once

#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class SearchAuctionTicketUI;
class TicketCollection;
class MemberCollection;
class Ticket;


class SearchAuctionTicketControl
{
	//Class: SearchAuctionTicketControl
	//Description: SearchAuctionTicket�� control class
	//Created: 2019/6/2
	//Author: ȫ����


private:
	Ticket *temp[MAX];
	//�˻��� ��� ���� Ƽ�ϵ��� ��⳯¥ �� �ð��� ���� Ƽ�Ϻ��� �����ؼ� �����ֱ� ���� �ӽð�ü
	int tempCount;

public:
	SearchAuctionTicketControl();
	void showBuyerWantAuctionTicket(string homeTeam, TicketCollection* ticketCollection, MemberCollection* memberCollection);
	//�����ڰ� ���ϴ� ������� Ƽ�� ����� ���ĵ� ���·� �����ִ� �Լ�
	Ticket* getSortedList(int ticketCount);
	//��⳯¥ �� �ð��� ���� Ƽ������ ���ĵ� ����Ʈ�� ��ȯ�ϴ� �Լ�
	int getTempCount();

};