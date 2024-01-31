#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

#include "ImageType.h"

using namespace std;
using namespace cv;

class ImageService
{
public:
	ImageService();
	~ImageService();

	bool OpenImage(const string& _fileName, const ecOpenFlag _openFlag);
	bool ShowImage(const string& _windowsName, const ecWindowFlag _showFlag);

private:
	int ConvertOpenFlag(const ecOpenFlag _openFlag) const;
	int ConvertWindowsFlag(const ecWindowFlag _windowFlag) const;

	Mat m_cvImage;
	string m_windowName;
};

