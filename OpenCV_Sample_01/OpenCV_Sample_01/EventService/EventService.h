#pragma once

#include <iostream>

using namespace std;

class EventService
{
public:
	EventService();
	~EventService();

	int			waitKeyEvent(int _delay = 0);

private:

};

