#pragma once
#include <string>

using namespace std;


class Ticket {
	//Class : Ticket
	//Description : Ticket의 정보를 나타내는 entity class
	//Created : 2019/05/28
	//Author : 홍지은
	

private:
	string tid; //티켓 ID
	string sid; //seller의 ID
	string homeTeam; //홈팀
	string awayTeam; //어웨이팀 
	int price; //티켓의 가격
	string gameDatenTime; //게임 시작날짜와 시간
	string registerTicketDate; //티켓 등록 날짜 -> 등록한지 1년이 지난 티켓 비교를 위함
	string seatNum; //티켓의 좌석
	bool isSold; //팔렸는지의 여부
	string ticketType; //티켓의 타입 -> 일반인지 경매인지
	bool isLimitedTimeAuction; //티켓을 경매로 넘길것인지의 여부



public:
	Ticket(); //생성자
	void addNewTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction ); //티켓 생성
	//날짜 시간 예시 : 2019:05:22:12:00
	//void removeTicket();

	bool getReservable(); //티켓이 예약되었는지의 여부 확인
	void setReservable(bool isSold);
	string getSellerId(); //판매자의 아이디 가져오기
	string getTicketId(); //티켓 아이디 가져오기 -> 티켓에 부여된 예약번호라 칭한다.
	string getHomeTeam(); //홈팀 가져오기
	string getAwayTeam();
	int getTicketPrice();
	//int getAuctionTicketPrice(); ->굳이 필요한가... 왜냐하면 경매티켓은 항상 반값부터 시작하기 때문이다.
	string getTicketRegisterDate();


};