//Flie name: main.h
//Description: main���� ���Ǵ� ��� �� ������ ��� �Է�
//Created: 2018/05/25
//Author: ������
//   1. When & Who : 2018/05/30 by ������
//      What : main�� ���ǵǾ� �ִ� ��� ��� �� ���� ����� �Լ��� �̰����� �̵�


#pragma once

#include<iostream>
#include<string>
#include<cstdio>


//�α���/�α׾ƿ�/ȸ������/ȸ��Ż�� /���
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


//���� ���, ��� ���� ��ȸ ���
#include "Accommodation.h"
#include "AccommodationCollection.h"
#include "CheckAccommodationControl.h"
#include "CheckAccommodationUI.h"
#include "RegisterAccommodationControl.h"
#include "RegisterAccommodationUI.h"

//���� �˻� �� ���� ���, Opaque inventory, ���� ���� ��ȸ ���
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

//Ÿ�̸� �� ����
#include "Timer.h"
#include "SetCurrentTimeUI.h"
#include "SetCurrentTimeControl.h"


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


void signInInterface(MemberInfoCollection* memberInfoCollection); //1.1 ȸ������ �������̽�
void loginInterface(MemberInfoCollection* memberInfoCollection); //2.1 �α��� �������̽�
void logoutInterface(MemberInfoCollection* memberInfoCollection); //2.2 �α׾ƿ� �������̽�
void unregisterInterface(AccommodationCollection* accommodationCollection, ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection); //1.2 ȸ��Ż�� �������̽�
void registerAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection, Timer * timer); //3.1 ���� ��� �������̽�
void checkAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection); //3.2 ���� ��ȸ �������̽�
void searchAccommodationInterface(AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection);  //4.1 ���Ұ˻� �������̽�
void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection,MemberInfoCollection* memberInfoCollection); //4.2 ���ҿ��� �������̽�
void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, AccommodationCollection* accommodationCollection, MemberInfoCollection* memberInfoCollection, Timer* timer); //4.3 opaque inventory ���� �������̽�
void checkReservationInterface(ReservationCollection* reservationCollection, MemberInfoCollection* memberInfoCollection);  //4.4 �������� ��ȸ �������̽�
void setCurrentTimeInterface(Timer* timer, AccommodationCollection* accommodationCollection, MemberInfoCollection * memberInfoCollection); //5.1 ����ð�����
void changeSession(MemberInfoCollection* p_membercollection);  //6.1 Session����
void guestSession(MemberInfoCollection* p_membercollection); //6.2. gusetSession���� ����
void programExit(); //7.1���� �������̽�




