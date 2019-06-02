// Fliename: main.h
// Description: main���� ���Ǵ� ��� �� ������ ��� �Է�
// Created: 2019/05/29
// Author: �̰��

#pragma once

#include <iostream>
#include <string.h>
#include <cstdio>

#include "Member.h"           // ���             
#include "MemberCollection.h"
#include "SignUpUI.h"         // ȸ������
#include "SignUpControl.h"

#include "LoginUI.h"          // �α���
#include "LoginControl.h"
#include "LogoutUI.h"         // �α׾ƿ� 
#include "LogoutControl.h"
/*
#include "UnregisterUI.h"     // ȸ��Ż�� 
#include "UnregisterControl.h"
*/

//Ƽ�� ���, ��� Ƽ�� ��ȸ ���
#include "Ticket.h"
#include "TicketCollection.h"
//#include "CheckTicketControl.h"
//#include "CheckTicketUI.h"
#include "RegisterTicketControl.h"
#include "RegisterTicketUI.h"

//Ƽ�� �˻� �� ���� ���, Opaque inventory, ���� ���� ��ȸ ���
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

//����ð� ���� ���, ���� ���� ���
#include "Timer.h"
#include "SetCurrentTimeUI.h"
#include "SetCurrentTimeControl.h"
#include "ChangeSessionUI.h"
#include "ChangeSessionControl.h"

void signupInterface(MemberCollection* memberCollection);//1.1 ȸ������ �������̽�

void loginInterface(MemberCollection* memberCollection); //2.1 �α��� �������̽�
void logoutInterface(MemberCollection* memberCollection);//2.2 �α׾ƿ� �������̽�

//void unregisterInterface(TicketCollection* TicketCollection, ReservationCollection* reservationCollection, MemberCollection* MemberCollection); //1.2 ȸ��Ż�� �������̽�

void registerTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer * timer); //3.1 Ƽ�� ���

void searchTicketInterface(TicketCollection* TicketCollection, MemberCollection* memberCollection);  //4.1 Ƽ�� �˻�
void searchAutionTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer); //4.3 ���Ƽ�� �˻�
//void reserveGeneralReservationInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection,MemberCollection* MemberCollection); //4.2 ���ҿ��� �������̽�
//void reserveOpaqueReservationInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer* timer); //4.3 opaque inventory ���� �������̽�
//void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection);  //4.4 �������� ��ȸ �������̽�

void setCurrentTimeInterface(Timer* timer, TicketCollection* ticketCollection); //5.1 ����ð�����
void changeSessionInterface(MemberCollection* mCollection);  //6.1 Session����

//void guestSession(MemberCollection* p_membercollection); //6.2. gusetSession���� ����
void exitProgram(); //7.1���� �������̽�


// �Է�����
/* 
1 1 [ID] [��й�ȣ] [�̸�] [�ֹι�ȣ] [����� ����]  
1 2  
2 1 [ID] [��й�ȣ] 
2 2 
3 1 [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ] [��ż��ÿ���]
3 2
4 1 [Ȩ��] 
4 2 [��¥-�ð�] [�������] [�¼���ġ]
4 3 [Ȩ��]
4 4 [��¥-�ð�] [�������] [�¼���ġ] [�����ݾ�]  
4 5
5 1 [����ð�]
6 1 [ID]
6 2 
7 1
*/ 

// �������
/*
1.1. ȸ������
> [ID] [��й�ȣ] [�̸�] [�ֹι�ȣ] [����� ����] 
1.2. ȸ��Ż��
> [ID]
2.1. �α��� 
> [ID] [��й�ȣ] 
2.2. �α׾ƿ�
> [ID]
3.1. �Ǹ�Ƽ�� ���
> [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ] [��ż��ÿ���]
3.2. ���Ƽ�� ��ȸ
> { [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ] [��ż��ÿ���] [�Ǹſ���] }*
4.1. Ƽ�� �˻�
> { [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ] }*
4.2. Ƽ�� ����
> [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ]
4.3. ��� ���� Ƽ�� �˻�
> { [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ] [�������� ���� �ð�] }*
4.4. ��� ����
> [�����ݾ�]
4.5. ���� ���� ��ȸ
> { [���Ű���] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ] }*
5.1. ����ð� ����
> [����ð�]
6.1. session ����
> [ID]
6.2. guest session���� ����
7.1. ����
*/