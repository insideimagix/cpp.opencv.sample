#include "VideoService.h"

VideoService::VideoService() {
}

VideoService::~VideoService() {
}

bool VideoService::IsOpenedVideo() {
	return m_cvCap.isOpened();
}

bool VideoService::OpenVideoFile(const string& _filename) {
	return false;
}

bool VideoService::OpenVideoDevice(const int _index) {
	if (true == m_cvCap.isOpened()) {
		ClosedVideo();
	}

	return m_cvCap.open(_index);
}

bool VideoService::GetVideoBuffer(Mat& _cvImage) {
	if (false == m_cvCap.read(_cvImage)) {
		cout << "영상 획득에 실패하였습니다." << endl;
		return false;
	}

	return true;
}

void VideoService::ClosedVideo() {
	m_cvCap.release();
}