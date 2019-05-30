#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignInUI;
class MemberInfoCollection;

class SignInControl
{
	//Class: SignInControl
	//Description: SignIn의 control class
	//Created: 2018/05/28
	//Author: 문현준
	// Revsions : 
	//   1. When & Who : 2018/05/29 by 박건용
	//      What : 매개변수에 memType 추가, checkId 변수 추가 및 해당 변수를 사용하는 생성자 및 함수 구현


private:
	bool checkId;  //해당 ID의 중복 여부를 저장하는 변수
public:
	SignInControl();  //SignInControl의 기본 생성자가 아닌, 아무 입력 없이 control 객체의 checkID값을 NULL값으로 초기화 하는 생성자
	void createAccount(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, MemberInfoCollection* memberInfoCollection); //매개변수를 입력받아 새 Account를 생성하며, 입력된 ID의 중복 여부를 확인하는 함수
	bool getCheckId(); //회원 가입을 시도하는 ID의 중복 여부를 반환하는 함수

};