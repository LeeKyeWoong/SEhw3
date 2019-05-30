#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginUI;
class MemberInfoCollection;

class LoginControl
{
	//Class: LoginControl
	//Description: Login의 control class
	//Created: 2018/05/28
	//Author: 문현준
	// Revsions : 
	//   1. When & Who : 2018/05/30 by 박건용
	//      What : Login 성공 여부를 저장하는 변수 successLogin 및 해당 변수를 조작하는 함수 추가


	
private:
	bool successLogin;  //Login 성공 여부를 저장하는 변수
public:
	LoginControl();  //Login을 시도하며 successLogin 변수를 False로 초기화 하는 함수
	void requestLogin(string ID, string password, MemberInfoCollection* memberInfoCollection);  //입력받은 ID 및 password가 MemberCollection에 있는지 확인하여 Login을 시도하는 함수
	bool getSuccessLogin();  //Login 성공 여부를 반환하는 함수

};