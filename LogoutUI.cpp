#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void LogoutUI::callLogout(LogoutControl* _logout, MemberInfoCollection* memberInfoCollection)
{
	//Function: callLogout(LogoutControl* _logout, MemberInfoCollection* memberInfoCollection)
	//Description: Control�� Logout�� ��û�ϴ� �Լ�
	//Created: 2018/05/27
	//Author: ������


	_logout->requestLogout(memberInfoCollection);

	cout << "2.2. �α׾ƿ�" << endl;
	cout << ">" << _logout->getLogoutId() << endl;

}
