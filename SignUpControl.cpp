#pragma once
#include "SignInUI.h"
#include "SignInControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

SignInControl::SignInControl()
{
	// Function : SignInControl()
	// Description: SignInControl�� �⺻ �����ڰ� �ƴ�, �ƹ� �Է� ���� control ��ü�� checkID���� NULL������ �ʱ�ȭ �ϴ� ������
	// Created: 2017/5/29
	// Author: �ڰǿ�


	checkId = true;
}

void SignInControl::createAccount(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, MemberInfoCollection* memberInfoCollection)
{
	// Function : createAccount(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, MemberInfoCollection* memberInfoCollection)
	// Description: �Ű������� �Է¹޾� �� Account�� �����ϸ�, �Էµ� ID�� �ߺ� ���θ� Ȯ���ϴ� �Լ�
	// Created: 2017/5/28
	// Author: ������
	// Revsions : 
	//   1. When & Who : 2018/05/29 by �ڰǿ�
	//      What : �Ű������� memType �߰� 


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
	// Description: ȸ�� ������ �õ��ϴ� ID�� �ߺ� ���θ� ��ȯ�ϴ� �Լ�
	// Created: 2017/5/29
	// Author: �ڰǿ�


	return checkId;
}