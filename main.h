//Flie name: main.h
//Description: main에서 사용되는 헤더 및 참조할 헤더 입력
//Created: 2018/05/25
//Author: 김정걸
//   1. When & Who : 2018/05/30 by 김정걸
//      What : main에 정의되어 있던 모든 헤더 및 전방 선언된 함수를 이곳으로 이동


#pragma once

#include<iostream>
#include<string>
#include<cstdio>


//로그인/로그아웃/회원가입/회원탈퇴 /멤버
#include "MemberInfo.h"
#include "MemberInfoCollection.h"
#include "SignInUI.h"
#include "SignInControl.h"
#include "LoginUI.h"
#include "LoginControl.h"
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "UnregisterUI.h"
#include "UnregisterControl.h"


//숙소 등록, 등록 숙소 조회 기능
#include "Accommodation.h"
#include "AccommodationCollection.h"
#include "CheckAccommodationControl.h"
#include "CheckAccommodationUI.h"
#include "RegisterAccommodationControl.h"
#include "RegisterAccommodationUI.h"

//숙소 검색 및 예약 기능, Opaque inventory, 예약 정보 조회 기능
#include "Reservation.h"
#include "ReservationCollection.h"
#include "ReserveGeneralAccommodationUI.h"
#include "ReserveGeneralAccommodationControl.h"
#include "ReserveGeneralAccommodationUI.h"
#include "SearchAccommodationControl.h"
#include "SearchAccommodationUI.h"
#include "ReserveOpaqueInventoryUI.h"
#include "ReserveOpaqueInventoryControl.h"
#include "CheckReservationInformationUI.h"
#include "CheckReservationInformationControl.h"

//타이머 및 세션
#include "Timer.h"
#include "SetCurrentTimeUI.h"
#include "SetCurrentTimeControl.h"


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


void signInInterface(MemberInfoCollection* memberInfoCollection); //1.1 회원가입 인터페이스
void loginInterface(MemberInfoCollection* memberInfoCollection); //2.1 로그인 인터페이스
void logoutInterface(MemberInfoCollection* memberInfoCollection); //2.2 로그아웃 인터페이스
void unregisterInterface(AccommodationCollection* accommodationCollection, ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection); //1.2 회원탈퇴 인터페이스
void registerAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection, Timer * timer); //3.1 숙소 등록 인터페이스
void checkAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection); //3.2 숙소 조회 인터페이스
void searchAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection);  //4.1 숙소검색 인터페이스
void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection,MemberInfoCollection* memberInfoCollection); //4.2 숙소예약 인터페이스
void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection, Timer* timer); //4.3 opaque inventory 예약 인터페이스
void checkReservationInterface(ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection);  //4.4 예약정보 조회 인터페이스
void setCurrentTimeInterface(Timer* timer, AccommodationCollection* accommodationCollection, MemberInfoCollection * memberInfoCollection); //5.1 현재시간설정
void changeSession(MemberInfoCollection* p_membercollection);  //6.1 Session변경
void guestSession(MemberInfoCollection* p_membercollection); //6.2. gusetSession으로 변경
void programExit(); //7.1종료 인터페이스




