#pragma once
#include "../../CommonType.h"

class UtilService
{
public:
	UtilService();
	virtual ~UtilService();

	void			DrawNormalLine(Mat& _cvImage, const Point _pt1, const Point _pt2, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawArrowedLine(Mat& _cvImage, const Point _pt1, const Point _pt2, const Scalar& _color,
						const int _thickness, const double _tipLength, const ecLineType _lineType, const int _shift);

	void			DrawRectangle(Mat& _cvImage, const Point _pt1, const Point _pt2, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawRectangle(Mat& _cvImage, const Rect _rect, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawCircle(Mat& _cvImage, const Point _center, const int _radius, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawMarker(Mat& _cvImage, const Point _pt, const Scalar& _color, const ecMarkerType _markerType,
						const int _markerSize, const int _thickness, const ecLineType _lineType);

private:
	int				ConvertLineType(const ecLineType _lineType) const;
	int				ConvertMarkerType(const ecMarkerType _markerType) const;
};

