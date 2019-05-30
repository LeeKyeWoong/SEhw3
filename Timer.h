#pragma once

#include <iostream>
#include <string>
using namespace std;

class Timer {
	// Class: Timer
	// Description:
	// Created: 2019/05/30
	// Author: 김승연

private:
	string currentTime; // 현재 시간을 저장할 변수

private:
	void setCurrentTime(string cntTime);
	string getCurrentTime();
	bool checkTimeToDeleteTicket(string registerTime);

};