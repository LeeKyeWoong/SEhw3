#pragma once
#include "SignInUI.h"
#include "SignInControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

SignInControl::SignInControl()
{
	// Function : SignInControl()
	// Description: SignInControl의 기본 생성자가 아닌, 아무 입력 없이 control 객체의 checkID값을 NULL값으로 초기화 하는 생성자
	// Created: 2017/5/29
	// Author: 박건용


	checkId = true;
}

void SignInControl::createAccount(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, MemberInfoCollection* memberInfoCollection)
{
	// Function : createAccount(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, MemberInfoCollection* memberInfoCollection)
	// Description: 매개변수를 입력받아 새 Account를 생성하며, 입력된 ID의 중복 여부를 확인하는 함수
	// Created: 2017/5/28
	// Author: 문현준
	// Revsions : 
	//   1. When & Who : 2018/05/29 by 박건용
	//      What : 매개변수에 memType 추가 


	int memberInfoCount = memberInfoCollection->getMemberInfoCount();

	for (int i = 0; i < memberInfoCount; i++)
	{
		if (ID.compare(memberInfoCollection->getMemberInfo(i)->getID()) == 0)
		{
			checkId = false;
		}
	}

	if (checkId)
	{
		memberInfoCollection->addMemberInfo(memType, name, residentRegistrationNumber, address, ID, password, "0", false);
	}
	else
	{
		
	}
	
}

bool SignInControl::getCheckId()
{
	// Function : SignInControl()
	// Description: 회원 가입을 시도하는 ID의 중복 여부를 반환하는 함수
	// Created: 2017/5/29
	// Author: 박건용


	return checkId;
}