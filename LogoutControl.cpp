#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void LogoutControl::requestLogout(MemberInfoCollection* memberInfoCollection)
{
	//Function: requestLogout(MemberInfoCollection* memberInfoCollection)
	//Description: ȸ���� ���ǻ��¸� ������ �α׾ƿ� ��.
	//Created: 2018/05/27
	//Author: ������

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
	//Description: LogoutID�� ����ϴ� �Լ�
	//Created: 2018/05/27
	//Author: ������
	return logoutId;
}