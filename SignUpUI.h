#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignInControl;
class MemberInfoCollection;

class SignInUI
{
	//Class: SignInUI
	//Description: SignIn의 boundary class
	//Created: 2018/05/28
	//Author: 문현준


private:
	
public:
	void inputInfo(SignInControl* _signIn, MemberInfoCollection* memberInfoCollection);  ////입력된 정보를 기반으로 MemberInfo를 생성 후, 해당 객체를 MemberInfoColelction에 저장하고, 메세지를 출력하는 함수 
};

