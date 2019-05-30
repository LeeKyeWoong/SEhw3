#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void LogoutUI::callLogout(LogoutControl* _logout, MemberInfoCollection* memberInfoCollection)
{
	//Function: callLogout(LogoutControl* _logout, MemberInfoCollection* memberInfoCollection)
	//Description: Control에 Logout을 요청하는 함수
	//Created: 2018/05/27
	//Author: 문현준


	_logout->requestLogout(memberInfoCollection);

	cout << "2.2. 로그아웃" << endl;
	cout << ">" << _logout->getLogoutId() << endl;

}
