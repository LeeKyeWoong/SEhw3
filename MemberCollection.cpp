#pragma once

#include "MemberCollection.h"
#include "Member.h"

MemberCollection::MemberCollection(Member Member[MAX])
{
	//Functnion: MemberCollection(Member Member[MAX])
	//Description: MemberCollecion을 생성하는 생성자
	//Created: 2019/05/30
	//Author: 이계웅
	memberNumber = 0;
	for (int i = 0; i < MAX; i++) // MAX까지 반복한다.
	{
		this->Member[i] = &Member[i]; // i번째 멤버는 Member[i]의 주소를 넣어준다.(포인터배열)
	}
}

void MemberCollection::addMember(string id, string password, string name, string idNum, string memType, bool sessionOn); //MemberCollectoin에 Member객체를 저장하는 함수
{
	//Functnion: addMember(string id, string password, string name, string idNum, string memType, bool sessionOn)
	//Description: MemberCollection에 Member 객체를 추가하는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	this->Member[memberNumber]->createMember(string id, string password, string name, string idNum, string memType, bool sessionOn);
	this->memberNumber++;
}

void MemberCollection::deleteMember(int deleteMemberIndex)
{
	//Functnion: deleteMember(int deleteMemberIndex)
	//Description: MemberCollecton의 deleteMemberIndex번째의 Member를 삭제하는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	if (deleteMemberIndex == 0) // 만약 지울 번호가 0번이라면 
	{
		Member[deleteMemberIndex]->deleteMember(); // string을 ""으로 만든다.
		Member[deleteMemberIndex] = NULL; // 그리고 NULL로 만들어버린다.
	}
	else // 0번이 아니라면 
	{
		Member[deleteMemberIndex]->deleteMember(); // string을 ""으로 만든다.

		for(int i = deleteMemberIndex; i < this->memberNumber; i++) // 한칸씩 당긴다.
		{
			Member[deleteMemberIndex] = Member[deleteMemberIndex + 1];
		}
		Member[this->memberNumber - 1]->deleteMember(); // 마지막에 있는 Member지우고 
		Member[this->memberNumber - 1] = NULL;          // 널처리를 해준다.
		this->memberNumber--;                           // 멤버 수를 하나 줄인다. 
	}
}

Member* MemberCollection::getMember(int memberIndex)
{
	//Functnion: getMember(int memberIndex)
	//Description:MemberCollection의 memberIndex Member 를 반환하는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	return Member[memberIndex]; // 리턴하는 것은 포인터
}

Member* MemberCollection::currentSession()
{
	//Functnion: currentSession()
	//Description: 어떤 Memeber가 현재 Session인지 확인하는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	bool checkSession = false; //  일단 false로 한다.
	for (int i = 0; i < this->memberNumber; i++) // 멤버 수만큼 반복문을 돌린다.
	{
		if (Member[i]->getSessionOn() == true) // 만약 그 멤버의 세션이 트루라면 
		{
			checkSession = true; // 체크세션을 트루로 하고
			return Member[i];    // 그 멤버를 리턴한다.
		}
	}
	if (!checkSession) // 만약 아무것도 true가 아니라면 
	{ 
	 	return NULL;   // NULL을 리턴한다.
	}
}

int MemberCollection::getCurrentSessionIndex()
{
	//Functnion: getCurrentSessionIndex()
	//Description: 몇번째 Member가 현재 Session을 사용하는지 그 인덱스를 반환하는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	for (int i = 0; i < this->memberNumber; i++) // 멤버수만큼 반복문을 돌린다.
	{
		if (Member[i]->getSessionOn() == true) // 만약 세션온이 True라면 
		{ 
			return i; // 그 인덱스를 받는다.
		}
	}
}

int MemberCollection::getMemberNumber()
{
	//Functnion: getMemberNumber()
	//Description: MemberCollection의 멤버변수 memberNumber를 불러오는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	return this->memberNumber;
}

void MemberCollection::setMemberCount(int memberIndex)
{
	//Functnion: setMemberCount(int memberIndex)
	//Description: memberIndex의 인자를 멤버변수인 memberNumber로 Set하는 함수
	//Created: 2019/05/30
	//Author: 이계웅

	memberNumber = memberIndex;
}
