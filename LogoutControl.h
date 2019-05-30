#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutUI;
class MemberInfoCollection;

class LogoutControl
{
	//Class: LogoutControl
	//Description: Logout의 control class
	//Created: 2018/05/27
	//Author: 문현준


private:
	string logoutId;  //Logout을 시도하는 MemeberInfo의 ID를 저장하는 변수
public:
	void requestLogout(MemberInfoCollection* memberInfoCollection); //현제 sessionOn상태의 회원을 세션 종료하는 함수
	string getLogoutId();  //logoutID를 반환하는 함수
};