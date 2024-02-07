#pragma once

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