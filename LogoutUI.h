#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutControl;
class MemberInfoCollection;

class LogoutUI
{
	//Class: LogoutUI
	//Description: Logout�� boundary class
	//Created: 2018/05/27
	//Author: ������

private:

public:
	void callLogout(LogoutControl* _logout, MemberInfoCollection* memberInfoCollection); //LogoutControl ��ü�� User�� Logout ��û�� �����ϴ� �Լ�
};

