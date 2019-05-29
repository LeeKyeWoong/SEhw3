#pragma once

#include <iostream>
#include <string>
using namespace std;

class Reservation {
	// Class: Reservation
	// Description: Reservation ������ ��Ÿ���� entity class
	// Created: 2019/05/29
	// Author: ��¿�

private:
	string sellerID; // Ƽ���� �Ǹ��� Member�� ID
	string buyerID; // Ƽ�� ������ �� Member�� ID
	int reservePrice; // Ƽ���� ������ ����
	string reserveDate; // Ƽ���� ������ ��¥              ������ �� �ð��̶� �����ؾ� �ϳ�??????????????
	string gameDate; // ��� ��¥
	string homeTeam; // Ȩ��
	string awayTeam; // �������
	int seatNumber; // �¼� ��ȣ

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
