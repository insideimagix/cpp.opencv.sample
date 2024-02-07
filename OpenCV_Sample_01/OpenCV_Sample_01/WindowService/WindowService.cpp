#include "WindowService.h"

using namespace cv;

WindowService::WindowService() {
}

WindowService::~WindowService() {
	if (false == m_windowName.empty()) {
		DestroyWindow(m_windowName);
	}
}

bool WindowService::CreateWindow(const string& _windowName, const ecWindowFlag _showFlag) {
	if (true == _windowName.empty()) {
		cout << "윈도우 창 이름이 설정되지 않았습니다." << endl;
		return false;
	}

	if ((false == m_windowName.empty()) && (m_windowName != _windowName)) {
		DestroyWindow(m_windowName);
	}
	
	if (true == m_windowName.empty()) {
		m_windowName = _windowName;
		namedWindow(_windowName, ConvertWindowsFlag(_showFlag));
	}
	
	return true;
}

bool WindowService::DestroyWindow(const string& _windowName) {
	if (true == m_windowName.empty()) {
		cout << "\"" + _windowName + "\"윈도우 창 이름이 존재하지 않습니다." << endl;
		return false;
	}

	destroyWindow(m_windowName);
	m_windowName.clear();

	return true;
}

void WindowService::ShowInputArray(const Mat& _InputArray) const {
	imshow(m_windowName, _InputArray);
}

int WindowService::ConvertWindowsFlag(const ecWindowFlag _windowFlag) const {
	int cvWindowFlag = WindowFlags::WINDOW_AUTOSIZE;

	if (_windowFlag >= ecWindowFlag::MAX) {
		return cvWindowFlag;
	}

	switch (_windowFlag) {
		case ecWindowFlag::DEFAULT:
		case ecWindowFlag::WINDOW_AUTOSIZE: {
			cvWindowFlag = WindowFlags::WINDOW_AUTOSIZE;
		}
		break;

		case ecWindowFlag::WINDOW_NORMAL: {
			cvWindowFlag = WindowFlags::WINDOW_NORMAL;
		}
		break;

		case ecWindowFlag::WINDOW_OEPNGL: {
			cvWindowFlag = WindowFlags::WINDOW_OPENGL;
		}
		break;

		default: {
			cvWindowFlag = WindowFlags::WINDOW_AUTOSIZE;
		}
		break;
	}

	return cvWindowFlag;
}