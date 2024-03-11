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

void UtilService::DrawCircle(Mat& _cvImage, const Point _center, const int _radius, const Scalar& _color, const int _thickness, const ecLineType _lineType, const int _shift) {
	circle(_cvImage, _center, _radius, _color, _thickness, ConvertLineType(_lineType), _shift);
}

void UtilService::DrawMarker(Mat& _cvImage, const Point _pt, const Scalar& _color, const ecMarkerType _markerType, const int _markerSize, const int _thickness, const ecLineType _lineType) {
	drawMarker(_cvImage, _pt, _color, ConvertMarkerType(_markerType), _markerSize, _thickness, ConvertLineType(_lineType));
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