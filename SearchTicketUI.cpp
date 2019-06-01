#pragma once
#include "SearchTicketUI.h"
#include "SearchTicketControl.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void SearchTicketUI::selectHomeTeam(SearchTicketControl* searchTicket, TicketCollection* ticketCollection, MemberCollection* memberCollection)
{
	string homeTeam; //È¨ÆÀ
	cin >> homeTeam;

	searchTicket->sh