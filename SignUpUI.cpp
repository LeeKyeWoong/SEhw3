#pragma once
#include "SignInUI.h"
#include "SignInControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void SignInUI::inputInfo(SignInControl* _signIn, MemberInfoCollection* memberInfoCollection)
{

	// Function :inputInfo(SignInControl* _signIn, MemberInfoCollection* memberInfoCollection)
	// Description: 입력된 정보를 바탕으로 새 계정을 만드는 함수
	// Created: 2017/5/29
	// Author: 문현준

	
	string memType, name, residentRegistrationNumber, address, ID, password;
	cin >> memType >> name >> residentRegistrationNumber >> address >> ID >> password;
	_signIn->createAccount(memType, name, residentRegistrationNumber, address, ID, password, memberInfoCollection);

	if (_signIn->getCheckId())
	{
		cout << "1.1 회원가입" << endl;
		cout << ">" << memType << " " << name << " " << residentRegistrationNumber << " " << address << " " << ID << " " << password << endl;
	}
	else
	{

	}
	
}
