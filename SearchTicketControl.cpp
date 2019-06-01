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
	//Description: 티켓조회 컨트롤 생성자, 출력문에 출력할 임시 객체를 초기화한다.
	//Created: 2019/6/1
	//Author: 홍지은

	tempCount = 0;
	for (int i = 0; i < MAX; i++)
		temp[i] = NULL;
}

void SearchTicketControl::showBuyerWantTicket(string homeTeam, SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	//Function: showBuyerWantTicket(string homeTeam, SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: 구매자가 원하는 티켓을 날짜 및 시간 순서가 빠른 순대로 보여준다.
	//Created: 2019/6/1
	//Author: 홍지은

	if (memberCollection->currentSession() == NULL)
	{ }

	else
	{
		if (memberCollection->currentSession()->getMemType().compare("guest") == 0)
		{
			int ticketCount = ticketCollection->getTicketCount();
			//구매자가 선택한 홈팀에 대한 예약가능한 티켓 목록 임시 저장
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

			
			//날짜 및 시간순으로 정렬
			for (int i = 0; i < tempCount - 1; i++)
			{
				for (int j = 0; j < tempCount - 1 - i; j++)
				{
					if (atoi((temp[j]->getGameDateNTime()).substr(0, 4).c_str()) > atoi((temp[j+1]->getGameDateNTime()).substr(0, 4).c_str())) //year 비교
					{
						Ticket* tempTicket = temp[j];
						temp[j] = temp[j + 1];
						temp[j + 1] = tempTicket;
					}

					else //만일 year가 같다면
					{
						if (atoi((temp[j]->getGameDateNTime()).substr(5, 2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(5, 2).c_str())) //month비교
						{
							Ticket* tempTicket = temp[j];
							temp[j] = temp[j + 1];
							temp[j + 1] = tempTicket;
						}

						else //만일 month가 같다면
						{
							if (atoi((temp[j]->getGameDateNTime()).substr(8, 2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(8,2).c_str()))
							{
								Ticket* tempTicket = temp[j];
								temp[j] = temp[j + 1];
								temp[j + 1] = tempTicket;
							}

							else //만일 day 같다면
							{
								if (atoi((temp[j]->getGameDateNTime()).substr(11,2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(11,2).c_str())) // hour 비교
								{
									Ticket* tempTicket = temp[j];
									temp[j] = temp[j + 1];
									temp[j + 1] = tempTicket;
								}

								else //만일 시간이 같다면
								{
									if (atoi((temp[j]->getGameDateNTime()).substr(14,2).c_str()) > atoi((temp[j + 1]->getGameDateNTime()).substr(14,2).c_str()))//minute비교
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
	//Description: 정렬된 리스트를 반환한다.
	//Created: 2019/6/1
	//Author: 홍지은

	return temp[ticketCount];
}

int SearchTicketControl::getTempCount()
{
	//Function: getTempCount()
	//Description: 임시로 저장된 티켓의 수를 반환한다.
	//Created: 2019/6/1
	//Author: 홍지은

	return tempCount;
}