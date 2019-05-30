#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void LogoutControl::requestLogout(MemberInfoCollection* memberInfoCollection)
{
	//Function: requestLogout(MemberInfoCollection* memberInfoCollection)
	//Description: 회원의 세션상태를 변경해 로그아웃 함.
	//Created: 2018/05/27
	//Author: 문현준

	if (memberInfoCollection->currentSession() == NULL)
	{
	}
	else
	{
		logoutId = memberInfoCollection->currentSession()->getID();
		memberInfoCollection->currentSession()->setsessionOn(false);
	}
}

string LogoutControl::getLogoutId()
{
	//Function: getLogoutId()
	//Description: LogoutID를 출력하는 함수
	//Created: 2018/05/27
	//Author: 문현준
	return logoutId;
}