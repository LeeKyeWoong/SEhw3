#include "Timer.h"

void Timer::setCurrentTime(string cntTime) {
	// Function: void setCurrentTime(string cntTime)
	// Description: �Ű������� ���� �ð��� ��������� currentTime�� �����ϴ� �Լ��̴�.
	// Parameter: string cntTime - ���ο� ����ð����� �����ϱ� ���� ���� ��
	// Created: 2019/05/30
	// Author: ��¿�

	this->currentTime = cntTime;
}

string Timer::getCurrentTime() {
	// Function: string getCurrentTime()
	// Description: ��������� currentTime�� ���� �����ϴ� �Լ��̴�.
	// Return value: ���� �ð�
	// Created: 2019/05/30
	// Author: ��¿�

	return this->currentTime;
}
/*
bool Timer::checkTimeToDeleteTicket(string registerTime) {
	// Function: bool checkTimeToDeleteTicket(string registerTime)
	// Description: Ƽ���� ��ϵ� �ð��� ����ð��� ���Ͽ� Ƽ���� �������� �����ϴ� �Լ��̴�.
	// Parameter: string registerTime - Ƽ���� ��ϵ� �ð�
	// Return value: Ƽ���� ��ϵ� �� 1�� �̻� �� ��� true��, �׷��� ���� ��� false�� �����Ѵ�.
	// Created: 2019/05/30
	// Author: ��¿�


}*/