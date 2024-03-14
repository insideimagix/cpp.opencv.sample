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
	bool		AddLine(const Point _pt1, const Point _pt2, const stDrawOptions& _options = stDrawOptions());
	bool		AddArrowedLine(const Point _pt1, const Point _pt2, const double _tipLength = 0.1, const stDrawOptions& _options = stDrawOptions());
	bool		AddRectangle(const Point _pt1, const Point _pt2, const stDrawOptions& _options = stDrawOptions());
	bool		AddRectangle(const Rect _rect, const stDrawOptions& _options = stDrawOptions());
	bool		AddRotatedRect(const RotatedRect _rect, const stDrawOptions& _options = stDrawOptions());
	bool		AddCircle(const Point _center, const int _radius, const stDrawOptions& _options = stDrawOptions());
	bool		AddEllipse(const Point _center, const Size _axes, const double _angle, const double _startAngle, const double _endAngle, const stDrawOptions& _options = stDrawOptions());
	bool		AddEllipse(const RotatedRect _rect, const stDrawOptions& _options = stDrawOptions());
	bool		AddPloyline(const Point** _pts, const int* _npts, const int _ncontours, const bool _isClosed, const stDrawOptions& _options = stDrawOptions());
	bool		AddPloyline(const InputArrayOfArrays _pts, const bool _isClosed, const stDrawOptions& _options = stDrawOptions());

	bool		AddMarker(const Point _pt, const ecMarkerType _markerType = ecMarkerType::DEFAULT, const int _markerSize = 20, const stDrawOptions& _options = stDrawOptions());
	bool		AddText(const String& _text, const Point _org, const stFontOptions _fontOptions = stFontOptions(), const stDrawOptions& _options = stDrawOptions());

private:
	void		ShowArray(const Mat& _array) const;
	int			ConvertWindowsFlag(const ecWindowFlag _windowFlag) const;

	string		m_windowName;
	Mat			m_cvImage;
};

