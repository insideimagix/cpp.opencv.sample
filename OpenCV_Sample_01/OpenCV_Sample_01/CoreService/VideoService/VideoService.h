#pragma once
#include "../../CommonType.h"

class VideoService
{
public:
	VideoService();
	virtual ~VideoService();

	bool			IsOpenedVideo();
	
	bool			OpenVideoFile(const string& _filename);
	bool			OpenVideoDevice(const int _index);

	bool			GetVideoBuffer(Mat& _cvImage);
	void			ClosedVideo();

private:
	VideoCapture	m_cvCap;
};

 