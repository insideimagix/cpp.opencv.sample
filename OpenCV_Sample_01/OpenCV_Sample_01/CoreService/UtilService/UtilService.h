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

	void			DrawRotatedRect(Mat& _cvImage, const RotatedRect _rect, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawCircle(Mat& _cvImage, const Point _center, const int _radius, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawEllipse(Mat& _cvImage, const Point _center, const Size _axes, const double _angle, 
						const double _startAngle, const double _endAngle, const Scalar& _color,
						const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawEllipse(Mat& _cvImage, RotatedRect _rect, const Scalar& _color,
						const int _thickness, const ecLineType _lineType);

	void			DrawPloyline(Mat& _cvImage, const Point** _pts, const int* _npts, const int _ncontours, const bool _isClosed,
						const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawPloyline(Mat& _cvImage, const InputArrayOfArrays _pts, const bool _isClosed,
						const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift);

	void			DrawFillPloy(Mat& _cvImage, const Point** _pts, const int* _npts, const int _ncontours,
						const Scalar& _color, const ecLineType _lineType, const int _shift, const Point _offset);

	void			DrawFillPloy(Mat& _cvImage, const InputArrayOfArrays _pts,
						const Scalar& _color, const ecLineType _lineType, const int _shift, const Point _offset);

	void			DrawMarker(Mat& _cvImage, const Point _pt, const Scalar& _color, const ecMarkerType _markerType,
						const int _markerSize, const int _thickness, const ecLineType _lineType);

	void			DrawText(Mat& _cvImage, const String& _text, const Point _org, const ecFontType _fontType, const double fontScale,
						const Scalar& _color, const int _thickness, const ecLineType _lineType, const bool _bottomLeftOrigin);

private:
	int				ConvertLineType(const ecLineType _lineType) const;
	int				ConvertMarkerType(const ecMarkerType _markerType) const;
	int				ConvertFontType(const ecFontType _fontType) const;
};

