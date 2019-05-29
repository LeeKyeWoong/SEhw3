#pragma once

#include <iostream>
#include <string>
using namespace std;

class Reservation {
	// Class: Reservation
	// Description: Reservation 정보를 나타내는 entity class
	// Created: 2019/05/29
	// Author: 김승연

private:
	string sellerID; // 티켓을 판매한 Member의 ID
	string buyerID; // 티켓 예약을 한 Member의 ID
	int reservePrice; // 티켓을 구매한 가격
	string reserveDate; // 티켓을 예약한 날짜              입찰을 한 시간이랑 구분해야 하나??????????????
	string gameDate; // 경기 날짜
	string homeTeam; // 홈팀
	string awayTeam; // 어웨이팀
	int seatNumber; // 좌석 번호

public:
	Reservation();
	void makeNewReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat);
	void changeAuctionBuyer(string bID, int price, string date);
	string getSellerID();
	string getBuyerID();
	int getReservePrice();
	string getReserveDate();
	string getHomeTeam();
	string getAwayTeam();
	int getSeatNumber();
};
