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


bool WindowService::OpenImage(const string& _fileName, const ecOpenFlag _openFlag) {
	if (false == OpenImageFile(_fileName, _openFlag)) {
		return false;
	}

	if (false == GetImageBuffer(m_cvImage)) {
		return false;
	}

	return true;
}

bool WindowService::ShowImage() {
	if (true == m_cvImage.empty()) {
		cout << "열려있는 이미지 파일이 존재하지 않습니다." << endl;
		return false;
	}

	ShowArray(m_cvImage);
	return true;
}

bool WindowService::OpenVideo(const int _index) {
	bool bOpened = true;
	if (false == IsOpenedVideo()) {
		bOpened = OpenVideoDevice(_index);
	}

	if (false == bOpened) {
		cout << "비디오 장치 열기에 실패하였습니다." << endl;
		return false;
	}

	return bOpened;
}

bool WindowService::GrapVideo() {
	if (false == GetVideoBuffer(m_cvImage)) {
		return false;
	}

	return true;
}

bool WindowService::ShowVideo() {
	if (true == m_cvImage.empty()) {
		cout << "획득된 이미지 버퍼가 존재하지 않습니다." << endl;
		return false;
	}

	ShowArray(m_cvImage);
	return true;
}

bool WindowService::AddLine(const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	if (true == m_cvImage.empty()) {
		cout << "이미지가 존재하지 않습니다." << endl;
		return false;
	}

	DrawNormalLine(m_cvImage, _pt1, _pt2, _color, _thickness, _lineType, _shift);
	return true;
}

bool WindowService::AddArrowedLine(const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness, const double _tipLength, const ecLineType _lineType, const int _shift) {
	if (true == m_cvImage.empty()) {
		cout << "이미지가 존재하지 않습니다." << endl;
		return false;
	}

	DrawArrowedLine(m_cvImage, _pt1, _pt2, _color, _thickness, _tipLength, _lineType, _shift);
	return true;
}

bool WindowService::AddRectangle(const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	if (true == m_cvImage.empty()) {
		cout << "이미지가 존재하지 않습니다." << endl;
		return false;
	}

	DrawRectangle(m_cvImage, _pt1, _pt2, _color, _thickness, _lineType, _shift);
	return true;
}

bool WindowService::AddRectangle(const Rect _rect, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	if (true == m_cvImage.empty()) {
		cout << "이미지가 존재하지 않습니다." << endl;
		return false;
	}

	DrawRectangle(m_cvImage, _rect, _color, _thickness, _lineType, _shift);
	return true;
}

bool WindowService::AddCircle(const Point _center, const int _radius, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	if (true == m_cvImage.empty()) {
		cout << "이미지가 존재하지 않습니다." << endl;
		return false;
	}

	DrawCircle(m_cvImage, _center, _radius, _color, _thickness, _lineType, _shift);
	return true;
}

bool WindowService::AddMarker(const Point _pt, const Scalar& _color, const ecMarkerType _markerType, const int _markerSize, const int _thickness, const ecLineType _lineType) {
	if (true == m_cvImage.empty()) {
		cout << "이미지가 존재하지 않습니다." << endl;
		return false;
	}

	DrawMarker(m_cvImage, _pt, _color, _markerType, _markerSize, _thickness, _lineType);
	return true;
}

void WindowService::ShowArray(const Mat& _array) const {
	imshow(m_windowName, _array);
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