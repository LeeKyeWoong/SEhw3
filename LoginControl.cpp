#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

LoginControl::LoginControl()
{
	//Functnion: LoginControl()
	//Description: Login�� �õ��ϸ� successLogin ������ False�� �ʱ�ȭ �ϴ� �Լ�
	//Created: 2018/05/30
	//Author: ������


	successLogin = false;
}

void LoginControl::requestLogin(string ID, string password, MemberInfoCollection* memberInfoCollection)
{
	//Functnion: requestLogin(string ID, string password, MemberInfoCollection* memberInfoCollection)
	//Description: �Է¹��� ID �� password�� MemberCollection�� �ִ��� Ȯ���Ͽ� Login�� �õ��Ѵ�
	//Created: 2018/05/28
	//Author: ������


	int memberCount = memberInfoCollection->getMemberInfoCount();
	for (int i = 0; i < memberCount; i++)
	{
		if ((memberInfoCollection->getMemberInfo(i)->getID().compare(ID) == 0) && (memberInfoCollection->getMemberInfo(i)->getpassword().compare(password) == 0))
		{
			successLogin = true;
			memberInfoCollection->getMemberInfo(i)->setsessionOn(true);
		}
		else
		{
			memberInfoCollection->getMemberInfo(i)->setsessionOn(false);
		}
	}
}

bool LoginControl::getSuccessLogin()
{
	//Functnion: LoginControl()
	//Description: Login ���� ���θ� ��ȯ�ϴ� �Լ�
	//Created: 2018/05/30
	//Author: ������


	return successLogin;
}