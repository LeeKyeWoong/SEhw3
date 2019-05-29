#pragma once

#include <iostream>
#include <string>
#include "Reservation.h"

#define MAX 50

class Reservation;

class ReservationCollection {
	// Class: ReservationCollection
	// Description: Reservation 객체들을 관리할 수 있는 콜렉션 클래스
	// Created: 2019/05/29
	// Author: 김승연

private:
	Reservation *reservation[MAX];
	int reservationCount;

public:
	ReservationCollection();
	void addReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat);
	int getReservationCount();
	Reservation getReservationInfo(int reservationCount);
};