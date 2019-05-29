#include "ReservationCollection.h"

ReservationCollection::ReservationCollection() {
	// Function: ReservationCollection()
	// Description: ReservationCollection의 기본 생성자이다. arraySize만큼 Reservation을 담는 배열을 동적생성하고, reservationCount를 0으로 초기화한다.
	// Created: 2019/05/29
	// Author: 김승연

	reservationCount = 0;
}

void ReservationCollection::addReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat) {
	reservation[reservationCount]->makeNewReservation(sID, bID, price, date, homeTeam, awayTeam, seat);
	reservationCount++;
}

int ReservationCollection::getReservationCount() {

	return this->reservationCount;
}

Reservation ReservationCollection::getReservationInfo(int reservationCount) {

	return *reservation[reservationCount];
}