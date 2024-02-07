#include "ImageService.h"

ImageService::ImageService() {
}

ImageService::~ImageService() {
}

bool ImageService::OpenImage(const string& _fileName, const ecOpenFlag _openFlag) {
	m_cvImage = imread(_fileName, ConvertOpenFlag(_openFlag));
	if (m_cvImage.empty()) {
		cout << "\"" + _fileName + "\" 파일을 읽을 수 없습니다." << endl;
		return false;
	}

	return true;
}

bool ImageService::ShowImage(const string& _windowName, const ecWindowFlag _showFlag) {
	if (true == m_cvImage.empty()) {
		cout << "Open된 이미지가 없습니다." << endl;
		return false;
	}

	if (false == CreateWindow(_windowName, _showFlag)) {
		cout << "\"" + _windowName + "\" 윈도우 생성에 실패하였습니다." << endl;
		return false;
	}

	ShowInputArray(m_cvImage);
	return true;
}

bool ImageService::GetBufferInfo(stBufferInfo& _info) const {
	if (true == m_cvImage.empty()) {
		cout << "Open된 이미지가 없습니다." << endl;
		return false;
	}

	_info.Initialzie();

	_info.width = m_cvImage.cols;
	_info.height = m_cvImage.rows;
	_info.channels = m_cvImage.channels();
	_info.imageSize = m_cvImage.cols * m_cvImage.rows * m_cvImage.channels();

	return true;
}

bool ImageService::GetBuffer(uint8_t* _pBuffer) {
	if (m_cvImage.empty()) {
		cout << "Open된 이미지가 없습니다." << endl;
		return false;
	}

	if (nullptr != _pBuffer) {
		delete [] _pBuffer;
		_pBuffer = nullptr;
	}

	int imageSize = m_cvImage.cols * m_cvImage.rows * m_cvImage.channels();
	_pBuffer = new uint8_t[imageSize];
	memcpy(_pBuffer, m_cvImage.data, imageSize);

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