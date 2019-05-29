#pragma once

#include <iostream>
#include <string>

#define MAX 50

using namespace std;

class Member;

class MemberCollection
{
	// Class: MemberCollection
	// Description: Member�� element�� ���� MemberCollection class
	// Created: 2019/05/28
	// Author: �̰��

private:
	Member * Member[MAX];  // Member�� �����ϴ� �����͸� ���ҷ� �ϴ� �迭
	int memberNumber;      // Member ��ȣ�� ����ϴ� ����

public:
	MemberCollection(Member Member[MAX]);  // MeberInfoCollection�� ����� ���� ������
	void addMember(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, string opaqueInventoryTryTime, bool sessionOn);  //MemeberInfoCollectoin�� Member��ü�� �����ϴ� �Լ�
	void deleteMember(int deleteMemberIndex);  //MemberCollecton�� deleteMemberIndex��°�� Member�� �����ϴ� �Լ�
	Member *getMember(int memberNumber);  //Membercount ��°�� Member�� �ҷ����� �Լ�
	Member *currentSession();  		//���� ������ Ȯ���ϴ� �Լ�
	int getCurrentSessionIndex();   //���� ������ ����� MemberCollection�� ��ü�� �� ��ȯ�ϴ� �Լ�
	int getMemberCount();  			// MemberCollection���� ���°�� ����Ǿ� �ִ��� ��ȯ�ϴ� �Լ�
	void setMemberCount(int _MemberCount);  //MemeberInfoCount�� �����ϴ� �Լ�
};
