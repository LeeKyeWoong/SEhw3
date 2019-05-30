#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignInUI;
class MemberInfoCollection;

class SignInControl
{
	//Class: SignInControl
	//Description: SignIn�� control class
	//Created: 2018/05/28
	//Author: ������
	// Revsions : 
	//   1. When & Who : 2018/05/29 by �ڰǿ�
	//      What : �Ű������� memType �߰�, checkId ���� �߰� �� �ش� ������ ����ϴ� ������ �� �Լ� ����


private:
	bool checkId;  //�ش� ID�� �ߺ� ���θ� �����ϴ� ����
public:
	SignInControl();  //SignInControl�� �⺻ �����ڰ� �ƴ�, �ƹ� �Է� ���� control ��ü�� checkID���� NULL������ �ʱ�ȭ �ϴ� ������
	void createAccount(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, MemberInfoCollection* memberInfoCollection); //�Ű������� �Է¹޾� �� Account�� �����ϸ�, �Էµ� ID�� �ߺ� ���θ� Ȯ���ϴ� �Լ�
	bool getCheckId(); //ȸ�� ������ �õ��ϴ� ID�� �ߺ� ���θ� ��ȯ�ϴ� �Լ�

};