#include "UtilService.h"

UtilService::UtilService() {
}

UtilService::~UtilService() {
}

void UtilService::DrawNormalLine(Mat& _cvImage, const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	line(_cvImage, _pt1, _pt2, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawArrowedLine(Mat& _cvImage, const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness, const double _tipLength, const ecLineType _lineType, const int _shift) {
	arrowedLine(_cvImage, _pt1, _pt2, _color, _thickness, ConvertLineType(_lineType), _shift, _tipLength);
}

void UtilService::DrawRectangle(Mat& _cvImage, const Point _pt1, const Point _pt2, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	rectangle(_cvImage, _pt1, _pt2, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawRectangle(Mat& _cvImage, const Rect _rect, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	rectangle(_cvImage, _rect, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawRotatedRect(Mat& _cvImage, const RotatedRect _rect, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	Point2f vertices[4];
	_rect.points(vertices);

	for (int index = 0; index < 4; index++) {
		DrawNormalLine(_cvImage, vertices[index], vertices[(index + 1) % 4], _color, _thickness, _lineType, _shift);
	}
}

void UtilService::DrawCircle(Mat& _cvImage, const Point _center, const int _radius, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	circle(_cvImage, _center, _radius, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawEllipse(Mat& _cvImage, const Point _center, const Size _axes, const double _angle, const double _startAngle, const double _endAngle, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	ellipse(_cvImage, _center, _axes, _angle, _startAngle, _endAngle, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawEllipse(Mat& _cvImage, RotatedRect _rect, const Scalar& _color, const int _thickness, const ecLineType _lineType) {
	ellipse(_cvImage, _rect, _color, _thickness, ConvertLineType(_lineType));
}

void UtilService::DrawPloyline(Mat& _cvImage, const Point** _pts, const int* _npts, const int _ncontours, const bool _isClosed, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	polylines(_cvImage, _pts, _npts, _ncontours, _isClosed, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawPloyline(Mat& _cvImage, const InputArrayOfArrays _pts, const bool _isClosed, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	polylines(_cvImage, _pts, _isClosed, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawFillPloy(Mat& _cvImage, const Point** _pts, const int* _npts, const int _ncontours, const Scalar& _color, const ecLineType _lineType, const int _shift, const Point _offset) {
	fillPoly(_cvImage, _pts, _npts, _ncontours, _color, ConvertLineType(_lineType), _shift, _offset);
}

void UtilService::DrawFillPloy(Mat& _cvImage, const InputArrayOfArrays _pts, const Scalar& _color, const ecLineType _lineType, const int _shift, const Point _offset) {
	fillPoly(_cvImage, _pts, _color, ConvertLineType(_lineType), _shift, _offset);
}

void UtilService::DrawMarker(Mat& _cvImage, const Point _pt, const Scalar& _color, const ecMarkerType _markerType, const int _markerSize, const int _thickness, const ecLineType _lineType) {
	drawMarker(_cvImage, _pt, _color, ConvertMarkerType(_markerType), _markerSize, _thickness, ConvertLineType(_lineType));
}

void UtilService::DrawText(Mat& _cvImage, const String& _text, const Point _org, const ecFontType _fontType, const double fontScale, const Scalar& _color, const int _thickness, const ecLineType _lineType, const bool _bottomLeftOrigin) {
	putText(_cvImage, _text, _org, ConvertFontType(_fontType), fontScale, _color, _thickness, ConvertLineType(_lineType), _bottomLeftOrigin);
}

int UtilService::ConvertLineType(const ecLineType _lineType) const {
	int cvLineType = LineTypes::LINE_8;

	if (_lineType >= ecLineType::MAX) {
		return cvLineType;
	}

	switch (_lineType) {
		case ecLineType::DEFAULT:
		case ecLineType::LINETYPE_8CONNECT: {
			cvLineType = LineTypes::LINE_8;
		}
		break;

		case ecLineType::LINETYPE_FILLED: {
			cvLineType = LineTypes::FILLED;
		}
		break;

		case ecLineType::LINETYPE_4CONNECT: {
			cvLineType = LineTypes::LINE_4;
		}
		break;

		case ecLineType::LINETYPE_AA: {
			cvLineType = LineTypes::LINE_AA;
		}
		break;

		default: {
			cvLineType = LineTypes::LINE_8;
		}
		break;
	}

	return cvLineType;
}

int UtilService::ConvertMarkerType(const ecMarkerType _markerType) const {
	int cvMarkerType = MarkerTypes::MARKER_CROSS;

	if (_markerType >= ecMarkerType::MAX) {
		return cvMarkerType;
	}

	switch (_markerType) {
		case ecMarkerType::DEFAULT:
		case ecMarkerType::MARKERTYPE_CROSS: {
			cvMarkerType = MarkerTypes::MARKER_CROSS;
		}
		break;

		case ecMarkerType::MARKERTYPE_TILTED_CROSS: {
			cvMarkerType = MarkerTypes::MARKER_TILTED_CROSS;
		}
		break;

		case ecMarkerType::MARKERTYPE_STAR: {
			cvMarkerType = MarkerTypes::MARKER_STAR;
		}
		break;

		case ecMarkerType::MARKERTYPE_DIAMOND: {
			cvMarkerType = MarkerTypes::MARKER_DIAMOND;
		}
		break;

		case ecMarkerType::MARKERTYPE_SQUARE: {
			cvMarkerType = MarkerTypes::MARKER_SQUARE;
		}
		break;

		case ecMarkerType::MARKERTYPE_TRIANGLE_UP: {
			cvMarkerType = MarkerTypes::MARKER_TRIANGLE_UP;
		}
		break;

		case ecMarkerType::MARKERTYPE_TRIANGLE_DOWN: {
			cvMarkerType = MarkerTypes::MARKER_TRIANGLE_DOWN;
		}
		break;

		default: {
			cvMarkerType = MarkerTypes::MARKER_CROSS;
		}
		break;
	}

	return cvMarkerType;
}

int	UtilService::ConvertFontType(const ecFontType _fontType) const {
	int cvFontType = HersheyFonts::FONT_HERSHEY_SIMPLEX;

	if (_fontType >= ecFontType::MAX) {
		return cvFontType;
	}

	switch (_fontType) {
		case ecFontType::DEFAULT:
		case ecFontType::FONT_SIMPLEX: {
			cvFontType = HersheyFonts::FONT_HERSHEY_SIMPLEX;
		}
		break;

		case ecFontType::FONT_PLAIN: {
			cvFontType = HersheyFonts::FONT_HERSHEY_PLAIN;
		}
		break;

		case ecFontType::FONT_DUPLEX: {
			cvFontType = HersheyFonts::FONT_HERSHEY_DUPLEX;
		}
		break;

		case ecFontType::FONT_COMPLEX: {
			cvFontType = HersheyFonts::FONT_HERSHEY_COMPLEX;
		}
		break;

		case ecFontType::FONT_TRIPLEX: {
			cvFontType = HersheyFonts::FONT_HERSHEY_TRIPLEX;
		}
		break;

		case ecFontType::FONT_COMPLEX_SMALL: {
			cvFontType = HersheyFonts::FONT_HERSHEY_COMPLEX_SMALL;
		}
		break;

		case ecFontType::FONT_SCRIPT_SIMPLEX: {
			cvFontType = HersheyFonts::FONT_HERSHEY_SCRIPT_SIMPLEX;
		}
		break;

		case ecFontType::FONT_SCRIPT_COMPLEX: {
			cvFontType = HersheyFonts::FONT_HERSHEY_SCRIPT_COMPLEX;
		}
		break;

		case ecFontType::FONT_ITALIC: {
			cvFontType = HersheyFonts::FONT_ITALIC;
		}
		break;

		default: {
			cvFontType = HersheyFonts::FONT_HERSHEY_SIMPLEX;
		}
		break;
	}

	return cvFontType;
}