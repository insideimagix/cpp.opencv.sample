#pragma once
#include "../CommonType.h"

class EventService
{
public:
	EventService();
	~EventService();

	int			waitKeyEvent(int _delay = 0);

private:

};

