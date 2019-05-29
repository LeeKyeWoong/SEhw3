#pragma once
#include "main.h"
#define MAX 50
using namespace std;


int main()
{
	//Function: Main()
	//Description: 숙소 예약 프로그램의 main역할을 하는 함수
	//Created: 2018/05/25
	//Author: 김정걸
	// Revsions : 
	//   1. When & Who : 2018/05/26 by 김정걸
	//      What : switch 및 case문의 interface 함수 생성 
	//   2. When & Who : 2018/05/26 by 김정걸
	//      What : Reservation 기능 관련 함수 입력 및 test
	//   3. When & Who : 2018/05/27 by 김정걸
	//      What : Accommodation 기능 관련 함수 입력 및 test
	//   4. When & Who : 2018/05/27 by 성경환
	//      What : Accommodation 버그 수정, 새로 정의 된 함수 및 클래스 반영
	//   5. When & Who : 2018/05/28 by 김정걸
	//      What : Meber 기능 관련 함수 입력 및 test
	//   6. When & Who : 2018/05/28 by 문현준
	//      What : Member 버그 수정, 새로 정의 된 함수 및 클래스 반영
	//   7. When & Who : 2018/05/28 by 박건용
	//      What : Reservation 버그 수정, 새로 정의 된 함수 및 클래스 반영, Opaque invnetory 관련 함수 재정의
	//   8. When & Who : 2018/05/28 by 김정걸
	//      What : 변경된 사항을 기반으로 case문 함수 수정 및 test
	//   9. When & Who : 2018/05/29 by 김정걸
	//      What : 자동 삭제 기능 수정 및 가시성을 위해 통일되지 않은 입력 변수명 수정 및 최종 test
	//   10. When & Who : 2018/05/30 by 김정걸
	//      What : 추가 수정사항 반영 후 모든 기능 test, preprocessor 및 전방 선헌 interface 함수를 main.h에 이동


	Reservation reservation[MAX];
	Accommodation accommodation[MAX];
	MemberInfo memberInfo[MAX];
	Timer timer;

	ReservationCollection reservationCollection(reservation);
	AccommodationCollection accommodationCollection(accommodation);
	MemberInfoCollection memberInfoCollection(memberInfo);


	freopen("input.txt", "r", stdin); // scanf시에 input.txt에서 읽어옴
	freopen("output.txt", "w", stdout); // printf시에 output.txt에서 씀

	while (1)
	{
		// 메뉴 파싱을 위한 level 구분을 위한 변수
		int menulevel_1 = 0, menulevel_2 = 0;

		// 입력파일에서 메뉴 숫자 2개를 읽기
		cin >> menulevel_1 >> menulevel_2;

		//메뉴 구분 및 해당 연산 수행
		switch (menulevel_1)
		{
		case 1:
		{
			switch (menulevel_2)
			{
			case 1: {	// "1.1. 회원가입" 메뉴 부분 
				signInInterface(&memberInfoCollection);
				break;
			}
			case 2: {	// "1.2. 회원 탈퇴" 메뉴 부분
				unregisterInterface(&accommodationCollection, &reservationCollection, &memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 2:
		{
			switch (menulevel_2)
			{
			case 1: {	// "2.1. 로그인" 메뉴 부분 
				loginInterface(&memberInfoCollection);
				break;
			}
			case 2: {	// "2.2. 로그아웃" 메뉴 부분
				logoutInterface(&memberInfoCollection);
				break;
			}
			}
			break;
		}
		case 3: {
			switch (menulevel_2) {
			case 1: {   // "3.1. 숙소 등록“ 메뉴 부분
				registerAccommodationInterface(&accommodationCollection, &memberInfoCollection,&timer);
				break;
			}
			case 2: {   // "3.2 등록 숙소 조회" 메뉴부분
				checkAccommodationInterface(&accommodationCollection, &memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 4: {
			switch (menulevel_2) {
			case 1: {   // "4.1 숙소 검색" 메뉴부분
				searchAccommodationInterface(&accommodationCollection, &memberInfoCollection);
				break;
			}
			case 2: {   //"4.2 숙소 예약" 메뉴부분
				reserveGeneralReservationInterface(&reservationCollection, &accommodationCollection, &memberInfoCollection);
				break;
			}
			case 3: {   //"4.3 Opaque inventroy"메뉴부분
				reserveOpaqueReservationInterface(&reservationCollection, &accommodationCollection, &memberInfoCollection, &timer);
				break;
			}
			case 4: {   // "4.4 예약정보 조회"메뉴부분
				checkReservationInterface(&reservationCollection, &memberInfoCollection);
				break;
			}

			}
			break;
		}
		case 5:
		{
			switch (menulevel_2) {
			case 1: {	 // " 5.1. 현재시간 설정
				setCurrentTimeInterface(&timer, &accommodationCollection, &memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 6: {
			switch (menulevel_2) {
			case 1: {	 // " 6.1 Session 변경" 메뉴 부분
				changeSession(&memberInfoCollection);
				break;
			}
			case 2: {	// " 6.2. Guest session으로 변경 " 메뉴 부분
				guestSession(&memberInfoCollection);
				break;
			}
			}
			break;
		}

		case 7: {
			switch (menulevel_2) {
			case 1: {   // "7.1. 종료“ 메뉴 부분
				programExit();	//programExit() 함수에서 해당 기능 수행
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

void signInInterface(MemberInfoCollection* memberInfoCollection)  //1.1회원가입 인터페이스
{
	SignInUI userInterface;
	SignInControl control;
	userInterface.inputInfo(&control, memberInfoCollection);
}

void unregisterInterface(AccommodationCollection* accommodationCollection, ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection) //1.2 회원탈퇴 인터페이스
{
	UnregisterUI userInterface;
	UnregisterControl control;
	userInterface.callUnregister(&control, accommodationCollection, reservationCollection, memberInfoCollection);
}

void loginInterface(MemberInfoCollection* memberInfoCollection) //2.1 로그인 인터페이스
{
	LoginUI userInterface;
	LoginControl control;
	userInterface.inputLoginInfo(&control, memberInfoCollection);
}

void logoutInterface(MemberInfoCollection* memberInfoCollection) //2.2 로그아웃 인터페이스
{
	LogoutUI userInterface;
	LogoutControl control;
	userInterface.callLogout(&control, memberInfoCollection);
}


void registerAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection,Timer * timer) //3.1 숙소 등록 인터페이스
{

	RegisterAccommodationUI userInterface;
	RegisterAccommodationControl control;
	userInterface.inputRegisterNewAccommodation(&control, accommodationCollection, memberInfoCollection, timer);
}

void checkAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection) //3.2 숙소 조회 인터페이스
{
	CheckAccommodationUI userInterface;
	CheckAccommodationControl control;
	control.getHostAccommodation(&userInterface, accommodationCollection, memberInfoCollection);
}

void searchAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection)  //4.1 숙소검색 인터페이스
{
	SearchAccommodationUI userInterface;
	SearchAccommodationControl control;
	userInterface.selectCityAndDate(&control, accommodationCollection, memberInfoCollection);
}
void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection) //4.2 숙소예약 인터페이스
{
	ReserveGeneralAccommodationUI userInterface;
	ReserveGeneralAccommodationControl control;
	userInterface.reserveGeneralAccommodation(&control, reservationCollection, accommodationCollection, memberInfoCollection);
}
void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection, Timer* timer) //4.3 opaque inventory 예약 인터페이스
{
	ReserveOpaqueInventoryUI userInterface;
	ReserveOpaqueInventoryControl control;
	userInterface.reserveOpaqueInventory(&control, reservationCollection, accommodationCollection, memberInfoCollection, timer);
}
void checkReservationInterface(ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection)  //4.4 예약정보 조회 인터페이스
{
	CheckReservationInformationUI userInterface;
	CheckReservationInformationControl control;
	userInterface.showReservationInformation(&control, reservationCollection, memberInfoCollection);
}
void setCurrentTimeInterface(Timer* timer, AccommodationCollection * accommodationCollection, MemberInfoCollection* memberInfoCollection) //5.1 현재시간설정
{
	SetCurrentTimeUI userInterface;
	SetCurrentTimeControl control;
	userInterface.startInterface(&control, timer, memberInfoCollection, accommodationCollection);
}

void changeSession(MemberInfoCollection* p_membercollection)//6.1 Session변경
{
	// Function : changeSession(MemberInfoCollection* p_membercollection)
	// Description: 입력받은 ID로 Session Change를 시도하는 함수
	// Created: 2018/5/27
	// Author: 김정걸


	string ID;
	cin >> ID;
	bool sameID = false;
	int membercount = p_membercollection->getMemberInfoCount();

	// 해당 기능 수행
	for (int i = 0; i < membercount; i++)
	{
		if (p_membercollection->getMemberInfo(i)->getID().compare(ID) == 0)
		{
			sameID = true;
			break;
		}
	}

	if (sameID)
	{
		for (int i = 0; i < membercount; i++)
		{
			if (p_membercollection->getMemberInfo(i)->getID().compare(ID) == 0)
			{
				p_membercollection->getMemberInfo(i)->setsessionOn(true);
			}
			else
			{
				p_membercollection->getMemberInfo(i)->setsessionOn(false);
			}
		}
		cout << "6.1 Session 변경" << endl;
		cout << ">" << ID << endl;
	}

}

void guestSession(MemberInfoCollection* p_memberInfoCollection)  //6.2. gusetSession으로 변경
{
	// Function :guestSession(MemberInfoCollection* membercollection)
	// Description: 프로그램의 memType을 guest로 수정
	// Created: 2018/5/27
	// Author: 김정걸

	// 해당 기능 수행

	if (p_memberInfoCollection->currentSession() == NULL)
	{
		cout << "6.2 Guest Session으로 변경" << endl;
	}
	else
	{
		p_memberInfoCollection->currentSession()->setsessionOn(false);
		cout << "6.2 Guest Session으로 변경" << endl;
	}

}



void programExit() {  //7.1 종료 인터페이스

	// Function :programExit()
	// Description: 프로그램 종료
	// Created: 2018/05/25
	// Author: 성경환

	printf("7.1 종료\n");
	exit(0);
}
