#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginControl;
class MemberInfoCollection;

class LoginUI
{
	//Class: LoginUI
	//Description: Login의 boundary class
	//Created: 2018/05/28
	//Author: 문현준


private:
	
public:
	void inputLoginInfo(LoginControl* _login, MemberInfoCollection* memberInfoCollection);  ////Login 정보를 입력받는 함수
};

