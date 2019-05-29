#include "Reservation.h"

Reservation::Reservation() {

}

void Reservation::makeNewReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat) {
	this->sellerID = sID;
	this->buyerID = bID;
	this->reservePrice = price;
	this->reserveDate;
	this->gameDate = date;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->seatNumber = seat;
}

void Reservation::changeAuctionBuyer(string bID, int price, string date) {
	//

	this->buyerID = bID;
	this->reservePrice = price;
	this->reserveDate = ;
}

string Reservation::getSellerID() {

	return this->sellerID;
}

string Reservation::getBuyerID() {

	return this->buyerID;
}

int Reservation::getReservePrice() {

	return this->reservePrice;
}

string Reservation::getReserveDate() {

	return this->reserveDate;
}

string Reservation::getHomeTeam() {

	return this->homeTeam;
}

string Reservation::getAwayTeam() {
	
	return this->awayTeam;
}

int Reservation::getSeatNumber() {

	return this->seatNumber;
}