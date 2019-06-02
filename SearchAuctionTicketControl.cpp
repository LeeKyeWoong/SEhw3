#pragma once

#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"
#include "Timer.h"
#include <string.h>

using namespace std;

SearchAuctionTicketControl::SearchAuctionTicketControl()
{
	//Function: SearchAuctionTicketControl()
	//Description: 경매 티켓검색 컨트롤 생성자, 출력문에 출력할 임시 객체를 초기화한다.
	//Created: 2019/6/2
	//Author: 홍지은

	tempCount = 0;
	for (int i = 0; i < MAX; i++)
		temp[i] = NULL;
}

void SearchAuctionTicketControl::showBuyerWantAuctionTicket(string homeTeam, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t)
{
	//Function: showBuyerWantAuctionTicket(string homeTeam, SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
	//Description: 구매자가 원하는 경매 중인 티켓을 날짜 및 시간 순서가 빠른 순대로 보여준다.
	//Created: 2019/6/2
	//Author: 홍지은

	if (memberCollection->currentSession() == NULL)
	{
	}

	else
	{
		if (memberCollection->currentSession()->getMemType().compare("buyer") == 0 ) //티켓이 경매티켓인지 여부와 현재 시간과 경매시간 비교 24시간 전인것만 검색가능)
		{
			int ticketCount = ticketCollection->getTicketCount();
			//구매자가 선택한 홈팀에 대한 예약가능한 티켓 목록 임시 저장
			for (int i = 0; i < ticketCount; i++)
			{
				if (ticketCollection->getTicket(i)->getIsLimitedTimeAuction() == true) //경매 티켓이고
				{
					string currentTime, gameTime;
					currentTime = t->getCurrentTime();
					gameTime = ticketCollection->getTicket(i)->getGameDateNTime();
					string temp_crt, temp_gt;

					temp_crt.append.append(currentTime, 0, 4).append(currentTime, 5, 2).append(currentTime, 8, 2).append(currentTime, 11, 2).append(currentTime, 14, 2);
					temp_gt.append.append(gameTime, 0, 4).append(gameTime, 5, 2).append(gameTime, 8, 2).append(gameTime, 11, 2).append(gameTime, 14, 2);
					
					long long cT = stoll(temp_crt);
					long long gT = stoll(temp_gt);
					if (gT - cT >= 600 && gT - cT <= 10000) //경매 들어간 시간
					{
						if ((ticketCollection->getTicket(i)->getHomeTeam().compare(homeTeam) == 0))
						{
							if (ticketCollection->getTicket(i)->getReservable() == true)
							{
								temp[tempCount++] = ticketCollection->getTicket(i);
							}
						}
					}
				}
			}

			//날짜및 시간이 빠른순서대로 정렬
			for (int i = 0; i < tempCount - 1; i++)
			{
				for (int j = 0; j < tempCount - 1 - i; j++)

				{
					if (strcmp(temp[j]->getGameDateNTime().c_str(), temp[j + 1]->getGameDateNTime().c_str()) > 0)
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

Ticket* SearchAuctionTicketControl::getSortedList(int ticketCount)
{
	//Function: getSortedList(int ticketCount)
	//Description: 정렬된 리스트를 반환한다.
	//Created: 2019/6/1
	//Author: 홍지은

	return temp[ticketCount];
}

int SearchAuctionTicketControl::getTempCount()
{
	//Function: getTempCount()
	//Description: 임시로 저장된 경매 중인 티켓의 수를 반환한다.
	//Created: 2019/6/1
	//Author: 홍지은

	return tempCount;
}