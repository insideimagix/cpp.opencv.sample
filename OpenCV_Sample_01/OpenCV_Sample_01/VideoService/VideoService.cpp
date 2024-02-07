#include "VideoService.h"
#include <opencv2/opencv.hpp>

using namespace cv;

VideoService::VideoService() {
}

VideoService::~VideoService() {
}

bool VideoService::OpenVideo(const int _index) {
	return m_cvCap.open(_index);
}

bool VideoService::ShowVideo(const string& _windowName, const ecWindowFlag _showFlag) {
	if (false == CreateWindow(_windowName, _showFlag)) {
		cout << "\"" + _windowName + "\" 윈도우 생성에 실패하였습니다." << endl;
		return false;
	}

	if (false == m_cvCap.read(m_cvImage)) {
		cout << "영상 획득에 실패하였습니다." << endl;
		return false;
	}

	ShowInputArray(m_cvImage);
	return true;
}
