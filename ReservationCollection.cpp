#include "ReservationCollection.h"

ReservationCollection::ReservationCollection() {
	// Function: ReservationCollection()
	// Description: ReservationCollection�� �⺻ �������̴�. arraySize��ŭ Reservation�� ��� �迭�� ���������ϰ�, reservationCount�� 0���� �ʱ�ȭ�Ѵ�.
	// Created: 2019/05/29
	// Author: ��¿�

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