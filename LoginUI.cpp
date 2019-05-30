#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "MemberInfo.h"
#include "MemberInfoCollection.h"

void LoginUI::inputLoginInfo(LoginControl* _login, MemberInfoCollection* memberInfoCollection)
{
	//Functnion: inputLoginInfo(LoginControl* _login, MemberInfoCollection* memberInfoCollection)
	//Description: Login ������ �Է¹޴´�
	//Created: 2018/05/28
	//Author: ������

	
	string ID, password;
	cin >> ID >> password;
	_login->requestLogin(ID, password, memberInfoCollection);

	if (_login->getSuccessLogin())
	{
		cout << "2.1 �α���" << endl;
		cout << ">" << ID << " " << password << endl;
	}
	else
	{

	}
}
