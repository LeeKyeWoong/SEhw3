#include "SetCurrentTimeControl.h"

void SetCurrentTimeControl::setCurrentTime(Timer *t, string time, TicketCollection *tc) {
	// Function: void setCurrentTime(Timer *t, string time, TicketCollection *tc)
	// Description: 현재시간을 업데이트하도록 timer의 함수인 setCurrentTime을 호출하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	t->setCurrentTime(time);
	// 티켓 삭제 구현~~~~~~~
}