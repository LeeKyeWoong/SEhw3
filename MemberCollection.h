#pragma once

#include <iostream>
#include <string>

#define MAX 50

using namespace std;

class Member;

class MemberCollection
{
	// Class: MemberCollection
	// Description: Member를 element로 갖는 MemberCollection class
	// Created: 2019/05/28
	// Author: 이계웅

private:
	Member * Member[MAX];  // Member를 저장하는 포인터를 원소로 하는 배열
	int memberNumber;      // Member 번호를 기록하는 변수

public:
	MemberCollection(Member Member[MAX]);  // MeberInfoCollection의 사용자 정의 생성자
	void addMember(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, string opaqueInventoryTryTime, bool sessionOn);  //MemeberInfoCollectoin에 Member객체를 저장하는 함수
	void deleteMember(int deleteMemberIndex);  //MemberCollecton의 deleteMemberIndex번째의 Member를 삭제하는 함수
	Member *getMember(int memberNumber);  //Membercount 번째의 Member를 불러오는 함수
	Member *currentSession();  		//현재 세션을 확인하는 함수
	int getCurrentSessionIndex();   //현제 세션이 몇번재 MemberCollection의 객체인 지 반환하는 함수
	int getMemberCount();  			// MemberCollection에서 몇번째로 저장되어 있는지 반환하는 함수
	void setMemberCount(int _MemberCount);  //MemeberInfoCount를 저장하는 함수
};
