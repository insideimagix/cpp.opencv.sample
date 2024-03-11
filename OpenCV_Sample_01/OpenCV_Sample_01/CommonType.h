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

struct stBufferInfo {
	int width;
	int height;
	int channels;
	int imageSize;

	void Initialzie() {
		width = 0;
		height = 0;
		channels = 0;
		imageSize = 0;
	}

	stBufferInfo() {
		Initialzie();
	}
};