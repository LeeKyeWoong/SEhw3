#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignInControl;
class MemberInfoCollection;

class SignInUI
{
	//Class: SignInUI
	//Description: SignIn�� boundary class
	//Created: 2018/05/28
	//Author: ������


private:
	
public:
	void inputInfo(SignInControl* _signIn, MemberInfoCollection* memberInfoCollection);  ////�Էµ� ������ ������� MemberInfo�� ���� ��, �ش� ��ü�� MemberInfoColelction�� �����ϰ�, �޼����� ����ϴ� �Լ� 
};

