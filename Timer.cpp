#include "Timer.h"

void Timer::setCurrentTime(string cntTime) {
	// Function: void setCurrentTime(string cntTime)
	// Description: 매개변수로 받은 시간을 멤버변수인 currentTime에 저장하는 함수이다.
	// Parameter: string cntTime - 새로운 현재시간으로 설정하기 위해 받은 값
	// Created: 2019/05/30
	// Author: 김승연

	this->currentTime = cntTime;
}

string Timer::getCurrentTime() {
	// Function: string getCurrentTime()
	// Description: 멤버변수인 currentTime의 값을 리턴하는 함수이다.
	// Return value: 현재 시간
	// Created: 2019/05/30
	// Author: 김승연

	return this->currentTime;
}
/*
bool Timer::checkTimeToDeleteTicket(string registerTime) {
	// Function: bool checkTimeToDeleteTicket(string registerTime)
	// Description: 티켓이 등록된 시간과 현재시간을 비교하여 티켓을 삭제할지 결정하는 함수이다.
	// Parameter: string registerTime - 티켓이 등록된 시간
	// Return value: 티켓이 등록된 지 1년 이상 된 경우 true를, 그렇지 않은 경우 false를 리턴한다.
	// Created: 2019/05/30
	// Author: 김승연


}*/