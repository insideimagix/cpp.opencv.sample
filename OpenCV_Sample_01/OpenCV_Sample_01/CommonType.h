#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

enum class ecOpenFlag {
	DEFAULT = 0,
	OPEN_COLOR,
	OPEN_GRAYSCALE,
	OPEN_UNCHANGED,
	MAX,
};

enum class ecWindowFlag {
	DEFAULT = 0,
	WINDOW_AUTOSIZE,
	WINDOW_NORMAL,
	WINDOW_OEPNGL,
	MAX,
};

enum class ecLineType {
	DEFAULT = 0,
	LINETYPE_FILLED,
	LINETYPE_4CONNECT,
	LINETYPE_8CONNECT,
	LINETYPE_AA,
	MAX,
};

enum class ecMarkerType {
	DEFAULT = 0,
	MARKERTYPE_CROSS,
	MARKERTYPE_TILTED_CROSS,
	MARKERTYPE_STAR,
	MARKERTYPE_DIAMOND,
	MARKERTYPE_SQUARE,
	MARKERTYPE_TRIANGLE_UP,
	MARKERTYPE_TRIANGLE_DOWN,
	MAX,
};

enum class ecFontType {
	DEFAULT= 0,
	FONT_SIMPLEX,
	FONT_PLAIN,
	FONT_DUPLEX,
	FONT_COMPLEX,
	FONT_TRIPLEX,
	FONT_COMPLEX_SMALL,
	FONT_SCRIPT_SIMPLEX,
	FONT_SCRIPT_COMPLEX,
	FONT_ITALIC,
	MAX,
};

struct stBufferInfo {
	int			width;
	int			height;
	int			channels;
	int			imageSize;

	stBufferInfo() {
		width = 0;
		height = 0;
		channels = 0;
		imageSize = 0;
	}
};

struct stDrawOptions {
	Scalar		color;
	int			thickness;
	ecLineType	lineType;
	int			bitShift;
	bool		isFilled;
	Point		offset;

	stDrawOptions() {
		color = Scalar(0, 0, 0);
		thickness = 1;
		lineType = ecLineType::DEFAULT;
		bitShift = 0;
		isFilled = false;
		offset = Point();
	}

	stDrawOptions(Scalar _color) {
		color = _color;
		thickness = 1;
		lineType = ecLineType::DEFAULT;
		bitShift = 0;
		isFilled = false;
		offset = Point();
	}

	stDrawOptions(Scalar _color, int _thickness) {
		color = _color;
		thickness = _thickness;
		lineType = ecLineType::DEFAULT;
		bitShift = 0;
		isFilled = false;
		offset = Point();
	}

	stDrawOptions(Scalar _color, int _thickness, ecLineType	_lineType) {
		color = _color;
		thickness = _thickness;
		lineType = _lineType;
		bitShift = 0;
		isFilled = false;
		offset = Point();
	}

	stDrawOptions(Scalar _color, int _thickness, ecLineType	_lineType, int _bitShift) {
		color = _color;
		thickness = _thickness;
		lineType = _lineType;
		bitShift = _bitShift;
		isFilled = false;
		offset = Point();
	}

	stDrawOptions(Scalar _color, int _thickness, ecLineType	_lineType, int _bitShift, bool _isFilled) {
		color = _color;
		thickness = _thickness;
		lineType = _lineType;
		bitShift = _bitShift;
		isFilled = _isFilled;
		offset = Point();
	}

	stDrawOptions(Scalar _color, int _thickness, ecLineType	_lineType, int _bitShift, bool _isFilled, Point _offset) {
		color = _color;
		thickness = _thickness;
		lineType = _lineType;
		bitShift = _bitShift;
		isFilled = _isFilled;
		offset = _offset;
	}
};

struct stFontOptions {
	ecFontType	fontType;
	double		fontScale;
	bool		bottomLeftOrigin;

	stFontOptions() {
		fontType = ecFontType::DEFAULT;
		fontScale = 1;
		bottomLeftOrigin = false;
	}

	stFontOptions(ecFontType _fontType) {
		fontType = _fontType;
		fontScale = 1;
		bottomLeftOrigin = false;
	}

	stFontOptions(ecFontType _fontType, double _fontScale) {
		fontType = _fontType;
		fontScale = _fontScale;
		bottomLeftOrigin = false;
	}

	stFontOptions(ecFontType _fontType, double _fontScale, bool _bottomLeftOrigin) {
		fontType = _fontType;
		fontScale = _fontScale;
		bottomLeftOrigin = _bottomLeftOrigin;
	}
};