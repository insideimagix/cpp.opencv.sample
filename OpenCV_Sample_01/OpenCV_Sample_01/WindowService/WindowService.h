#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include "../CommonType.h"

using namespace std;
using namespace cv;

class WindowService
{
public:
	WindowService();
	virtual		~WindowService();

protected:
	bool		CreateWindow(const string& _windowName, const ecWindowFlag _showFlag);
	bool		DestroyWindow(const string& _windowName);
	void		ShowInputArray(const Mat& _InputArray) const;

private:
	int			ConvertWindowsFlag(const ecWindowFlag _windowFlag) const;

	string		m_windowName;
};

