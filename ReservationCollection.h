#pragma once

#include <iostream>
#include <string>
#include "Reservation.h"

#define MAX 50

class Reservation;

class ReservationCollection {
	// Class: ReservationCollection
	// Description: Reservation ��ü���� ������ �� �ִ� �ݷ��� Ŭ����
	// Created: 2019/05/29
	// Author: ��¿�

private:
	Reservation *reservation[MAX];
	int reservationCount;

public:
	ReservationCollection();
	void addReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat);
	int getReservationCount();
	Reservation getReservationInfo(int reservationCount);
};