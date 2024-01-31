#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class EventService
{
public:
	EventService();
	~EventService();

	void waitKeyEvent(int _delay = 0);

private:

};

