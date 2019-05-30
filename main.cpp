#pragma once
#include "main.h"
#define MAX 50
using namespace std;


int main()
{
	// Function: Main()
	// Description: 티켓 예약 프로그램 main함수
	// Created: 2019/05/29
	// Author: 이계웅
	// Revsions : 
	// 1. When & Who : 20--/--/-- by ___
	//    What : switch 및 case문의 interface 함수 생성 

	Member member[MAX];             // 멤버 객체 생성 
	Timer timer;					// 타이머 객체 생성 
	Reservation reservation[MAX];	// 예약 객체 생성
	Ticket ticket[MAX];				// 티켓 객체 생성

	ReservationCollection reservationCollection(reservation);  // 예약 생성
	TicketCollection ticketCollection(ticket);                 // 티켓 생성
	MemberCollection memberCollection(member);				   // 멤버 생성

	freopen("input.txt", "r", stdin);   // scanf시에 input.txt에서 read한다.
	freopen("output.txt", "w", stdout); // printf시에 output.txt에서 write한다.

	while (1)
	{
		// 두 개의 메뉴를 위한 변수 
		int menu_1 = 0;
		int menu_2 = 0;

		// 입력파일에서 메뉴 숫자 2개를 읽기
		cin >> menu_1 >> menu_2;

		// 메뉴 구분 및 해당 연산 수행
		switch(menu_1)
		{
			case 1: 
			{
				switch(menu_2)
				{
					case 1: {	// 1.1. 회원가입 
						signupInterface(&memberCollection);
						break;
					}
					case 2: {	// 1.2. 회원탈퇴 
						//unregisterInterface(&TicketCollection, &reservationCollection, &MemberCollection);
						break;
					}
				}
				break;
			}
			case 2:
			{
				switch(menu_2)
				{
					case 1: {	// 2.1. 로그인
						//loginInterface(&MemberCollection);
						break;
					}
					case 2: {	// 2.2. 로그아웃
						//logoutInterface(&MemberCollection);
						break;
					}
				}
				break;
			}
			case 3: 
			{
				switch(menu_2) 
				{
					case 1: {   // 3.1. 판매티켓 등록
						//registerTicketInterface(&TicketCollection, &MemberCollection,&timer);
						break;
					}
					case 2: {   // 3.2. 등록티켓 조회
						//checkTicketInterface(&TicketCollection, &MemberCollection);
						break;
					}
				}
				break;
			}
			case 4: 
			{
				switch(menu_2) 
				{
					case 1: {   // 4.1. 티켓 검색
						//searchTicketInterface(&TicketCollection, &MemberCollection);
						break;
					}
					case 2: {   // 4.2. 티켓 예약
						//reserveGeneralReservationInterface(&reservationCollection, &TicketCollection, &MemberCollection);
						break;
					}
					case 3: {   // 4.3. 경매 중인 티켓 검색
						//reserveOpaqueReservationInterface(&reservationCollection, &TicketCollection, &MemberCollection, &timer);
						break;
					}
					case 4: {   // 4.4. 경매 참여
						//checkReservationInterface(&reservationCollection, &MemberCollection);
						break;
					}
					case 5: {   // 4.5. 예약 정보 조회
						//checkReservationInterface(&reservationCollection, &MemberCollection);
						break;
					}
				}
				break;
			}
			case 5:
			{
				switch(menu_2) 
				{
					case 1: {	 // 5.1. 현재시간 설정
						//setCurrentTimeInterface(&timer, &TicketCollection, &MemberCollection);
						break;
					}
				}	
				break;
			}
			case 6: 
			{
				switch(menu_2) 
				{
					case 1: {	 // 6.1. session 변경
						//changeSession(&MemberCollection);
						break;
					}
					case 2: {	// 6.2. guest session으로 변경
						//guestSession(&MemberCollection);
						break;
					}
				}
				break;
			}
			case 7: {
				switch(menu_2) 
				{
					case 1: {   // 7.1. 종료
						//programExit();	//programExit() 함수에서 해당 기능 수행
						break;
					}
				}
				break;
			}
		}
		cout << endl;
	}
	return 0;
}

