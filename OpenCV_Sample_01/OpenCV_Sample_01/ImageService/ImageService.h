#pragma once

#include <iostream>
#include "../WindowService/WindowService.h"
#include "../CommonType.h"

using namespace std;
using namespace cv;

class ImageService : public WindowService
{
public:
	ImageService();
	~ImageService() final;

	bool			OpenImage(const string& _fileName, const ecOpenFlag _openFlag);
	bool			ShowImage(const string& _windowName, const ecWindowFlag _showFlag);

	bool			GetBufferInfo(stBufferInfo& _info) const;
	bool			GetBuffer(uint8_t* _pBuffer);

private:
	int				ConvertOpenFlag(const ecOpenFlag _openFlag) const;

	Mat				m_cvImage;
};

