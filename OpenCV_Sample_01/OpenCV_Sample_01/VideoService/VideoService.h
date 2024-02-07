#pragma once

#include <iostream>
#include "../WindowService/WindowService.h"
#include "../CommonType.h"

using namespace std;
using namespace cv;

class VideoService : public WindowService
{
public:
	VideoService();
	~VideoService() final;

	bool			OpenVideo(const int _index);
	bool			ShowVideo(const string& _windowName, const ecWindowFlag _showFlag);

private:
	VideoCapture	m_cvCap;
	Mat				m_cvImage;
};

 