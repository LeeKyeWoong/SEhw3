#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginUI;
class MemberInfoCollection;

class LoginControl
{
	//Class: LoginControl
	//Description: Login�� control class
	//Created: 2018/05/28
	//Author: ������
	// Revsions : 
	//   1. When & Who : 2018/05/30 by �ڰǿ�
	//      What : Login ���� ���θ� �����ϴ� ���� successLogin �� �ش� ������ �����ϴ� �Լ� �߰�


	
private:
	bool successLogin;  //Login ���� ���θ� �����ϴ� ����
public:
	LoginControl();  //Login�� �õ��ϸ� successLogin ������ False�� �ʱ�ȭ �ϴ� �Լ�
	void requestLogin(string ID, string password, MemberInfoCollection* memberInfoCollection);  //�Է¹��� ID �� password�� MemberCollection�� �ִ��� Ȯ���Ͽ� Login�� �õ��ϴ� �Լ�
	bool getSuccessLogin();  //Login ���� ���θ� ��ȯ�ϴ� �Լ�

};