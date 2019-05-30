#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutControl;
class MemberInfoCollection;

class LogoutUI
{
	//Class: LogoutUI
	//Description: Logout의 boundary class
	//Created: 2018/05/27
	//Author: 문현준

private:

public:
	void callLogout(LogoutControl* _logout, MemberInfoCollection* memberInfoCollection); //LogoutControl 객체에 User의 Logout 요청을 전달하는 함수
};

