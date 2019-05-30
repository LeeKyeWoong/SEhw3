#pragma once
#include "SignInUI.h"
#include "SignInControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void SignInUI::inputInfo(SignInControl* _signIn, MemberInfoCollection* memberInfoCollection)
{

	// Function :inputInfo(SignInControl* _signIn, MemberInfoCollection* memberInfoCollection)
	// Description: �Էµ� ������ �������� �� ������ ����� �Լ�
	// Created: 2017/5/29
	// Author: ������

	
	string memType, name, residentRegistrationNumber, address, ID, password;
	cin >> memType >> name >> residentRegistrationNumber >> address >> ID >> password;
	_signIn->createAccount(memType, name, residentRegistrationNumber, address, ID, password, memberInfoCollection);

	if (_signIn->getCheckId())
	{
		cout << "1.1 ȸ������" << endl;
		cout << ">" << memType << " " << name << " " << residentRegistrationNumber << " " << address << " " << ID << " " << password << endl;
	}
	else
	{

	}
	
}
