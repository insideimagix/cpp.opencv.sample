#pragma once
#include "../CoreService/ImageService/ImageService.h"
#include "../CoreService/VideoService/VideoService.h"
#include "../CoreService/UtilService/UtilService.h"

class WindowService : public VideoService, ImageService, UtilService
{
public:
	WindowService();
	virtual ~WindowService();

	bool		CreateWindow(const string& _windowName, const ecWindowFlag _showFlag);
	bool		DestroyWindow(const string& _windowName);

public:
	bool		OpenImage(const string& _fileName, const ecOpenFlag _openFlag);
	bool		ShowImage();

public:
	bool		OpenVideo(const int _index);
	bool		GrapVideo();
	bool		ShowVideo();

public:
	bool		AddLine(const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness = 1, const ecLineType _lineType = ecLineType::DEFAULT, const int _shift = 0);
	bool		AddArrowedLine(const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness = 1, const double _tipLength = 0.1, const ecLineType _lineType = ecLineType::DEFAULT, const int _shift = 0);
	bool		AddRectangle(const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness = 1, const ecLineType _lineType = ecLineType::DEFAULT, const int _shift = 0);
	bool		AddRectangle(const Rect _rect, const Scalar& _color, const int _thickness = 1, const ecLineType _lineType = ecLineType::DEFAULT, const int _shift = 0);
	bool		AddCircle(const Point _center, const int _radius, const Scalar& _color, const int _thickness = 1, const ecLineType _lineType = ecLineType::DEFAULT, const int _shift = 0);
	bool		AddMarker(const Point _pt, const Scalar& _color, const ecMarkerType _markerType = ecMarkerType::DEFAULT, const int _markerSize = 20, const int _thickness = 1, const ecLineType _lineType = ecLineType::DEFAULT);

private:
	void		ShowArray(const Mat& _array) const;
	int			ConvertWindowsFlag(const ecWindowFlag _windowFlag) const;

	string		m_windowName;
	Mat			m_cvImage;
};

