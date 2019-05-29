#pragma once

#include "MemberInfoCollection.h"
#include "MemberInfo.h"

MemberInfoCollection::MemberInfoCollection(MemberInfo _memberInfo[MAX])
{
	//Functnion: MemberInfoCollection(MemberInfo _memberInfo[MAX])
	//Description:MemberInfoCollecion을 생성하는 생성자
	//Created: 2018/05/28
	//Author: 문현준


	memberInfoCount = 0;
	for (int i = 0; i < MAX; i++)
	{
		this->memberInfo[i] = &_memberInfo[i];
	}
}

void MemberInfoCollection::addMemberInfo(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, string opaqueInventoryTryTime, bool sessionOn)
{
	//Functnion: addMemberInfo(string memType, string name, string residentRegistrationNumber, string address, string ID, string password, string opaqueInventoryTryTime, bool sessionOn)
	//Description: MemberInfoCollection에 Member 객체를 입력하는 함수
	//Created: 2018/05/28
	//Author: 문현준


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
	//Description: MemberInfoCollecton의 deleteMemberInfoIndex번째의 MemberInfo를 삭제하는 함수
	//Created: 2018/05/28
	//Author: 문현준


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
	//Description:MemberInfoCollection의 memberInfoCount번째 MemberInfo 를 반환하는 함수
	//Created: 2018/05/28
	//Author: 문현준


	return memberInfo[memberInfoCount];
}

MemberInfo* MemberInfoCollection::currentSession()
{
	//Functnion: currentSession()
	//Description: 어떤 Memeber가 현재 Session인지 확인하는 함수
	//Created: 2018/05/28
	//Author: 문현준


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
	//Description: 몇번째 memberInfoCollection이 현재 Sessiohn을 사용하는 지 반환하는 함수
	//Created: 2018/05/28
	//Author: 문현준


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
	//Description: 특정 MemberInfo가 몇번째로 Collectoin인지 불러오는 함수
	//Created: 2018/05/28
	//Author: 문현준


	return memberInfoCount;
}

void MemberInfoCollection::setMemberInfoCount(int _memberInfoCount)
{
	//Functnion: setMemberInfoCount(int _memberInfoCount)
	//Description:MemeberInfo를 부여하는 함수
	//Created: 2018/05/28
	//Author: 문현준


	memberInfoCount = _memberInfoCount;
}
