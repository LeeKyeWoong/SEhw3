#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

LoginControl::LoginControl()
{
	//Functnion: LoginControl()
	//Description: Login을 시도하며 successLogin 변수를 False로 초기화 하는 함수
	//Created: 2018/05/30
	//Author: 문현준


	successLogin = false;
}

void LoginControl::requestLogin(string ID, string password, MemberInfoCollection* memberInfoCollection)
{
	//Functnion: requestLogin(string ID, string password, MemberInfoCollection* memberInfoCollection)
	//Description: 입력받은 ID 및 password가 MemberCollection에 있는지 확인하여 Login을 시도한다
	//Created: 2018/05/28
	//Author: 문현준


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
	//Description: Login 성공 여부를 반환하는 함수
	//Created: 2018/05/30
	//Author: 문현준


	return successLogin;
}