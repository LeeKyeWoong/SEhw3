#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;


string tid; //티켓 ID
string sid; //seller의 ID
string homeTeam; //홈팀
string awayTeam; //어웨이팀 
int price; //티켓의 가격
string gameDatenTime; //게임 시작날짜와 시간
string registerTicketDate; //티켓 등록 날짜 -> 등록한지 1년이 지난 티켓 비교를 위함
//	string city; //도시 -> 없앰으로 수정
string seatNum; //티켓의 좌석
bool isSold; //팔렸는지의 여부
string ticketType; //티켓의 타입 -> 일반인지 경매인지
bool isLimitedTimeAuction; //티켓을 경매로 넘길것인지의 여부

Ticket::Ticket()
{
	this->tid = "";
	this->sid = "";
	this->homeTeam = "";
	this->awayTeam = "";
	this->price = 0;
	this->gameDatenTime = "";
	this->registerTicketDate = "";
	this->seatNum = "";
	this->isSold = false;
	this->ticketType = "";
	this->isLimitedTimeAuction = false;
}

void Ticket::addNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction)
{
	//어떻게 지정해줄것인가.
	this->tid = tid;
	this->sid = sid;	
	this->registerTicketDate = registerTicketDate;
	this->isSold = false;
	this->ticketType = ticketType;

	//아래는 실제 입력 데이터
	this->price = price;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->gameDatenTime = gameDatenTime;
	this->seatNum = seatNum;
	this->isLimitedTimeAuction = isLimitedTimeAuction;
}

//void Ticket::removeTicket()  ->필요한가
//-> 타이머에서 1년이 지난 티켓 삭제 하지만 구현은 여기서?

bool Ticket::getReservable()
{
	return isSold;
}

void Ticket::setReservable(bool isSold)
{
	
}

string Ticket::getTicketId()
{
	return this->tid;
}

string Ticket::getSellerId()
{
	return this->sid;
}

string Ticket::getHomeTeam()
{
	return this->homeTeam;
}

string Ticket::getAwayTeam()
{
	return this->awayTeam;
}

int Ticket::getTicketPrice()
{
	return this->price;
}


string Ticket::getTicketRegisterDate()
{
	return this->registerTicketDate;
}

