#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginControl;
class MemberInfoCollection;

class LoginUI
{
	//Class: LoginUI
	//Description: Login�� boundary class
	//Created: 2018/05/28
	//Author: ������


private:
	
public:
	void inputLoginInfo(LoginControl* _login, MemberInfoCollection* memberInfoCollection);  ////Login ������ �Է¹޴� �Լ�
};

