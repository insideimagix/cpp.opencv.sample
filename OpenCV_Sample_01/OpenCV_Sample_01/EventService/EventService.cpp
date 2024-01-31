#include "EventService.h"

EventService::EventService() {
}

EventService::~EventService() {
}

void EventService::waitKeyEvent(int _delay) {
	waitKey(_delay);
}
