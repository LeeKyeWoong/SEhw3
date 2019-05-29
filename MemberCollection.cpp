#pragma once

#include "MemberInfoCollection.h"
#include "MemberInfo.h"

MemberInfoCollection::MemberInfoCollection(MemberInfo _memberInfo[MAX])
{
	//Functnion: MemberInfoCollection(MemberInfo _memberInfo[MAX])
	//Description:MemberInfoCollecion�� �����ϴ� ������
	//Created: 2018/05/28
	//Author: ������


	memberInfoCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		this->memberInfo[i] = &_memberInfo[i];
	}
}

void MemberInfoCollection::addMemberInfo(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, string opaqueInventoryTryTime, bool sessionOn)
{
	//Functnion: addMemberInfo(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, string opaqueInventoryTryTime, bool sessionOn)
	//Description: MemberInfoCollection�� Member ��ü�� �Է��ϴ� �Լ�
	//Created: 2018/05/28
	//Author: ������


	string tempmemType = memType;
	string tempname = name;
	string tempresidentRegistrationNumber = residentRegistrationNumber;
	string tempaddress = address;
	string tempID = ID;
	string temppassword = password;
	string tempopaqueInventoryTryTime = opaqueInventoryTryTime;
	bool tempsessionOn = sessionOn;

	this->memberInfo[memberInfoCount]->createMemberInfo(tempmemType, tempname, tempresidentRegistrationNumber, tempaddress, tempID, temppassword, tempopaqueInventoryTryTime, tempsessionOn);
	this->memberInfoCount++;
}


void MemberInfoCollection::deleteMemberInfo(int deleteMemberInfoIndex)
{
	//Functnion: deleteMemberInfo(int deleteMemberInfoIndex)
	//Description: MemberInfoCollecton�� deleteMemberInfoIndex��°�� MemberInfo�� �����ϴ� �Լ�
	//Created: 2018/05/28
	//Author: ������


	if (deleteMemberInfoIndex == 0)
	{
		memberInfo[deleteMemberInfoIndex]->removeMemberInfo();
		memberInfo[deleteMemberInfoIndex] = NULL;
	}
	else
	{
		memberInfo[deleteMemberInfoIndex]->removeMemberInfo();
		for (int i = deleteMemberInfoIndex; i < memberInfoCount; i++)
		{
			memberInfo[deleteMemberInfoIndex] = memberInfo[deleteMemberInfoIndex + 1];
		}
		memberInfo[memberInfoCount - 1]->removeMemberInfo();
		memberInfo[memberInfoCount - 1] = NULL;
		memberInfoCount--;

	}
}

MemberInfo* MemberInfoCollection::getMemberInfo(int memberInfoCount)
{
	//Functnion: getMemberInfo(int memberInfoCount)
	//Description:MemberInfoCollection�� memberInfoCount��° MemberInfo �� ��ȯ�ϴ� �Լ�
	//Created: 2018/05/28
	//Author: ������


	return memberInfo[memberInfoCount];
}

MemberInfo* MemberInfoCollection::currentSession()
{
	//Functnion: currentSession()
	//Description: � Memeber�� ���� Session���� Ȯ���ϴ� �Լ�
	//Created: 2018/05/28
	//Author: ������


	bool checkSession = false;
	for (int i = 0; i < memberInfoCount; i++)
	{
		if (memberInfo[i]->getsessionOn() == true)
		{
			checkSession = true;
			return memberInfo[i];
		}
	}
	if (!checkSession)
	{
		return NULL;
	}
}

int MemberInfoCollection::getCurrentSessionIndex()
{
	//Functnion: getCurrentSessionIndex()
	//Description: ���° memberInfoCollection�� ���� Sessiohn�� ����ϴ� �� ��ȯ�ϴ� �Լ�
	//Created: 2018/05/28
	//Author: ������


	for (int i = 0; i < memberInfoCount; i++)
	{
		if (memberInfo[i]->getsessionOn() == true)
		{
			return i;
		}
	}
}

int MemberInfoCollection::getMemberInfoCount()
{	
	//Functnion: getMemberInfoCount()
	//Description: Ư�� MemberInfo�� ���°�� Collectoin���� �ҷ����� �Լ�
	//Created: 2018/05/28
	//Author: ������


	return memberInfoCount;
}

void MemberInfoCollection::setMemberInfoCount(int _memberInfoCount)
{
	//Functnion: setMemberInfoCount(int _memberInfoCount)
	//Description:MemeberInfo�� �ο��ϴ� �Լ�
	//Created: 2018/05/28
	//Author: ������


	memberInfoCount = _memberInfoCount;
}
