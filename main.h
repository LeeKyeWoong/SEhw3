// Fliename: main.h
// Description: main에서 사용되는 헤더 및 참조할 헤더 입력
// Created: 2019/05/29
// Author: 이계웅

#pragma once

#include <iostream>
#include <string.h>
#include <cstdio>


#include "Member.h"           // 멤버             
#include "MemberCollection.h"
#include "SignUpUI.h"         // 회원가입
#include "SignUpControl.h"

#include "LoginUI.h"          // 로그인
#include "LoginControl.h"
#include "LogoutUI.h"         // 로그아웃 
#include "LogoutControl.h"
/*
#include "UnregisterUI.h"     // 회원탈퇴 
#include "UnregisterControl.h"
*/
/*
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
*/
//타이머 및 세션
//#include "Timer.h"
//#include "SetCurrentTimeUI.h"
//#include "SetCurrentTimeControl.h"

void signupInterface(MemberCollection* memberCollection);//1.1 회원가입 인터페이스

void loginInterface(MemberCollection* memberCollection); //2.1 로그인 인터페이스
void logoutInterface(MemberCollection* memberCollection);//2.2 로그아웃 인터페이스

//void unregisterInterface(AccommodationCollection* accommodationCollection, ReservationCollection* reservationCollection, MemberCollection* MemberCollection); //1.2 회원탈퇴 인터페이스
/*
void registerAccommodationInterface(AccommodationCollection* accommodationCollection, MemberCollection* MemberCollection, Timer * timer); //3.1 숙소 등록 인터페이스
void checkAccommodationInterface(AccommodationCollection* accommodationCollection, MemberCollection* MemberCollection); //3.2 숙소 조회 인터페이스
void searchAccommodationInterface(AccommodationCollection* accommodationCollection, MemberCollection* MemberCollection);  //4.1 숙소검색 인터페이스
void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection,MemberCollection* MemberCollection); //4.2 숙소예약 인터페이스
void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberCollection* MemberCollection, Timer* timer); //4.3 opaque inventory 예약 인터페이스
void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection);  //4.4 예약정보 조회 인터페이스
*/
//void setCurrentTimeInterface(Timer* timer, AccommodationCollection* accommodationCollection, MemberCollection * MemberCollection); //5.1 현재시간설정
/*
void changeSession(MemberCollection* p_membercollection);  //6.1 Session변경
void guestSession(MemberCollection* p_membercollection); //6.2. gusetSession으로 변경
void programExit(); //7.1종료 인터페이스
*/

// 입력형식
/* 
1 1 [ID] [비밀번호] [이름] [주민번호] [사용자 유형]  
1 2  
2 1 [ID] [비밀번호] 
2 2 
3 1 [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치] [경매선택여부]
3 2
4 1 [홈팀] 
4 2 [날짜-시간] [어웨이팀] [좌석위치]
4 3 [홈팀]
4 4 [날짜-시간] [어웨이팀] [좌석위치] [입찰금액]  
4 5
5 1 [현재시간]
6 1 [ID]
6 2 
7 1
*/ 

// 출력형식
/*
1.1. 회원가입
> [ID] [비밀번호] [이름] [주민번호] [사용자 유형] 
1.2. 회원탈퇴
> [ID]
2.1. 로그인 
> [ID] [비밀번호] 
2.2. 로그아웃
> [ID]
3.1. 판매티켓 등록
> [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치] [경매선택여부]
3.2. 등록티켓 조회
> { [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치] [경매선택여부] [판매여부] }*
4.1. 티켓 검색
> { [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치] }*
4.2. 티켓 예약
> [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치]
4.3. 경매 중인 티켓 검색
> { [날짜-시간] [홈팀] [어웨이팀] [좌석위치] [마감까지 남은 시간] }*
4.4. 경매 참여
> [입찰금액]
4.5. 예약 정보 조회
> { [구매가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치] }*
5.1. 현재시간 설정
> [현재시간]
6.1. session 변경
> [ID]
6.2. guest session으로 변경
7.1. 종료
*/