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

//티켓 등록, 등록 티켓 조회 기능
#include "Ticket.h"
#include "TicketCollection.h"
//#include "CheckTicketControl.h"
//#include "CheckTicketUI.h"
#include "RegisterTicketControl.h"
#include "RegisterTicketUI.h"

//티켓 검색 및 예약 기능, Opaque inventory, 예약 정보 조회 기능
#include "Reservation.h"
#include "ReservationCollection.h"
//#include "ReserveGeneralTicketUI.h"
//#include "ReserveGeneralTicketControl.h"
#include "SearchTicketControl.h"
#include "SearchTicketUI.h"
#include "SearchAuctionTicketControl.h"
#include "SearchAuctionTicketUI.h"
//#include "ReserveOpaqueInventoryUI.h"
//#include "ReserveOpaqueInventoryControl.h"
//#include "CheckReservationInformationUI.h"
//#include "CheckReservationInformationControl.h"

//현재시간 변경 기능, 세션 변경 기능
#include "Timer.h"
#include "SetCurrentTimeUI.h"
#include "SetCurrentTimeControl.h"
#include "ChangeSessionUI.h"
#include "ChangeSessionControl.h"

void signupInterface(MemberCollection* memberCollection);//1.1 회원가입 인터페이스

void loginInterface(MemberCollection* memberCollection); //2.1 로그인 인터페이스
void logoutInterface(MemberCollection* memberCollection);//2.2 로그아웃 인터페이스

//void unregisterInterface(TicketCollection* TicketCollection, ReservationCollection* reservationCollection, MemberCollection* MemberCollection); //1.2 회원탈퇴 인터페이스

void registerTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer * timer); //3.1 티켓 등록

void searchTicketInterface(TicketCollection* TicketCollection, MemberCollection* memberCollection);  //4.1 티켓 검색
void searchAutionTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer); //4.3 경매티켓 검색
//void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection,MemberCollection* MemberCollection); //4.2 숙소예약 인터페이스
//void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer* timer); //4.3 opaque inventory 예약 인터페이스
//void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection);  //4.4 예약정보 조회 인터페이스

void setCurrentTimeInterface(Timer* timer, TicketCollection* ticketCollection); //5.1 현재시간설정
void changeSessionInterface(MemberCollection* mCollection);  //6.1 Session변경

//void guestSession(MemberCollection* p_membercollection); //6.2. gusetSession으로 변경
void exitProgram(); //7.1종료 인터페이스


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