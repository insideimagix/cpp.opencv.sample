#include "ImageService.h"

ImageService::ImageService() {
	m_windowName.clear();
}

ImageService::~ImageService() {
	if (false == m_windowName.empty()) {
		destroyWindow(m_windowName);
	}
}

bool ImageService::OpenImage(const string& _fileName, const ecOpenFlag _openFlag) {
	m_cvImage = imread(_fileName, ConvertOpenFlag(_openFlag));
	if (m_cvImage.empty()) {
		cout << "\"" + _fileName + "\" ������ ���� �� �����ϴ�." << endl;
		return false;
	}

	return true;
}

bool ImageService::ShowImage(const string& _windowsName, const ecWindowFlag _showFlag) {
	if (m_cvImage.empty()) {
		cout << "�̹��� ������ �������� �ʽ��ϴ�." << endl;
		return false;
	}

	if (_windowsName.empty()) {
		cout << "������ â �̸��� �������� �ʾҽ��ϴ�." << endl;
		return false;
	}

	m_windowName = _windowsName;
	namedWindow(m_windowName, ConvertWindowsFlag(_showFlag));
	imshow(m_windowName, m_cvImage);

	return true;
}

int ImageService::ConvertOpenFlag(const ecOpenFlag _openFlag) const {
	int cvOpenFlag = ImreadModes::IMREAD_COLOR;

	if (_openFlag >= ecOpenFlag::MAX) {
		return cvOpenFlag;
	}

	switch (_openFlag) {
		case ecOpenFlag::DEFAULT:
		case ecOpenFlag::OPEN_COLOR: {
			cvOpenFlag = ImreadModes::IMREAD_COLOR;
		}
		break;

		case ecOpenFlag::OPEN_GRAYSCALE: {
			cvOpenFlag = ImreadModes::IMREAD_GRAYSCALE;
		}
		break;

		case ecOpenFlag::OPEN_UNCHANGED: {
			cvOpenFlag = ImreadModes::IMREAD_UNCHANGED;
		}
		break;

		default: {
			cvOpenFlag = ImreadModes::IMREAD_COLOR;
		}
		break;
	}

	return cvOpenFlag;
}

int ImageService::ConvertWindowsFlag(const ecWindowFlag _windowFlag) const {
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