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

bool Timer::checkTimeToDeleteTicket(string registerTime) {
	// Function: bool checkTimeToDeleteTicket(string registerTime)
	// Description: 티켓이 등록된 시간과 현재시간을 비교하여 티켓을 삭제할지 결정하는 함수이다.
	// Parameter: string registerTime - 티켓이 등록된 시간
	// Return value: 티켓이 등록된 지 1년 이상 된 경우 true를, 그렇지 않은 경우 false를 리턴한다.
	// Created: 2019/05/30
	// Author: 김승연

	/*
	매개변수로 받은 registerTime이 string형으로 ????:??:??:??:?? 형식이기 때문에
	':'를 제외하고 년월일까지를 따로 임시 변수 tmp_registerTime에 저장을 한다.
	그래서 2019:05:30:12:23 이란 시간을 tmp_registerTime에 20190530 으로 저장한다.
	그러고나서 이 string으로 된 것을 int형으로 변환을 한다.
	이는 currentTime의 경우에도 동일하다.

	티켓 삭제는 등록된 지 1년 지났을 때 이루어지기 때문에, 현재시간과 티켓 등록 시간의 차이가 10000 이상이 되는 경우 삭제하면 된다.
	*/

	string tmp_registerTime, tmp_currentTime;
	tmp_registerTime.append(registerTime, 0, 4);
	tmp_registerTime.append(registerTime, 5, 2);
	tmp_registerTime.append(registerTime, 8, 2);
	tmp_currentTime.append(this->currentTime, 0, 4);
	tmp_currentTime.append(this->currentTime, 5, 2);
	tmp_currentTime.append(this->currentTime, 8, 2);

	int regTime, cntTime;
	regTime = stoi(tmp_registerTime);
	cntTime = stoi(tmp_currentTime);

	if (cntTime - regTime > 10000) return true;
	else return false;
}