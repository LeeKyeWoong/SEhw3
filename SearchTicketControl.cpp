#pragma once

#include "SearchTicketUI.h"
#include "SearchTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"

using namespace std;

SearchTicketControl::SearchTicketControl()
{
	//Function: SearchTicketControl()
	//Description: Ƽ����ȸ ��Ʈ�� ������, ��¹��� ����� �ӽ� ��ü�� �ʱ�ȭ�Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����

	tempCount = 0;
	for (int i = 0; i < MAX; i++)
		temp[i] = NULL;
}

void SearchTicketControl::showBuyerWantTicket(string homeTeam, SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	//Function: showBuyerWantTicket(string homeTeam, SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: �����ڰ� ���ϴ� Ƽ���� ��¥ �� �ð� ������ ���� ����� �����ش�.
	//Created: 2019/6/1
	//Author: ȫ����

	if (memberCollection->currentSession() == NULL)
	{ }

	else
	{
		if (memberCollection->currentSession()->getMemType().compare("guest") == 0)
		{
			int ticketCount = ticketCollection->getTicketCount();
			//�����ڰ� ������ Ȩ���� ���� ���డ���� Ƽ�� ��� �ӽ� ����
			for (int i = 0; i < ticketCount; i++)
			{
				if ((ticketCollection->getTicket(i)->getHomeTeam().compare(homeTeam) == 0))
				{
					if (ticketCollection->getTicket(i)->getReservable() == 0)
					{
						temp[tempCount++] = ticketCollection->getTicket(i);
					}
				}
			}

			
			//��¥ �� �ð������� ����
			for (int i = 0; i < tempCount - 1; i++)
			{
				for (int j = 0; j < tempCount - 1 - i; j++)
				{
					if (atoi((temp[j]->getGameDateNTime()).substr(0, 4).c_str()) > atoi((temp[j+1]->getGameDateNTime()).substr(0, 4).c_str())) //year ��
					{
						Ticket* tempTicket = temp[j];
						temp[j] = temp[j + 1];
						temp[j + 1] = tempTicket;
					}

					else //���� year�� ���ٸ�
					{
						if (atoi((temp[j]->getGameDateNTime()).substr(5, 2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(5, 2).c_str())) //month��
						{
							Ticket* tempTicket = temp[j];
							temp[j] = temp[j + 1];
							temp[j + 1] = tempTicket;
						}

						else //���� month�� ���ٸ�
						{
							if (atoi((temp[j]->getGameDateNTime()).substr(8, 2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(8,2).c_str()))
							{
								Ticket* tempTicket = temp[j];
								temp[j] = temp[j + 1];
								temp[j + 1] = tempTicket;
							}

							else //���� day ���ٸ�
							{
								if (atoi((temp[j]->getGameDateNTime()).substr(11,2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(11,2).c_str())) // hour ��
								{
									Ticket* tempTicket = temp[j];
									temp[j] = temp[j + 1];
									temp[j + 1] = tempTicket;
								}

								else //���� �ð��� ���ٸ�
								{
									if (atoi((temp[j]->getGameDateNTime()).substr(14,2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(14,2).c_str()))//minute��
									{
										Ticket* tempTicket = temp[j];
										temp[j] = temp[j + 1];
										temp[j + 1] = tempTicket;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

Ticket* SearchTicketControl::getSortedList(int ticketCount)
{
	//Function: getSortedList(int ticketCount)
	//Description: ���ĵ� ����Ʈ�� ��ȯ�Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����

	return temp[ticketCount];
}

int SearchTicketControl::getTempCount()
{
	//Function: getTempCount()
	//Description: �ӽ÷� ����� Ƽ���� ���� ��ȯ�Ѵ�.
	//Created: 2019/6/1
	//Author: ȫ����

	return tempCount;
}