void signupInterface(MemberCollection* memberCollection)  // 1.1 회원가입 인터페이스
{
	SignUpUI userInterface;
	SignUpControl control;
	userInterface.inputInfo(&control, memberCollection);
}
/*
void unregisterInterface(TicketCollection* TicketCollection, ReservationCollection* reservationCollection, MemberCollection* MemberCollection) //1.2 회원탈퇴 인터페이스
{
	UnregisterUI userInterface;
	UnregisterControl control;
	userInterface.callUnregister(&control, TicketCollection, reservationCollection, MemberCollection);
}

void loginInterface(MemberCollection* MemberCollection) //2.1 로그인 인터페이스
{
	LoginUI userInterface;
	LoginControl control;
	userInterface.inputLoginInfo(&control, MemberCollection);
}

void logoutInterface(MemberCollection* MemberCollection) //2.2 로그아웃 인터페이스
{
	LogoutUI userInterface;
	LogoutControl control;
	userInterface.callLogout(&control, MemberCollection);
}

void registerTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer * timer) // 3.1 판매티켓 등록 인터페이스
{
	RegisterTicketUI userInterface;
	RegisterTicketControl control;
	userInterface.inputRegisterNewTicket(&control, TicketCollection, MemberCollection, timer);
}

void checkTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection) // 3.2. 등록티켓 조회 인터페이스
{
	CheckTicketUI userInterface;
	CheckTicketControl control;
	control.getHostTicket(&userInterface, TicketCollection, MemberCollection);

void searchGeneralTickeInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection)  // 4.1. 티켓 검색 인터페이스
{
	SearchTicketUI userInterface;
	SearchTicketControl control;
	userInterface.selectCityAndDate(&control, TicketCollection, MemberCollection);
}

void reserveGeneralTicketInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection) // 4.2. 티켓 예약 인터페이스
{
	ReserveGeneralTicketUI userInterface;
	ReserveGeneralTicketControl control;
	userInterface.reserveGeneralTicket(&control, reservationCollection, TicketCollection, MemberCollection);
}

void searchAuctionTicketInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer* timer) // 4.3. 경매 중인 티켓 검색 인터페이스 
{
	ReserveOpaqueInventoryUI userInterface;
	ReserveOpaqueInventoryControl control;
	userInterface.reserveOpaqueInventory(&control, reservationCollection, TicketCollection, MemberCollection, timer);
}

void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection)  // 4.4. 예약 정보 조회
{
	CheckReservationInformationUI userInterface;
	CheckReservationInformationControl control;
	userInterface.showReservationInformation(&control, reservationCollection, MemberCollection);
}

void participateAuctionTicketInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection) // 4.5. 경매 참여 인터페이스
{
	CheckReservationInformationUI userInterface;
	CheckReservationInformationControl control;
	userInterface.showReservationInformation(&control, reservationCollection, MemberCollection);
}

void setCurrentTimeInterface(Timer* timer, TicketCollection * TicketCollection, MemberCollection* MemberCollection) // 5.1 현재시간설정 인터페이스
{
	SetCurrentTimeUI userInterface;
	SetCurrentTimeControl control;
	userInterface.startInterface(&control, timer, MemberCollection, TicketCollection);
}

void changeSession(MemberCollection* p_membercollection) // 6.1 Session변경
{
	// Function : changeSession(MemberCollection* p_membercollection)
	// Description: 입력받은 ID로 Session Change를 시도하는 함수
	// Created: 2018/5/27
	// Author: 김정걸
	string ID;
	cin >> ID;
	bool sameID = false;
	int membercount = p_membercollection->getMemberCount();

	// 해당 기능 수행
	for (int i = 0; i < membercount; i++)
	{
		if (p_membercollection->getMember(i)->getID().compare(ID) == 0)
		{
			sameID = true;
			break;
		}
	}

	if (sameID)
	{
		for (int i = 0; i < membercount; i++)
		{
			if (p_membercollection->getMember(i)->getID().compare(ID) == 0)
			{
				p_membercollection->getMember(i)->setsessionOn(true);
			}
			else
			{
				p_membercollection->getMember(i)->setsessionOn(false);
			}
		}
		cout << "6.1 Session 변경" << endl;
		cout << ">" << ID << endl;
	}

}

void guestSession(MemberCollection* p_MemberCollection)  // 6.2. guest session으로 변경
{
	// Function :guestSession(MemberCollection* membercollection)
	// Description: 프로그램의 memType을 guest로 수정
	// Created: 2018/5/27
	// Author: 김정걸

	// 해당 기능 수행

	if (p_MemberCollection->currentSession() == NULL)
	{
		cout << "6.2 Guest Session으로 변경" << endl;
	}
	else
	{
		p_MemberCollection->currentSession()->setsessionOn(false);
		cout << "6.2 Guest Session으로 변경" << endl;
	}

}

void exitProgram() {  // 7.1 종료 인터페이스

	// Function :programExit()
	// Description: 프로그램 종료
	// Created: 2018/05/25
	// Author: 성경환

	printf("7.1 종료\n");
	exit(0);
}
*/