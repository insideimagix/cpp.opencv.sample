#include "EventService.h"
#include <opencv2/opencv.hpp>

using namespace cv;

EventService::EventService() {
}

EventService::~EventService() {
}

int EventService::waitKeyEvent(int _delay) {
	return waitKey(_delay);
}
