#include "ChangeSessionUI.h"

void ChangeSessionUI::startInterface(ChangeSessionControl *ctl, MemberCollection *mcollection) {
	// Function: void startInterface(ChangeSessionControl *ctl, MemberCollection *mcollection)
	// Description: ���� ���� �������̽�
	// Created: 2019/05/31
	// Author: ��¿�

	string ID;
	cin >> ID;

	ctl->changeSession(ID, mcollection);
}