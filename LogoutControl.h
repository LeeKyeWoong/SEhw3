#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutUI;
class MemberInfoCollection;

class LogoutControl
{
	//Class: LogoutControl
	//Description: Logout�� control class
	//Created: 2018/05/27
	//Author: ������


private:
	string logoutId;  //Logout�� �õ��ϴ� MemeberInfo�� ID�� �����ϴ� ����
public:
	void requestLogout(MemberInfoCollection* memberInfoCollection); //���� sessionOn������ ȸ���� ���� �����ϴ� �Լ�
	string getLogoutId();  //logoutID�� ��ȯ�ϴ� �Լ�
};